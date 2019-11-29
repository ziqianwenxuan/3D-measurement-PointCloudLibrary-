#include "feature.h"
#include "ui_feature.h"
#include <pcl/keypoints/iss_3d.h>//关键点检测
#include <pcl/keypoints/sift_keypoint.h>//关键点检测
#include <pcl/keypoints/harris_3D.h>//harris特征点估计类头文件声明
#include <QFileDialog>
#include <pcl/features/shot_omp.h>
#include <QMessageBox>
#include <QDebug>
#include <pcl/filters/statistical_outlier_removal.h>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/filters/passthrough.h>
#include <pcl/filters/voxel_grid.h>
#include <pcl/ModelCoefficients.h>
#include <pcl/registration/icp.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/sample_consensus/method_types.h>
#include <pcl/sample_consensus/model_types.h>
#include <pcl/segmentation/sac_segmentation.h>
#include <pcl/features/range_image_border_extractor.h>
#include <pcl/visualization/range_image_visualizer.h>
#include <pcl/range_image/range_image.h>
#include <pcl/filters/extract_indices.h>
#include <pcl/filters/conditional_removal.h>
#include <pcl/filters/radius_outlier_removal.h>
#include <pcl/filters/crop_hull.h>
#include <pcl/surface/concave_hull.h>
#include <pcl/keypoints/narf_keypoint.h>
#include <pcl/features/narf_descriptor.h>
#include <pcl/point_cloud.h>
#include <pcl/correspondence.h>
#include <pcl/features/normal_3d_omp.h>
#include <pcl/features/shot_omp.h>
#include <pcl/features/board.h>
#include <pcl/keypoints/uniform_sampling.h>
#include <pcl/recognition/cg/hough_3d.h>
#include <pcl/recognition/cg/geometric_consistency.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/kdtree/kdtree_flann.h>
#include <pcl/kdtree/impl/kdtree_flann.hpp>
#include <pcl/common/transforms.h>

//typedef pcl::PointXYZ PointT;
//typedef pcl::PointCloud<PointT> PointCloud;

Feature::Feature(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Feature)
{
    ui->setupUi(this);

    connect(ui->loadSceneBut,SIGNAL(clicked(bool)),this,SLOT(loadScene()));
    connect(ui->executeButton,SIGNAL(clicked(bool)),this,SLOT(ISSKeypoint3D()));

    connect(ui->loadSceneBut_2,SIGNAL(clicked(bool)),this,SLOT(loadScene2()));
    connect(ui->executeButton_2,SIGNAL(clicked(bool)),this,SLOT(SIFTKeypoint()));

    connect(ui->loadSceneBut_3,SIGNAL(clicked(bool)),this,SLOT(loadScene3()));
    connect(ui->executeButton_3,SIGNAL(clicked(bool)),this,SLOT(SHOTKeypoint()));

    connect(ui->loadSceneBut_4,SIGNAL(clicked(bool)),this,SLOT(loadScene4()));
    connect(ui->executeButton_4,SIGNAL(clicked(bool)),this,SLOT(Harris3DKeypoint()));

    connect(ui->loadSceneBut_5,SIGNAL(clicked(bool)),this,SLOT(loadScene5()));
    connect(ui->executeButton_5,SIGNAL(clicked(bool)),this,SLOT(NARFKeypoint()));

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

Feature::~Feature()
{
    delete ui;
}



void Feature::showScene()
{
    if(m_scenePointCloud->points.size() == 0){
        return;
    }

    m_pclSceneViewer->removeAllPointClouds();
    m_pclSceneViewer->addPointCloud(m_scenePointCloud,"cloud2");
    m_pclSceneViewer->resetCamera();
    ui->widget_1->update();

}
void Feature::showScene2()
{
    if(m_scenePointCloud->points.size() == 0){
        return;
    }
    m_pclSceneViewer2->removeAllPointClouds();
    m_pclSceneViewer2->addPointCloud(m_scenePointCloud,"cloud2");
    m_pclSceneViewer2->resetCamera();
    ui->widget_2->update();
}
void Feature::showScene3()
{
    if(m_scenePointCloud->points.size() == 0){
        return;
    }
    m_pclSceneViewer3->removeAllPointClouds();
    m_pclSceneViewer3->addPointCloud(m_scenePointCloud,"cloud2");
    m_pclSceneViewer3->resetCamera();
    ui->widget_3->update();
}
void Feature::showScene4()
{
    if(m_scenePointCloud->points.size() == 0){
        return;
    }
    m_pclSceneViewer4->removeAllPointClouds();
    m_pclSceneViewer4->addPointCloud(m_scenePointCloud,"cloud2");
    m_pclSceneViewer4->resetCamera();
    ui->widget_4->update();
}
void Feature::showScene5()
{
    if(m_scenePointCloud->points.size() == 0){
        return;
    }
    m_pclSceneViewer5->removeAllPointClouds();
    m_pclSceneViewer5->addPointCloud(m_scenePointCloud,"cloud2");
    m_pclSceneViewer5->resetCamera();
    ui->widget_5->update();
}

void Feature::loadScene()
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
void Feature::loadScene2()
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

void Feature::loadScene3()
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
void Feature::loadScene4()
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
void Feature::loadScene5()
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
void Feature::ISSKeypoint3D()
{
     clock_t start = clock();
    //iss关键点提取
    PointCloud::Ptr cloud_src_is(new PointCloud);
    //pcl::PointCloud<pcl::PointXYZ>::Ptr model_keypoint(new pcl::PointCloud<pcl::PointXYZ>());
    pcl::ISSKeypoint3D<pcl::PointXYZ, pcl::PointXYZ> iss_det;
    pcl::search::KdTree<pcl::PointXYZ>::Ptr tree_1(new pcl::search::KdTree<pcl::PointXYZ>());
    double model_solution = ui->MSBox->value();//参数小，采取的关键点多，论文中为500左右
    //参数设置
    iss_det.setSearchMethod(tree_1);
    iss_det.setSalientRadius(ui->SRBox->value());//
    iss_det.setNonMaxRadius(ui->NMRBox->value());//
    iss_det.setThreshold21(ui->TBox->value());
    iss_det.setThreshold32(ui->TBox->value());
    iss_det.setMinNeighbors(ui->MNBBox->value());
    iss_det.setNumberOfThreads(ui->NOTBox->value());
    iss_det.setInputCloud(m_scenePointCloud);
    iss_det.compute(*cloud_src_is);
    clock_t end = clock();
     qDebug() << "iss time:" << (double)(end - start) / CLOCKS_PER_SEC << endl;
     qDebug() << "iss number" << cloud_src_is->size() << endl;
    PointCloud::Ptr cloud_src(new PointCloud);
    pcl::copyPointCloud(*cloud_src_is, *cloud_src);
    pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> icpColor(cloud_src, 0, 255, 0);
    showScene();

    m_pclSceneViewer->removeAllPointClouds();
    m_pclSceneViewer->addPointCloud(m_scenePointCloud,"123");
    m_pclSceneViewer->addPointCloud(cloud_src,icpColor,"456");
    m_pclSceneViewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 7, "456");
    m_pclSceneViewer->resetCamera();
    ui->widget_1->update();
}

namespace pcl
{
  template<>
    struct SIFTKeypointFieldSelector<PointXYZ>
    {
      inline float
      operator () (const PointXYZ &p) const
      {
    return p.z;
      }
    };
}
void Feature::SIFTKeypoint()   //数据；类型转换的困难
{

//pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_xyz (new pcl::PointCloud<pcl::PointXYZ>);
// pcl::io::loadPCDFile("stdmodel.pcd", *cloud_xyz);

     //设定参数值
        const float min_scale = ui->MSBox_2->value(); //设置尺度空间中最小尺度的标准偏差//the standard deviation of the smallest scale in the scale space
        const int n_octaves = ui->SRBox_2->value();//设置高斯金字塔组（octave）的数目//尺度空间层数,小、关键点多
        const int n_scales_per_octave = ui->NMRBox_2->value();//设置每组（octave）计算的尺度 //the number of scales to compute within each octave
        const float min_contrast = ui->TBox_2->value();//设置限制关键点检测的阈值 //根据点云，设置大小，越小关键点越多

        pcl::SIFTKeypoint<pcl::PointXYZ, pcl::PointWithScale> sift;//创建sift关键点检测对象
        pcl::PointCloud<pcl::PointWithScale> result;
        sift.setInputCloud(m_scenePointCloud);//设置输入点云

        pcl::search::KdTree<pcl::PointXYZ>::Ptr tree(new pcl::search::KdTree<pcl::PointXYZ> ());
        sift.setSearchMethod(tree);//创建一个空的kd树对象tree，并把它传递给sift检测对象
        sift.setScales(min_scale, n_octaves, n_scales_per_octave);//指定搜索关键点的尺度范围
        sift.setMinimumContrast(min_contrast);//设置限制关键点检测的阈值
        sift.compute(result);//执行sift关键点检测，保存结果在result

    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_temp (new pcl::PointCloud<pcl::PointXYZ>);
    copyPointCloud(result, *cloud_temp);//将点类型pcl::PointWithScale的数据转换为点类型pcl::PointXYZ的数据

    pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> icpColor(cloud_temp, 0, 255, 0);

    m_pclSceneViewer2->removeAllPointClouds();
    m_pclSceneViewer2->addPointCloud(m_scenePointCloud,"123");
    m_pclSceneViewer2->addPointCloud(cloud_temp,icpColor,"456");
    m_pclSceneViewer2->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 7, "456");
    m_pclSceneViewer2->resetCamera();
    ui->widget_2->update();
}

void Feature::SHOTKeypoint()
{
         //0.做一些声明
    typedef pcl::PointXYZRGBA PointType;
    typedef pcl::Normal NormalType;
    typedef pcl::ReferenceFrame RFType;
    typedef pcl::SHOT352 DescriptorType;
       //00.做一些定义
    pcl::PointCloud<PointType>::Ptr model (new pcl::PointCloud<PointType> ());
    pcl::PointCloud<PointType>::Ptr model_keypoints (new pcl::PointCloud<PointType> ());
    pcl::PointCloud<PointType>::Ptr scene (new pcl::PointCloud<PointType> ());
    pcl::PointCloud<PointType>::Ptr scene_keypoints (new pcl::PointCloud<PointType> ());
    pcl::PointCloud<NormalType>::Ptr model_normals (new pcl::PointCloud<NormalType> ());
    pcl::PointCloud<NormalType>::Ptr scene_normals (new pcl::PointCloud<NormalType> ());
    pcl::PointCloud<DescriptorType>::Ptr model_descriptors (new pcl::PointCloud<DescriptorType> ());
    pcl::PointCloud<DescriptorType>::Ptr scene_descriptors (new pcl::PointCloud<DescriptorType> ());
        //1.首先对点云计算法线。使用的是常规的算法

    pcl::io::loadPCDFile("milk_pose_changed.pcd", *model);

    pcl::NormalEstimationOMP<PointType, NormalType> norm_est;
    norm_est.setKSearch (10);
    norm_est.setInputCloud (model);
    norm_est.compute (*scene_normals);
        //2.使用均匀采样，降低计算量
//    pcl::PointCloud<int> sampled_indices;
//     pcl::UniformSampling<PointType> uniform_sampling;
//     uniform_sampling.setInputCloud (model);
//     uniform_sampling.setRadiusSearch (0.03);
//     uniform_sampling.compute (sampled_indices);
//     pcl::copyPointCloud (*model, sampled_indices.points, *scene_keypoints);
      //3.进行SHOT计算关键点
     pcl::SHOTEstimationOMP<PointType, NormalType, DescriptorType> descr_est;
     descr_est.setRadiusSearch (0.5);

     descr_est.setInputCloud (model);
     descr_est.setInputNormals (scene_normals);
     descr_est.setSearchSurface (model);
     descr_est.compute (*scene_descriptors);
    //4.进行显示操作

     PointCloud::Ptr cloud_src(new PointCloud);
     pcl::copyPointCloud(*scene_descriptors, *cloud_src);
     pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> icpColor(cloud_src, 0, 255, 0);


     m_pclSceneViewer3->removeAllPointClouds();
     m_pclSceneViewer3->addPointCloud(m_scenePointCloud,"123");
     m_pclSceneViewer3->addPointCloud(cloud_src,icpColor,"456");
     m_pclSceneViewer3->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 7, "456");
     m_pclSceneViewer3->resetCamera();
     ui->widget_3->update();
}

void Feature::Harris3DKeypoint()
{
    pcl::PointCloud<pcl::PointXYZI>::Ptr Harris_keypoints (new pcl::PointCloud<pcl::PointXYZI> ());
        pcl::HarrisKeypoint3D<pcl::PointXYZ,pcl::PointXYZI,pcl::Normal>* harris_detector = new pcl::HarrisKeypoint3D<pcl::PointXYZ,pcl::PointXYZI,pcl::Normal> ;
        //harris_detector->setNonMaxSupression(true);
        harris_detector->setRadius(ui->MNBBox_4->value());
        harris_detector->setRadiusSearch(ui->NOTBox_4->value());
        harris_detector->setInputCloud (m_scenePointCloud);
        //harris_detector->setNormals(normal_source);
        //harris_detector->setMethod(pcl::HarrisKeypoint3D<pcl::PointXYZRGB,pcl::PointXYZI>::LOWE);
        harris_detector->compute (*Harris_keypoints);
        pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZI> ColorHandlerT3(Harris_keypoints, 0, 255, 0);
        m_pclSceneViewer4->removeAllPointClouds();
        m_pclSceneViewer4->addPointCloud(m_scenePointCloud,"123");
        m_pclSceneViewer4->addPointCloud(Harris_keypoints,ColorHandlerT3,"456");
        m_pclSceneViewer4->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 3, "456");
        m_pclSceneViewer4->resetCamera();
        ui->widget_4->update();


}

void Feature::NARFKeypoint()
{

   typedef pcl::PointXYZ PointType;
    float angular_resolution = ui->MNBBox_5->value();           ////angular_resolution为模拟的深度传感器的角度分辨率，即深度图像中一个像素对应的角度大小
    float support_size = ui->NOTBox_5->value();                 //点云大小的设置
    pcl::RangeImage::CoordinateFrame coordinate_frame = pcl::RangeImage::CAMERA_FRAME;     //设置坐标系
    bool setUnseenToMaxRange = false;
    bool rotation_invariant = true;
    int tmp_coordinate_frame;
    coordinate_frame = pcl::RangeImage::CoordinateFrame(tmp_coordinate_frame);
    angular_resolution = pcl::deg2rad(angular_resolution);
    pcl::PointCloud<PointType>::Ptr point_cloud_ptr(new pcl::PointCloud<PointType>);
    pcl::PointCloud<PointType>& point_cloud = *m_scenePointCloud;
    pcl::PointCloud<pcl::PointWithViewpoint> far_ranges;
    Eigen::Affine3f scene_sensor_pose(Eigen::Affine3f::Identity());
    float noise_level = ui->MNBBox_6->value();
    float min_range =ui->NOTBox_6->value();
    int border_size = ui->NOTBox_7->value();
    boost::shared_ptr<pcl::RangeImage> range_image_ptr(new pcl::RangeImage);
    pcl::RangeImage& range_image = *range_image_ptr;
    range_image.createFromPointCloud(point_cloud, angular_resolution, pcl::deg2rad(360.0f), pcl::deg2rad(180.0f),
        scene_sensor_pose, coordinate_frame, noise_level, min_range, border_size);
    range_image.integrateFarRanges(far_ranges);
    if (setUnseenToMaxRange)
        range_image.setUnseenToMaxRange();

//查看深度图
//m_pclSceneViewer5->setBackgroundColor(1, 1, 1);
pcl::visualization::PointCloudColorHandlerCustom<pcl::PointWithRange> range_image_color_handler(range_image_ptr, 0, 0, 0);
m_pclSceneViewer5->addPointCloud(range_image_ptr, range_image_color_handler, "range image");
m_pclSceneViewer5->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1, "range image");
m_pclSceneViewer5->resetCamera();
ui->widget_5->update();
//保存深度图
pcl::io::savePCDFileBinary ("output666666.pcd", *range_image_ptr);



pcl::RangeImageBorderExtractor range_image_border_extractor;   //用来提取边缘
pcl::NarfKeypoint narf_keypoint_detector;      //用来检测关键点
narf_keypoint_detector.setRangeImageBorderExtractor(&range_image_border_extractor);   //
narf_keypoint_detector.setRangeImage(&range_image);
narf_keypoint_detector.getParameters().support_size = support_size;    //设置NARF的参数

pcl::PointCloud<int> keypoint_indices;
narf_keypoint_detector.compute(keypoint_indices);

pcl::PointCloud<pcl::PointXYZ>::Ptr keypoints_ptr(new pcl::PointCloud<pcl::PointXYZ>);

pcl::PointCloud<pcl::PointXYZ>& keypoints = *keypoints_ptr;

keypoints.points.resize(keypoint_indices.points.size());
for (size_t i = 0; i<keypoint_indices.points.size(); ++i)
    keypoints.points[i].getVector3fMap() = range_image.points[keypoint_indices.points[i]].getVector3fMap();
pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> keypoints_color_handler(keypoints_ptr, 0, 255, 0);
    m_pclSceneViewer5->removeAllPointClouds();
    m_pclSceneViewer5->addPointCloud(m_scenePointCloud,"123");
m_pclSceneViewer5->addPointCloud<pcl::PointXYZ>(keypoints_ptr, keypoints_color_handler, "keypoints");
m_pclSceneViewer5->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 7, "keypoints");

}




























