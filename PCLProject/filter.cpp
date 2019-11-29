#include "filter.h"
#include "ui_filter.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>
#include <pcl/filters/statistical_outlier_removal.h>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/filters/passthrough.h>
#include <pcl/filters/voxel_grid.h>
#include <pcl/ModelCoefficients.h>
#include <pcl/registration/icp.h>

#include <pcl/sample_consensus/method_types.h>
#include <pcl/sample_consensus/model_types.h>
#include <pcl/segmentation/sac_segmentation.h>

#include <pcl/filters/extract_indices.h>
#include <pcl/filters/conditional_removal.h>
#include <pcl/filters/radius_outlier_removal.h>
#include <pcl/filters/crop_hull.h>
#include <pcl/surface/concave_hull.h>


Filter::Filter(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Filter)
{
    ui->setupUi(this);


    connect(ui->PTLoadBUT,SIGNAL(clicked(bool)),this,SLOT(loadScene()));
    connect(ui->PTDoBUT,SIGNAL(clicked(bool)),this,SLOT(PassThrough()));
    connect(ui->VGLoadBUT,SIGNAL(clicked(bool)),this,SLOT(loadScene2()));
    connect(ui->VGDoBUT,SIGNAL(clicked(bool)),this,SLOT(VoxelGrid()));

    connect(ui->SOLoadBUT,SIGNAL(clicked(bool)),this,SLOT(loadScene3()));
    connect(ui->SODoBUT,SIGNAL(clicked(bool)),this,SLOT(StatisticalOutlierRemoval()));

    connect(ui->MCLoadBUT,SIGNAL(clicked(bool)),this,SLOT(loadScene4()));
    connect(ui->MCDoBUT,SIGNAL(clicked(bool)),this,SLOT(ExtractIndices()));

    connect(ui->CRLoadBUT,SIGNAL(clicked(bool)),this,SLOT(loadScene6()));
    connect(ui->CRDoBUT,SIGNAL(clicked(bool)),this,SLOT(ConditionalRemoval()));

    connect(ui->RORLoadBUT,SIGNAL(clicked(bool)),this,SLOT(loadScene7()));
    connect(ui->RORDoBUT,SIGNAL(clicked(bool)),this,SLOT(RadiusOutlierRemoval()));

    connect(ui->CHLoadBUT,SIGNAL(clicked(bool)),this,SLOT(loadScene8()));
    connect(ui->CHDoBUT,SIGNAL(clicked(bool)),this,SLOT(CropHull()));


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

Filter::~Filter()
{
    delete ui;
}


void Filter::showScene()
{
    if(m_scenePointCloud->points.size() == 0){
        return;
    }

    m_pclSceneViewer->removeAllPointClouds();
    m_pclSceneViewer->addPointCloud(m_scenePointCloud,"cloud2");
    m_pclSceneViewer->resetCamera();
    ui->qvtkWidget->update();

}

void Filter::showScene2()
{
    if(m_scenePointCloud->points.size() == 0){
        return;
    }

    m_pclSceneViewer2->removeAllPointClouds();
    m_pclSceneViewer2->addPointCloud(m_scenePointCloud,"cloud2");
    m_pclSceneViewer2->resetCamera();
    ui->qvtkWidget_2->update();
}
void Filter::showScene3()
{
    if(m_scenePointCloud->points.size() == 0){
        return;
    }

    m_pclSceneViewer3->removeAllPointClouds();
    m_pclSceneViewer3->addPointCloud(m_scenePointCloud,"cloud2");
    m_pclSceneViewer3->resetCamera();
    ui->qvtkWidget_3->update();
}

void Filter::showScene4()
{
    if(m_scenePointCloud->points.size() == 0){
        return;
    }

    m_pclSceneViewer4->removeAllPointClouds();
    m_pclSceneViewer4->addPointCloud(m_scenePointCloud,"cloud2");
    m_pclSceneViewer4->resetCamera();
    ui->qvtkWidget_4->update();
}

void Filter::showScene6()
{
    if(m_scenePointCloud->points.size() == 0){
        return;
    }

    m_pclSceneViewer6->removeAllPointClouds();
    m_pclSceneViewer6->addPointCloud(m_scenePointCloud,"cloud2");
    m_pclSceneViewer6->resetCamera();
    ui->qvtkWidget_6->update();
}

void Filter::showScene7()
{
    if(m_scenePointCloud->points.size() == 0){
        return;
    }

    m_pclSceneViewer7->removeAllPointClouds();
    m_pclSceneViewer7->addPointCloud(m_scenePointCloud,"cloud2");
    m_pclSceneViewer7->resetCamera();
    ui->qvtkWidget_7->update();
}

void Filter::showScene8()
{
    if(m_scenePointCloud->points.size() == 0){
        return;
    }

    m_pclSceneViewer8->removeAllPointClouds();
    m_pclSceneViewer8->addPointCloud(m_scenePointCloud,"cloud2");
    m_pclSceneViewer8->resetCamera();
    ui->qvtkWidget_8->update();
}

void Filter::loadScene()
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
void Filter::loadScene2()
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

void Filter::loadScene3()
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

    showScene3();
}

void Filter::loadScene4()
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

    showScene4();
}

void Filter::loadScene6()
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

    showScene6();
}

void Filter::loadScene7()
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

    showScene7();
}

void Filter::loadScene8()
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

    showScene8();
}

void Filter::PassThrough()
{
    // 创建滤波器对象
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered (new pcl::PointCloud<pcl::PointXYZ>);
    pcl::PassThrough<pcl::PointXYZ> pass;
    pass.setInputCloud (m_scenePointCloud);
    pass.setFilterFieldName ("z");
   float lowerlimit = static_cast<float>(ui->LLBox->value());
   float upperlimit = static_cast<float>(ui->ULBox->value());
    pass.setFilterLimits (lowerlimit, upperlimit);
    pass.setFilterLimitsNegative (true); //true 表示过滤掉0-10的点

//    if ((ui->radioButton->setChecked(true))!=0)
//      {
//          pass.setFilterLimitsNegative (true);
//      }


//   pass.setFilterLimitsNegative (bool (ui->radioButton->setChecked(true)));

    pass.filter (*cloud_filtered);
    showScene();
    m_pclSceneViewer->removeAllPointClouds();
    m_pclSceneViewer->addPointCloud(cloud_filtered,"icpPoint");
    m_pclSceneViewer->resetCamera();
    ui->qvtkWidget->update();
}

void Filter::VoxelGrid()
{
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered2 (new pcl::PointCloud<pcl::PointXYZ>);
    // 创建滤波器对象
    pcl::VoxelGrid<pcl::PointXYZ> vg;
    float leafSize = static_cast<float>(ui->leafSizeSBox->value());
    vg.setInputCloud (m_scenePointCloud);
    vg.setLeafSize(leafSize,leafSize,leafSize);
    vg.filter (*cloud_filtered2);

    showScene2();

    m_pclSceneViewer2->removeAllPointClouds();
    m_pclSceneViewer2->addPointCloud(cloud_filtered2,"icpPoint");
    m_pclSceneViewer2->resetCamera();
    ui->qvtkWidget_2->update();

}

void Filter::StatisticalOutlierRemoval()
{
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered3 (new pcl::PointCloud<pcl::PointXYZ>);
    // 创建滤波器对象
    pcl::StatisticalOutlierRemoval<pcl::PointXYZ> sor;
    sor.setInputCloud (m_scenePointCloud);
    sor.setMeanK (ui->MKBox->value());
    sor.setStddevMulThresh (ui->SMTBox->value());

    sor.filter (*cloud_filtered3);

    showScene3();

    m_pclSceneViewer3->removeAllPointClouds();
    m_pclSceneViewer3->addPointCloud(cloud_filtered3,"icpPoint");
    m_pclSceneViewer3->resetCamera();
    ui->qvtkWidget_3->update();

}

void Filter::ExtractIndices()
{
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered_blob (new pcl::PointCloud<pcl::PointXYZ>);
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_p (new pcl::PointCloud<pcl::PointXYZ>), cloud_f (new pcl::PointCloud<pcl::PointXYZ>);
    // 创建滤波器对象:使用叶大小为1cm的下采样
     pcl::VoxelGrid<pcl::PointXYZ> sor;
     sor.setInputCloud (m_scenePointCloud);
     sor.setLeafSize (1.0f, 1.0f, 1.0f);
     sor.filter (*cloud_filtered_blob);
     pcl::ModelCoefficients::Ptr coefficients (new pcl::ModelCoefficients ());
     pcl::PointIndices::Ptr inliers (new pcl::PointIndices ());
     // 创建分割对象
      pcl::SACSegmentation<pcl::PointXYZ> seg;
      // 可选
      seg.setOptimizeCoefficients (true);
      // 必选
      seg.setModelType (pcl::SACMODEL_PLANE);
      seg.setMethodType (pcl::SAC_RANSAC);

      seg.setMaxIterations (ui->MIBox->value());
      seg.setDistanceThreshold (ui->DTBox->value());
      // 创建滤波器对象
      pcl::ExtractIndices<pcl::PointXYZ> extract;
      int i = 0, nr_points = (int) m_scenePointCloud->points.size ();
      // 当还有30%原始点云数据时
      while (m_scenePointCloud->points.size () > 0.3 * nr_points)
      {
        // 从余下的点云中分割最大平面组成部分
        seg.setInputCloud (cloud_filtered_blob);
        seg.segment (*inliers, *coefficients);
        if (inliers->indices.size () == 0)
        {
//          std::cerr << "Could not estimate a planar model for the given dataset." << std::endl;
          break;
        }
        // 分离内层
        extract.setInputCloud (cloud_filtered_blob);
        extract.setIndices (inliers);
        extract.setNegative (false);
        extract.filter (*cloud_p);
//        std::cerr << "PointCloud representing the planar component: " << cloud_p->width * cloud_p->height << " data points." << std::endl;
//        std::stringstream ss;
//        ss << "table_scene_lms400_plane_" << i << ".pcd";
//        writer.write<pcl::PointXYZ> (ss.str (), *cloud_p, false);
        // 创建滤波器对象
        extract.setNegative (true);
        extract.filter (*cloud_f);
        cloud_filtered_blob.swap (cloud_f);
        i++;
      }
    showScene4();
    m_pclSceneViewer4->removeAllPointClouds();
    m_pclSceneViewer4->addPointCloud(cloud_p,"icpPoint");
    m_pclSceneViewer4->resetCamera();
    ui->qvtkWidget_4->update();
}

void Filter::ConditionalRemoval()
{
    // 创建滤波器对象
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered6 (new pcl::PointCloud<pcl::PointXYZ>);
    // 创建环境
    pcl::ConditionAnd<pcl::PointXYZ>::Ptr range_cond (new pcl::ConditionAnd<pcl::PointXYZ> ());
        float gt = static_cast<float>(ui->GTBox->value());
        float lt = static_cast<float>(ui->LTBox->value());
    range_cond->addComparison (pcl::FieldComparison<pcl::PointXYZ>::ConstPtr (new pcl::FieldComparison<pcl::PointXYZ> ("z", pcl::ComparisonOps::GT, gt)));
    range_cond->addComparison (pcl::FieldComparison<pcl::PointXYZ>::ConstPtr (new pcl::FieldComparison<pcl::PointXYZ> ("z", pcl::ComparisonOps::LT, lt)));
    // 创建滤波器
    pcl::ConditionalRemoval<pcl::PointXYZ> condrem (range_cond);
    condrem.setInputCloud (m_scenePointCloud);
    condrem.setKeepOrganized(true);
    // 应用滤波器
    condrem.filter (*cloud_filtered6);
    showScene6();
    m_pclSceneViewer6->removeAllPointClouds();
    m_pclSceneViewer6->addPointCloud(cloud_filtered6,"icpPoint");
    m_pclSceneViewer6->resetCamera();
    ui->qvtkWidget_6->update();
}

void Filter::RadiusOutlierRemoval()
{
    // 创建滤波器对象
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered7 (new pcl::PointCloud<pcl::PointXYZ>);
    // 创建环境

        pcl::RadiusOutlierRemoval<pcl::PointXYZ> outrem;
        // 创建滤波器
        outrem.setInputCloud(m_scenePointCloud);
        outrem.setRadiusSearch(ui->BJBox->value());
        outrem.setMinNeighborsInRadius (ui->LJBox->value());
        // 应用滤波器
        outrem.filter (*cloud_filtered7);
        showScene7();

    m_pclSceneViewer7->removeAllPointClouds();
    m_pclSceneViewer7->addPointCloud(cloud_filtered7,"icpPoint");
    m_pclSceneViewer7->resetCamera();
    ui->qvtkWidget_7->update();
}


void Filter::CropHull()
{
    // 创建滤波器对象
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered8 (new pcl::PointCloud<pcl::PointXYZ>);
    // 创建环境

    pcl::PointCloud<pcl::PointXYZ>::Ptr boundingbox_ptr (new pcl::PointCloud<pcl::PointXYZ>);
    boundingbox_ptr->push_back(pcl::PointXYZ(0.1, 0.1, 0));
    boundingbox_ptr->push_back(pcl::PointXYZ(0.1, -0.1,0 ));
    boundingbox_ptr->push_back(pcl::PointXYZ(-0.1, 0.1,0 ));
    boundingbox_ptr->push_back(pcl::PointXYZ(-0.1, -0.1,0 ));
    boundingbox_ptr->push_back(pcl::PointXYZ(0.15, 0.1,0 ));

    pcl::ConvexHull<pcl::PointXYZ> hull;
    hull.setInputCloud(boundingbox_ptr);
    hull.setDimension(ui->aBox->value());
    std::vector<pcl::Vertices> polygons;
    pcl::PointCloud<pcl::PointXYZ>::Ptr surface_hull (new pcl::PointCloud<pcl::PointXYZ>);
    hull.reconstruct(*surface_hull, polygons);
    pcl::CropHull<pcl::PointXYZ> bb_filter;
    bb_filter.setDim(ui->bBox->value());
    bb_filter.setInputCloud(m_scenePointCloud);
    bb_filter.setHullIndices(polygons);
    bb_filter.setHullCloud(surface_hull);
    bb_filter.filter(*cloud_filtered8);

    showScene8();

    m_pclSceneViewer8->removeAllPointClouds();
    m_pclSceneViewer8->addPointCloud(cloud_filtered8,"icpPoint");
    m_pclSceneViewer8->resetCamera();
    ui->qvtkWidget_8->update();
}












