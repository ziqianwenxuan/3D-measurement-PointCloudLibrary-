#include "pclsegmentation.h"
#include "ui_pclsegmentation.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/ModelCoefficients.h>
#include <pcl/registration/icp.h>
#include <pcl/sample_consensus/method_types.h>
#include <pcl/sample_consensus/model_types.h>
#include <pcl/segmentation/sac_segmentation.h>
#include <pcl/filters/extract_indices.h>
#include <pcl/filters/voxel_grid.h>
#include <pcl/filters/passthrough.h>
#include <pcl/features/normal_3d.h>
#include <pcl/point_cloud.h>
#include <pcl/segmentation/region_growing.h>
#include <pcl/search/search.h>
#include <pcl/features/normal_3d_omp.h>
#include <pcl/filters/conditional_removal.h>
#include <pcl/search/organized.h>
#include <pcl/search/kdtree.h>
#include <pcl/point_types.h>
#include <pcl/segmentation/min_cut_segmentation.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/features/don.h>
#include <pcl/segmentation/supervoxel_clustering.h>
#include <pcl/segmentation/extract_clusters.h>
#include <pcl/segmentation/impl/extract_clusters.hpp>
#include <pcl/segmentation/progressive_morphological_filter.h>
#include <pcl/segmentation/conditional_euclidean_clustering.h>
#include <pcl/visualization/point_cloud_color_handlers.h>
#include <vtkAutoInit.h>
VTK_MODULE_INIT(vtkRenderingOpenGL)

PCLSegmentation::PCLSegmentation(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PCLSegmentation)
{
    ui->setupUi(this);
    connect(ui->PSLoadBUT,SIGNAL(clicked(bool)),this,SLOT(loadScene()));
    connect(ui->PSDoBUT,SIGNAL(clicked(bool)),this,SLOT(PlanSegmetion()));

    connect(ui->SNLoadBUT,SIGNAL(clicked(bool)),this,SLOT(loadScene2()));
    connect(ui->SNPTBUT,SIGNAL(clicked(bool)),this,SLOT(PassThrough()));
    connect(ui->SNNBUT,SIGNAL(clicked(bool)),this,SLOT(ComputerNormal()));
    connect(ui->SNPBUT,SIGNAL(clicked(bool)),this,SLOT(SegmetionPlan()));
    connect(ui->SNCBUT,SIGNAL(clicked(bool)),this,SLOT(SegmetionCylinder()));

    connect(ui->JLRGLoadBUT,SIGNAL(clicked(bool)),this,SLOT(loadScene3()));
    connect(ui->JLRGDoBUT,SIGNAL(clicked(bool)),this,SLOT(RegionGrowingSegmetion()));

    connect(ui->GCLoadBUT,SIGNAL(clicked(bool)),this,SLOT(loadScene4()));
    connect(ui->GCDoBUT,SIGNAL(clicked(bool)),this,SLOT(MinCutSegmentation()));

    connect(ui->DONLoadBUT,SIGNAL(clicked(bool)),this,SLOT(loadScene5()));
    connect(ui->DONDoBUT,SIGNAL(clicked(bool)),this,SLOT(DONSegmentation()));

    connect(ui->VCCSLoadBUT,SIGNAL(clicked(bool)),this,SLOT(loadScene6()));
    connect(ui->VCCSDoBUT,SIGNAL(clicked(bool)),this,SLOT(SupervoxelClustering()));

    connect(ui->XTXLoadBUT,SIGNAL(clicked(bool)),this,SLOT(loadScene7()));
    connect(ui->XTXDoBUT,SIGNAL(clicked(bool)),this,SLOT(ProgressiveMorphologicalFilter()));

    connect(ui->CECLoadBUT,SIGNAL(clicked(bool)),this,SLOT(loadScene8()));
    connect(ui->CECDoBUT,SIGNAL(clicked(bool)),this,SLOT(ConditionalEuclideanClustering()));

    m_pclSceneViewer = new pcl::visualization::PCLVisualizer("viewer2",false);
    m_scenePointCloud.reset(new pcl::PointCloud<PointT>);
    m_pclSceneViewer->addPointCloud(m_scenePointCloud,"cloud2");
    ui->qvtkWidget->SetRenderWindow(m_pclSceneViewer->getRenderWindow());
    m_pclSceneViewer->setupInteractor(ui->qvtkWidget->GetInteractor(),ui->qvtkWidget->GetRenderWindow());
    ui->qvtkWidget->update();


    m_pclSceneViewer2 = new pcl::visualization::PCLVisualizer("viewer2",false);
    m_scenePointCloud.reset(new pcl::PointCloud<PointT>);
    m_pclSceneViewer2->addPointCloud(m_scenePointCloud,"cloud2");
    ui->qvtkWidget_2->SetRenderWindow(m_pclSceneViewer2->getRenderWindow());
    m_pclSceneViewer2->setupInteractor(ui->qvtkWidget_2->GetInteractor(),ui->qvtkWidget_2->GetRenderWindow());
    ui->qvtkWidget_2->update();

    m_pclSceneViewer3 = new pcl::visualization::PCLVisualizer("viewer2",false);
    m_scenePointCloud.reset(new pcl::PointCloud<PointT>);
    m_pclSceneViewer3->addPointCloud(m_scenePointCloud,"cloud2");
    ui->qvtkWidget_3->SetRenderWindow(m_pclSceneViewer3->getRenderWindow());
    m_pclSceneViewer3->setupInteractor(ui->qvtkWidget_3->GetInteractor(),ui->qvtkWidget_3->GetRenderWindow());
    ui->qvtkWidget_3->update();

    m_pclSceneViewer4 = new pcl::visualization::PCLVisualizer("viewer2",false);
    m_scenePointCloud.reset(new pcl::PointCloud<PointT>);
    m_pclSceneViewer4->addPointCloud(m_scenePointCloud,"cloud2");
    ui->qvtkWidget_4->SetRenderWindow(m_pclSceneViewer4->getRenderWindow());
    m_pclSceneViewer4->setupInteractor(ui->qvtkWidget_4->GetInteractor(),ui->qvtkWidget_4->GetRenderWindow());
    ui->qvtkWidget_4->update();

    m_pclSceneViewer5 = new pcl::visualization::PCLVisualizer("viewer2",false);
    m_scenePointCloud.reset(new pcl::PointCloud<PointT>);
    m_pclSceneViewer5->addPointCloud(m_scenePointCloud,"cloud2");
    ui->qvtkWidget_5->SetRenderWindow(m_pclSceneViewer5->getRenderWindow());
    m_pclSceneViewer5->setupInteractor(ui->qvtkWidget_5->GetInteractor(),ui->qvtkWidget_5->GetRenderWindow());
    ui->qvtkWidget_5->update();

    m_pclSceneViewer6 = new pcl::visualization::PCLVisualizer("viewer2",false);
    m_scenePointCloud.reset(new pcl::PointCloud<PointT>);
    m_pclSceneViewer6->addPointCloud(m_scenePointCloud,"cloud2");
    ui->qvtkWidget_6->SetRenderWindow(m_pclSceneViewer6->getRenderWindow());
    m_pclSceneViewer6->setupInteractor(ui->qvtkWidget_6->GetInteractor(),ui->qvtkWidget_6->GetRenderWindow());
    ui->qvtkWidget_6->update();

    m_pclSceneViewer7 = new pcl::visualization::PCLVisualizer("viewer2",false);
    m_scenePointCloud.reset(new pcl::PointCloud<PointT>);
    m_pclSceneViewer7->addPointCloud(m_scenePointCloud,"cloud2");
    ui->qvtkWidget_7->SetRenderWindow(m_pclSceneViewer7->getRenderWindow());
    m_pclSceneViewer7->setupInteractor(ui->qvtkWidget_7->GetInteractor(),ui->qvtkWidget_7->GetRenderWindow());
    ui->qvtkWidget_7->update();

    m_pclSceneViewer8 = new pcl::visualization::PCLVisualizer("viewer2",false);
    m_scenePointCloud.reset(new pcl::PointCloud<PointT>);
    m_pclSceneViewer8->addPointCloud(m_scenePointCloud,"cloud2");
    ui->qvtkWidget_8->SetRenderWindow(m_pclSceneViewer8->getRenderWindow());
    m_pclSceneViewer8->setupInteractor(ui->qvtkWidget_8->GetInteractor(),ui->qvtkWidget_8->GetRenderWindow());
    ui->qvtkWidget_8->update();
}

PCLSegmentation::~PCLSegmentation()
{
    delete ui;
}

void PCLSegmentation::showScene()
{
    if(m_scenePointCloud->points.size() == 0){
        return;
    }
    m_pclSceneViewer->removeAllPointClouds();
    m_pclSceneViewer->addPointCloud(m_scenePointCloud,"cloud2");
    m_pclSceneViewer->resetCamera();
    ui->qvtkWidget->update();
}

void PCLSegmentation::showScene2()
{
    if(m_scenePointCloud->points.size() == 0){
        return;
    }
    m_pclSceneViewer2->removeAllPointClouds();
    m_pclSceneViewer2->addPointCloud(m_scenePointCloud,"cloud2");
    m_pclSceneViewer2->resetCamera();
    ui->qvtkWidget_2->update();
}
void PCLSegmentation::showScene3()
{
    if(m_scenePointCloud->points.size() == 0){
        return;
    }
    m_pclSceneViewer3->removeAllPointClouds();
    m_pclSceneViewer3->addPointCloud(m_scenePointCloud,"cloud2");
    m_pclSceneViewer3->resetCamera();
    ui->qvtkWidget_3->update();
}
void PCLSegmentation::showScene4()
{
    if(m_scenePointCloud->points.size() == 0){
        return;
    }
    m_pclSceneViewer4->removeAllPointClouds();
    m_pclSceneViewer4->addPointCloud(m_scenePointCloud,"cloud2");
    m_pclSceneViewer4->resetCamera();
    ui->qvtkWidget_4->update();
}
void PCLSegmentation::showScene5()
{
    if(m_scenePointCloud->points.size() == 0){
        return;
    }
    m_pclSceneViewer5->removeAllPointClouds();
    m_pclSceneViewer5->addPointCloud(m_scenePointCloud,"cloud2");
    m_pclSceneViewer5->resetCamera();
    ui->qvtkWidget_5->update();
}
void PCLSegmentation::showScene6()
{
    if(m_scenePointCloud->points.size() == 0){
        return;
    }
    m_pclSceneViewer6->removeAllPointClouds();
    m_pclSceneViewer6->addPointCloud(m_scenePointCloud,"cloud2");
    m_pclSceneViewer6->resetCamera();
    ui->qvtkWidget_6->update();
}
void PCLSegmentation::showScene7()
{
    if(m_scenePointCloud->points.size() == 0){
        return;
    }
    m_pclSceneViewer7->removeAllPointClouds();
    m_pclSceneViewer7->addPointCloud(m_scenePointCloud,"cloud2");
    m_pclSceneViewer7->resetCamera();
    ui->qvtkWidget_7->update();
}
void PCLSegmentation::showScene8()
{
    if(m_scenePointCloud->points.size() == 0){
        return;
    }
    m_pclSceneViewer8->removeAllPointClouds();
    m_pclSceneViewer8->addPointCloud(m_scenePointCloud,"cloud2");
    m_pclSceneViewer8->resetCamera();
    ui->qvtkWidget_8->update();
}
void PCLSegmentation::loadScene()
{
    QString pcdFile = QFileDialog::getOpenFileName(this,"Pcd",QApplication::applicationDirPath(),"*.pcd");
    if(pcdFile.isEmpty()){
        return;
    }
    m_isSceneReady = false;
    qDebug() << "pcdFile : " << pcdFile;
    pcl::PCDReader reader;
    reader.read(pcdFile.toStdString(), *m_scenePointCloud);
    m_sceneFCloud.setInputCloud(m_scenePointCloud);
    showScene();
}

void PCLSegmentation::loadScene2()
{
    QString pcdFile = QFileDialog::getOpenFileName(this,"Pcd",QApplication::applicationDirPath(),"*.pcd");
    if(pcdFile.isEmpty()){
        return;
    }
    m_isSceneReady = false;
    qDebug() << "pcdFile : " << pcdFile;
    pcl::PCDReader reader;
    reader.read(pcdFile.toStdString(), *m_scenePointCloud);
    m_sceneFCloud.setInputCloud(m_scenePointCloud);
    showScene2();
}
void PCLSegmentation::loadScene3()
{
    time_t start,end,diff[5],option;
    start = time(0);

    QString pcdFile = QFileDialog::getOpenFileName(this,"Pcd",QApplication::applicationDirPath(),"*.pcd");
    if(pcdFile.isEmpty()){
        return;
    }
    m_isSceneReady = false;
    qDebug() << "pcdFile : " << pcdFile;
    pcl::PCDReader reader;
    reader.read(pcdFile.toStdString(), *m_scenePointCloud);
    m_sceneFCloud.setInputCloud(m_scenePointCloud);
    showScene3();
    end = time(0);
    diff[0] = difftime (end, start);
    qDebug() <<"\Loading pcd file takes(seconds): %d\n"<< diff[0];
}

void PCLSegmentation::loadScene4()
{
    time_t start,end,diff[5],option;
    start = time(0);

    QString pcdFile = QFileDialog::getOpenFileName(this,"Pcd",QApplication::applicationDirPath(),"*.pcd");
    if(pcdFile.isEmpty()){
        return;
    }
    m_isSceneReady = false;
    qDebug() << "pcdFile : " << pcdFile;
    pcl::PCDReader reader;
    reader.read(pcdFile.toStdString(), *m_scenePointCloud);
    m_sceneFCloud.setInputCloud(m_scenePointCloud);
    showScene4();
    end = time(0);
    diff[0] = difftime (end, start);
    qDebug() <<"\Loading pcd file takes(seconds): %d\n"<< diff[0];
}
void PCLSegmentation::loadScene5()
{
    time_t start,end,diff[5],option;
    start = time(0);

    QString pcdFile = QFileDialog::getOpenFileName(this,"Pcd",QApplication::applicationDirPath(),"*.pcd");
    if(pcdFile.isEmpty()){
        return;
    }
    m_isSceneReady = false;
    qDebug() << "pcdFile : " << pcdFile;
    pcl::PCDReader reader;
    reader.read(pcdFile.toStdString(), *m_scenePointCloud);
    m_sceneFCloud.setInputCloud(m_scenePointCloud);
    showScene5();
    end = time(0);
    diff[0] = difftime (end, start);
    qDebug() <<"\Loading pcd file takes(seconds): %d\n"<< diff[0];
}
void PCLSegmentation::loadScene6()
{
    time_t start,end,diff[5],option;
    start = time(0);

    QString pcdFile = QFileDialog::getOpenFileName(this,"Pcd",QApplication::applicationDirPath(),"*.pcd");
    if(pcdFile.isEmpty()){
        return;
    }
    m_isSceneReady = false;
    qDebug() << "pcdFile : " << pcdFile;
    pcl::PCDReader reader;
    reader.read(pcdFile.toStdString(), *m_scenePointCloud);
    m_sceneFCloud.setInputCloud(m_scenePointCloud);
    showScene6();
    end = time(0);
    diff[0] = difftime (end, start);
    qDebug() <<"\Loading pcd file takes(seconds): %d\n"<< diff[0];
}

void PCLSegmentation::loadScene7()
{
    time_t start,end,diff[5],option;
    start = time(0);

    QString pcdFile = QFileDialog::getOpenFileName(this,"Pcd",QApplication::applicationDirPath(),"*.pcd");
    if(pcdFile.isEmpty()){
        return;
    }
    m_isSceneReady = false;
    qDebug() << "pcdFile : " << pcdFile;
    pcl::PCDReader reader;
    reader.read(pcdFile.toStdString(), *m_scenePointCloud);
    m_sceneFCloud.setInputCloud(m_scenePointCloud);
    showScene7();
    end = time(0);
    diff[0] = difftime (end, start);
    qDebug() <<"\Loading pcd file takes(seconds): %d\n"<< diff[0];
}
void PCLSegmentation::loadScene8()
{
    time_t start,end,diff[5],option;
    start = time(0);

    QString pcdFile = QFileDialog::getOpenFileName(this,"Pcd",QApplication::applicationDirPath(),"*.pcd");
    if(pcdFile.isEmpty()){
        return;
    }
    m_isSceneReady = false;
    qDebug() << "pcdFile : " << pcdFile;
    pcl::PCDReader reader;
    reader.read(pcdFile.toStdString(), *m_scenePointCloud);
    m_sceneFCloud.setInputCloud(m_scenePointCloud);
    showScene8();
    end = time(0);
    diff[0] = difftime (end, start);
    qDebug() <<"\Loading pcd file takes(seconds): %d\n"<< diff[0];
}
void PCLSegmentation::PlanSegmetion()
{
    pcl::ModelCoefficients::Ptr coefficients (new pcl::ModelCoefficients);
    pcl::PointIndices::Ptr inliers (new pcl::PointIndices);
    //创建分割对象
      pcl::SACSegmentation<pcl::PointXYZ> seg;
     //可选设置
      seg.setOptimizeCoefficients (true);
    //必须设置
      seg.setModelType (pcl::SACMODEL_PLANE);
      seg.setMethodType (pcl::SAC_RANSAC);
      seg.setMaxIterations (ui->SMIBox->value());
      seg.setDistanceThreshold (ui->SDTBox->value());
      seg.setInputCloud (m_scenePointCloud);
      seg.segment (*inliers, *coefficients);
      //得到的是两个点集，将点集存储为点云并且可视化
    pcl::ExtractIndices<PointT> extract;
    // Extract the planar inliers from the input cloud
    extract.setInputCloud (m_scenePointCloud);
    extract.setIndices (inliers);
    extract.setNegative (false);
    // Write the planar inliers to disk
    pcl::PointCloud<PointT>::Ptr cloud_inliers (new pcl::PointCloud<PointT> ());
    extract.filter (*cloud_inliers);
    showScene();
    m_pclSceneViewer->removeAllPointClouds();
    m_pclSceneViewer->addPointCloud(cloud_inliers,"icpPoint");
    m_pclSceneViewer->resetCamera();
    ui->qvtkWidget->update();
}

void PCLSegmentation::PassThrough()
{
    // 创建滤波器对象
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered (new pcl::PointCloud<pcl::PointXYZ>);
    pcl::PassThrough<pcl::PointXYZ> pass;
    pass.setInputCloud (m_scenePointCloud);
    pass.setFilterFieldName ("z");
   float lowerlimit = static_cast<float>(ui->LLBox->value());
   float upperlimit = static_cast<float>(ui->ULBox->value());
    pass.setFilterLimits (lowerlimit, upperlimit);
   // pass.setFilterLimitsNegative (true); //true 表示过滤掉0-10的点
    pass.filter (*cloud_filtered);
    showScene2();
    m_pclSceneViewer2->removeAllPointClouds();
    m_pclSceneViewer2->addPointCloud(cloud_filtered,"icpPoint");
    m_pclSceneViewer2->resetCamera();
    ui->qvtkWidget_2->update();
}
void PCLSegmentation::ComputerNormal()
{
    // 创建滤波器对象
    // Estimate point normals
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered (new pcl::PointCloud<pcl::PointXYZ>);
    pcl::PassThrough<pcl::PointXYZ> pass;
    pcl::search::KdTree<PointT>::Ptr tree (new pcl::search::KdTree<PointT> ());

    pass.setInputCloud (m_scenePointCloud);
    pass.setFilterFieldName ("z");
   float lowerlimit = static_cast<float>(ui->LLBox->value());
   float upperlimit = static_cast<float>(ui->ULBox->value());
    pass.setFilterLimits (lowerlimit, upperlimit);
   // pass.setFilterLimitsNegative (true); //true 表示过滤掉0-10的点
    pass.filter (*cloud_filtered);
    pcl::NormalEstimation<PointT, pcl::Normal> ne;
    pcl::PointCloud<pcl::Normal>::Ptr cloud_normals (new pcl::PointCloud<pcl::Normal>);
    ne.setSearchMethod (tree);
    ne.setInputCloud (cloud_filtered);
    ne.setKSearch (ui->KSBox->value());
    ne.compute (*cloud_normals);
    QMessageBox::information(this,"Info","Success");
}


void PCLSegmentation::SegmetionPlan()
{
    pcl::ModelCoefficients::Ptr coefficients_plane (new pcl::ModelCoefficients), coefficients_cylinder (new pcl::ModelCoefficients);
    pcl::PointIndices::Ptr inliers_plane (new pcl::PointIndices), inliers_cylinder (new pcl::PointIndices);
    //创建分割对象
      pcl::SACSegmentationFromNormals<PointT, pcl::Normal> seg;
      pcl::ExtractIndices<pcl::Normal> extract_normals;
      pcl::search::KdTree<PointT>::Ptr tree (new pcl::search::KdTree<PointT> ());

      pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered (new pcl::PointCloud<pcl::PointXYZ>);
      pcl::PassThrough<pcl::PointXYZ> pass;
      pass.setInputCloud (m_scenePointCloud);
      pass.setFilterFieldName ("z");
     float lowerlimit = static_cast<float>(ui->LLBox->value());
     float upperlimit = static_cast<float>(ui->ULBox->value());
      pass.setFilterLimits (lowerlimit, upperlimit);
     // pass.setFilterLimitsNegative (true); //true 表示过滤掉0-10的点
      pass.filter (*cloud_filtered);
      pcl::NormalEstimation<PointT, pcl::Normal> ne;
      pcl::PointCloud<pcl::Normal>::Ptr cloud_normals (new pcl::PointCloud<pcl::Normal>);
      ne.setSearchMethod (tree);
      ne.setInputCloud (cloud_filtered);
      ne.setKSearch (ui->KSBox->value());
      ne.compute (*cloud_normals);

     //可选设置
      seg.setOptimizeCoefficients (true);
    //必须设置
      seg.setModelType (pcl::SACMODEL_PLANE);
      seg.setMethodType (pcl::SAC_RANSAC);
      seg.setNormalDistanceWeight (ui->SNNWBox->value());
      seg.setMaxIterations (ui->SNMIBox->value());
      seg.setDistanceThreshold (ui->SNDTBox->value());
      seg.setInputCloud (cloud_filtered);
      seg.setInputNormals (cloud_normals);
      seg.segment (*inliers_plane, *coefficients_plane);
      //得到的是两个点集，将点集存储为点云并且可视化
    pcl::ExtractIndices<PointT> extract;
    // Extract the planar inliers from the input cloud
    extract.setInputCloud (cloud_filtered);
    extract.setIndices (inliers_plane);
    extract.setNegative (false);
    // Write the planar inliers to disk
    pcl::PointCloud<PointT>::Ptr cloud_inliers (new pcl::PointCloud<PointT> ());
    extract.filter (*cloud_inliers);
    showScene2();
    m_pclSceneViewer2->removeAllPointClouds();
    m_pclSceneViewer2->addPointCloud(cloud_inliers,"icpPoint");
    m_pclSceneViewer2->resetCamera();
    ui->qvtkWidget_2->update();
}
void PCLSegmentation::SegmetionCylinder()
{
    pcl::ModelCoefficients::Ptr coefficients_plane (new pcl::ModelCoefficients), coefficients_cylinder (new pcl::ModelCoefficients);
    pcl::PointIndices::Ptr inliers_plane (new pcl::PointIndices), inliers_cylinder (new pcl::PointIndices);
    //创建分割对象
    pcl::SACSegmentationFromNormals<PointT, pcl::Normal> seg;
    pcl::ExtractIndices<pcl::Normal> extract_normals;
    pcl::search::KdTree<PointT>::Ptr tree (new pcl::search::KdTree<PointT> ());
      pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered (new pcl::PointCloud<pcl::PointXYZ>);
      pcl::NormalEstimation<PointT, pcl::Normal> ne;
      pcl::PointCloud<pcl::Normal>::Ptr cloud_normals (new pcl::PointCloud<pcl::Normal>);
      pcl::PointCloud<PointT>::Ptr cloud_filtered2 (new pcl::PointCloud<PointT>);
      pcl::PointCloud<pcl::Normal>::Ptr cloud_normals2 (new pcl::PointCloud<pcl::Normal>);
      pcl::PassThrough<pcl::PointXYZ> pass;
      pass.setInputCloud (m_scenePointCloud);
      pass.setFilterFieldName ("z");
     float lowerlimit = static_cast<float>(ui->LLBox->value());
     float upperlimit = static_cast<float>(ui->ULBox->value());
      pass.setFilterLimits (lowerlimit, upperlimit);
     // pass.setFilterLimitsNegative (true); //true 表示过滤掉0-10的点
      pass.filter (*cloud_filtered);
      ne.setSearchMethod (tree);
      ne.setInputCloud (cloud_filtered);
      ne.setKSearch (ui->KSBox->value());
      ne.compute (*cloud_normals);
     //可选设置
      seg.setOptimizeCoefficients (true);
    //必须设置
      seg.setModelType (pcl::SACMODEL_PLANE);
      seg.setMethodType (pcl::SAC_RANSAC);
      seg.setNormalDistanceWeight (ui->SNNWBox->value());
      seg.setMaxIterations (ui->SNMIBox->value());
      seg.setDistanceThreshold (ui->SNDTBox->value());
      seg.setInputCloud (cloud_filtered);
      seg.setInputNormals (cloud_normals);
      seg.segment (*inliers_plane, *coefficients_plane);
      //得到的是两个点集，将点集存储为点云并且可视化
    pcl::ExtractIndices<PointT> extract;
    // Extract the planar inliers from the input cloud
    extract.setInputCloud (cloud_filtered);
    extract.setIndices (inliers_plane);
    extract.setNegative (false);
    // Write the planar inliers to disk
    pcl::PointCloud<PointT>::Ptr cloud_inliers (new pcl::PointCloud<PointT> ());
    extract.filter (*cloud_inliers);

    extract.setNegative (true);
    extract.filter (*cloud_filtered2);
    extract_normals.setNegative (true);
    extract_normals.setInputCloud (cloud_normals);
    extract_normals.setIndices (inliers_plane);
    extract_normals.filter (*cloud_normals2);
    seg.setOptimizeCoefficients (true);
    seg.setModelType (pcl::SACMODEL_CYLINDER);
    seg.setMethodType (pcl::SAC_RANSAC);
    seg.setNormalDistanceWeight (0.1);
    seg.setMaxIterations (10000);
    seg.setDistanceThreshold (0.05);
    seg.setRadiusLimits (0, 0.1);
    seg.setInputCloud (cloud_filtered2);
    seg.setInputNormals (cloud_normals2);
    seg.segment (*inliers_cylinder, *coefficients_cylinder);
    extract.setInputCloud (cloud_filtered2);
    extract.setIndices (inliers_cylinder);
    extract.setNegative (false);
    pcl::PointCloud<PointT>::Ptr cloud_cylinder (new pcl::PointCloud<PointT> ());
    extract.filter (*cloud_cylinder);

    showScene2();
    m_pclSceneViewer2->removeAllPointClouds();
    m_pclSceneViewer2->addPointCloud(cloud_cylinder,"icpPoint");
    m_pclSceneViewer2->resetCamera();
    ui->qvtkWidget_2->update();
}

void PCLSegmentation::RegionGrowingSegmetion()
{
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);

    bool Bool_Cuting=false;//设置默认输入参数
    pcl::search::Search<pcl::PointXYZ>::Ptr tree = boost::shared_ptr<pcl::search::Search<pcl::PointXYZ> > (new pcl::search::KdTree<pcl::PointXYZ>);//创建一个指向kd树搜索对象的共享指针
    pcl::PointCloud <pcl::Normal>::Ptr normals (new pcl::PointCloud <pcl::Normal>);
    pcl::NormalEstimation<pcl::PointXYZ, pcl::Normal> normal_estimator;//创建法线估计对象
    normal_estimator.setSearchMethod (tree);//设置搜索方法
    normal_estimator.setInputCloud (m_scenePointCloud);//设置法线估计对象输入点集
    normal_estimator.setKSearch (ui->JLRGKSBox->value());// 设置用于法向量估计的k近邻数目
    normal_estimator.compute (*normals);//计算并输出法向量
    pcl::IndicesPtr indices (new std::vector <int>);//创建一组索引
    if(Bool_Cuting)//判断是否需要直通滤波
    {

        pcl::PassThrough<pcl::PointXYZ> pass;//设置直通滤波器对象
        pass.setInputCloud (m_scenePointCloud);//设置输入点云
        pass.setFilterFieldName ("z");//设置指定过滤的维度
        float lowerlimit = static_cast<float>(ui->JLRGLLBox->value());
        float upperlimit = static_cast<float>(ui->JLRGRLBox->value());
        pass.setFilterLimits (lowerlimit, upperlimit);//设置指定纬度过滤的范围
        pass.filter (*indices);//执行滤波，保存滤波结果在上述索引中
    }
    // 区域生长算法的5个参数
    pcl::RegionGrowing<pcl::PointXYZ, pcl::Normal> reg;//创建区域生长分割对象
    reg.setMinClusterSize (ui->JLRGMinCBox->value());//设置一个聚类需要的最小点数
    reg.setMaxClusterSize (ui->JLRGMaxCBox->value());//设置一个聚类需要的最大点数
    reg.setSearchMethod (tree);//设置搜索方法
    reg.setNumberOfNeighbours (ui->JLRGNNBox->value());//设置搜索的临近点数目
    reg.setInputCloud (m_scenePointCloud);//设置输入点云
    if(Bool_Cuting)reg.setIndices (indices);//通过输入参数设置，确定是否输入点云索引
    reg.setInputNormals (normals);//设置输入点云的法向量
     float ST = static_cast<float>(ui->JLRGSTBox->value());
    reg.setSmoothnessThreshold (ST / 180.0 * M_PI);//设置平滑阈值
    reg.setCurvatureThreshold (ui->JLRGCTBox->value());//设置曲率阈值

    std::vector <pcl::PointIndices> clusters;
    reg.extract (clusters);//获取聚类的结果，分割结果保存在点云索引的向量中。
    pcl::PointCloud <pcl::PointXYZRGB>::Ptr colored_cloud = reg.getColoredCloud ();

    showScene3();
    m_pclSceneViewer3->removeAllPointClouds();
    m_pclSceneViewer3->addPointCloud(colored_cloud,"icpPoint");
    m_pclSceneViewer3->resetCamera();
    ui->qvtkWidget_3->update();
}


void PCLSegmentation::MinCutSegmentation()
{
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);

    bool Bool_Cuting=false;//设置默认输入参数
    pcl::IndicesPtr indices (new std::vector <int>);//创建一组索引
    pcl::PointCloud<pcl::PointXYZ>::Ptr foreground_points(new pcl::PointCloud<pcl::PointXYZ> ());//创建一个PointCloud <pcl::PointXYZRGB>共享指针并进行实例化
    if(Bool_Cuting)//判断是否需要直通滤波
    {

        pcl::PassThrough<pcl::PointXYZ> pass;//设置直通滤波器对象
        pass.setInputCloud (m_scenePointCloud);//设置输入点云
        pass.setFilterFieldName ("z");//设置指定过滤的维度
        float lowerlimit = static_cast<float>(ui->GCLLBox->value());
        float upperlimit = static_cast<float>(ui->GCRLBox->value());
        pass.setFilterLimits (lowerlimit, upperlimit);//设置指定纬度过滤的范围
        pass.filter (*indices);//执行滤波，保存滤波结果在上述索引中
    }

    pcl::MinCutSegmentation<pcl::PointXYZ> seg;//创建一个PointXYZRGB类型的区域生长分割对象
    seg.setInputCloud (m_scenePointCloud);//设置输入点云
    if(Bool_Cuting)seg.setIndices (indices);//设置输入点云的索引

    pcl::PointXYZ point;//定义中心点并赋值
    float C_x = static_cast<float>(ui->C_xBox->value());
    float C_y = static_cast<float>(ui->C_yBox->value());
    float C_z = static_cast<float>(ui->C_zBox->value());

    point.x = C_x;
    point.y = C_y;
    point.z = C_z;
    foreground_points->points.push_back(point);
    seg.setForegroundPoints (foreground_points);//输入前景点云（目标物体）的中心点
    seg.setSigma (ui->SigmaBox->value());//设置平滑成本的Sigma值
    seg.setRadius (ui->RadiusBox->value());//设置背景惩罚权重的半径
    seg.setNumberOfNeighbours (ui->GCNNBox->value());//设置临近点数目
    seg.setSourceWeight (ui->SWBox->value());//设置前景惩罚权重
    std::vector <pcl::PointIndices> clusters;
    seg.extract (clusters);//获取分割的结果，分割结果保存在点云索引的向量中。

    pcl::PointCloud <pcl::PointXYZRGB>::Ptr colored_cloud = seg.getColoredCloud ();

    showScene4();
    m_pclSceneViewer4->removeAllPointClouds();
    m_pclSceneViewer4->addPointCloud(colored_cloud,"icpPoint");
    m_pclSceneViewer4->resetCamera();
    ui->qvtkWidget_4->update();
}

void PCLSegmentation::DONSegmentation()  // 有问题 暂时注释掉
{
//    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);
//    pcl::search::Search<PointXYZRGB>::Ptr tree;

//    if (m_scenePointCloud->isOrganized ())
//    {
//      tree.reset (new pcl::search::OrganizedNeighbor<PointXYZRGB> ());
//    }
//    else
//    {
//      tree.reset (new pcl::search::KdTree<PointXYZRGB> (false));
//    }
//    // Set the input pointcloud for the search tree
//    tree->setInputCloud (m_scenePointCloud);

//    float scale1 = static_cast<float>(ui->RSLBox->value());
//    float scale2 = static_cast<float>(ui->RSUBox->value());
//    float threshold = static_cast<float>(ui->ThresholdBox->value());
//    float segradius = static_cast<float>(ui->SegradiusBox->value());
//  double mean_radius;
//    //caculate the mean radius of cloud and mutilply with corresponding input 计算云的平均半径，并与相应的输入残差
//     {
//         int size_cloud=cloud->size();
//         int step=size_cloud/10;
//         double total_distance=0;
//         int i,j=1;
//         for(i=0;i<size_cloud;i+=step,j++)
//         {
//             std::vector<int> pointIdxNKNSearch(2);
//             std::vector<float> pointNKNSquaredDistance(2);
//             tree->nearestKSearch(m_scenePointCloud->points[i],2,pointIdxNKNSearch,pointNKNSquaredDistance);
//             total_distance+=pointNKNSquaredDistance[1]+pointNKNSquaredDistance[0];
//         }
//         mean_radius=sqrt((total_distance/j));
//         cout<<"mean radius of cloud is： "<<mean_radius<<endl;
//         scale1*=mean_radius;
//         scale2*=mean_radius;
//         segradius*=mean_radius;
//     }
//    if (scale1 >= scale2)
//     {
//       cerr << "Error: Large scale must be > small scale!" << endl;
//       exit (EXIT_FAILURE);
//     }
//     // Compute normals using both small and large scales at each point
//     pcl::NormalEstimationOMP<PointXYZRGB, PointNormal> ne;
//     ne.setInputCloud (m_scenePointCloud);
//     ne.setSearchMethod (tree);
//     ne.setViewPoint (std::numeric_limits<float>::max (), std::numeric_limits<float>::max (), std::numeric_limits<float>::max ());   //随机设定一个任意的但固定的视点
//     pcl::PointCloud<PointNormal>::Ptr normals_small_scale (new pcl::PointCloud<PointNormal>);     //小过滤
//     ne.setRadiusSearch (scale1);
//     ne.compute (*normals_small_scale);
//     pcl::PointCloud<PointNormal>::Ptr normals_large_scale (new pcl::PointCloud<PointNormal>);     //大过滤
//     ne.setRadiusSearch (scale2);
//     ne.compute (*normals_large_scale);
//     // Create output cloud for DoN results 创建DON算子，计算其特征向量
//     PointCloud<PointNormal>::Ptr doncloud (new pcl::PointCloud<PointNormal>);
//     copyPointCloud<PointXYZRGB, PointNormal>(*cloud, *doncloud);
//     pcl::DifferenceOfNormalsEstimation<PointXYZRGB, PointNormal, PointNormal> don;
//     don.setInputCloud (cloud);
//     don.setNormalScaleLarge (normals_large_scale);
//     don.setNormalScaleSmall (normals_small_scale);
//     if (!don.initCompute ())
//     {
//       std::cerr << "Error: Could not intialize DoN feature operator" << std::endl;
//       exit (EXIT_FAILURE);
//     }
//     // Compute DoN
//     don.computeFeature (*doncloud);
//     pcl::PCDWriter writer;
//     writer.write<pcl::PointNormal> ("don.pcd", *doncloud, false);
//     // Build the filter
//      pcl::ConditionalRemoval<PointNormal> condrem (range_cond);
//      condrem.setInputCloud (doncloud);
//      pcl::PointCloud<PointNormal>::Ptr doncloud_filtered (new pcl::PointCloud<PointNormal>);
//      // Apply filter
//      condrem.filter (*doncloud_filtered);
//      doncloud = doncloud_filtered;
//     writer.write<pcl::PointNormal> ("don_filtered.pcd", *doncloud, false);
//     pcl::search::KdTree<PointNormal>::Ptr segtree (new pcl::search::KdTree<PointNormal>);
//     segtree->setInputCloud (doncloud);
//     std::vector<pcl::PointIndices> cluster_indices;
//     pcl::EuclideanClusterExtraction<PointNormal> ec;
//     ec.setClusterTolerance (segradius);
//     ec.setMinClusterSize (50);
//     ec.setMaxClusterSize (100000);
//     ec.setSearchMethod (segtree);
//     ec.setInputCloud (doncloud);
//     ec.extract (cluster_indices); //获取分割的结果，分割结果保存在点云索引的向量中。
//    pcl::PointCloud <pcl::PointXYZRGB>::Ptr colored_cloud = seg.getColoredCloud ();
//    showScene5();
//    m_pclSceneViewer5->removeAllPointClouds();
//    m_pclSceneViewer5->addPointCloud(colored_cloud,"icpPoint");
//    m_pclSceneViewer5->resetCamera();
//    ui->qvtkWidget_5->update();
}


//void PCLSegmentation::addSupervoxelConnectionsToViewer (PointT &supervoxel_center,
//    PointCloudT &adjacent_supervoxel_centers,
//    std::string supervoxel_name,
//    boost::shared_ptr<pcl::visualization::PCLVisualizer> & viewer)
//{

//    int i=0;
//    //Iterate through all adjacent points, and add a center point to adjacent point pair
//    PointCloudT::iterator adjacent_itr = adjacent_supervoxel_centers.begin ();
//    for ( ; adjacent_itr != adjacent_supervoxel_centers.end (); ++adjacent_itr)
//    {
//        std::stringstream ss;
//        ss<<supervoxel_name<<i;
//        viewer->addLine(supervoxel_center,*adjacent_itr,ss.str());

//        viewer->setShapeRenderingProperties(pcl::visualization::PCL_VISUALIZER_LINE_WIDTH,3,ss.str());
//        viewer->setShapeRenderingProperties(pcl::visualization::PCL_VISUALIZER_COLOR,0,255,0,ss.str());
//        ss<<supervoxel_name<<i;
//        viewer->addSphere(supervoxel_center,0.008,0,0,255,ss.str());
//        viewer->setShapeRenderingProperties(pcl::visualization::PCL_VISUALIZER_SHADING,pcl::visualization::PCL_VISUALIZER_SHADING_GOURAUD,ss.str());
//        //viewer->setShapeRenderingProperties(pcl::visualization::PCL_VISUALIZER_OPACITY,0.9,ss.str());
//        i++;
//    }

//}
void PCLSegmentation::SupervoxelClustering()  // 有问题，无法正确载入XYZRGBA 图像，显示问题
{
    // Types
//    typedef pcl::PointXYZRGBA PointT;
//    typedef pcl::PointCloud<PointT> PointCloudT;
//    typedef pcl::PointNormal PointNT;
//    typedef pcl::PointCloud<PointNT> PointNCloudT;
//    typedef pcl::PointXYZL PointLT;
//    typedef pcl::PointCloud<PointLT> PointLCloudT;
//    void addSupervoxelConnectionsToViewer (PointT &supervoxel_center,
//        PointCloudT &adjacent_supervoxel_centers,
//        std::string supervoxel_name,
//        boost::shared_ptr<pcl::visualization::PCLVisualizer> & viewer);
//    PointCloudT::Ptr cloud = boost::make_shared <PointCloudT> ();
//    float voxel_resolution = static_cast<float>(ui->C_xBox->value());
//    float seed_resolution = static_cast<float>(ui->C_xBox->value());
//    float color_importance = static_cast<float>(ui->C_xBox->value());
//    float spatial_importance = static_cast<float>(ui->C_xBox->value());
//    float normal_importance = static_cast<float>(ui->C_xBox->value());
//    pcl::SupervoxelClustering<PointT> super (voxel_resolution, seed_resolution);
//    super.setUseSingleCameraTransform (false);
//    super.setInputCloud (cloud);
//    super.setColorImportance (color_importance);
//    super.setSpatialImportance (spatial_importance);
//    super.setNormalImportance (normal_importance);

//    std::map <uint32_t, pcl::Supervoxel<PointT>::Ptr > supervoxel_clusters;
//    super.extract (supervoxel_clusters);
//    PointLCloudT::Ptr labeled_voxel_cloud = super.getLabeledVoxelCloud ();
//    PointNCloudT::Ptr sv_normal_cloud = super.makeSupervoxelNormalCloud (supervoxel_clusters);
//    std::multimap<uint32_t, uint32_t> supervoxel_adjacency;
//    super.getSupervoxelAdjacency (supervoxel_adjacency);
//    //遍历多重映射容器构造邻接图
//    std::multimap<uint32_t,uint32_t>::iterator label_itr = supervoxel_adjacency.begin ();
//    for ( ; label_itr != supervoxel_adjacency.end (); )
//    {
//        //获取标签值
//        uint32_t supervoxel_label = label_itr->first;
//        //根据标签索引到该超体素
//        pcl::Supervoxel<PointT>::Ptr supervoxel = supervoxel_clusters.at (supervoxel_label);

//        //遍历该超体素相邻超体素并以其相邻超体素中心为点集构造点云，用于后续可视化，这里的相邻超体素在多重映射容器中具有相同的键值
//        PointCloudT adjacent_supervoxel_centers;
//        std::multimap<uint32_t,uint32_t>::iterator adjacent_itr = supervoxel_adjacency.equal_range (supervoxel_label).first;
//        for ( ; adjacent_itr!=supervoxel_adjacency.equal_range (supervoxel_label).second; ++adjacent_itr)
//        {
//            pcl::Supervoxel<PointT>::Ptr neighbor_supervoxel = supervoxel_clusters.at (adjacent_itr->second);
//            adjacent_supervoxel_centers.push_back (neighbor_supervoxel->centroid_);
//        }
//        //
//        std::stringstream ss;
//        label_itr = supervoxel_adjacency.upper_bound (supervoxel_label);
//    }
//    showScene6();
//    m_pclSceneViewer6->removeAllPointClouds();
//    m_pclSceneViewer6->addPointCloud(cloud,"icpPoint");
//    m_pclSceneViewer6->resetCamera();
//    ui->qvtkWidget_6->update();
}


void PCLSegmentation::ProgressiveMorphologicalFilter()
{
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered (new pcl::PointCloud<pcl::PointXYZ>),cloud_ground (new pcl::PointCloud<pcl::PointXYZ>);
    pcl::PointIndicesPtr ground (new pcl::PointIndices);
    // Create the filtering object
    pcl::ProgressiveMorphologicalFilter<pcl::PointXYZ> pmf;
    pmf.setInputCloud (m_scenePointCloud);
    pmf.setMaxWindowSize (ui->MWSBox->value());
    pmf.setSlope (ui->SBox->value());
    pmf.setInitialDistance (ui->IDBox->value());
    pmf.setMaxDistance (ui->MAXDBox->value());
    pmf.extract (ground->indices);
    // Create the filtering object
    pcl::ExtractIndices<pcl::PointXYZ> extract;
    extract.setInputCloud (m_scenePointCloud);
    extract.setIndices (ground);
    extract.filter (*cloud_ground);
    extract.setNegative (true);
    extract.filter (*cloud_filtered);
    showScene7();
    m_pclSceneViewer7->removeAllPointClouds();
    m_pclSceneViewer7->addPointCloud(cloud_filtered,"icpPoint");
    m_pclSceneViewer7->resetCamera();
    ui->qvtkWidget_7->update();
}

void PCLSegmentation::ConditionalEuclideanClustering() //有问题，无法正确载入XYZRGBA 图像，显示问题
{
//    typedef pcl::PointXYZI PointTypeIO;
//    typedef pcl::PointXYZINormal PointTypeFull;
//    typedef pcl::visualization::PointCloudColorHandler<pcl::PCLPointCloud2> ColorHandler;
//    typedef ColorHandler::Ptr ColorHandlerPtr;
//    typedef ColorHandler::ConstPtr ColorHandlerConstPtr;
//    using namespace pcl::console;
//    // Data containers used
//    pcl::PointCloud<PointTypeIO>::Ptr cloud_in (new pcl::PointCloud<PointTypeIO>), cloud_out (new pcl::PointCloud<PointTypeIO>);//创建PointCloud <pcl::PointXYZI>共享指针并进行实例化
//    pcl::PointCloud<PointTypeFull>::Ptr cloud_with_normals (new pcl::PointCloud<PointTypeFull>);//创建PointCloud <pcl::PointXYZINormal>共享指针并进行实例化
//    pcl::IndicesClustersPtr clusters (new pcl::IndicesClusters), small_clusters (new pcl::IndicesClusters), large_clusters (new pcl::IndicesClusters);
//    pcl::search::KdTree<PointTypeIO>::Ptr search_tree (new pcl::search::KdTree<PointTypeIO>);
//    float Leaf=40,Radius=300;
//    int Method=1;
//    pcl::VoxelGrid<PointTypeIO> vg;//设置滤波对象
//    vg.setInputCloud (m_scenePointCloud);//设置需要过滤的点云给滤波对象
//    vg.setLeafSize (Leaf,Leaf,Leaf);//设置滤波时创建的栅格边长
//    vg.setDownsampleAllData (true);//设置所有的数值域需要被下采样
//    vg.filter (*cloud_out);//执行滤波处理，存储输出cloud_out
//    pcl::copyPointCloud (*cloud_out, *cloud_with_normals);//复制点云
//    pcl::NormalEstimation<PointTypeIO, PointTypeFull> ne;//创建法线估计对象
//    ne.setInputCloud (cloud_out);//设置法线估计对象输入点集
//    ne.setSearchMethod (search_tree);//设置搜索方法
//    ne.setRadiusSearch (Radius);// 设置搜索半径
//    ne.compute (*cloud_with_normals);//计算并输出法向量
//    pcl::ConditionalEuclideanClustering<PointTypeFull> cec (true);//创建条件聚类分割对象，并进行初始化。
//    cec.setInputCloud (cloud_with_normals);//设置输入点集
////    cec.setConditionFunction (TRUE);
//    cec.setClusterTolerance (500.0);//设置聚类参考点的搜索距离
//    cec.setMinClusterSize (cloud_with_normals->points.size () / 1000);//设置过小聚类的标准
//    cec.setMaxClusterSize (cloud_with_normals->points.size () / 5);//设置过大聚类的标准
//    cec.segment (*clusters);//获取聚类的结果，分割结果保存在点云索引的向量中
////	cec.getRemovedClusters (small_clusters, large_clusters);//获取无效尺寸的聚类

//    pcl::PointCloud <pcl::PointXYZRGB>::Ptr colored_cloud = cec.getColoredCloud ();
//    showScene8();
//    m_pclSceneViewer8->removeAllPointClouds();
//    m_pclSceneViewer8->addPointCloud(colored_cloud,"icpPoint");
//    m_pclSceneViewer8->resetCamera();
//    ui->qvtkWidget_8->update();
}

