#include "registation.h"
#include "ui_registation.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>

#include <pcl/io/pcd_io.h>
#include <pcl/filters/passthrough.h>
#include <pcl/filters/voxel_grid.h>
#include <pcl/features/3dsc.h>
#include <pcl/registration/icp.h>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/registration/icp.h>//icp头文件
#include <pcl/registration/ndt.h> //ndt头文件
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/point_cloud.h>
#include <pcl/point_cloud.h>
#include <pcl/filters/voxel_grid.h>
#include <pcl/filters/filter.h>
#include <pcl/features/normal_3d.h>//去除NAN点的头文件
#include <pcl/filters/approximate_voxel_grid.h> //官网上采样过滤，先不用

#include <pcl/registration/ia_fpcs.h>
#include <pcl/registration/ia_kfpcs.h>


Registation::Registation(QWidget *parent) :
    QMainWindow(parent),ui(new Ui::Registation),m_searchMethod(new SearchMethod),m_isTemplateReady(false),m_isSceneReady(false)

{
    ui->setupUi(this);
    connect(ui->loadTemplateBut,SIGNAL(clicked(bool)),this,SLOT(loadTemplate()));
    connect(ui->templateComputeBut,SIGNAL(clicked(bool)),this,SLOT(computeTemplate()));

    connect(ui->sceneComputeBut,SIGNAL(clicked(bool)),this,SLOT(computeScene()));
     connect(ui->loadSceneBut,SIGNAL(clicked(bool)),this,SLOT(loadScene()));
    connect(ui->executeButton,SIGNAL(clicked(bool)),this,SLOT(DSC_ICP1()));
    connect(ui->executeButton_7,SIGNAL(clicked(bool)),this,SLOT(DSC_ICP2()));


//    connect(ui->sceneComputeBut_2,SIGNAL(clicked(bool)),this,SLOT(computeScene()));
     connect(ui->loadSceneBut_2,SIGNAL(clicked(bool)),this,SLOT(loadScene2()));
    connect(ui->executeButton_8,SIGNAL(clicked(bool)),this,SLOT(PCS_ICP1()));
    connect(ui->executeButton_2,SIGNAL(clicked(bool)),this,SLOT(PCS_ICP2()));

    connect(ui->sceneComputeBut_3,SIGNAL(clicked(bool)),this,SLOT(computeScene()));
     connect(ui->loadSceneBut_3,SIGNAL(clicked(bool)),this,SLOT(loadScene3()));
    connect(ui->executeButton_3,SIGNAL(clicked(bool)),this,SLOT(SAC_ICP1()));
    connect(ui->executeButton_5,SIGNAL(clicked(bool)),this,SLOT(SAC_ICP2()));

    connect(ui->sceneComputeBut_4,SIGNAL(clicked(bool)),this,SLOT(computeScene()));
     connect(ui->loadSceneBut_4,SIGNAL(clicked(bool)),this,SLOT(loadScene4()));
    connect(ui->executeButton_4,SIGNAL(clicked(bool)),this,SLOT(NDT_ICP1()));
   connect(ui->executeButton_6,SIGNAL(clicked(bool)),this,SLOT(NDT_ICP2()));

    m_pclTemplateViewer = new pcl::visualization::PCLVisualizer("viewer1",false);
    m_templatePointCloud.reset(new pcl::PointCloud<PointT>);
    m_pclTemplateViewer->addPointCloud(m_templatePointCloud,"cloud1");
    ui->widget->SetRenderWindow(m_pclTemplateViewer->getRenderWindow());
    m_pclTemplateViewer->setupInteractor(ui->widget->GetInteractor(),ui->widget->GetRenderWindow());
    ui->widget->update();



    m_pclSceneViewer = new pcl::visualization::PCLVisualizer("viewer2",false);
    m_scenePointCloud.reset(new pcl::PointCloud<PointT>);
    m_pclSceneViewer->addPointCloud(m_scenePointCloud,"cloud2");
    ui->widget_1->SetRenderWindow(m_pclSceneViewer->getRenderWindow());
    m_pclSceneViewer->setupInteractor(ui->widget_1->GetInteractor(),ui->widget_1->GetRenderWindow());
    ui->widget_1->update();

    m_pclSceneViewer2 = new pcl::visualization::PCLVisualizer("viewer3",false);
    m_scenePointCloud.reset(new pcl::PointCloud<PointT>);
    m_pclSceneViewer2->addPointCloud(m_scenePointCloud,"cloud3");
    ui->widget_2->SetRenderWindow(m_pclSceneViewer2->getRenderWindow());
    m_pclSceneViewer2->setupInteractor(ui->widget_2->GetInteractor(),ui->widget_2->GetRenderWindow());
    ui->widget_2->update();

    m_pclSceneViewer3 = new pcl::visualization::PCLVisualizer("viewer3",false);
    m_scenePointCloud.reset(new pcl::PointCloud<PointT>);
    m_pclSceneViewer3->addPointCloud(m_scenePointCloud,"cloud3");
    ui->widget_3->SetRenderWindow(m_pclSceneViewer3->getRenderWindow());
    m_pclSceneViewer3->setupInteractor(ui->widget_3->GetInteractor(),ui->widget_3->GetRenderWindow());
    ui->widget_3->update();

    m_pclSceneViewer4 = new pcl::visualization::PCLVisualizer("viewer3",false);
    m_scenePointCloud.reset(new pcl::PointCloud<PointT>);
    m_pclSceneViewer4->addPointCloud(m_scenePointCloud,"cloud3");
    ui->widget_4->SetRenderWindow(m_pclSceneViewer4->getRenderWindow());
    m_pclSceneViewer4->setupInteractor(ui->widget_4->GetInteractor(),ui->widget_4->GetRenderWindow());
    ui->widget_4->update();


}

Registation::~Registation()
{
    delete ui;
}

pcl::PointCloud<pcl::PointXYZ>::Ptr output_cloud_ndt (new pcl::PointCloud<pcl::PointXYZ>);
pcl::PointCloud<pcl::PointXYZ>::Ptr output_cloud_dsc (new pcl::PointCloud<pcl::PointXYZ>);
pcl::PointCloud<pcl::PointXYZ>::Ptr output_cloud_pcs (new pcl::PointCloud<pcl::PointXYZ>);

void Registation::showTemplate()
{
    if(m_templatePointCloud->points.size() == 0){
        return;
    }

    m_pclTemplateViewer->removeAllPointClouds();
    m_pclTemplateViewer->addPointCloud(m_templatePointCloud,"cloud1");
    m_pclTemplateViewer->resetCamera();
    ui->widget->update();
}

void Registation::showScene()
{
    if(m_scenePointCloud->points.size() == 0){
        return;
    }

    m_pclSceneViewer->removeAllPointClouds();
    m_pclSceneViewer->addPointCloud(m_scenePointCloud,"cloud2");
    m_pclSceneViewer->resetCamera();
    ui->widget_1->update();

}
void Registation::showScene2()
{
    if(m_scenePointCloud->points.size() == 0){
        return;
    }

    m_pclSceneViewer2->removeAllPointClouds();
    m_pclSceneViewer2->addPointCloud(m_scenePointCloud,"cloud2");
    m_pclSceneViewer2->resetCamera();
    ui->widget_2->update();
}
void Registation::showScene3()
{
    if(m_scenePointCloud->points.size() == 0){
        return;
    }

    m_pclSceneViewer3->removeAllPointClouds();
    m_pclSceneViewer3->addPointCloud(m_scenePointCloud,"cloud2");
    m_pclSceneViewer3->resetCamera();
    ui->widget_3->update();

}
void Registation::showScene4()
{
    if(m_scenePointCloud->points.size() == 0){
        return;
    }

    m_pclSceneViewer4->removeAllPointClouds();
    m_pclSceneViewer4->addPointCloud(m_scenePointCloud,"cloud2");
    m_pclSceneViewer4->resetCamera();
    ui->widget_4->update();

}
void Registation::loadTemplate()
{
    QString pcdFile = QFileDialog::getOpenFileName(this,"Pcd",QApplication::applicationDirPath(),"*.pcd");
    if(pcdFile.isEmpty()){
        return;
    }
    m_isTemplateReady = false;

    qDebug() << "pcdFile : " << pcdFile;

    pcl::PCDReader reader;
    reader.read(pcdFile.toStdString(), *m_templatePointCloud);

    m_templateFCloud.setInputCloud(m_templatePointCloud);

    showTemplate();
}

void Registation::loadScene()
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
void Registation::loadScene2()
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
void Registation::loadScene3()
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
void Registation::loadScene4()
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
void Registation::computeTemplate()
{
    if(m_templatePointCloud->points.size() == 0){
        return;
    }
// 这两处计算表面法线和局部特征的值是为了 SAC-IA 使用的，ICP用不上
    m_templateSurfaceNormal = computeSurfaceNormal(m_templatePointCloud,m_searchMethod,ui->templateNRSBox->value());
    m_templateLocalFeatures = computeLocalFeatures(m_templatePointCloud,m_templateSurfaceNormal,m_searchMethod,ui->templateFRSBox->value());

    qDebug() << "m_templateSurfaceNormal : " << m_templateSurfaceNormal->points.size();
    qDebug() << "m_templateLocalFeatures : " << m_templateLocalFeatures->points.size();

    m_isTemplateReady = true;

    QMessageBox::information(this,"Info","Success");
}

void Registation::computeScene()
{
    if(m_scenePointCloud->points.size() == 0){
        return;
    }
// 这两处计算表面法线和局部特征的值是为了 SAC-IA 使用的，ICP用不上
    m_sceneSurfaceNormal = computeSurfaceNormal(m_scenePointCloud,m_searchMethod,ui->sceneNRSBox->value());
    m_sceneLocalFeatures = computeLocalFeatures(m_scenePointCloud,m_sceneSurfaceNormal,m_searchMethod,ui->sceneFRSBox->value());

    m_isSceneReady = true;

    QMessageBox::information(this,"Info","Success");
}

void Registation::SAC()
{
    m_templateAlign.setTargetCloud(m_sceneFCloud);
    TemplateAlignment::Result alignment;
    m_templateAlign.align(m_templateFCloud,alignment);
    Eigen::Matrix4f matrix = alignment.final_transformation;
    qDebug() << "matrix : " << matrix.rows() << " * " << matrix.cols();
    qDebug() << "Transformation : \n"
             << matrix(0,0) << "," << matrix(0,1) << "," << matrix(0,2) << "," << matrix(0,3) << "\n"
             << matrix(1,0) << "," << matrix(1,1) << "," << matrix(1,2) << "," << matrix(1,3) << "\n"
             << matrix(2,0) << "," << matrix(2,1) << "," << matrix(2,2) << "," << matrix(2,3) << "\n"
             << matrix(3,0) << "," << matrix(3,1) << "," << matrix(3,2) << "," << matrix(3,3) << "\n";
    pcl::PointCloud<PointT>::Ptr transformed_cloud(new pcl::PointCloud<PointT>);
    pcl::transformPointCloud (*m_templateFCloud.getPointCloud(), *transformed_cloud, alignment.final_transformation);
    m_pclTemplateViewer->resetCamera();
    ui->widget->update();
    m_pclSceneViewer->addPointCloud(transformed_cloud,"transformedCloud");
    pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> icpColor(transformed_cloud, 0, 255, 0);
        m_pclSceneViewer->addPointCloud(transformed_cloud,icpColor,"icpPoint");
    m_pclSceneViewer->resetCamera();
    ui->widget_1->update();
    pcl::io::savePCDFileBinary ("output.pcd", *transformed_cloud);
}
void Registation::DSC_ICP1()
{

    //加载点云
//…………………………………………………………………………………………………………
        //去除NAN点
    //…………………………………………………………………………………………
    //下采样
//…………………………………………………………………………………………
    //计算表面法线
    pcl::NormalEstimation<pcl::PointXYZ, pcl::Normal> ne_src;
    ne_src.setInputCloud(m_scenePointCloud);
    pcl::search::KdTree< pcl::PointXYZ>::Ptr tree_src(new pcl::search::KdTree< pcl::PointXYZ>());
    ne_src.setSearchMethod(tree_src);
    pcl::PointCloud<pcl::Normal>::Ptr cloud_src_normals(new pcl::PointCloud< pcl::Normal>);
    ne_src.setRadiusSearch(ui->sceneNRSBox->value());
    ne_src.compute(*cloud_src_normals);

    pcl::NormalEstimation<pcl::PointXYZ, pcl::Normal> ne_tgt;
    ne_tgt.setInputCloud(m_templatePointCloud);
    pcl::search::KdTree< pcl::PointXYZ>::Ptr tree_tgt(new pcl::search::KdTree< pcl::PointXYZ>());
    ne_tgt.setSearchMethod(tree_tgt);
    pcl::PointCloud<pcl::Normal>::Ptr cloud_tgt_normals(new pcl::PointCloud< pcl::Normal>);
    //ne_tgt.setKSearch(20);
    ne_tgt.setRadiusSearch(ui->templateNRSBox->value());
    ne_tgt.compute(*cloud_tgt_normals);
    //计算3dsc
    pcl::ShapeContext3DEstimation<pcl::PointXYZ, pcl::Normal, pcl::ShapeContext1980> sp_tgt;
    sp_tgt.setInputCloud(m_templatePointCloud);
    sp_tgt.setInputNormals(cloud_tgt_normals);
    //kdTree加速
    pcl::search::KdTree<PointT>::Ptr tree_tgt_sp(new pcl::search::KdTree<PointT>);
    sp_tgt.setSearchMethod(tree_tgt_sp);
    pcl::PointCloud<pcl::ShapeContext1980>::Ptr sps_tgt(new pcl::PointCloud<pcl::ShapeContext1980>());
    sp_tgt.setRadiusSearch(0.5);
    sp_tgt.compute(*sps_tgt);

    pcl::ShapeContext3DEstimation<pcl::PointXYZ, pcl::Normal, pcl::ShapeContext1980> sp_src;
    sp_src.setInputCloud(m_scenePointCloud);
    sp_src.setInputNormals(cloud_src_normals);
    //kdTree加速
    pcl::search::KdTree<PointT>::Ptr tree_src_sp(new pcl::search::KdTree<PointT>);
    sp_src.setSearchMethod(tree_src_sp);
    pcl::PointCloud<pcl::ShapeContext1980>::Ptr sps_src(new pcl::PointCloud<pcl::ShapeContext1980>());
    sp_src.setRadiusSearch(0.5);
    sp_src.compute(*sps_src);

    pcl::SampleConsensusInitialAlignment<pcl::PointXYZ, pcl::PointXYZ, pcl::ShapeContext1980> scia;
    scia.setInputSource(m_scenePointCloud);
    scia.setInputTarget(m_templatePointCloud);
    scia.setSourceFeatures(sps_src);
    scia.setTargetFeatures(sps_tgt);

    scia.setMinSampleDistance(ui->minSTSBox->value());
    scia.setMaxCorrespondenceDistance(ui->maxCDSBox->value());
    scia.setMaximumIterations(ui->maxIterationSBox->value());

    qDebug() << "start align";
    pcl::PointCloud<PointT>::Ptr sciaOut(new pcl::PointCloud<PointT>);
    scia.align(*sciaOut);

    qDebug() << "end align";
    qDebug() << "score : " << scia.getFitnessScore();

    DSC_trans = scia.getFinalTransformation();
   pcl::transformPointCloud(*m_scenePointCloud, *sciaOut, DSC_trans);
    qDebug() << "matrix : " << DSC_trans.rows() << " * " << DSC_trans.cols();
    qDebug() << "Transformation : \n"
             << DSC_trans(0,0) << "," << DSC_trans(0,1) << "," << DSC_trans(0,2) << "," << DSC_trans(0,3) << "\n"
             << DSC_trans(1,0) << "," << DSC_trans(1,1) << "," << DSC_trans(1,2) << "," << DSC_trans(1,3) << "\n"
             << DSC_trans(2,0) << "," << DSC_trans(2,1) << "," << DSC_trans(2,2) << "," << DSC_trans(2,3) << "\n"
             << DSC_trans(3,0) << "," << DSC_trans(3,1) << "," << DSC_trans(3,2) << "," << DSC_trans(3,3) << "\n";
    m_pclTemplateViewer->resetCamera();
    ui->widget->update();

    m_pclSceneViewer->removeAllPointClouds();
    m_pclSceneViewer->addPointCloud(m_templatePointCloud,"cloud2");
    pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> sciaColor(sciaOut, 0, 255, 0);
    m_pclSceneViewer->addPointCloud(sciaOut,sciaColor,"icpPoint");
    m_pclSceneViewer->resetCamera();
    ui->widget_1->update();
}

void Registation::DSC_ICP2()
{
    PointCloud::Ptr icp_result(new PointCloud);
    pcl::IterativeClosestPoint<pcl::PointXYZ, pcl::PointXYZ> icp;
    icp.setInputSource(m_scenePointCloud);
    icp.setInputTarget(m_templatePointCloud);
    icp.setMaxCorrespondenceDistance(ui->icpmcdBox_4->value());
    icp.setMaximumIterations (ui->icpIterationsSBox_3->value());//setMaximumIterations
//    icp.setRANSACOutlierRejectionThreshold (ui->mcdSBox->value());//
    icp.setTransformationEpsilon (ui->mcdSBox_3->value());//setTranslationThreshold
    icp.setEuclideanFitnessEpsilon(ui->efeSBox_3->value());//setRelativeMSE

    pcl::PointCloud<PointT>::Ptr icpPoint(new pcl::PointCloud<PointT>);
    icp.align (*icpPoint,DSC_trans);
    Eigen::Matrix4f matrix = icp.getFinalTransformation();
     pcl::transformPointCloud(*m_scenePointCloud, *icpPoint, matrix);
    qDebug() << "fitnessScore : " << icp.getFitnessScore();
    qDebug() << "matrix : " << matrix.rows() << " * " << matrix.cols();
    qDebug() << "Transformation : \n"
             << matrix(0,0) << "," << matrix(0,1) << "," << matrix(0,2) << "," << matrix(0,3) << "\n"
             << matrix(1,0) << "," << matrix(1,1) << "," << matrix(1,2) << "," << matrix(1,3) << "\n"
             << matrix(2,0) << "," << matrix(2,1) << "," << matrix(2,2) << "," << matrix(2,3) << "\n"
             << matrix(3,0) << "," << matrix(3,1) << "," << matrix(3,2) << "," << matrix(3,3) << "\n";
    pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> icpColor(icpPoint, 0, 255, 0);
    m_pclTemplateViewer->resetCamera();
    ui->widget->update();

    m_pclSceneViewer->removeAllPointClouds();
    m_pclSceneViewer->addPointCloud(m_templatePointCloud,"cloud2");
    m_pclSceneViewer->addPointCloud(icpPoint,icpColor,"icpPoint");
    m_pclSceneViewer->resetCamera();
    ui->widget_1->update();
}



void Registation::ICP()
{
    pcl::IterativeClosestPoint<PointT, PointT> icp;
    icp.setMaximumIterations (ui->icpmiBox->value());
    icp.setInputSource (m_templatePointCloud);
    icp.setInputTarget (m_scenePointCloud);
    pcl::PointCloud<PointT>::Ptr icpPoint(new pcl::PointCloud<PointT>);
    icp.align (*icpPoint);
    //输出ICP配准的信息（是否收敛，拟合度）
    std::cout << "has converged:" << icp.hasConverged() << " score: " <<icp.getFitnessScore() << std::endl;
    Eigen::Matrix4f matrix = icp.getFinalTransformation();
    qDebug() << "fitnessScore : " << icp.getFitnessScore();
    qDebug() << "matrix : " << matrix.rows() << " * " << matrix.cols();
    qDebug() << "Transformation : \n"
             << matrix(0,0) << "," << matrix(0,1) << "," << matrix(0,2) << "," << matrix(0,3) << "\n"
             << matrix(1,0) << "," << matrix(1,1) << "," << matrix(1,2) << "," << matrix(1,3) << "\n"
             << matrix(2,0) << "," << matrix(2,1) << "," << matrix(2,2) << "," << matrix(2,3) << "\n"
             << matrix(3,0) << "," << matrix(3,1) << "," << matrix(3,2) << "," << matrix(3,3) << "\n";
    m_pclTemplateViewer->resetCamera();
    ui->widget->update();
    m_pclSceneViewer2->addPointCloud(icpPoint,"transformedCloud");
    pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> icpColor(icpPoint, 0, 255, 0);
        m_pclSceneViewer2->addPointCloud(icpPoint,icpColor,"icpPoint");
        m_pclSceneViewer2->resetCamera();
        ui->widget_2->update();
}
void Registation::PCS_ICP1()
{

    typedef pcl::PointXYZ PointT;
    typedef pcl::PointCloud<PointT> PointCloud;

    //四点法配准
        PointCloud::Ptr pcs(new PointCloud);
        pcl::registration::FPCSInitialAlignment<pcl::PointXYZ,pcl::PointXYZ> fpcs;

        fpcs.setInputSource(m_scenePointCloud);
        fpcs.setInputTarget(m_templatePointCloud);

        //参数设置
        fpcs.setApproxOverlap(ui->minSTSBox_3->value());
        fpcs.setDelta(ui->maxCDSBox_3->value());
        fpcs.setMaxComputationTime(ui->maxIterationSBox_3->value());
        fpcs.setNumberOfSamples(ui->maxIterationSBox_4->value());
        fpcs.align(*pcs);

     qDebug() << "score:: " << fpcs.getFitnessScore() ;
        Eigen::Matrix4f PSC_trans = fpcs.getFinalTransformation();

        pcl::transformPointCloud(*m_scenePointCloud,*output_cloud_pcs,PSC_trans);
        qDebug() << "matrix : " << PSC_trans.rows() << " * " << PSC_trans.cols();
        qDebug() << "Transformation : \n"
                 << PSC_trans(0,0) << "," << PSC_trans(0,1) << "," << PSC_trans(0,2) << "," << PSC_trans(0,3) << "\n"
                 << PSC_trans(1,0) << "," << PSC_trans(1,1) << "," << PSC_trans(1,2) << "," << PSC_trans(1,3) << "\n"
                 << PSC_trans(2,0) << "," << PSC_trans(2,1) << "," << PSC_trans(2,2) << "," << PSC_trans(2,3) << "\n"
                 << PSC_trans(3,0) << "," << PSC_trans(3,1) << "," << PSC_trans(3,2) << "," << PSC_trans(3,3) << "\n";

    m_pclTemplateViewer->resetCamera();
    ui->widget->update();

    m_pclSceneViewer2->removeAllPointClouds();
    m_pclSceneViewer2->addPointCloud(m_templatePointCloud,"cloud2");
    pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> icpColor(output_cloud_pcs, 0, 255, 0);
    m_pclSceneViewer2->addPointCloud(output_cloud_pcs,icpColor,"icpPoint");
    m_pclSceneViewer2->resetCamera();
    ui->widget_2->update();

}

void Registation::PCS_ICP2()
{

    typedef pcl::PointXYZ PointT;
    typedef pcl::PointCloud<PointT> PointCloud;

    //四点法配准
        PointCloud::Ptr pcs(new PointCloud);
        pcl::registration::FPCSInitialAlignment<pcl::PointXYZ,pcl::PointXYZ> fpcs;

        fpcs.setInputSource(m_scenePointCloud);
        fpcs.setInputTarget(m_templatePointCloud);

        //参数设置
        fpcs.setApproxOverlap(ui->minSTSBox_3->value());
        fpcs.setDelta(ui->maxCDSBox_3->value());
        fpcs.setMaxComputationTime(ui->maxIterationSBox_3->value());
        fpcs.setNumberOfSamples(ui->maxIterationSBox_4->value());
        fpcs.align(*pcs);

     qDebug() << "score:: " << fpcs.getFitnessScore() ;
        Eigen::Matrix4f PSC_trans = fpcs.getFinalTransformation();

    pcl::IterativeClosestPoint<pcl::PointXYZ, pcl::PointXYZ> icp;


    //设置参数
    icp.setInputSource(m_scenePointCloud);
    icp.setInputTarget(m_templatePointCloud);
    icp.setMaxCorrespondenceDistance(ui->icpmcdBox->value());//当两个点云相距较远时候，距离值要变大，所以一开始需要粗配准。
    icp.setTransformationEpsilon(ui->icpteBox->value());//svd奇异值分解，对icp时间影响不大
    icp.setEuclideanFitnessEpsilon(ui->icpefeBox->value());//前后两次误差大小，当误差值小于这个值停止迭代
    icp.setMaximumIterations(ui->icpmiBox->value());//最大迭代次数
 pcl::PointCloud<PointT>::Ptr icpPoint(new pcl::PointCloud<PointT>);
    icp.align(*icpPoint, PSC_trans);


    qDebug() << "score:: " << icp.getFitnessScore() ;
    Eigen::Matrix4f transformation_icp = icp.getFinalTransformation();
    pcl::transformPointCloud(*m_scenePointCloud, *icpPoint, transformation_icp);

    //计算误差
    Eigen::Vector3f ANGLE_origin;
    Eigen::Vector3f TRANS_origin;
    ANGLE_origin << 0, 0, M_PI / 4;
    TRANS_origin << 0, 0.3, 0.2;
    Eigen::Vector3f ANGLE_result;
    matrix2angle(transformation_icp, ANGLE_result);
    m_pclTemplateViewer->resetCamera();
    ui->widget->update();
    m_pclSceneViewer2->removeAllPointClouds();
    m_pclSceneViewer2->addPointCloud(m_templatePointCloud,"cloud2");
    pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> icpColor(icpPoint, 0, 255, 0);
    m_pclSceneViewer2->addPointCloud(icpPoint,icpColor,"icpPoint");

    m_pclSceneViewer2->resetCamera();
    ui->widget_2->update();

}

void Registation::SAC_ICP1()
{
    computeTemplate();
    computeScene();
    if(m_templatePointCloud->points.size() == 0
            || m_scenePointCloud->points.size() == 0
            || !m_isTemplateReady || !m_isSceneReady){
        QMessageBox::critical(this,"Error","Not ready for SCIA");
        return;
    }
    m_scia.setMinSampleDistance(ui->minSTSBox->value());
    m_scia.setMaxCorrespondenceDistance(ui->maxCDSBox->value());
    m_scia.setMaximumIterations(ui->maxIterationSBox->value());
    m_scia.setInputTarget(m_scenePointCloud);
    m_scia.setTargetFeatures(m_sceneLocalFeatures);
    m_scia.setInputSource(m_templatePointCloud);
    m_scia.setSourceFeatures(m_templateLocalFeatures);
    qDebug() << "start align";
    pcl::PointCloud<PointT>::Ptr sciaOut(new pcl::PointCloud<PointT>);
    m_scia.align(*sciaOut);
    qDebug() << "end align";
    qDebug() << "score : " << m_scia.getFitnessScore();
    m_matrix = m_scia.getFinalTransformation();
    qDebug() << "matrix : " << m_matrix.rows() << " * " << m_matrix.cols();
    qDebug() << "Transformation : \n"
             << m_matrix(0,0) << "," << m_matrix(0,1) << "," << m_matrix(0,2) << "," << m_matrix(0,3) << "\n"
             << m_matrix(1,0) << "," << m_matrix(1,1) << "," << m_matrix(1,2) << "," << m_matrix(1,3) << "\n"
             << m_matrix(2,0) << "," << m_matrix(2,1) << "," << m_matrix(2,2) << "," << m_matrix(2,3) << "\n"
             << m_matrix(3,0) << "," << m_matrix(3,1) << "," << m_matrix(3,2) << "," << m_matrix(3,3) << "\n";

    m_pclTemplateViewer->resetCamera();
    ui->widget->update();

    m_pclSceneViewer3->removeAllPointClouds();
    m_pclSceneViewer3->addPointCloud(m_scenePointCloud,"cloud2");
    pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> sciaColor(sciaOut, 0, 255, 0);
    m_pclSceneViewer3->addPointCloud(sciaOut,sciaColor,"icpPoint");
    m_pclSceneViewer3->resetCamera();
    ui->widget_3->update();
}

void Registation::SAC_ICP2()
{
    pcl::IterativeClosestPoint<PointT, PointT> icp;
    icp.setMaximumIterations (ui->icpIterationsSBox->value());//setMaximumIterations
//    icp.setRANSACOutlierRejectionThreshold (ui->mcdSBox->value());//
    icp.setTransformationEpsilon (ui->mcdSBox->value());//setTranslationThreshold
    icp.setEuclideanFitnessEpsilon(ui->efeSBox->value());//setRelativeMSE
    icp.setInputSource (m_templatePointCloud);
    icp.setInputTarget (m_scenePointCloud);
    pcl::PointCloud<PointT>::Ptr icpPoint(new pcl::PointCloud<PointT>);
    icp.align (*icpPoint,m_matrix);
    Eigen::Matrix4f matrix = icp.getFinalTransformation();
    qDebug() << "fitnessScore : " << icp.getFitnessScore();
    qDebug() << "matrix : " << matrix.rows() << " * " << matrix.cols();
    qDebug() << "Transformation : \n"
             << matrix(0,0) << "," << matrix(0,1) << "," << matrix(0,2) << "," << matrix(0,3) << "\n"
             << matrix(1,0) << "," << matrix(1,1) << "," << matrix(1,2) << "," << matrix(1,3) << "\n"
             << matrix(2,0) << "," << matrix(2,1) << "," << matrix(2,2) << "," << matrix(2,3) << "\n"
             << matrix(3,0) << "," << matrix(3,1) << "," << matrix(3,2) << "," << matrix(3,3) << "\n";




    m_pclTemplateViewer->resetCamera();
    ui->widget->update();

    m_pclSceneViewer3->removeAllPointClouds();
    m_pclSceneViewer3->addPointCloud(m_scenePointCloud,"cloud2");
     pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> icpColor(icpPoint, 0, 255, 0);
    m_pclSceneViewer3->addPointCloud(icpPoint,icpColor,"icpPoint");
    m_pclSceneViewer3->resetCamera();
    ui->widget_3->update();
}

void Registation::matrix2angle (Eigen::Matrix4f &result_trans,Eigen::Vector3f &result_angle)
{
  double ax,ay,az;
  if (result_trans(2,0)==1 || result_trans(2,0)==-1)
  {
      az=0;
      double dlta;
      dlta=atan2(result_trans(0,1),result_trans(0,2));
      if (result_trans(2,0)==-1)
      {
          ay=M_PI/2;
          ax=az+dlta;
      }
      else
      {
          ay=-M_PI/2;
          ax=-az+dlta;
      }
  }
  else
  {
      ay=-asin(result_trans(2,0));
      ax=atan2(result_trans(2,1)/cos(ay),result_trans(2,2)/cos(ay));
      az=atan2(result_trans(1,0)/cos(ay),result_trans(0,0)/cos(ay));
  }
  result_angle<<ax,ay,az;
}


void Registation::NDT_ICP1()
{
    //将输入的扫描过滤到原始尺寸的大概10%以提高匹配的速度。
    pcl::PointCloud<pcl::PointXYZ>::Ptr filtered_cloud (new pcl::PointCloud<pcl::PointXYZ>);
    pcl::ApproximateVoxelGrid<pcl::PointXYZ> approximate_voxel_filter;
    approximate_voxel_filter.setLeafSize (0.2, 0.2, 0.2);
    approximate_voxel_filter.setInputCloud (m_scenePointCloud);
    approximate_voxel_filter.filter (*filtered_cloud);

    //初始化正态分布变换（NDT）
    pcl::NormalDistributionsTransform<pcl::PointXYZ, pcl::PointXYZ> ndt;
    //设置依赖尺度NDT参数
    //为终止条件设置最小转换差异
 //   ndt.setTransformationEpsilon (0.01);
    ndt.setTransformationEpsilon(ui->NdtteBox->value());
    //为More-Thuente线搜索设置最大步长
   // ndt.setStepSize (0.1);
    ndt.setStepSize(ui->NdtssBox->value());
    //设置NDT网格结构的分辨率（VoxelGridCovariance）
    //ndt.setResolution (1.0);
    ndt.setResolution(ui->NdtrBox->value());
    //设置匹配迭代的最大次数
   // ndt.setMaximumIterations (35);
    ndt.setMaximumIterations(ui->NdtmiBox->value());
    // 设置要配准的点云
    ndt.setInputCloud (filtered_cloud);
//    ndt.setInputSourec(filtered_cloud);
    //设置点云配准目标
    ndt.setInputTarget (m_templatePointCloud);

    //设置初始变换矩阵，可有可无
    Eigen::AngleAxisf init_rotation(M_PI / 4, Eigen::Vector3f::UnitZ());//以z轴为坐标轴，旋转45°
    Eigen::Translation3f init_transtion(0, 0, 0);
    Eigen::Matrix4f init_guess = (init_transtion*init_rotation).matrix();
    //计算需要的刚体变换以便将输入的点云匹配到目标点云
    pcl::PointCloud<pcl::PointXYZ>::Ptr output_cloud (new pcl::PointCloud<pcl::PointXYZ>);
//    ndt.align (*output_cloud_ndt, init_guess);
    ndt.align (*output_cloud_ndt);
    qDebug() << "score:: " << ndt.getFitnessScore() ;

    ndt_trans=ndt.getFinalTransformation();
    pcl::transformPointCloud(*m_scenePointCloud, *output_cloud_ndt, ndt_trans);
    Eigen::Vector3f ANGLE_origin;
    ANGLE_origin<<0,0,M_PI/5;
    double error_x,error_y,error_z;
    Eigen::Vector3f ANGLE_result;
    matrix2angle(ndt_trans,ANGLE_result);
    error_x=fabs(ANGLE_result(0))-fabs(ANGLE_origin(0));
    error_y=fabs(ANGLE_result(1))-fabs(ANGLE_origin(1));
    error_z=fabs(ANGLE_result(2))-fabs(ANGLE_origin(2));
    qDebug()<<"error in aixs_x: "<<error_x<<"  error in aixs_y: "<<error_y<<"  error in aixs_z: "<<error_z<<endl;
    m_pclTemplateViewer->resetCamera();
    ui->widget->update();

    m_pclSceneViewer4->removeAllPointClouds();
    m_pclSceneViewer4->addPointCloud(m_templatePointCloud,"cloud2");
    pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> icpColor(output_cloud_ndt, 0, 255, 0);
    m_pclSceneViewer4->addPointCloud(output_cloud_ndt,icpColor,"icpPoint");
    m_pclSceneViewer4->resetCamera();
    ui->widget_4->update();

    pcl::io::savePCDFileBinary ("output2.pcd", *output_cloud_ndt);
}

void Registation::NDT_ICP2()
{

    pcl::IterativeClosestPoint<pcl::PointXYZ, pcl::PointXYZ> icp;
    PointCloud::Ptr cloud_icp_registration(new PointCloud);
    //kdTree 加速搜索
    pcl::search::KdTree<pcl::PointXYZ>::Ptr tree1(new pcl::search::KdTree<pcl::PointXYZ>);
    tree1->setInputCloud(output_cloud_ndt);
    pcl::search::KdTree<pcl::PointXYZ>::Ptr tree2(new pcl::search::KdTree<pcl::PointXYZ>);
    tree2->setInputCloud(m_templatePointCloud);
    icp.setSearchMethodSource(tree1);
    icp.setSearchMethodTarget(tree2);

    //设置参数
    icp.setInputSource(output_cloud_ndt);
    icp.setInputTarget(m_templatePointCloud);
    icp.setMaxCorrespondenceDistance(ui->icpmcdBox_3->value());//当两个点云相距较远时候，距离值要变大，所以一开始需要粗配准。
    icp.setTransformationEpsilon(ui->mcdSBox_2->value());//svd奇异值分解，对icp时间影响不大
    icp.setEuclideanFitnessEpsilon(ui->efeSBox_2->value());//前后两次误差大小，当误差值小于这个值停止迭代
    icp.setMaximumIterations(ui->icpIterationsSBox_2->value());//最大迭代次数
    icp.align(*cloud_icp_registration, ndt_trans);
    qDebug() << "score:: " << icp.getFitnessScore() ;
    Eigen::Matrix4f transformation_icp = icp.getFinalTransformation();
    pcl::transformPointCloud(*output_cloud_ndt, *cloud_icp_registration, transformation_icp);

    //计算误差
    Eigen::Vector3f ANGLE_origin;
    Eigen::Vector3f TRANS_origin;
    ANGLE_origin << 0, 0, M_PI / 4;
    TRANS_origin << 0, 0.3, 0.2;
    Eigen::Vector3f ANGLE_result;
    matrix2angle(transformation_icp, ANGLE_result);
    m_pclTemplateViewer->resetCamera();
    ui->widget->update();
    m_pclSceneViewer4->removeAllPointClouds();
    m_pclSceneViewer4->addPointCloud(m_templatePointCloud,"cloud2");
    pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> icpColor(cloud_icp_registration, 0, 255, 0);
    m_pclSceneViewer4->addPointCloud(cloud_icp_registration,icpColor,"icpPoint");
    m_pclSceneViewer4->resetCamera();
    ui->widget_4->update();
    pcl::io::savePCDFileBinary ("output2.pcd", *cloud_icp_registration);
}


//下面这两个是计算的实现函数，计算surfacenormal 表面法线  和localfeatures 局部特征

SurfaceNormal::Ptr Registation::computeSurfaceNormal(pcl::PointCloud<PointT>::Ptr inputCloud,
                                                      SearchMethod::Ptr searchMethod,
                                                      double normalRadius)
{
    SurfaceNormal::Ptr surfaceNormal = SurfaceNormal::Ptr(new SurfaceNormal);
    pcl::NormalEstimation<PointT,pcl::Normal> norEst;
    norEst.setInputCloud(inputCloud);
    norEst.setSearchMethod(searchMethod);
    norEst.setRadiusSearch(normalRadius);
    norEst.compute(*surfaceNormal);
    qDebug() << "surfaceNormal : " << surfaceNormal->points.size();
    return surfaceNormal;
}

LocalFeatures::Ptr Registation::computeLocalFeatures(pcl::PointCloud<PointT>::Ptr inputCloud,
                                                      SurfaceNormal::Ptr inputNormal,
                                                      SearchMethod::Ptr searchMethod,
                                                      double featureRadius)
{
    LocalFeatures::Ptr localFeatures = LocalFeatures::Ptr(new LocalFeatures);
    pcl::FPFHEstimation<PointT,pcl::Normal,pcl::FPFHSignature33> fpfhEst;
    fpfhEst.setInputCloud(inputCloud);
    fpfhEst.setInputNormals(inputNormal);
    fpfhEst.setSearchMethod(searchMethod);
    fpfhEst.setRadiusSearch(featureRadius);
    fpfhEst.compute(*localFeatures);
    qDebug() << "localFeatures : " << localFeatures->points.size();
    return localFeatures;
}

