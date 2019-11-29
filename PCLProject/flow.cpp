#include "flow.h"
#include "ui_flow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>
#include <pcl/keypoints/sift_keypoint.h>//关键点检测
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
#include <pcl/correspondence.h>   //对应表示两个实体之间的匹配
#include <pcl/features/normal_3d_omp.h> //法线
#include <pcl/features/shot_omp.h>  //描述子
#include <pcl/features/board.h>
#include <pcl/keypoints/uniform_sampling.h> //均匀采样
#include <pcl/recognition/cg/hough_3d.h>   //hough算子
#include <pcl/recognition/cg/geometric_consistency.h> //几何一致性
#include <pcl/visualization/pcl_visualizer.h>   //可视化
#include <pcl/kdtree/kdtree_flann.h>            //配准方法
#include <pcl/kdtree/impl/kdtree_flann.hpp> //KDtree
#include <pcl/common/transforms.h>    //转换矩阵

pcl::PointCloud<PointT>::Ptr m_templatekeypoints (new pcl::PointCloud<PointT>);
pcl::PointCloud<PointT>::Ptr m_scenekeypoints (new pcl::PointCloud<PointT>);
pcl::PointCloud<PointT>::Ptr inputAlignedSAC(new pcl::PointCloud<PointT>);


Flow::Flow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Flow)
{
    ui->setupUi(this);
    connect(ui->loadTemplateBut,SIGNAL(clicked(bool)),this,SLOT(loadTemplate()));
    connect(ui->templateComputeBut,SIGNAL(clicked(bool)),this,SLOT(computeTemplateSIFT()));
    connect(ui->templateComputeBut_2,SIGNAL(clicked(bool)),this,SLOT(computeTemplateNorMal()));
    connect(ui->templateComputeBut_3,SIGNAL(clicked(bool)),this,SLOT(computeTemplateFPFH()));
    connect(ui->loadSceneBut,SIGNAL(clicked(bool)),this,SLOT(loadScene()));
    connect(ui->sceneComputeBut,SIGNAL(clicked(bool)),this,SLOT(computeSceneSIFT()));
    connect(ui->sceneComputeBut_2,SIGNAL(clicked(bool)),this,SLOT(computeSceneNorMal()));
    connect(ui->sceneComputeBut_3,SIGNAL(clicked(bool)),this,SLOT(computeSceneFPFH()));
    connect(ui->executeButton_1,SIGNAL(clicked(bool)),this,SLOT(SAC()));
    connect(ui->executeButton_2,SIGNAL(clicked(bool)),this,SLOT(ICP()));
    connect(ui->loadSceneBut_2,SIGNAL(clicked(bool)),this,SLOT(loadScene2()));
    connect(ui->loadTemplateBut_2,SIGNAL(clicked(bool)),this,SLOT(loadTemplate2()));

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

    m_pclTemplateViewer2 = new pcl::visualization::PCLVisualizer("viewer1",false);
    m_templatePointCloud.reset(new pcl::PointCloud<PointT>);
    m_pclTemplateViewer2->addPointCloud(m_templatePointCloud,"cloud1");
    ui->widget_2->SetRenderWindow(m_pclTemplateViewer2->getRenderWindow());
    m_pclTemplateViewer2->setupInteractor(ui->widget_2->GetInteractor(),ui->widget_2->GetRenderWindow());
    ui->widget_2->update();
    m_pclSceneViewer2 = new pcl::visualization::PCLVisualizer("viewer2",false);
    m_scenePointCloud.reset(new pcl::PointCloud<PointT>);
    m_pclSceneViewer2->addPointCloud(m_scenePointCloud,"cloud2");
    ui->widget_3->SetRenderWindow(m_pclSceneViewer2->getRenderWindow());
    m_pclSceneViewer2->setupInteractor(ui->widget_3->GetInteractor(),ui->widget_3->GetRenderWindow());
    ui->widget_3->update();

}

Flow::~Flow()
{
    delete ui;
}

//pcl::PointCloud<pcl::PointXYZ>::Ptr output_cloud_ndt (new pcl::PointCloud<pcl::PointXYZ>);
//pcl::PointCloud<pcl::PointXYZ>::Ptr output_cloud_dsc (new pcl::PointCloud<pcl::PointXYZ>);
//pcl::PointCloud<pcl::PointXYZ>::Ptr output_cloud_pcs (new pcl::PointCloud<pcl::PointXYZ>);

void Flow::showTemplate()
{
    if(m_templatePointCloud->points.size() == 0){
        return;
    }

    m_pclTemplateViewer->removeAllPointClouds();
    m_pclTemplateViewer->addPointCloud(m_templatePointCloud,"cloud1");
    m_pclTemplateViewer->resetCamera();
    ui->widget->update();
}
void Flow::showTemplate2()
{
    if(m_templatePointCloud->points.size() == 0){
        return;
    }

    m_pclTemplateViewer2->removeAllPointClouds();
    m_pclTemplateViewer2->addPointCloud(m_templatePointCloud,"cloud1");
    m_pclTemplateViewer2->resetCamera();
    ui->widget_2->update();
}

void Flow::showScene()
{
    if(m_scenePointCloud->points.size() == 0){
        return;
    }

    m_pclSceneViewer->removeAllPointClouds();
    m_pclSceneViewer->addPointCloud(m_scenePointCloud,"cloud2");
    m_pclSceneViewer->resetCamera();
    ui->widget_1->update();

}
void Flow::showScene2()
{
    if(m_scenePointCloud->points.size() == 0){
        return;
    }

    m_pclSceneViewer2->removeAllPointClouds();
    m_pclSceneViewer2->addPointCloud(m_scenePointCloud,"cloud2");
    m_pclSceneViewer2->resetCamera();
    ui->widget_3->update();

}

void Flow::loadTemplate()
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
void Flow::loadTemplate2()
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

    showTemplate2();
}

void Flow::loadScene()
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

void Flow::loadScene2()
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

void Flow::computeTemplateSIFT()
{

    pcl::SIFTKeypoint<pcl::PointXYZ, pcl::PointWithScale> sift1;//创建sift关键点检测对象
    float min_scale = ui->MSBox_2->value(); //设置尺度空间中最小尺度的标准偏差//the standard deviation of the smallest scale in the scale space
     int n_octaves = ui->SRBox_2->value();//设置高斯金字塔组（octave）的数目//尺度空间层数,小、关键点多
     int n_scales_per_octave = ui->NMRBox_2->value();//设置每组（octave）计算的尺度 //the number of scales to compute within each octave
     float min_contrast = ui->TBox_2->value();//设置限制关键点检测的阈值 //根据点云，设置大小，越小关键点越多
    sift1.setScales(min_scale, n_octaves, n_scales_per_octave);//指定搜索关键点的尺度范围
    sift1.setMinimumContrast(min_contrast);//设置限制关键点检测的阈值
    sift1.setInputCloud (m_templatePointCloud);
    sift1.compute (Templatekeypoints);
//     pcl::PointCloud<pcl::PointXYZ>::Ptr m_templatekeypoints (new pcl::PointCloud<pcl::PointXYZ>);
     copyPointCloud(Templatekeypoints, *m_templatekeypoints);//将点类型pcl::PointWithScale的数据转换为点类型pcl::PointXYZ的数据
    pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> icpColor(m_templatekeypoints, 0, 255, 0);
    m_pclTemplateViewer->removeAllPointClouds();

    m_pclTemplateViewer->addPointCloud(m_templatePointCloud,"123");
    m_pclTemplateViewer->addPointCloud(m_templatekeypoints,icpColor,"456");
    m_pclTemplateViewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 7, "456");
    m_pclTemplateViewer->resetCamera();
    ui->widget->update();

}

void Flow::computeSceneSIFT()
{
    pcl::SIFTKeypoint<pcl::PointXYZ, pcl::PointWithScale> sift;//创建sift关键点检测对象
    pcl::search::KdTree<pcl::PointXYZ>::Ptr tree(new pcl::search::KdTree<pcl::PointXYZ> ());
    sift.setSearchMethod(tree);
    const float min_scale = ui->MSBox_1->value(); //设置尺度空间中最小尺度的标准偏差//the standard deviation of the smallest scale in the scale space
    const int n_octaves = ui->SRBox_1->value();//设置高斯金字塔组（octave）的数目//尺度空间层数,小、关键点多
    const int n_scales_per_octave = ui->NMRBox_1->value();//设置每组（octave）计算的尺度 //the number of scales to compute within each octave
    const float min_contrast = ui->TBox_1->value();//设置限制关键点检测的阈值 //根据点云，设置大小，越小关键点越多
    sift.setScales(min_scale, n_octaves, n_scales_per_octave);//指定搜索关键点的尺度范围
    sift.setMinimumContrast(min_contrast);//设置限制关键点检测的阈值
    sift.setInputCloud (m_scenePointCloud);
    sift.compute (scenekeypoints);
//    pcl::PointCloud<pcl::PointXYZ>::Ptr m_scenekeypoints (new pcl::PointCloud<pcl::PointXYZ>);
    copyPointCloud(scenekeypoints, *m_scenekeypoints);//将点类型pcl::PointWithScale的数据转换为点类型pcl::PointXYZ的数据
    pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> icpColor(m_scenekeypoints, 0, 255, 0);
    m_pclSceneViewer->removeAllPointClouds();
    m_pclSceneViewer->addPointCloud(m_scenePointCloud,"123");
    m_pclSceneViewer->addPointCloud(m_scenekeypoints,icpColor,"456");
    m_pclSceneViewer->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 7, "456");
    m_pclSceneViewer->resetCamera();
    ui->widget_1->update();

}


void Flow::computeTemplateNorMal()
{

    pcl::NormalEstimation<PointT,pcl::Normal> norEst;
    pcl::search::KdTree<pcl::PointXYZ>::Ptr tree(new pcl::search::KdTree<pcl::PointXYZ> ());
    norEst.setSearchMethod(tree);
    norEst.setInputCloud(m_templatePointCloud);
    norEst.setRadiusSearch(ui->TemplateNRBox->value());
    norEst.compute(*TemplateNormal);
      QMessageBox::information(this,"Info","Success");
}

void Flow::computeSceneNorMal()
{


    pcl::NormalEstimation<PointT,pcl::Normal> norEst;
    pcl::search::KdTree<pcl::PointXYZ>::Ptr tree(new pcl::search::KdTree<pcl::PointXYZ> ());
    norEst.setSearchMethod(tree);
    norEst.setInputCloud(m_scenePointCloud);
    norEst.setRadiusSearch(ui->sceneNRBox->value());
    norEst.compute(*sceneNormal);
      QMessageBox::information(this,"Info","Success");

}
void Flow::computeTemplateFPFH()
{

    pcl::FPFHEstimation<PointT,pcl::Normal,pcl::FPFHSignature33> fpfhEst;
    fpfhEst.setInputCloud(m_templatekeypoints);

    fpfhEst.setInputNormals(TemplateNormal);
    pcl::search::KdTree<pcl::PointXYZ>::Ptr tree(new pcl::search::KdTree<pcl::PointXYZ> ());
    fpfhEst.setSearchMethod(tree);

    fpfhEst.setRadiusSearch(6.75);
    fpfhEst.setSearchSurface(m_templatePointCloud);

    fpfhEst.compute(*TemplateFeatures);
     QMessageBox::information(this,"Info","Success");
}

void Flow::computeSceneFPFH()
{
    pcl::FPFHEstimation<PointT,pcl::Normal,pcl::FPFHSignature33> fpfhEst;
    fpfhEst.setInputCloud(m_scenekeypoints);
    fpfhEst.setInputNormals(sceneNormal);
    pcl::search::KdTree<pcl::PointXYZ>::Ptr tree(new pcl::search::KdTree<pcl::PointXYZ> ());
    fpfhEst.setSearchMethod(tree);
    fpfhEst.setRadiusSearch(6.75);
    fpfhEst.setSearchSurface(m_scenePointCloud);
    fpfhEst.compute(*sceneFeatures);
     QMessageBox::information(this,"Info","Success");
}

void Flow::SAC()
{

    pcl::SampleConsensusInitialAlignment<PointT,PointT,pcl::FPFHSignature33> m_scia;
    m_scia.setMinSampleDistance(ui->minSTSBox->value());
    m_scia.setMaxCorrespondenceDistance(ui->maxCDSBox->value());
    m_scia.setMaximumIterations(ui->maxIterationSBox->value());

    m_scia.setInputTarget(m_templatekeypoints);
    m_scia.setTargetFeatures(TemplateFeatures);
    m_scia.setInputSource(m_scenekeypoints);

    m_scia.setSourceFeatures(sceneFeatures);
    qDebug() << "start align";
    pcl::PointCloud<PointT>::Ptr sciaOut(new pcl::PointCloud<PointT>);
    m_scia.align(*sciaOut);
    qDebug() << "end align";
    qDebug() << "score : " << m_scia.getFitnessScore();
    m_matrix = m_scia.getFinalTransformation();
        qDebug() << "11111111111111111" ;
    transformPointCloud(*m_scenePointCloud, *inputAlignedSAC, m_matrix);
        qDebug() << "22222222222222222" ;
    qDebug() << "matrix : " << m_matrix.rows() << " * " << m_matrix.cols();
    qDebug() << "Transformation : \n"
             << m_matrix(0,0) << "," << m_matrix(0,1) << "," << m_matrix(0,2) << "," << m_matrix(0,3) << "\n"
             << m_matrix(1,0) << "," << m_matrix(1,1) << "," << m_matrix(1,2) << "," << m_matrix(1,3) << "\n"
             << m_matrix(2,0) << "," << m_matrix(2,1) << "," << m_matrix(2,2) << "," << m_matrix(2,3) << "\n"
             << m_matrix(3,0) << "," << m_matrix(3,1) << "," << m_matrix(3,2) << "," << m_matrix(3,3) << "\n";
    qDebug() << "333333333333333" ;
    m_pclTemplateViewer->resetCamera();
    ui->widget->update();

    m_pclSceneViewer->removeAllPointClouds();
    m_pclSceneViewer->addPointCloud(m_templatePointCloud,"cloud2");
    pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> sciaColor(inputAlignedSAC, 0, 255, 0);
    m_pclSceneViewer->addPointCloud(inputAlignedSAC,sciaColor,"icpPoint");
    m_pclSceneViewer->resetCamera();
    ui->widget_1->update();
}

void Flow::ICP()
{
    pcl::IterativeClosestPoint<PointT, PointT> icp;
    icp.setMaximumIterations (ui->icpIterationsSBox->value());//setMaximumIterations

    icp.setTransformationEpsilon (ui->mcdSBox->value());//setTranslationThreshold
    icp.setEuclideanFitnessEpsilon(ui->efeSBox->value());//setRelativeMSE
    icp.setInputSource (m_scenePointCloud);
    icp.setInputTarget (m_templatePointCloud);
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

    m_pclSceneViewer->removeAllPointClouds();
    m_pclSceneViewer->addPointCloud(m_templatePointCloud,"cloud2");
     pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> icpColor(icpPoint, 0, 255, 0);
    m_pclSceneViewer->addPointCloud(icpPoint,icpColor,"icpPoint");
    m_pclSceneViewer->resetCamera();
    ui->widget_1->update();
}
typedef pcl::PointXYZRGBA PointType;
double computeCloudResolution(const pcl::PointCloud<PointType>::ConstPtr &cloud)   //用于实施所给点云的空间分辨率计算，算出输入点云的每个点与其临近点距离的平均值
{
    double res = 0.0;
    int n_points = 0;
    int nres;
    std::vector<int> indices(2);
    std::vector<float> sqr_distances(2);
    pcl::search::KdTree<PointType> tree;
    tree.setInputCloud(cloud);             //设置输入点云

    for (size_t i = 0; i < cloud->size(); ++i)
    {
        if (!pcl_isfinite((*cloud)[i].x))
        {
            continue;
        }
        //Considering the second neighbor since the first is the point itself.
        nres = tree.nearestKSearch(i, 2, indices, sqr_distances);
        if (nres == 2)
        {
            res += sqrt(sqr_distances[1]);
            ++n_points;
        }
    }
    if (n_points != 0)
    {
        res /= n_points;
    }
    return res;


    qDebug() << "aaaaa" <<res;
}
typedef pcl::PointXYZRGBA PointType;  //PointXYZRGBA数据结构
typedef pcl::Normal NormalType;       //法线结构
typedef pcl::ReferenceFrame RFType;    //参考帧
typedef pcl::SHOT352 DescriptorType;   //SHOT特征的数据结构http://www.cnblogs.com/li-yao7758258/p/6612856.html
pcl::PointCloud<PointType>::Ptr model(new pcl::PointCloud<PointType>()); //模型点云
pcl::PointCloud<PointType>::Ptr model_keypoints(new pcl::PointCloud<PointType>());//模型角点
pcl::PointCloud<PointType>::Ptr scene(new pcl::PointCloud<PointType>());  //目标点云
pcl::PointCloud<PointType>::Ptr scene_keypoints(new pcl::PointCloud<PointType>());//目标角点
pcl::PointCloud<NormalType>::Ptr model_normals(new pcl::PointCloud<NormalType>()); //法线
pcl::PointCloud<NormalType>::Ptr scene_normals(new pcl::PointCloud<NormalType>());
pcl::PointCloud<DescriptorType>::Ptr model_descriptors(new pcl::PointCloud<DescriptorType>()); //描述子
pcl::PointCloud<DescriptorType>::Ptr scene_descriptors(new pcl::PointCloud<DescriptorType>());
 pcl::CorrespondencesPtr model_scene_corrs(new pcl::Correspondences());

void Flow::on_pushButton_clicked()   //计算法线并且展示
{
    int ksearch = ui->sceneNRSBox_3->value();
    float model_ss= ui->sceneNRSBox_8->value();
    float scene_ss_= ui->sceneNRSBox_7->value();
    float rf_rad_=  ui->sceneNRSBox_2->value();
    float descr_rad_= ui->sceneNRSBox_4->value();
    float cg_size_= ui->sceneNRSBox_5->value();
    float cg_thresh= ui->sceneNRSBox_6->value();
    int level =ui->sceneNRSBox_10->value(),scale =ui->sceneNRSBox_9->value();

       //1.模型点云和目标点云，理论上都应该是XYZRGBA格式的数据结构。不是的话，copypointcloud 也可以转换

        pcl::copyPointCloud(*m_scenePointCloud, *scene);
        pcl::copyPointCloud(*m_templatePointCloud, *model);

        //计算法线 normalestimationomp估计局部表面特性在每个三个特点，分别表面的法向量和曲率，平行，使用OpenMP标准。//初始化调度程序并设置要使用的线程数（默认为0）。
        pcl::NormalEstimationOMP<PointType, NormalType> norm_est;
        norm_est.setKSearch(ksearch);       //设置K邻域搜索阀值为10个点
        norm_est.setInputCloud(model);  //设置输入点云
        norm_est.compute(*model_normals);   //计算点云法线

        norm_est.setInputCloud(scene);
        norm_est.compute(*scene_normals);

            m_pclTemplateViewer2->removeAllPointClouds();
            pcl::visualization::PointCloudColorHandlerCustom<PointType> model_color_handler(model, 0, 0, 255);
            m_pclTemplateViewer2->addPointCloud(model, model_color_handler, "model_normals");

            m_pclTemplateViewer2->addPointCloudNormals<PointType, pcl::Normal>(model, model_normals, level , scale,"template_normal");
            m_pclTemplateViewer2->resetCamera();
            ui->widget_2->update();

            m_pclSceneViewer2->removeAllPointClouds();
            pcl::visualization::PointCloudColorHandlerCustom<PointType> scene_color_handler(scene, 0, 0, 255);
            m_pclSceneViewer2->addPointCloud(scene, scene_color_handler, "scene_normals");

            m_pclSceneViewer2->addPointCloudNormals<PointType, pcl::Normal>(scene, scene_normals, level , scale,"scene_normal");
            m_pclSceneViewer2->resetCamera();
            ui->widget_3->update();
}

void Flow::on_pushButton_2_clicked()   // 下采样
{
    int ksearch = ui->sceneNRSBox_3->value();
    float model_ss_= ui->sceneNRSBox_8->value();
    float scene_ss_= ui->sceneNRSBox_7->value();
    float rf_rad_=  ui->sceneNRSBox_2->value();
    float descr_rad_= ui->sceneNRSBox_4->value();
    float cg_size_= ui->sceneNRSBox_5->value();
    float cg_thresh= ui->sceneNRSBox_6->value();
    int level =ui->sceneNRSBox_10->value(),scale =ui->sceneNRSBox_9->value();
    //均匀采样点云并提取关键点      体素下采样，重心代替
    pcl::UniformSampling<PointType> uniform_sampling;
    uniform_sampling.setInputCloud(model);  //输入点云
    uniform_sampling.setRadiusSearch(model_ss_);   //设置半径 model_ss_初值是0.01可以通过agv修改
    uniform_sampling.filter(*model_keypoints);   //滤波
    uniform_sampling.setInputCloud(scene);
    uniform_sampling.setRadiusSearch(scene_ss_);
    uniform_sampling.filter(*scene_keypoints);

     str =QString("Demo:")+QString("3D Object Recognition based on Correspondence Grouping" )+QString("\n")+
            QString("Model total points:")+QString::number(model->size()) +QString("; Selected Keypoints: ")+QString::number(model_keypoints->size())+QString("\n")+
             QString("Scene total points:")+QString::number(scene->size()) +QString("; Selected Keypoints: ")+QString::number(scene_keypoints->size())+QString("\n");
ui->label->setText(str);

    m_pclTemplateViewer2->removeAllPointClouds();
    pcl::visualization::PointCloudColorHandlerCustom<PointType> model_color_handler(model, 0, 0, 255);
    m_pclTemplateViewer2->addPointCloud(model, model_color_handler, "model_normals");
    pcl::visualization::PointCloudColorHandlerCustom<PointType> model_color_keypoints(model_keypoints, 255, 0, 0);
    m_pclTemplateViewer2->addPointCloud(model_keypoints, model_color_keypoints, "model_keypoints");
    m_pclTemplateViewer2->resetCamera();
    ui->widget_2->update();

    m_pclSceneViewer2->removeAllPointClouds();
    pcl::visualization::PointCloudColorHandlerCustom<PointType> scene_color_handler(scene, 0, 0, 255);
    m_pclSceneViewer2->addPointCloud(scene, scene_color_handler, "scene_normals");
    pcl::visualization::PointCloudColorHandlerCustom<PointType> scene_color_keypoints(scene_keypoints, 255, 0, 0);
    m_pclSceneViewer2->addPointCloud(scene_keypoints, scene_color_keypoints, "scene_keypoints");
    m_pclSceneViewer2->resetCamera();
    ui->widget_3->update();

}

void Flow::on_pushButton_3_clicked()      //为关键点计算描述子
{

    int ksearch = ui->sceneNRSBox_3->value();
    float model_ss_= ui->sceneNRSBox_8->value();
    float scene_ss_= ui->sceneNRSBox_7->value();
    float rf_rad_=  ui->sceneNRSBox_2->value();
    float descr_rad_= ui->sceneNRSBox_4->value();
    float cg_size_= ui->sceneNRSBox_5->value();
    float cg_thresh= ui->sceneNRSBox_6->value();
    int level =ui->sceneNRSBox_10->value(),scale =ui->sceneNRSBox_9->value();
    //均匀采样点云并提取关键点      体素下采样，重心代替

    pcl::SHOTEstimationOMP<PointType, NormalType, DescriptorType> descr_est;
    descr_est.setRadiusSearch(descr_rad_);  //设置搜索半径
    descr_est.setInputCloud(model_keypoints);  //输入模型的关键点
    descr_est.setInputNormals(model_normals);  //输入模型的法线
    descr_est.setSearchSurface(model);         //输入的点云
    descr_est.compute(*model_descriptors);     //计算描述子
    descr_est.setInputCloud(scene_keypoints);  //同理
    descr_est.setInputNormals(scene_normals);
    descr_est.setSearchSurface(scene);
    descr_est.compute(*scene_descriptors);

    str += QString("model_descriptors:")+QString::number(model_descriptors->size())+QString("\n")+
            QString("scene_descriptors:")+QString::number(scene_descriptors->size())+QString("\n");
    ui->label->setText(str);
QMessageBox::information(this,"Info","为关键点计算描述子Success");
}

void Flow::on_pushButton_4_clicked()   //  使用Kdtree找出 Model-Scene 匹配点
{

    int ksearch = ui->sceneNRSBox_3->value();
    float model_ss_= ui->sceneNRSBox_8->value();
    float scene_ss_= ui->sceneNRSBox_7->value();
    float rf_rad_=  ui->sceneNRSBox_2->value();
    float descr_rad_= ui->sceneNRSBox_4->value();
    float cg_size_= ui->sceneNRSBox_5->value();
    float cg_thresh= ui->sceneNRSBox_6->value();
    int level =ui->sceneNRSBox_10->value(),scale =ui->sceneNRSBox_9->value();

   //1.模型点云和目标点云，理论上都应该是XYZRGBA格式的数据结构。不是的话，copypointcloud 也可以转换

    pcl::copyPointCloud(*m_scenePointCloud, *scene);
    pcl::copyPointCloud(*m_templatePointCloud, *model);

    //计算法线 normalestimationomp估计局部表面特性在每个三个特点，分别表面的法向量和曲率，平行，使用OpenMP标准。//初始化调度程序并设置要使用的线程数（默认为0）。
    pcl::NormalEstimationOMP<PointType, NormalType> norm_est;
    norm_est.setKSearch(10);       //设置K邻域搜索阀值为10个点
    norm_est.setInputCloud(model);  //设置输入点云
    norm_est.compute(*model_normals);   //计算点云法线
    norm_est.setInputCloud(scene);
    norm_est.compute(*scene_normals);
    //计算法线
    //均匀采样点云并提取关键点      体素下采样，重心代替
    pcl::UniformSampling<PointType> uniform_sampling;
    uniform_sampling.setInputCloud(model);  //输入点云
    uniform_sampling.setRadiusSearch(model_ss_);   //设置半径 model_ss_初值是0.01可以通过agv修改
    uniform_sampling.filter(*model_keypoints);   //滤波
    uniform_sampling.setInputCloud(scene);
    uniform_sampling.setRadiusSearch(scene_ss_);
    uniform_sampling.filter(*scene_keypoints);

    QString str =QString("Demo:")+QString("3D Object Recognition based on Correspondence Grouping" )+QString("\n")+
            QString("Model total points:")+QString::number(model->size()) +QString("; Selected Keypoints: ")+QString::number(model_keypoints->size())+QString("\n")+
             QString("Scene total points:")+QString::number(scene->size()) +QString("; Selected Keypoints: ")+QString::number(scene->size())+QString("\n");


    //均匀采样点云并提取关键点      体素下采样，重心代替
    //为关键点计算描述子
    pcl::SHOTEstimationOMP<PointType, NormalType, DescriptorType> descr_est;
    descr_est.setRadiusSearch(descr_rad_);  //设置搜索半径
    descr_est.setInputCloud(model_keypoints);  //输入模型的关键点
    descr_est.setInputNormals(model_normals);  //输入模型的法线
    descr_est.setSearchSurface(model);         //输入的点云
    descr_est.compute(*model_descriptors);     //计算描述子
    descr_est.setInputCloud(scene_keypoints);  //同理
    descr_est.setInputNormals(scene_normals);
    descr_est.setSearchSurface(scene);
    descr_est.compute(*scene_descriptors);
    //  使用Kdtree找出 Model-Scene 匹配点
    pcl::CorrespondencesPtr model_scene_corrs(new pcl::Correspondences());
    pcl::KdTreeFLANN<DescriptorType> match_search;   //设置配准的方法
    match_search.setInputCloud(model_descriptors);  //输入模板点云的描述子
                                                   //每一个场景的关键点描述子都要找到模板中匹配的关键点描述子并将其添加到对应的匹配向量中。
    for (size_t i = 0; i < scene_descriptors->size(); ++i)
    {
        std::vector<int> neigh_indices(1);   //设置最近邻点的索引
        std::vector<float> neigh_sqr_dists(1); //申明最近邻平方距离值
        if (!pcl_isfinite(scene_descriptors->at(i).descriptor[0])) //忽略 NaNs点
        {
            continue;
        }
        int found_neighs = match_search.nearestKSearch(scene_descriptors->at(i), 1, neigh_indices, neigh_sqr_dists);
        //scene_descriptors->at (i)是给定点云 1是临近点个数 ，neigh_indices临近点的索引  neigh_sqr_dists是与临近点的索引

        if (found_neighs == 1 && neigh_sqr_dists[0] < 0.25f) // 仅当描述子与临近点的平方距离小于0.25（描述子与临近的距离在一般在0到1之间）才添加匹配
        {
            //neigh_indices[0]给定点，  i  是配准数  neigh_sqr_dists[0]与临近点的平方距离
            pcl::Correspondence corr(neigh_indices[0], static_cast<int> (i), neigh_sqr_dists[0]);
            model_scene_corrs->push_back(corr);   //把配准的点存储在容器中
        }
    }


  str +=QString("Correspondences found(最终配准的点数):")+QString::number(model_scene_corrs->size());
  ui->label->setText(str);

QMessageBox::information(this,"Info","使用Kdtree找出 Model-Scene匹配点Success");
}

void Flow::on_pushButton_5_clicked()   //霍夫聚类算法
{
    int ksearch = ui->sceneNRSBox_3->value();
    float model_ss_= ui->sceneNRSBox_8->value();
    float scene_ss_= ui->sceneNRSBox_7->value();
    float rf_rad_=  ui->sceneNRSBox_2->value();
    float descr_rad_= ui->sceneNRSBox_4->value();
    float cg_size_= ui->sceneNRSBox_5->value();
    float cg_thresh_= ui->sceneNRSBox_6->value();
    int level =ui->sceneNRSBox_10->value(),scale =ui->sceneNRSBox_9->value();
    //1.模型点云和目标点云，理论上都应该是XYZRGBA格式的数据结构。不是的话，copypointcloud 也可以转换

     pcl::copyPointCloud(*m_scenePointCloud, *scene);
     pcl::copyPointCloud(*m_templatePointCloud, *model);

     //计算法线 normalestimationomp估计局部表面特性在每个三个特点，分别表面的法向量和曲率，平行，使用OpenMP标准。//初始化调度程序并设置要使用的线程数（默认为0）。
     pcl::NormalEstimationOMP<PointType, NormalType> norm_est;
     norm_est.setKSearch(ksearch);       //设置K邻域搜索阀值为10个点
     norm_est.setInputCloud(model);  //设置输入点云
     norm_est.compute(*model_normals);   //计算点云法线
     norm_est.setInputCloud(scene);
     norm_est.compute(*scene_normals);
     //计算法线
     //均匀采样点云并提取关键点      体素下采样，重心代替
     pcl::UniformSampling<PointType> uniform_sampling;
     uniform_sampling.setInputCloud(model);  //输入点云
     uniform_sampling.setRadiusSearch(model_ss_);   //设置半径 model_ss_初值是0.01可以通过agv修改
     uniform_sampling.filter(*model_keypoints);   //滤波
     uniform_sampling.setInputCloud(scene);
     uniform_sampling.setRadiusSearch(scene_ss_);
     uniform_sampling.filter(*scene_keypoints);

     QString str =QString("Demo:")+QString("3D Object Recognition based on Correspondence Grouping" )+QString("\n")+
             QString("Model total points:")+QString::number(model->size()) +QString("; Selected Keypoints: ")+QString::number(model_keypoints->size())+QString("\n")+
              QString("Scene total points:")+QString::number(scene->size()) +QString("; Selected Keypoints: ")+QString::number(scene_keypoints->size())+QString("\n");


     //均匀采样点云并提取关键点      体素下采样，重心代替
     //为关键点计算描述子
     pcl::SHOTEstimationOMP<PointType, NormalType, DescriptorType> descr_est;
     descr_est.setRadiusSearch(descr_rad_);  //设置搜索半径
     descr_est.setInputCloud(model_keypoints);  //输入模型的关键点
     descr_est.setInputNormals(model_normals);  //输入模型的法线
     descr_est.setSearchSurface(model);         //输入的点云
     descr_est.compute(*model_descriptors);     //计算描述子
     descr_est.setInputCloud(scene_keypoints);  //同理
     descr_est.setInputNormals(scene_normals);
     descr_est.setSearchSurface(scene);
     descr_est.compute(*scene_descriptors);

     //  使用Kdtree找出 Model-Scene 匹配点
     pcl::CorrespondencesPtr model_scene_corrs(new pcl::Correspondences());
     pcl::KdTreeFLANN<DescriptorType> match_search;   //设置配准的方法
     match_search.setInputCloud(model_descriptors);  //输入模板点云的描述子
  //每一个场景的关键点描述子都要找到模板中匹配的关键点描述子并将其添加到对应的匹配向量中。
     //这是一个  从场景中寻的的 思路
     for (size_t i = 0; i < scene_descriptors->size(); ++i)
     {
         std::vector<int> neigh_indices(1);   //设置最近邻点的索引
         std::vector<float> neigh_sqr_dists(1); //申明最近邻平方距离值
         if (!pcl_isfinite(scene_descriptors->at(i).descriptor[0])) //忽略 NaNs点
         {
             continue;
         }
         int found_neighs = match_search.nearestKSearch(scene_descriptors->at(i), 1, neigh_indices, neigh_sqr_dists);
         //scene_descriptors->at (i)是给定点云 1是临近点个数 ，neigh_indices临近点的索引  neigh_sqr_dists是与临近点的索引

         if (found_neighs == 1 && neigh_sqr_dists[0] < 0.25f) // 仅当描述子与临近点的平方距离小于0.25（描述子与临近的距离在一般在0到1之间）才添加匹配
         {
             //neigh_indices[0]给定点，  i  是配准数  neigh_sqr_dists[0]与临近点的平方距离
             pcl::Correspondence corr(neigh_indices[0], static_cast<int> (i), neigh_sqr_dists[0]);
             model_scene_corrs->push_back(corr);   //把配准的点存储在容器中

         }
     }
    //  实际的配准方法的实现
    std::vector<Eigen::Matrix4f, Eigen::aligned_allocator<Eigen::Matrix4f> > rototranslations;
    std::vector<pcl::Correspondences> clustered_corrs;
    //  使用 Hough3D算法寻找匹配点
        //  Compute (Keypoints) Reference Frames only for Hough
        //计算参考帧的Hough（也就是关键点）

        pcl::PointCloud<RFType>::Ptr model_rf(new pcl::PointCloud<RFType>());
        pcl::PointCloud<RFType>::Ptr scene_rf(new pcl::PointCloud<RFType>());
        //特征估计的方法（点云，法线，参考帧）
        pcl::BOARDLocalReferenceFrameEstimation<PointType, NormalType, RFType> rf_est;
        rf_est.setFindHoles(true);
        rf_est.setRadiusSearch(rf_rad_);   //设置搜索半径

        rf_est.setInputCloud(model_keypoints);  //模型关键点
        rf_est.setInputNormals(model_normals); //模型法线
        rf_est.setSearchSurface(model);    //模型
        rf_est.compute(*model_rf);      //模型的参考帧

        rf_est.setInputCloud(scene_keypoints);  //同理
        rf_est.setInputNormals(scene_normals);
        rf_est.setSearchSurface(scene);
        rf_est.compute(*scene_rf);

        //  Clustering聚类的方法

        //对输入点与的聚类，以区分不同的实例的场景中的模型
        pcl::Hough3DGrouping<PointType, PointType, RFType, RFType> clusterer;
        clusterer.setHoughBinSize(cg_size_);//霍夫空间设置每个bin的大小
        clusterer.setHoughThreshold(cg_thresh_);//阀值
        clusterer.setUseInterpolation(true);
        clusterer.setUseDistanceWeight(false);
        clusterer.setInputCloud(model_keypoints);
        clusterer.setInputRf(model_rf);   //设置输入的参考帧
        clusterer.setSceneCloud(scene_keypoints);
        clusterer.setSceneRf(scene_rf);
        clusterer.setModelSceneCorrespondences(model_scene_corrs);//model_scene_corrs  存储配准的点，就是一一对应的关系点   都是 Correspondences类型的

                                                                  //clusterer.cluster (clustered_corrs);辨认出聚类的对象
        //rototranslations   是一个矩阵
        clusterer.recognize(rototranslations, clustered_corrs);
 qDebug() << "rototranslations" << rototranslations.size()<< endl;

str += QString("Correspondences found: ")+QString::number(model_scene_corrs->size())+QString("\n")+
             QString("使用3d hough 匹配方法 ")+QString("\n")+
             QString("rototranslations.size: ")+QString::number(rototranslations.size())+QString("\n")+
             QString("clustered_corrs[0].size.size: ")+QString::number(clustered_corrs[0].size())+QString("\n");

    for (size_t i = 0; i < rototranslations.size(); ++i)
        {
            qDebug() << "\n    Instance " << i + 1 << ":" << endl;
            qDebug() << "        Correspondences belonging to this instance: " << clustered_corrs[i].size() << endl;
            qDebug() << "        Correspondences belonging to this instance: " << clustered_corrs[0].size() << endl;

            // 打印处相对于输入模型的旋转矩阵与平移矩阵
            Eigen::Matrix3f rotation = rototranslations[i].block<3, 3>(0, 0);
            Eigen::Vector3f translation = rototranslations[i].block<3, 1>(0, 3);
str +=  QString("rotation : ")+QString("\n")+
            QString::number(rotation(0,0))+QString("  ")+QString::number(rotation(0,1))+QString("  ")+QString::number(rotation(0,2))+QString("\n")+
            QString::number(rotation(1,0))+QString("  ")+QString::number(rotation(1,1))+QString("  ")+QString::number(rotation(1,2))+QString("\n")+
            QString::number(rotation(2,0))+QString("  ")+QString::number(rotation(2,1))+QString("  ")+QString::number(rotation(2,2))+QString("\n")+
            QString("translation : ")+QString("\n")+
            QString::number(translation(0))+QString("  ")+QString::number(translation(1))+QString("  ")+QString::number(translation(2))+QString("\n");

ui->label->setText(str);
        }

m_pclSceneViewer2->addPointCloud(scene, "scene_cloud");//可视化场景点云
//   用绿色表示的是位移之后的model
pcl::PointCloud<PointType>::Ptr off_scene_model(new pcl::PointCloud<PointType>());
pcl::PointCloud<PointType>::Ptr off_scene_model_keypoints(new pcl::PointCloud<PointType>());
pcl::transformPointCloud(*model, *off_scene_model, Eigen::Vector3f(0, 0, 0), Eigen::Quaternionf(1, 0, 0, 0));
pcl::transformPointCloud(*model_keypoints, *off_scene_model_keypoints, Eigen::Vector3f(0, 0, 0), Eigen::Quaternionf(1, 0, 0, 0));
pcl::visualization::PointCloudColorHandlerCustom<PointType> off_scene_model_color_handler(off_scene_model, 0, 255, 0);
m_pclSceneViewer2->addPointCloud(off_scene_model, off_scene_model_color_handler, "off_scene_model");

//m_pclSceneViewer2->addCorrespondences<pcl::PointXYZ>(m_scenePointCloud, m_templatePointCloud, model_scene_corrs, "initial");   数据结构无法转变

//关键点    用蓝色表示关键点  均匀采样形成的
pcl::visualization::PointCloudColorHandlerCustom<PointType> scene_keypoints_color_handler(scene_keypoints, 0, 0, 255);
m_pclSceneViewer2->addPointCloud(scene_keypoints, scene_keypoints_color_handler, "scene_keypoints");
m_pclSceneViewer2->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 5, "scene_keypoints");

pcl::visualization::PointCloudColorHandlerCustom<PointType> off_scene_model_keypoints_color_handler(off_scene_model_keypoints, 0, 0, 255);
m_pclSceneViewer2->addPointCloud(off_scene_model_keypoints, off_scene_model_keypoints_color_handler, "off_scene_model_keypoints");
m_pclSceneViewer2->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 5, "off_scene_model_keypoints");
pcl::visualization::PointCloudColorHandlerRGBField<PointType> rgb(scene);
m_pclSceneViewer2->addPointCloud(scene, rgb, "The Scene");
for (size_t i = 0; i < rototranslations.size(); ++i)
  {
      pcl::PointCloud<PointType>::Ptr rotated_model(new pcl::PointCloud<PointType>());
      pcl::transformPointCloud(*model, *rotated_model, rototranslations[i]);
      std::stringstream ss_cloud;
      ss_cloud << "instance" << i;

      pcl::visualization::PointCloudColorHandlerCustom<PointType> rotated_model_color_handler(rotated_model, 255, 0, 0);
      m_pclSceneViewer2->addPointCloud(rotated_model, rotated_model_color_handler, ss_cloud.str());

          for (size_t j = 0; j < clustered_corrs[i].size(); ++j)
          {
              std::stringstream ss_line;
              ss_line << "correspondence_line" << i << "_" << j;
              PointType& model_point = off_scene_model_keypoints->at(clustered_corrs[i][j].index_query);
              PointType& scene_point = scene_keypoints->at(clustered_corrs[i][j].index_match);
              //  We are drawing a line for each pair of clustered correspondences found between the model and the scene 我们正在为模型和场景之间发现的每对集群对应关系画一条线
              m_pclSceneViewer2->addLine<PointType, PointType>(model_point, scene_point, 89, 255, 0, ss_line.str());

          }

   }

ui->label->setText(str);

m_pclSceneViewer2->resetCamera();
ui->widget_3->update();

}

void Flow::on_pushButton_6_clicked()
{
    typedef pcl::PointXYZRGBA PointType;  //PointXYZRGBA数据结构
    typedef pcl::Normal NormalType;       //法线结构
    typedef pcl::ReferenceFrame RFType;    //参考帧
    typedef pcl::SHOT352 DescriptorType;   //SHOT特征的数据结构http://www.cnblogs.com/li-yao7758258/p/6612856.html
    //Algorithm params
//    float model_ss_(0.03f);
//    float scene_ss_(0.02f);
//    float rf_rad_(0.015f);
//    float descr_rad_(0.045f);
//    float cg_size_(0.05f);
//    float cg_thresh_(5.0f);
    int ksearch = ui->sceneNRSBox_3->value();
    float model_ss_= ui->sceneNRSBox_8->value();
    float scene_ss_= ui->sceneNRSBox_7->value();
    float rf_rad_=  ui->sceneNRSBox_2->value();
    float descr_rad_= ui->sceneNRSBox_4->value();
    float cg_size_= ui->sceneNRSBox_5->value();
    float cg_thresh_= ui->sceneNRSBox_6->value();
    int level =ui->sceneNRSBox_10->value(),scale =ui->sceneNRSBox_9->value();

        pcl::PointCloud<PointType>::Ptr model(new pcl::PointCloud<PointType>()); //模型点云
        pcl::PointCloud<PointType>::Ptr model_keypoints(new pcl::PointCloud<PointType>());//模型角点
        pcl::PointCloud<PointType>::Ptr scene(new pcl::PointCloud<PointType>());  //目标点云
        pcl::PointCloud<PointType>::Ptr scene_keypoints(new pcl::PointCloud<PointType>());//目标角点
        pcl::PointCloud<NormalType>::Ptr model_normals(new pcl::PointCloud<NormalType>()); //法线
        pcl::PointCloud<NormalType>::Ptr scene_normals(new pcl::PointCloud<NormalType>());
        pcl::PointCloud<DescriptorType>::Ptr model_descriptors(new pcl::PointCloud<DescriptorType>()); //描述子
        pcl::PointCloud<DescriptorType>::Ptr scene_descriptors(new pcl::PointCloud<DescriptorType>());
       //1.模型点云和目标点云，理论上都应该是XYZRGBA格式的数据结构。不是的话，copypointcloud 也可以转换
//        if (pcl::io::loadPCDFile("milk_pose_changed.pcd", *model) < 0)
//        {
//            std::cout << "Error loading model cloud." << std::endl;

//        }
//        if (pcl::io::loadPCDFile("milk_cartoon_all_small_clorox.pcd", *scene) < 0)
//        {
//            std::cout << "Error loading scene cloud." << std::endl;

//        }
        pcl::copyPointCloud(*m_scenePointCloud, *scene);
        pcl::copyPointCloud(*m_templatePointCloud, *model);

        //计算法线 normalestimationomp估计局部表面特性在每个三个特点，分别表面的法向量和曲率，平行，使用OpenMP标准。//初始化调度程序并设置要使用的线程数（默认为0）。
        pcl::NormalEstimationOMP<PointType, NormalType> norm_est;
        norm_est.setKSearch(10);       //设置K邻域搜索阀值为10个点
        norm_est.setInputCloud(model);  //设置输入点云
        norm_est.compute(*model_normals);   //计算点云法线
        norm_est.setInputCloud(scene);
        norm_est.compute(*scene_normals);
        //计算法线
        //均匀采样点云并提取关键点      体素下采样，重心代替
        pcl::UniformSampling<PointType> uniform_sampling;
        uniform_sampling.setInputCloud(model);  //输入点云
        uniform_sampling.setRadiusSearch(model_ss_);   //设置半径 model_ss_初值是0.01可以通过agv修改
        uniform_sampling.filter(*model_keypoints);   //滤波
        uniform_sampling.setInputCloud(scene);
        uniform_sampling.setRadiusSearch(scene_ss_);
        uniform_sampling.filter(*scene_keypoints);

        QString str =QString("Demo:")+QString("3D Object Recognition based on Correspondence Grouping" )+QString("\n")+
                QString("Model total points:")+QString::number(model->size()) +QString("; Selected Keypoints: ")+QString::number(model_keypoints->size())+QString("\n")+
                 QString("Scene total points:")+QString::number(scene->size()) +QString("; Selected Keypoints: ")+QString::number(scene->size())+QString("\n");


        //均匀采样点云并提取关键点      体素下采样，重心代替
        //为关键点计算描述子
        pcl::SHOTEstimationOMP<PointType, NormalType, DescriptorType> descr_est;
        descr_est.setRadiusSearch(descr_rad_);  //设置搜索半径
        descr_est.setInputCloud(model_keypoints);  //输入模型的关键点
        descr_est.setInputNormals(model_normals);  //输入模型的法线
        descr_est.setSearchSurface(model);         //输入的点云
        descr_est.compute(*model_descriptors);     //计算描述子
        descr_est.setInputCloud(scene_keypoints);  //同理
        descr_est.setInputNormals(scene_normals);
        descr_est.setSearchSurface(scene);
        descr_est.compute(*scene_descriptors);
        //  使用Kdtree找出 Model-Scene 匹配点
        pcl::CorrespondencesPtr model_scene_corrs(new pcl::Correspondences());
        pcl::KdTreeFLANN<DescriptorType> match_search;   //设置配准的方法
        match_search.setInputCloud(model_descriptors);  //输入模板点云的描述子
                                                       //每一个场景的关键点描述子都要找到模板中匹配的关键点描述子并将其添加到对应的匹配向量中。
        for (size_t i = 0; i < scene_descriptors->size(); ++i)
        {
            std::vector<int> neigh_indices(1);   //设置最近邻点的索引
            std::vector<float> neigh_sqr_dists(1); //申明最近邻平方距离值
            if (!pcl_isfinite(scene_descriptors->at(i).descriptor[0])) //忽略 NaNs点
            {
                continue;
            }
            int found_neighs = match_search.nearestKSearch(scene_descriptors->at(i), 1, neigh_indices, neigh_sqr_dists);
            //scene_descriptors->at (i)是给定点云 1是临近点个数 ，neigh_indices临近点的索引  neigh_sqr_dists是与临近点的索引

            if (found_neighs == 1 && neigh_sqr_dists[0] < 0.25f) // 仅当描述子与临近点的平方距离小于0.25（描述子与临近的距离在一般在0到1之间）才添加匹配
            {
                //neigh_indices[0]给定点，  i  是配准数  neigh_sqr_dists[0]与临近点的平方距离
                pcl::Correspondence corr(neigh_indices[0], static_cast<int> (i), neigh_sqr_dists[0]);
                model_scene_corrs->push_back(corr);   //把配准的点存储在容器中
            }
        }
        //  实际的配准方法的实现
        std::vector<Eigen::Matrix4f, Eigen::aligned_allocator<Eigen::Matrix4f> > rototranslations;
        std::vector<pcl::Correspondences> clustered_corrs;
        //  使用 Hough3D算法寻找匹配点
            //
            //  Compute (Keypoints) Reference Frames only for Hough
            //计算参考帧的Hough（也就是关键点）

            pcl::PointCloud<RFType>::Ptr model_rf(new pcl::PointCloud<RFType>());
            pcl::PointCloud<RFType>::Ptr scene_rf(new pcl::PointCloud<RFType>());
            //特征估计的方法（点云，法线，参考帧）
            pcl::BOARDLocalReferenceFrameEstimation<PointType, NormalType, RFType> rf_est;
            rf_est.setFindHoles(true);
            rf_est.setRadiusSearch(rf_rad_);   //设置搜索半径

            rf_est.setInputCloud(model_keypoints);  //模型关键点
            rf_est.setInputNormals(model_normals); //模型法线
            rf_est.setSearchSurface(model);    //模型
            rf_est.compute(*model_rf);      //模型的参考帧

            rf_est.setInputCloud(scene_keypoints);  //同理
            rf_est.setInputNormals(scene_normals);
            rf_est.setSearchSurface(scene);
            rf_est.compute(*scene_rf);

            //  Clustering聚类的方法

            //对输入点与的聚类，以区分不同的实例的场景中的模型
            pcl::Hough3DGrouping<PointType, PointType, RFType, RFType> clusterer;
            clusterer.setHoughBinSize(cg_size_);//霍夫空间设置每个bin的大小
            clusterer.setHoughThreshold(cg_thresh_);//阀值
            clusterer.setUseInterpolation(true);
            clusterer.setUseDistanceWeight(false);

            clusterer.setInputCloud(model_keypoints);
            clusterer.setInputRf(model_rf);   //设置输入的参考帧
            clusterer.setSceneCloud(scene_keypoints);
            clusterer.setSceneRf(scene_rf);
            clusterer.setModelSceneCorrespondences(model_scene_corrs);//model_scene_corrs存储配准的点

                                                                      //clusterer.cluster (clustered_corrs);辨认出聚类的对象
            clusterer.recognize(rototranslations, clustered_corrs);

  str += QString("Correspondences found: ")+QString::number(model_scene_corrs->size())+QString("\n")+
                 QString("使用3d hough 匹配方法 ")+QString("\n")+
                 QString("rototranslations.size: ")+QString::number(rototranslations.size())+QString("\n")+
                 QString("clustered_corrs[0].size.size: ")+QString::number(clustered_corrs[0].size())+QString("\n");

        for (size_t i = 0; i < rototranslations.size(); ++i)
            {
                qDebug() << "\n    Instance " << i + 1 << ":" << endl;
                qDebug() << "        Correspondences belonging to this instance: " << clustered_corrs[i].size() << endl;
                qDebug() << "        Correspondences belonging to this instance: " << clustered_corrs[0].size() << endl;

                // 打印处相对于输入模型的旋转矩阵与平移矩阵
                Eigen::Matrix3f rotation = rototranslations[i].block<3, 3>(0, 0);
                Eigen::Vector3f translation = rototranslations[i].block<3, 1>(0, 3);

    str +=  QString("rotation : ")+QString("\n")+
                QString::number(rotation(0,0))+QString("  ")+QString::number(rotation(0,1))+QString("  ")+QString::number(rotation(0,2))+QString("\n")+
                QString::number(rotation(1,0))+QString("  ")+QString::number(rotation(1,1))+QString("  ")+QString::number(rotation(1,2))+QString("\n")+
                QString::number(rotation(2,0))+QString("  ")+QString::number(rotation(2,1))+QString("  ")+QString::number(rotation(2,2))+QString("\n")+
                QString("translation : ")+QString("\n")+
                QString::number(translation(0))+QString("  ")+QString::number(translation(1))+QString("  ")+QString::number(translation(2))+QString("\n");
ui->label->setText(str);

            }

m_pclSceneViewer2->addPointCloud(scene, "scene_cloud");//可视化场景点云
 //   用绿色表示的是位移之后的model
  pcl::PointCloud<PointType>::Ptr off_scene_model(new pcl::PointCloud<PointType>());
  pcl::PointCloud<PointType>::Ptr off_scene_model_keypoints(new pcl::PointCloud<PointType>());
  pcl::transformPointCloud(*model, *off_scene_model, Eigen::Vector3f(0, 0, 0), Eigen::Quaternionf(1, 0, 0, 0));
  pcl::transformPointCloud(*model_keypoints, *off_scene_model_keypoints, Eigen::Vector3f(0, 0, 0), Eigen::Quaternionf(1, 0, 0, 0));
  pcl::visualization::PointCloudColorHandlerCustom<PointType> off_scene_model_color_handler(off_scene_model, 0, 255, 0);   //绿色表示的是模板转移后的位置
  m_pclSceneViewer2->addPointCloud(off_scene_model, off_scene_model_color_handler, "off_scene_model");

  //m_pclSceneViewer2->addCorrespondences<pcl::PointXYZ>(m_scenePointCloud, m_templatePointCloud, model_scene_corrs, "initial");   数据结构无法转变

  //关键点    用蓝色表示关键点  均匀采样形成的
  pcl::visualization::PointCloudColorHandlerCustom<PointType> scene_keypoints_color_handler(scene_keypoints, 0, 0, 255);   //场景关键点蓝色
  m_pclSceneViewer2->addPointCloud(scene_keypoints, scene_keypoints_color_handler, "scene_keypoints");
  m_pclSceneViewer2->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 5, "scene_keypoints");

  pcl::visualization::PointCloudColorHandlerCustom<PointType> off_scene_model_keypoints_color_handler(off_scene_model_keypoints, 0, 0, 255);//模板关键点蓝色
  m_pclSceneViewer2->addPointCloud(off_scene_model_keypoints, off_scene_model_keypoints_color_handler, "off_scene_model_keypoints");
  m_pclSceneViewer2->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 5, "off_scene_model_keypoints");
  pcl::visualization::PointCloudColorHandlerRGBField<PointType> rgb(scene);
  m_pclSceneViewer2->addPointCloud(scene, rgb, "The Scene");
  for (size_t i = 0; i < rototranslations.size(); ++i)
      {
          pcl::PointCloud<PointType>::Ptr rotated_model(new pcl::PointCloud<PointType>());
          pcl::transformPointCloud(*model, *rotated_model, rototranslations[i]);
          std::stringstream ss_cloud;
          ss_cloud << "instance" << i;

          pcl::visualization::PointCloudColorHandlerCustom<PointType> rotated_model_color_handler(rotated_model, 255, 0, 0);   // 使用红色表示旋转后的模板（融入到场景中）
          m_pclSceneViewer2->addPointCloud(rotated_model, rotated_model_color_handler, ss_cloud.str());

              for (size_t j = 0; j < clustered_corrs[i].size(); ++j)
              {
                  std::stringstream ss_line;
                  ss_line << "correspondence_line" << i << "_" << j;
                  PointType& model_point = off_scene_model_keypoints->at(clustered_corrs[i][j].index_query);
                  PointType& scene_point = scene_keypoints->at(clustered_corrs[i][j].index_match);
                  //  We are drawing a line for each pair of clustered correspondences found between the model and the scene 我们正在为模型和场景之间发现的每对集群对应关系画一条线
                  m_pclSceneViewer2->addLine<PointType, PointType>(model_point, scene_point, 89, 255, 0, ss_line.str());

              }

       }



  m_pclSceneViewer2->resetCamera();
  ui->widget_3->update();

}

void Flow::on_pushButton_7_clicked()
{

    typedef pcl::PointXYZ PointType;
    typedef pcl::Normal NormalType;
    typedef pcl::ReferenceFrame RFType;
    typedef pcl::SHOT352 DescriptorType;
    //typedef pcl::FPFHSignature33 DescriptorType;


    //Algorithm params
    bool show_keypoints_(true);
    bool show_correspondences_(true);
    bool use_cloud_resolution_(false);
    bool use_hough_(true);
    //float model_ss_(0.01f);
    //float scene_ss_(0.03f);
    //float rf_rad_(0.015f);
    //float descr_rad_(0.02f);
    //float cg_size_(0.01f);
    //float cg_thresh_(5.0f);
    float model_ss_(0.03f);
    float scene_ss_(0.02f);
    float rf_rad_(0.015f);
    float descr_rad_(0.045f);
    float cg_size_(0.05f);
    float cg_thresh_(5.0f);


        pcl::PointCloud<PointType>::Ptr model(new pcl::PointCloud<PointType>());
        pcl::PointCloud<PointType>::Ptr model_keypoints(new pcl::PointCloud<PointType>());
        pcl::PointCloud<PointType>::Ptr scene(new pcl::PointCloud<PointType>());
        pcl::PointCloud<PointType>::Ptr scene_keypoints(new pcl::PointCloud<PointType>());
        pcl::PointCloud<NormalType>::Ptr model_normals(new pcl::PointCloud<NormalType>());
        pcl::PointCloud<NormalType>::Ptr scene_normals(new pcl::PointCloud<NormalType>());
        pcl::PointCloud<DescriptorType>::Ptr model_descriptors(new pcl::PointCloud<DescriptorType>());
        pcl::PointCloud<DescriptorType>::Ptr scene_descriptors(new pcl::PointCloud<DescriptorType>());

        //
        //  Load clouds
        //
//        if (pcl::io::loadPCDFile("bike.pcd", *model) < 0)
//        {
//            std::cout << "Error loading model cloud." << std::endl;

//        }
//        if (pcl::io::loadPCDFile("scenebike.pcd", *scene) < 0)
//        {
//            std::cout << "Error loading scene cloud." << std::endl;

//        }

        pcl::copyPointCloud(*m_scenePointCloud, *scene);
        pcl::copyPointCloud(*m_templatePointCloud, *model);

        //手枪识别时候不用，其余需要
        //pcl::transformPointCloud(*model, *model, Eigen::Vector3f(-3, 0, 0), Eigen::Quaternionf(3, 0, 0, 0));
        //
        //  Set up resolution invariance
        //

        //
        //  Compute Normals
        //
        pcl::NormalEstimationOMP<PointType, NormalType> norm_est;
        norm_est.setKSearch(10);
        //norm_est.setNumberOfThreads(4); //多线程  为了解决报错问题：User Error 1001: argument to num_threads clause must be positive
        norm_est.setInputCloud(model);
        norm_est.compute(*model_normals);

        norm_est.setInputCloud(scene);
        norm_est.compute(*scene_normals);

        //
        //  Downsample Clouds to Extract keypoints
        //

        pcl::UniformSampling<PointType> uniform_sampling;
        uniform_sampling.setInputCloud(model);
        uniform_sampling.setRadiusSearch(model_ss_);
        uniform_sampling.filter(*model_keypoints);
        std::cout << "Model total points: " << model->size() << "; Selected Keypoints: " << model_keypoints->size() << std::endl;

        uniform_sampling.setInputCloud(scene);
        uniform_sampling.setRadiusSearch(scene_ss_);
        uniform_sampling.filter(*scene_keypoints);
        std::cout << "Scene total points: " << scene->size() << "; Selected Keypoints: " << scene_keypoints->size() << std::endl;

        QString str =QString("Demo:")+QString("3D Object Recognition based on Correspondence Grouping" )+QString("\n")+
                QString("Model total points:")+QString::number(model->size()) +QString("; Selected Keypoints: ")+QString::number(model_keypoints->size())+QString("\n")+
                 QString("Scene total points:")+QString::number(scene->size()) +QString("; Selected Keypoints: ")+QString::number(scene_keypoints->size())+QString("\n");


        //pcl::visualization::PCLVisualizer viewer2("Correspondence Grouping2");

        //pcl::visualization::PointCloudColorHandlerCustom<PointType> model_color_handler(model, 255, 0, 0);
        //viewer2.addPointCloud(model, model_color_handler, "off_scene_mode2");
        //pcl::visualization::PointCloudColorHandlerCustom<PointType> model_color_handler__(model_keypoints, 0, 0, 255);
        //viewer2.addPointCloud(model_keypoints, model_color_handler__, "off_scene_mode3");
        //viewer2.setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 5, "off_scene_mode3");
        //while (!viewer2.wasStopped())
        //{
        //	viewer2.spinOnce();
        //}

        //
        //  Compute Descriptor for keypoints
        //
        pcl::SHOTEstimationOMP<PointType, NormalType, DescriptorType> descr_est;
        descr_est.setRadiusSearch(descr_rad_);

        descr_est.setInputCloud(model_keypoints);
        descr_est.setInputNormals(model_normals);
        //descr_est.setNumberOfThreads(4);  /多线程  为了解决报错问题：User Error 1001: argument to num_threads clause must be positive
        descr_est.setSearchSurface(model);
        descr_est.compute(*model_descriptors);

        descr_est.setInputCloud(scene_keypoints);
        descr_est.setInputNormals(scene_normals);
        //descr_est.setNumberOfThreads(4); /多线程  为了解决报错问题：User Error 1001: argument to num_threads clause must be positive
        descr_est.setSearchSurface(scene);
        descr_est.compute(*scene_descriptors);
        cout << "SHOT" << endl;

        //快速点特征直方图
        //pcl::FPFHEstimationOMP<pcl::PointXYZ, pcl::Normal, pcl::FPFHSignature33> fpfh_src;
        //fpfh_src.setNumberOfThreads(4); //指定4核计算
        //fpfh_src.setInputCloud(model_keypoints);
        //fpfh_src.setInputNormals(model_normals);
        //fpfh_src.setSearchSurface(model);
        //pcl::search::KdTree<PointType>::Ptr tree_src_fpfh(new pcl::search::KdTree<PointType>);
        //fpfh_src.setSearchMethod(tree_src_fpfh);
        //*fpfh_src.setRadiusSearch(1);
        //fpfh_src.setKSearch(20);
        //fpfh_src.compute(*model_descriptors);
        //std::cout << "compute *cloud_src fpfh" << endl;

        //pcl::FPFHEstimationOMP<pcl::PointXYZ, pcl::Normal, pcl::FPFHSignature33> fpfh_tgt;
        //fpfh_tgt.setNumberOfThreads(4);
        //fpfh_tgt.setInputCloud(scene_keypoints);
        //fpfh_tgt.setInputNormals(scene_normals);
        //fpfh_tgt.setSearchSurface(scene);
        //pcl::search::KdTree<PointType>::Ptr tree_tgt_fpfh(new pcl::search::KdTree<PointType>);
        //fpfh_tgt.setSearchMethod(tree_tgt_fpfh);
        //*fpfh_tgt.setRadiusSearch(1);//使用半径为5cm范围内的所有邻元素，注意：此处使用的半径必须要大于估计表面法线时使用的半径！！！
        //fpfh_tgt.setKSearch(20);
        //fpfh_tgt.compute(*scene_descriptors);
        //std::cout << "compute *cloud_tgt fpfh" << endl;


        //
        //  Find Model-Scene Correspondences with KdTree
        //
        pcl::CorrespondencesPtr model_scene_corrs(new pcl::Correspondences());

        pcl::KdTreeFLANN<DescriptorType> match_search;
        match_search.setInputCloud(model_descriptors);

        //  For each scene keypoint descriptor, find nearest neighbor into the model keypoints descriptor cloud and add it to the correspondences vector.
        for (size_t i = 0; i < scene_descriptors->size(); ++i)
        {
            std::vector<int> neigh_indices(1);
            std::vector<float> neigh_sqr_dists(1);
            if (!pcl_isfinite(scene_descriptors->at(i).descriptor[0])) //skipping NaNs
            {
                continue;
            }
            int found_neighs = match_search.nearestKSearch(scene_descriptors->at(i), 1, neigh_indices, neigh_sqr_dists);
            if (found_neighs == 1 && neigh_sqr_dists[0] < 0.25f) //  add match only if the squared descriptor distance is less than 0.25 (SHOT descriptor distances are between 0 and 1 by design)
            {
                pcl::Correspondence corr(neigh_indices[0], static_cast<int> (i), neigh_sqr_dists[0]);
                model_scene_corrs->push_back(corr);
            }
        }
        std::cout << "Correspondences found: " << model_scene_corrs->size() << std::endl;

        //
        //  Actual Clustering
        //
        std::vector<Eigen::Matrix4f, Eigen::aligned_allocator<Eigen::Matrix4f> > rototranslations;
        std::vector<pcl::Correspondences> clustered_corrs;

        //  Using Hough3D
        if (use_hough_)
        {
            //
            //  Compute (Keypoints) Reference Frames only for Hough
            //
            pcl::PointCloud<RFType>::Ptr model_rf(new pcl::PointCloud<RFType>());
            pcl::PointCloud<RFType>::Ptr scene_rf(new pcl::PointCloud<RFType>());

            pcl::BOARDLocalReferenceFrameEstimation<PointType, NormalType, RFType> rf_est;
            rf_est.setFindHoles(true);
            rf_est.setRadiusSearch(rf_rad_);

            rf_est.setInputCloud(model_keypoints);
            rf_est.setInputNormals(model_normals);
            rf_est.setSearchSurface(model);
            rf_est.compute(*model_rf);

            rf_est.setInputCloud(scene_keypoints);
            rf_est.setInputNormals(scene_normals);
            rf_est.setSearchSurface(scene);
            rf_est.compute(*scene_rf);

            //  Clustering
            pcl::Hough3DGrouping<PointType, PointType, RFType, RFType> clusterer;
            clusterer.setHoughBinSize(cg_size_);
            clusterer.setHoughThreshold(cg_thresh_);
            clusterer.setUseInterpolation(true);
            clusterer.setUseDistanceWeight(false);

            clusterer.setInputCloud(model_keypoints);
            clusterer.setInputRf(model_rf);
            clusterer.setSceneCloud(scene_keypoints);
            clusterer.setSceneRf(scene_rf);
            clusterer.setModelSceneCorrespondences(model_scene_corrs);

            //clusterer.cluster (clustered_corrs);
            clusterer.recognize(rototranslations, clustered_corrs);
        }
        else // Using GeometricConsistency
        {
            pcl::GeometricConsistencyGrouping<PointType, PointType> gc_clusterer;
            gc_clusterer.setGCSize(cg_size_);
            gc_clusterer.setGCThreshold(cg_thresh_);

            gc_clusterer.setInputCloud(model_keypoints);
            gc_clusterer.setSceneCloud(scene_keypoints);
            gc_clusterer.setModelSceneCorrespondences(model_scene_corrs);

            //gc_clusterer.cluster (clustered_corrs);
            gc_clusterer.recognize(rototranslations, clustered_corrs);
        }

        str += QString("Correspondences found: ")+QString::number(model_scene_corrs->size())+QString("\n")+
                     QString("使用3d hough 匹配方法 ")+QString("\n")+
                     QString("rototranslations.size: ")+QString::number(rototranslations.size())+QString("\n")+
                     QString("clustered_corrs[0].size.size: ")+QString::number(clustered_corrs[0].size())+QString("\n");



        //
        //  Output results
        //
        std::cout << "Model instances found: " << rototranslations.size() << std::endl;
        for (size_t i = 0; i < rototranslations.size(); ++i)
        {
            std::cout << "\n    Instance " << i + 1 << ":" << std::endl;
            std::cout << "        Correspondences belonging to this instance: " << clustered_corrs[i].size() << std::endl;

            // Print the rotation matrix and translation vector
            Eigen::Matrix3f rotation = rototranslations[i].block<3, 3>(0, 0);
            Eigen::Vector3f translation = rototranslations[i].block<3, 1>(0, 3);

            printf("\n");
            printf("            | %6.3f %6.3f %6.3f | \n", rotation(0, 0), rotation(0, 1), rotation(0, 2));
            printf("        R = | %6.3f %6.3f %6.3f | \n", rotation(1, 0), rotation(1, 1), rotation(1, 2));
            printf("            | %6.3f %6.3f %6.3f | \n", rotation(2, 0), rotation(2, 1), rotation(2, 2));
            printf("\n");
            printf("        t = < %0.3f, %0.3f, %0.3f >\n", translation(0), translation(1), translation(2));

            str +=  QString("rotation : ")+QString("\n")+
                        QString::number(rotation(0,0))+QString("  ")+QString::number(rotation(0,1))+QString("  ")+QString::number(rotation(0,2))+QString("\n")+
                        QString::number(rotation(1,0))+QString("  ")+QString::number(rotation(1,1))+QString("  ")+QString::number(rotation(1,2))+QString("\n")+
                        QString::number(rotation(2,0))+QString("  ")+QString::number(rotation(2,1))+QString("  ")+QString::number(rotation(2,2))+QString("\n")+
                        QString("translation : ")+QString("\n")+
                        QString::number(translation(0))+QString("  ")+QString::number(translation(1))+QString("  ")+QString::number(translation(2))+QString("\n");
        }


    ui->label->setText(str);


        //
        //  Visualization
        //




      //  pcl::visualization::PCLVisualizer viewer("Correspondence Grouping");
        pcl::visualization::PointCloudColorHandlerCustom<PointType> scene__color(scene, 192, 192, 192);//场景灰色
        m_pclSceneViewer2->addPointCloud<PointType>(scene, scene__color, "scene");

        pcl::PointCloud<PointType>::Ptr off_scene_model(new pcl::PointCloud<PointType>());//脱离场景的模型点云
        pcl::PointCloud<PointType>::Ptr off_scene_model_keypoints(new pcl::PointCloud<PointType>());//脱离场景的模型点云的关键点
        pcl::PointCloud<PointType>::Ptr rotated_model(new pcl::PointCloud<PointType>());//场景识别出来的点云

        if (show_correspondences_ || show_keypoints_)
        {
            //为何要做个初识变换
            //  We are translating the model so that it doesn't end in the middle of the scene representation
//            pcl::transformPointCloud(*model, *off_scene_model, Eigen::Vector3f(-6.5, 0, 0), Eigen::Quaternionf(5, 0, 0, 0));
//            pcl::transformPointCloud(*model_keypoints, *off_scene_model_keypoints, Eigen::Vector3f(-6.5, 0, 0), Eigen::Quaternionf(5, 0, 0, 0));

            pcl::transformPointCloud(*model, *off_scene_model, Eigen::Vector3f(-6.5, 0, 0), Eigen::Quaternionf(5, 0, 0, 0));
            pcl::transformPointCloud(*model_keypoints, *off_scene_model_keypoints, Eigen::Vector3f(-6.5, 0, 0), Eigen::Quaternionf(5, 0, 0, 0));

            pcl::visualization::PointCloudColorHandlerCustom<PointType> off_scene_model_color_handler(off_scene_model, 255, 0, 0);  //模板的初识位置 为红色
           m_pclSceneViewer2->addPointCloud(off_scene_model, off_scene_model_color_handler, "off_scene_model");
        }

        if (show_keypoints_)
        {
            pcl::visualization::PointCloudColorHandlerCustom<PointType> scene_keypoints_color_handler(scene_keypoints, 255, 165, 0);   //场景关键点为蓝色
            m_pclSceneViewer2->addPointCloud(scene_keypoints, scene_keypoints_color_handler, "scene_keypoints");
            m_pclSceneViewer2->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 5, "scene_keypoints");

            pcl::visualization::PointCloudColorHandlerCustom<PointType> off_scene_model_keypoints_color_handler(off_scene_model_keypoints, 0, 0, 255);  //变换后的模板点云关键点也为蓝色
            m_pclSceneViewer2->addPointCloud(off_scene_model_keypoints, off_scene_model_keypoints_color_handler, "off_scene_model_keypoints");
            m_pclSceneViewer2->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 5, "off_scene_model_keypoints");
        }
//        pcl::visualization::PointCloudColorHandlerCustom<PointType>  rgb(model, 0, 255, 0);
//        m_pclSceneViewer2->addPointCloud(model, rgb, "The Scene");

        for (size_t i = 0; i < rototranslations.size(); ++i)
        {
            //pcl::PointCloud<PointType>::Ptr rotated_model(new pcl::PointCloud<PointType>());
            pcl::transformPointCloud(*model, *rotated_model, rototranslations[i]);

            std::stringstream ss_cloud;
            ss_cloud << "instance" << i;

            pcl::visualization::PointCloudColorHandlerCustom<PointType> rotated_model_color_handler(rotated_model, 0, 255, 255);//场景提取模型旋转后的配准位置为青色
            m_pclSceneViewer2->addPointCloud(rotated_model, rotated_model_color_handler, ss_cloud.str());
            //viewer.setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 3, ss_cloud.str());

            if (show_correspondences_)
            {
                for (size_t j = 0; j < clustered_corrs[i].size(); ++j)
                {
                    std::stringstream ss_line;
                    ss_line << "correspondence_line" << i << "_" << j;
                    PointType& model_point = off_scene_model_keypoints->at(clustered_corrs[i][j].index_query);
                    PointType& scene_point = scene_keypoints->at(clustered_corrs[i][j].index_match);

                    //  We are drawing a line for each pair of clustered correspondences found between the model and the scene
                     m_pclSceneViewer2->addLine<PointType, PointType>(model_point, scene_point, 0, 255, 0, ss_line.str());   //连线为绿色
                }
            }
        }


   //  这一大段 是加了个包围盒？

        Eigen::Vector4f pcaCentroid;
        pcl::compute3DCentroid(*rotated_model, pcaCentroid);
        Eigen::Matrix3f covariance;
        pcl::computeCovarianceMatrixNormalized(*rotated_model, pcaCentroid, covariance);
        Eigen::SelfAdjointEigenSolver<Eigen::Matrix3f> eigen_solver(covariance, Eigen::ComputeEigenvectors);
        Eigen::Matrix3f eigenVectorsPCA = eigen_solver.eigenvectors();
        Eigen::Vector3f eigenValuesPCA = eigen_solver.eigenvalues();
        eigenVectorsPCA.col(2) = eigenVectorsPCA.col(0).cross(eigenVectorsPCA.col(1)); //校正主方向间垂直
        eigenVectorsPCA.col(0) = eigenVectorsPCA.col(1).cross(eigenVectorsPCA.col(2));
        eigenVectorsPCA.col(1) = eigenVectorsPCA.col(2).cross(eigenVectorsPCA.col(0));


        std::cout << "特征值va(3x1):\n" << eigenValuesPCA << std::endl;
        std::cout << "特征向量ve(3x3):\n" << eigenVectorsPCA << std::endl;
        std::cout << "质心点(4x1):\n" << pcaCentroid << std::endl;

        Eigen::Matrix4f tm = Eigen::Matrix4f::Identity();
        Eigen::Matrix4f tm_inv = Eigen::Matrix4f::Identity();
        tm.block<3, 3>(0, 0) = eigenVectorsPCA.transpose();   //R.
        tm.block<3, 1>(0, 3) = -1.0f * (eigenVectorsPCA.transpose()) *(pcaCentroid.head<3>());//  -R*t
        tm_inv = tm.inverse();
        std::cout << "变换矩阵tm(4x4):\n" << tm << std::endl;
        std::cout << "逆变矩阵tm'(4x4):\n" << tm_inv << std::endl;

        pcl::PointCloud<PointType>::Ptr transformedCloud(new pcl::PointCloud<PointType>);
        pcl::transformPointCloud(*rotated_model, *transformedCloud, tm);

        PointType min_p1, max_p1;   //点云的最大值与最小值点
        Eigen::Vector3f c1, c;
        pcl::getMinMax3D(*transformedCloud, min_p1, max_p1);
        c1 = 0.5f*(min_p1.getVector3fMap() + max_p1.getVector3fMap());

        std::cout << "型心c1(3x1):\n" << c1 << std::endl;

        Eigen::Affine3f tm_inv_aff(tm_inv);
        pcl::transformPoint(c1, c, tm_inv_aff);

        Eigen::Vector3f whd, whd1;
        whd1 = max_p1.getVector3fMap() - min_p1.getVector3fMap();
        whd = whd1;
        float sc1 = (whd1(0) + whd1(1) + whd1(2)) / 3;  //点云平均尺度，用于设置主方向箭头大小

        std::cout << "width1=" << whd1(0) << endl;
        std::cout << "heght1=" << whd1(1) << endl;
        std::cout << "depth1=" << whd1(2) << endl;
        std::cout << "scale1=" << sc1 << endl;

        const Eigen::Quaternionf bboxQ1(Eigen::Quaternionf::Identity());
        const Eigen::Vector3f    bboxT1(c1);

        const Eigen::Quaternionf bboxQ(tm_inv.block<3, 3>(0, 0));
        const Eigen::Vector3f    bboxT(c);


        //变换到原点的点云主方向
        PointType op;
        op.x = 0.0;
        op.y = 0.0;
        op.z = 0.0;
        Eigen::Vector3f px, py, pz;
        Eigen::Affine3f tm_aff(tm);
        pcl::transformVector(eigenVectorsPCA.col(0), px, tm_aff);
        pcl::transformVector(eigenVectorsPCA.col(1), py, tm_aff);
        pcl::transformVector(eigenVectorsPCA.col(2), pz, tm_aff);
        PointType pcaX;
        pcaX.x = sc1 * px(0);
        pcaX.y = sc1 * px(1);
        pcaX.z = sc1 * px(2);
        PointType pcaY;
        pcaY.x = sc1 * py(0);
        pcaY.y = sc1 * py(1);
        pcaY.z = sc1 * py(2);
        PointType pcaZ;
        pcaZ.x = sc1 * pz(0);
        pcaZ.y = sc1 * pz(1);
        pcaZ.z = sc1 * pz(2);


         m_pclSceneViewer2->addCube(bboxT, bboxQ, whd(0), whd(1), whd(2), "bbox");
         m_pclSceneViewer2->setShapeRenderingProperties(pcl::visualization::PCL_VISUALIZER_REPRESENTATION, pcl::visualization::PCL_VISUALIZER_REPRESENTATION_WIREFRAME, "bbox");
         m_pclSceneViewer2->setShapeRenderingProperties(pcl::visualization::PCL_VISUALIZER_COLOR, 1.0, 0.0, 0.0, "bbox");
         m_pclSceneViewer2->setShapeRenderingProperties(pcl::visualization::PCL_VISUALIZER_LINE_WIDTH, 3, "bbox");

        /***********AABB包围盒*************/
        /*pcl::MomentOfInertiaEstimation <pcl::PointXYZ> feature_extractor;
        feature_extractor.setInputCloud(rotated_model);
        feature_extractor.compute();

        std::vector <float> moment_of_inertia;
        std::vector <float> eccentricity;
        pcl::PointXYZ min_point_AABB;
        pcl::PointXYZ max_point_AABB;
        pcl::PointXYZ min_point_OBB;
        pcl::PointXYZ max_point_OBB;
        pcl::PointXYZ position_OBB;
        Eigen::Matrix3f rotational_matrix_OBB;
        float major_value, middle_value, minor_value;
        Eigen::Vector3f major_vector, middle_vector, minor_vector;
        Eigen::Vector3f mass_center;

        feature_extractor.getMomentOfInertia(moment_of_inertia);
        feature_extractor.getEccentricity(eccentricity);
        feature_extractor.getAABB(min_point_AABB, max_point_AABB);
        feature_extractor.getOBB(min_point_OBB, max_point_OBB, position_OBB, rotational_matrix_OBB);
        feature_extractor.getEigenValues(major_value, middle_value, minor_value);
        feature_extractor.getEigenVectors(major_vector, middle_vector, minor_vector);
        feature_extractor.getMassCenter(mass_center);


        viewer.addPointCloud(rotated_model, pcl::visualization::PointCloudColorHandlerCustom<PointType>(rotated_model, 0, 255, 255), "sample cloud");
        viewer.addCube(min_point_AABB.x, max_point_AABB.x, min_point_AABB.y, max_point_AABB.y, min_point_AABB.z, max_point_AABB.z, 1.0, 0.0, 0.0, "AABB");
        viewer.setShapeRenderingProperties(pcl::visualization::PCL_VISUALIZER_REPRESENTATION, pcl::visualization::PCL_VISUALIZER_REPRESENTATION_WIREFRAME, "AABB");
        viewer.setShapeRenderingProperties(pcl::visualization::PCL_VISUALIZER_LINE_WIDTH, 4, "AABB");*/































}

//这是一个计算分辨率的函数




void Flow::on_pushButton_8_clicked()
{
    typedef pcl::PointXYZ PointType;
    typedef pcl::Normal NormalType;
    typedef pcl::ReferenceFrame RFType;
    typedef pcl::SHOT352 DescriptorType;
    //typedef pcl::FPFHSignature33 DescriptorType;
    //Algorithm params
    bool use_hough_(true);
    float model_ss_(1.0f);   //0.01~10
    float scene_ss_(0.8f);   // 0.03~20
    float rf_rad_(0.49f);    //0.015~10
    float descr_rad_(2.50f);  //0.02~19
    float cg_size_(0.01f);    //0.01~10
    float cg_thresh_(5.0f);   //定阈值5.0

//    int ksearch = ui->sceneNRSBox_3->value();
//    float model_ss_= ui->sceneNRSBox_8->value();
//    float scene_ss_= ui->sceneNRSBox_7->value();
//    float rf_rad_=  ui->sceneNRSBox_2->value();
//    float descr_rad_= ui->sceneNRSBox_4->value();
//    float cg_size_= ui->sceneNRSBox_5->value();
//    float cg_thresh_= ui->sceneNRSBox_6->value();


        pcl::PointCloud<PointType>::Ptr model(new pcl::PointCloud<PointType>());
        pcl::PointCloud<PointType>::Ptr model_keypoints(new pcl::PointCloud<PointType>());
        pcl::PointCloud<PointType>::Ptr scene(new pcl::PointCloud<PointType>());
        pcl::PointCloud<PointType>::Ptr scene_keypoints(new pcl::PointCloud<PointType>());
        pcl::PointCloud<NormalType>::Ptr model_normals(new pcl::PointCloud<NormalType>());
        pcl::PointCloud<NormalType>::Ptr scene_normals(new pcl::PointCloud<NormalType>());
        pcl::PointCloud<DescriptorType>::Ptr model_descriptors(new pcl::PointCloud<DescriptorType>());
        pcl::PointCloud<DescriptorType>::Ptr scene_descriptors(new pcl::PointCloud<DescriptorType>());

        if (pcl::io::loadPCDFile("stdmodel.pcd", *model) < 0)
        {
            std::cout << "Error loading model cloud." << std::endl;

        }
        if (pcl::io::loadPCDFile("final0.pcd", *scene) < 0)
        {
            std::cout << "Error loading scene cloud." << std::endl;

        }

//        pcl::copyPointCloud(*m_scenePointCloud, *scene);
//        pcl::copyPointCloud(*m_templatePointCloud, *model);


        //手枪识别时候不用，其余需要
        //pcl::transformPointCloud(*model, *model, Eigen::Vector3f(-3, 0, 0), Eigen::Quaternionf(3, 0, 0, 0));
        //
        //  Set up resolution invariance
        //

        //
        //  Compute Normals
        //
        qDebug() << "111111111111111 " ;
        pcl::NormalEstimationOMP<PointType, NormalType> norm_est;
        norm_est.setKSearch(10);//设置K邻域搜索阀值为10个点
        //norm_est.setNumberOfThreads(4); //多线程  为了解决报错问题：User Error 1001: argument to num_threads clause must be positive
        norm_est.setInputCloud(model);
        norm_est.compute(*model_normals);

        norm_est.setInputCloud(scene);
        norm_est.compute(*scene_normals);

        //
        //  Downsample Clouds to Extract keypoints
        //

        pcl::UniformSampling<PointType> uniform_sampling;
        uniform_sampling.setInputCloud(model);
        uniform_sampling.setRadiusSearch(model_ss_);
        uniform_sampling.filter(*model_keypoints);
        std::cout << "Model total points: " << model->size() << "; Selected Keypoints: " << model_keypoints->size() << std::endl;

        uniform_sampling.setInputCloud(scene);
        uniform_sampling.setRadiusSearch(scene_ss_);
        uniform_sampling.filter(*scene_keypoints);
        std::cout << "Scene total points: " << scene->size() << "; Selected Keypoints: " << scene_keypoints->size() << std::endl;

        QString str =QString("Demo:")+QString("3D Object Recognition based on Correspondence Grouping" )+QString("\n")+
                QString("Model total points:")+QString::number(model->size()) +QString("; Selected Keypoints: ")+QString::number(model_keypoints->size())+QString("\n")+
                 QString("Scene total points:")+QString::number(scene->size()) +QString("; Selected Keypoints: ")+QString::number(scene_keypoints->size())+QString("\n");


        //pcl::visualization::PCLVisualizer viewer2("Correspondence Grouping2");

        //pcl::visualization::PointCloudColorHandlerCustom<PointType> model_color_handler(model, 255, 0, 0);
        //viewer2.addPointCloud(model, model_color_handler, "off_scene_mode2");
        //pcl::visualization::PointCloudColorHandlerCustom<PointType> model_color_handler__(model_keypoints, 0, 0, 255);
        //viewer2.addPointCloud(model_keypoints, model_color_handler__, "off_scene_mode3");
        //viewer2.setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 5, "off_scene_mode3");
        //while (!viewer2.wasStopped())
        //{
        //	viewer2.spinOnce();
        //}

        //
        //  Compute Descriptor for keypoints
        //
        pcl::SHOTEstimationOMP<PointType, NormalType, DescriptorType> descr_est;
        descr_est.setRadiusSearch(descr_rad_);

        descr_est.setInputCloud(model_keypoints);
        descr_est.setInputNormals(model_normals);
        //descr_est.setNumberOfThreads(4);  /多线程  为了解决报错问题：User Error 1001: argument to num_threads clause must be positive
        descr_est.setSearchSurface(model);
        descr_est.compute(*model_descriptors);

        descr_est.setInputCloud(scene_keypoints);
        descr_est.setInputNormals(scene_normals);
        //descr_est.setNumberOfThreads(4); /多线程  为了解决报错问题：User Error 1001: argument to num_threads clause must be positive
        descr_est.setSearchSurface(scene);
        descr_est.compute(*scene_descriptors);
        cout << "SHOT" << endl;

        //快速点特征直方图
        //pcl::FPFHEstimationOMP<pcl::PointXYZ, pcl::Normal, pcl::FPFHSignature33> fpfh_src;
        //fpfh_src.setNumberOfThreads(4); //指定4核计算
        //fpfh_src.setInputCloud(model_keypoints);
        //fpfh_src.setInputNormals(model_normals);
        //fpfh_src.setSearchSurface(model);
        //pcl::search::KdTree<PointType>::Ptr tree_src_fpfh(new pcl::search::KdTree<PointType>);
        //fpfh_src.setSearchMethod(tree_src_fpfh);
        //*fpfh_src.setRadiusSearch(1);
        //fpfh_src.setKSearch(20);
        //fpfh_src.compute(*model_descriptors);
        //std::cout << "compute *cloud_src fpfh" << endl;

        //pcl::FPFHEstimationOMP<pcl::PointXYZ, pcl::Normal, pcl::FPFHSignature33> fpfh_tgt;
        //fpfh_tgt.setNumberOfThreads(4);
        //fpfh_tgt.setInputCloud(scene_keypoints);
        //fpfh_tgt.setInputNormals(scene_normals);
        //fpfh_tgt.setSearchSurface(scene);
        //pcl::search::KdTree<PointType>::Ptr tree_tgt_fpfh(new pcl::search::KdTree<PointType>);
        //fpfh_tgt.setSearchMethod(tree_tgt_fpfh);
        //*fpfh_tgt.setRadiusSearch(1);//使用半径为5cm范围内的所有邻元素，注意：此处使用的半径必须要大于估计表面法线时使用的半径！！！
        //fpfh_tgt.setKSearch(20);
        //fpfh_tgt.compute(*scene_descriptors);
        //std::cout << "compute *cloud_tgt fpfh" << endl;


        //
        //  Find Model-Scene Correspondences with KdTree
        //
        pcl::CorrespondencesPtr model_scene_corrs(new pcl::Correspondences());

        pcl::KdTreeFLANN<DescriptorType> match_search;
        match_search.setInputCloud(model_descriptors);

        //  For each scene keypoint descriptor, find nearest neighbor into the model keypoints descriptor cloud and add it to the correspondences vector.
        for (size_t i = 0; i < scene_descriptors->size(); ++i)
        {
            std::vector<int> neigh_indices(1);
            std::vector<float> neigh_sqr_dists(1);
            if (!pcl_isfinite(scene_descriptors->at(i).descriptor[0])) //skipping NaNs
            {
                continue;
            }
            int found_neighs = match_search.nearestKSearch(scene_descriptors->at(i), 1, neigh_indices, neigh_sqr_dists);
            if (found_neighs == 1 && neigh_sqr_dists[0] < 0.25f) //  add match only if the squared descriptor distance is less than 0.25 (SHOT descriptor distances are between 0 and 1 by design)
            {
                pcl::Correspondence corr(neigh_indices[0], static_cast<int> (i), neigh_sqr_dists[0]);
                model_scene_corrs->push_back(corr);
            }
        }
        std::cout << "Correspondences found: " << model_scene_corrs->size() << std::endl;
    str += QString("Correspondences found: ")+QString::number(model_scene_corrs->size())+QString("\n");
     ui->label->setText(str);
        //
        //  Actual Clustering
        //
        std::vector<Eigen::Matrix4f, Eigen::aligned_allocator<Eigen::Matrix4f> > rototranslations;
        std::vector<pcl::Correspondences> clustered_corrs;

        //  Using Hough3D

            //  Compute (Keypoints) Reference Frames only for Hough
            pcl::PointCloud<RFType>::Ptr model_rf(new pcl::PointCloud<RFType>());
            pcl::PointCloud<RFType>::Ptr scene_rf(new pcl::PointCloud<RFType>());
            pcl::BOARDLocalReferenceFrameEstimation<PointType, NormalType, RFType> rf_est;
            rf_est.setFindHoles(true);
            rf_est.setRadiusSearch(rf_rad_);
            qDebug() << "2222222 "<<"rf_rad"<< rf_rad_;
            rf_est.setInputCloud(model_keypoints);
            rf_est.setInputNormals(model_normals);
            rf_est.setSearchSurface(model);
            rf_est.compute(*model_rf);
            rf_est.setInputCloud(scene_keypoints);
            rf_est.setInputNormals(scene_normals);
            rf_est.setSearchSurface(scene);
            rf_est.compute(*scene_rf);
            pcl::Hough3DGrouping<PointType, PointType, RFType, RFType> clusterer;
            clusterer.setHoughBinSize(cg_size_);

            clusterer.setHoughThreshold(cg_thresh_);
            clusterer.setUseInterpolation(true);
            clusterer.setUseDistanceWeight(false);

            clusterer.setInputCloud(model_keypoints);
            clusterer.setInputRf(model_rf);
            clusterer.setSceneCloud(scene_keypoints);
            clusterer.setSceneRf(scene_rf);
            qDebug() << "44444444444444"<<"scene_keypoints"<< scene_keypoints->size();
            clusterer.setModelSceneCorrespondences(model_scene_corrs);
             qDebug() << "5555555"<<"载入model_scene_corrs OK";
            clusterer.recognize(rototranslations, clustered_corrs);
            qDebug() << "6666666"<<"霍夫聚类投票 OK";
            qDebug() << "Model instances found: " << rototranslations.size() ;

        str += QString("Correspondences found: ")+QString::number(model_scene_corrs->size())+QString("\n")+
                     QString("使用3d hough 匹配方法 ")+QString("\n")+
                     QString("rototranslations.size: ")+QString::number(rototranslations.size())+QString("\n")+
                     QString("clustered_corrs[0].size.size: ")+QString::number(clustered_corrs[0].size())+QString("\n");

        //
        //  Output results
        //
        std::cout << "Model instances found: " << rototranslations.size() << std::endl;
        for (size_t i = 0; i < rototranslations.size(); ++i)
        {
            std::cout << "\n    Instance " << i + 1 << ":" << std::endl;
            std::cout << "        Correspondences belonging to this instance: " << clustered_corrs[i].size() << std::endl;

            // Print the rotation matrix and translation vector
            Eigen::Matrix3f rotation = rototranslations[i].block<3, 3>(0, 0);
            Eigen::Vector3f translation = rototranslations[i].block<3, 1>(0, 3);

            printf("\n");
            printf("            | %6.3f %6.3f %6.3f | \n", rotation(0, 0), rotation(0, 1), rotation(0, 2));
            printf("        R = | %6.3f %6.3f %6.3f | \n", rotation(1, 0), rotation(1, 1), rotation(1, 2));
            printf("            | %6.3f %6.3f %6.3f | \n", rotation(2, 0), rotation(2, 1), rotation(2, 2));
            printf("\n");
            printf("        t = < %0.3f, %0.3f, %0.3f >\n", translation(0), translation(1), translation(2));

            str +=  QString("rotation : ")+QString("\n")+
                        QString::number(rotation(0,0))+QString("  ")+QString::number(rotation(0,1))+QString("  ")+QString::number(rotation(0,2))+QString("\n")+
                        QString::number(rotation(1,0))+QString("  ")+QString::number(rotation(1,1))+QString("  ")+QString::number(rotation(1,2))+QString("\n")+
                        QString::number(rotation(2,0))+QString("  ")+QString::number(rotation(2,1))+QString("  ")+QString::number(rotation(2,2))+QString("\n")+
                        QString("translation : ")+QString("\n")+
                        QString::number(translation(0))+QString("  ")+QString::number(translation(1))+QString("  ")+QString::number(translation(2))+QString("\n");
        }


    ui->label->setText(str);


        //
        //  Visualization
        //
      //  pcl::visualization::PCLVisualizer viewer("Correspondence Grouping");
        pcl::visualization::PointCloudColorHandlerCustom<PointType> scene__color(scene, 192, 192, 192);//场景灰色
        m_pclSceneViewer2->addPointCloud<PointType>(scene, scene__color, "scene");

        pcl::PointCloud<PointType>::Ptr off_scene_model(new pcl::PointCloud<PointType>());//脱离场景的模型点云
        pcl::PointCloud<PointType>::Ptr off_scene_model_keypoints(new pcl::PointCloud<PointType>());//脱离场景的模型点云的关键点
        pcl::PointCloud<PointType>::Ptr rotated_model(new pcl::PointCloud<PointType>());//场景识别出来的点云
            //为何要做个初识变换
            //  We are translating the model so that it doesn't end in the middle of the scene representation
//            pcl::transformPointCloud(*model, *off_scene_model, Eigen::Vector3f(-6.5, 0, 0), Eigen::Quaternionf(5, 0, 0, 0));
//            pcl::transformPointCloud(*model_keypoints, *off_scene_model_keypoints, Eigen::Vector3f(-6.5, 0, 0), Eigen::Quaternionf(5, 0, 0, 0));

            pcl::transformPointCloud(*model, *off_scene_model, Eigen::Vector3f(-6.5, 0, 0), Eigen::Quaternionf(5, 0, 0, 0));
            pcl::transformPointCloud(*model_keypoints, *off_scene_model_keypoints, Eigen::Vector3f(-6.5, 0, 0), Eigen::Quaternionf(5, 0, 0, 0));   // 初始位置的模型点云

            pcl::visualization::PointCloudColorHandlerCustom<PointType> off_scene_model_color_handler(off_scene_model, 255, 0, 0);
           m_pclSceneViewer2->addPointCloud(off_scene_model, off_scene_model_color_handler, "off_scene_model");

            pcl::visualization::PointCloudColorHandlerCustom<PointType> scene_keypoints_color_handler(scene_keypoints, 0, 0, 255);
            m_pclSceneViewer2->addPointCloud(scene_keypoints, scene_keypoints_color_handler, "scene_keypoints");
            m_pclSceneViewer2->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 5, "scene_keypoints");

            pcl::visualization::PointCloudColorHandlerCustom<PointType> off_scene_model_keypoints_color_handler(off_scene_model_keypoints, 0, 0, 255);   //初识位置的模型点云为蓝色

            m_pclSceneViewer2->addPointCloud(off_scene_model_keypoints, off_scene_model_keypoints_color_handler, "off_scene_model_keypoints");
            m_pclSceneViewer2->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 5, "off_scene_model_keypoints");

//        pcl::visualization::PointCloudColorHandlerCustom<PointType>  rgb(model, 0, 255, 0);
//        m_pclSceneViewer2->addPointCloud(model, rgb, "The Scene");

        for (size_t i = 0; i < rototranslations.size(); ++i)
        {
            //pcl::PointCloud<PointType>::Ptr rotated_model(new pcl::PointCloud<PointType>());
            pcl::transformPointCloud(*model, *rotated_model, rototranslations[i]);

            std::stringstream ss_cloud;
            ss_cloud << "instance" << i;

            pcl::visualization::PointCloudColorHandlerCustom<PointType> rotated_model_color_handler(rotated_model, 0, 255, 255);//场景提取模型青色
            m_pclSceneViewer2->addPointCloud(rotated_model, rotated_model_color_handler, ss_cloud.str());
            //viewer.setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 3, ss_cloud.str());


                for (size_t j = 0; j < clustered_corrs[i].size(); ++j)
                {
                    std::stringstream ss_line;
                    ss_line << "correspondence_line" << i << "_" << j;
                    PointType& model_point = off_scene_model_keypoints->at(clustered_corrs[i][j].index_query);
                    PointType& scene_point = scene_keypoints->at(clustered_corrs[i][j].index_match);

                    //  We are drawing a line for each pair of clustered correspondences found between the model and the scene
                     m_pclSceneViewer2->addLine<PointType, PointType>(model_point, scene_point, 0, 255, 0, ss_line.str());
                }

        }


   //  这一大段 是加了个包围盒？

        Eigen::Vector4f pcaCentroid;
        pcl::compute3DCentroid(*rotated_model, pcaCentroid);
        Eigen::Matrix3f covariance;
        pcl::computeCovarianceMatrixNormalized(*rotated_model, pcaCentroid, covariance);
        Eigen::SelfAdjointEigenSolver<Eigen::Matrix3f> eigen_solver(covariance, Eigen::ComputeEigenvectors);
        Eigen::Matrix3f eigenVectorsPCA = eigen_solver.eigenvectors();
        Eigen::Vector3f eigenValuesPCA = eigen_solver.eigenvalues();
        eigenVectorsPCA.col(2) = eigenVectorsPCA.col(0).cross(eigenVectorsPCA.col(1)); //校正主方向间垂直
        eigenVectorsPCA.col(0) = eigenVectorsPCA.col(1).cross(eigenVectorsPCA.col(2));
        eigenVectorsPCA.col(1) = eigenVectorsPCA.col(2).cross(eigenVectorsPCA.col(0));


        std::cout << "特征值va(3x1):\n" << eigenValuesPCA << std::endl;
        std::cout << "特征向量ve(3x3):\n" << eigenVectorsPCA << std::endl;
        std::cout << "质心点(4x1):\n" << pcaCentroid << std::endl;

        Eigen::Matrix4f tm = Eigen::Matrix4f::Identity();
        Eigen::Matrix4f tm_inv = Eigen::Matrix4f::Identity();
        tm.block<3, 3>(0, 0) = eigenVectorsPCA.transpose();   //R.
        tm.block<3, 1>(0, 3) = -1.0f * (eigenVectorsPCA.transpose()) *(pcaCentroid.head<3>());//  -R*t
        tm_inv = tm.inverse();
        std::cout << "变换矩阵tm(4x4):\n" << tm << std::endl;
        std::cout << "逆变矩阵tm'(4x4):\n" << tm_inv << std::endl;

        pcl::PointCloud<PointType>::Ptr transformedCloud(new pcl::PointCloud<PointType>);
        pcl::transformPointCloud(*rotated_model, *transformedCloud, tm);

        PointType min_p1, max_p1;   //点云的最大值与最小值点
        Eigen::Vector3f c1, c;
        pcl::getMinMax3D(*transformedCloud, min_p1, max_p1);
        c1 = 0.5f*(min_p1.getVector3fMap() + max_p1.getVector3fMap());

        std::cout << "型心c1(3x1):\n" << c1 << std::endl;

        Eigen::Affine3f tm_inv_aff(tm_inv);
        pcl::transformPoint(c1, c, tm_inv_aff);

        Eigen::Vector3f whd, whd1;
        whd1 = max_p1.getVector3fMap() - min_p1.getVector3fMap();
        whd = whd1;
        float sc1 = (whd1(0) + whd1(1) + whd1(2)) / 3;  //点云平均尺度，用于设置主方向箭头大小

        std::cout << "width1=" << whd1(0) << endl;
        std::cout << "heght1=" << whd1(1) << endl;
        std::cout << "depth1=" << whd1(2) << endl;
        std::cout << "scale1=" << sc1 << endl;

        const Eigen::Quaternionf bboxQ1(Eigen::Quaternionf::Identity());
        const Eigen::Vector3f    bboxT1(c1);

        const Eigen::Quaternionf bboxQ(tm_inv.block<3, 3>(0, 0));
        const Eigen::Vector3f    bboxT(c);


        //变换到原点的点云主方向
        PointType op;
        op.x = 0.0;
        op.y = 0.0;
        op.z = 0.0;
        Eigen::Vector3f px, py, pz;
        Eigen::Affine3f tm_aff(tm);
        pcl::transformVector(eigenVectorsPCA.col(0), px, tm_aff);
        pcl::transformVector(eigenVectorsPCA.col(1), py, tm_aff);
        pcl::transformVector(eigenVectorsPCA.col(2), pz, tm_aff);
        PointType pcaX;
        pcaX.x = sc1 * px(0);
        pcaX.y = sc1 * px(1);
        pcaX.z = sc1 * px(2);
        PointType pcaY;
        pcaY.x = sc1 * py(0);
        pcaY.y = sc1 * py(1);
        pcaY.z = sc1 * py(2);
        PointType pcaZ;
        pcaZ.x = sc1 * pz(0);
        pcaZ.y = sc1 * pz(1);
        pcaZ.z = sc1 * pz(2);


         m_pclSceneViewer2->addCube(bboxT, bboxQ, whd(0), whd(1), whd(2), "bbox");
         m_pclSceneViewer2->setShapeRenderingProperties(pcl::visualization::PCL_VISUALIZER_REPRESENTATION, pcl::visualization::PCL_VISUALIZER_REPRESENTATION_WIREFRAME, "bbox");
         m_pclSceneViewer2->setShapeRenderingProperties(pcl::visualization::PCL_VISUALIZER_COLOR, 1.0, 0.0, 0.0, "bbox");
         m_pclSceneViewer2->setShapeRenderingProperties(pcl::visualization::PCL_VISUALIZER_LINE_WIDTH, 3, "bbox");
}
