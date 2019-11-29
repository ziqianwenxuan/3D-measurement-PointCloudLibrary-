#include "transform.h"
#include "ui_transform.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>
#include <pcl/visualization/range_image_visualizer.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/range_image/range_image.h>
#include <pcl/features/range_image_border_extractor.h>
#include <pcl/io/pcd_io.h>
#include <pcl/filters/passthrough.h>
#include <pcl/filters/voxel_grid.h>
#include <pcl/range_image/range_image.h>
#include <pcl/registration/icp.h>

#include <pcl/range_image/range_image.h>
#include <pcl/range_image/range_image_planar.h>
#include <pcl/io/io.h>
#include <pcl/io/pcd_io.h>
#include <pcl/features/integral_image_normal.h>
#include <pcl/visualization/cloud_viewer.h>
#include <pcl/point_types.h>
#include <pcl/features/normal_3d.h>
#include <pcl/console/print.h>
#include <pcl/surface/organized_fast_mesh.h>
#include <pcl/console/time.h>
#include <Eigen/StdVector>
#include <Eigen/Geometry>
#include <iostream>
#include <pcl/surface/impl/organized_fast_mesh.hpp>
#include <boost/thread/thread.hpp>

#include <pcl/common/common_headers.h>

#include <pcl/visualization/range_image_visualizer.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/console/parse.h>


Transform::Transform(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Transform),m_searchMethod(new SearchMethod),m_isTemplateReady(false),m_isSceneReady(false)
{
    ui->setupUi(this);
    connect(ui->loadSceneBut,SIGNAL(clicked(bool)),this,SLOT(loadScene()));
    connect(ui->executeButton,SIGNAL(clicked(bool)),this,SLOT(range_image()));

    connect(ui->loadSceneBut_2,SIGNAL(clicked(bool)),this,SLOT(loadScene2()));
    connect(ui->executeButton_2,SIGNAL(clicked(bool)),this,SLOT(ColorImage()));

    connect(ui->loadSceneBut_3,SIGNAL(clicked(bool)),this,SLOT(loadScene3()));
    connect(ui->executeButton_3,SIGNAL(clicked(bool)),this,SLOT(HeightImage()));

    connect(ui->loadSceneBut_4,SIGNAL(clicked(bool)),this,SLOT(loadScene4()));
    connect(ui->executeButton_4,SIGNAL(clicked(bool)),this,SLOT(GrayImage()));

    connect(ui->loadSceneBut_5,SIGNAL(clicked(bool)),this,SLOT(loadScene5()));
    connect(ui->executeButton_5,SIGNAL(clicked(bool)),this,SLOT(IntensityImage()));


    m_pclSceneViewer = new pcl::visualization::PCLVisualizer("viewer2",false);
    m_scenePointCloud.reset(new pcl::PointCloud<PointT>);
    m_pclSceneViewer->addPointCloud(m_scenePointCloud,"cloud2");
    ui->widget_1->SetRenderWindow(m_pclSceneViewer->getRenderWindow());
    m_pclSceneViewer->setupInteractor(ui->widget_1->GetInteractor(),ui->widget_1->GetRenderWindow());
    ui->widget_1->update();

    m_pclSceneViewer2 = new pcl::visualization::PCLVisualizer("viewer2",false);
    m_scenePointCloud.reset(new pcl::PointCloud<PointT>);
    m_pclSceneViewer2->addPointCloud(m_scenePointCloud,"cloud2");
    ui->widget_2->SetRenderWindow(m_pclSceneViewer2->getRenderWindow());
    m_pclSceneViewer2->setupInteractor(ui->widget_2->GetInteractor(),ui->widget_2->GetRenderWindow());
    ui->widget_2->update();

    m_pclSceneViewer3 = new pcl::visualization::PCLVisualizer("viewer2",false);
    m_scenePointCloud.reset(new pcl::PointCloud<PointT>);
    m_pclSceneViewer3->addPointCloud(m_scenePointCloud,"cloud2");
    ui->widget_3->SetRenderWindow(m_pclSceneViewer3->getRenderWindow());
    m_pclSceneViewer3->setupInteractor(ui->widget_3->GetInteractor(),ui->widget_3->GetRenderWindow());
    ui->widget_3->update();

    m_pclSceneViewer4 = new pcl::visualization::PCLVisualizer("viewer2",false);
    m_scenePointCloud.reset(new pcl::PointCloud<PointT>);
    m_pclSceneViewer4->addPointCloud(m_scenePointCloud,"cloud2");
    ui->widget_4->SetRenderWindow(m_pclSceneViewer4->getRenderWindow());
    m_pclSceneViewer4->setupInteractor(ui->widget_4->GetInteractor(),ui->widget_4->GetRenderWindow());
    ui->widget_4->update();

    m_pclSceneViewer5 = new pcl::visualization::PCLVisualizer("viewer2",false);
    m_scenePointCloud.reset(new pcl::PointCloud<PointT>);
    m_pclSceneViewer5->addPointCloud(m_scenePointCloud,"cloud2");
    ui->widget_5->SetRenderWindow(m_pclSceneViewer5->getRenderWindow());
    m_pclSceneViewer5->setupInteractor(ui->widget_5->GetInteractor(),ui->widget_5->GetRenderWindow());
    ui->widget_5->update();





}

Transform::~Transform()
{
    delete ui;
}

void Transform::showScene()
{
    if(m_scenePointCloud->points.size() == 0){
        return;
    }

    m_pclSceneViewer->removeAllPointClouds();
    m_pclSceneViewer->addPointCloud(m_scenePointCloud,"cloud2");
    m_pclSceneViewer->resetCamera();
    ui->widget_1->update();

}

void Transform::showScene2()
{
    if(m_scenePointCloud->points.size() == 0){
        return;
    }

    m_pclSceneViewer2->removeAllPointClouds();
    m_pclSceneViewer2->addPointCloud(m_scenePointCloud,"cloud2");
    m_pclSceneViewer2->resetCamera();
    ui->widget_2->update();

}
void Transform::showScene3()
{
    if(m_scenePointCloud->points.size() == 0){
        return;
    }

    m_pclSceneViewer3->removeAllPointClouds();
    m_pclSceneViewer3->addPointCloud(m_scenePointCloud,"cloud2");
    m_pclSceneViewer3->resetCamera();
    ui->widget_3->update();

}
void Transform::showScene4()
{
    if(m_scenePointCloud->points.size() == 0){
        return;
    }

    m_pclSceneViewer4->removeAllPointClouds();
    m_pclSceneViewer4->addPointCloud(m_scenePointCloud,"cloud2");
    m_pclSceneViewer4->resetCamera();
    ui->widget_4->update();

}
void Transform::showScene5()
{
    if(m_scenePointCloud->points.size() == 0){
        return;
    }

    m_pclSceneViewer5->removeAllPointClouds();
    m_pclSceneViewer5->addPointCloud(m_scenePointCloud,"cloud2");
    m_pclSceneViewer5->resetCamera();
    ui->widget_5->update();

}


void Transform::loadScene()
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

void Transform::loadScene2()
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
void Transform::loadScene3()
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
void Transform::loadScene4()
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
void Transform::loadScene5()
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
    showScene5();
}
void Transform::range_image()
{
    pcl::PointCloud<pcl::PointXYZ> pointCloud = *m_scenePointCloud;
  //以1度为角分辨率，从上面创建的点云创建深度图像。
    float angularResolution = (float) (  1.0f * (M_PI/180.0f));
  // 1度转弧度
    float maxAngleWidth     = (float) (360.0f * (M_PI/180.0f));
  // 360.0度转弧度
    float maxAngleHeight    = (float) (180.0f * (M_PI/180.0f));
  // 180.0度转弧度
    Eigen::Affine3f sensorPose = (Eigen::Affine3f)Eigen::Translation3f(0.0f, 0.0f, 0.0f);
    pcl::RangeImage::CoordinateFrame coordinate_frame = pcl::RangeImage::CAMERA_FRAME;
    float noiseLevel=ui->MNBBox_6->value();
    float minRange = ui->NOTBox_6->value();
    int borderSize = ui->NOTBox_7->value();
    boost::shared_ptr<pcl::RangeImage> range_image_ptr(new pcl::RangeImage);
    pcl::RangeImage& rangeImage = *range_image_ptr;
    rangeImage.createFromPointCloud(pointCloud, angularResolution, maxAngleWidth, maxAngleHeight, sensorPose, coordinate_frame, noiseLevel, minRange, borderSize);
    pcl::io::savePCDFileBinary ("output2.pcd", rangeImage);
    pcl::visualization::PointCloudColorHandlerCustom<pcl::PointWithRange> range_image_color_handler(range_image_ptr, 0, 0, 0);
    m_pclSceneViewer->addPointCloud(range_image_ptr, range_image_color_handler, "123");
    m_pclSceneViewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1, "123");
    m_pclSceneViewer->resetCamera();
    ui->widget_1->update();
}

void Transform::ColorImage()
{

}

void Transform::HeightImage()
{


}

void Transform::GrayImage()
{

}
void Transform::IntensityImage()
{


}
