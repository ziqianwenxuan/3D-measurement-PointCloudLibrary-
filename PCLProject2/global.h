#ifndef GLOBAL_H
#define GLOBAL_H

#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include <pcl/search/kdtree.h>
#include <pcl/kdtree/kdtree_flann.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <QVTKWidget.h>
#include <vtkRenderWindow.h>
#include <pcl/features/normal_3d.h>
#include <pcl/features/fpfh.h>
#include <pcl/registration/ia_ransac.h>
#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>
#include <pcl/filters/statistical_outlier_removal.h>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
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
#include <pcl/filters/radius_outlier_removal.h>
#include <pcl/filters/statistical_outlier_removal.h>
#include <pcl/filters/voxel_grid.h>
#include <pcl/io/pcd_io.h>
#include <pcl/io/ply_io.h>
#include <pcl/keypoints/uniform_sampling.h>
#include <vtkRenderWindow.h>
#include <QApplication>
#include <QDebug>
#include <QElapsedTimer>
#include <QFileDialog>
#include <QFileInfo>
#include <QHBoxLayout>
#include <QMessageBox>
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
#include <pcl/visualization/pcl_visualizer.h>
#include <QVTKWidget.h>
#include <vtkRenderWindow.h>
#include <pcl/features/normal_3d.h>
#include <pcl/features/fpfh.h>
#include <pcl/registration/ia_ransac.h>
#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include <QDebug>
#include <QMessageBox>
#include "filterpassthrough.h"
#include <QModelIndex>
#include <vtkAutoInit.h>
#include <vtkRenderWindow.h>
#include <QStringList>
#include <QStringListModel>
#include <pcl/visualization/pcl_visualizer.h>
#include <QVTKWidget.h>
#include <vtkRenderWindow.h>
#include <pcl/features/normal_3d.h>
#include <pcl/features/fpfh.h>
#include <pcl/registration/ia_ransac.h>
#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
//定义第一个类FeatureCloud 用于计算和存储每个点云数据和对应的特征描述子，包括 计算法线和特征估计

// A bit of shorthand
typedef pcl::PointXYZ PointT;
typedef pcl::PointCloud<pcl::PointXYZ> PointCloud;
typedef pcl::PointCloud<pcl::Normal> SurfaceNormal;
typedef pcl::PointCloud<pcl::FPFHSignature33> LocalFeatures;
typedef pcl::search::KdTree<pcl::PointXYZ> SearchMethod;



class FeatureCloud
{
  public:
    //1.构造函数 创建一个新的kdtreeflann对象并且初始化
    FeatureCloud () : search_method_xyz_ (new SearchMethod),normal_radius_ (0.02f),feature_radius_ (0.02f)
    {

    }

    ~FeatureCloud () {}

    // Process the given cloud
    void setInputCloud (PointCloud::Ptr xyz)     //  2.定义设置输入云的方法  法一：从输入点云指针传入对象点云数据并处理输入
    {
      xyz_ = xyz;
      processInput ();
    }

    // Load and process the cloud in the given PCD file
//    void loadInputCloud (const std::string &pcd_file)   //法二： 加载给定的pcd文件名的点云数据到对象并处理输入
//    {
//      xyz_ = PointCloud::Ptr (new PointCloud);
//      pcl::io::loadPCDFile (pcd_file, *xyz_);
//      processInput ();
//    }

    // Get a pointer to the cloud 3D points  获取指向云3D点的指针
    PointCloud::Ptr getPointCloud () const
    {
      return (xyz_);
    }

    // Get a pointer to the cloud of 3D surface normals   获取点云法线的指针
    SurfaceNormal::Ptr getSurfaceNormal () const
    {
      return (normals_);
    }

    // Get a pointer to the cloud of feature descriptors   获取点云特征描述子的指针
    LocalFeatures::Ptr getLocalFeatures () const
    {
      return (features_);
    }

  protected:
    // Compute the surface normals and local features    第二大部分，定义一个处理点云的方法，首先计算点云的曲面法线 然后估计曲面的特征描述子
    void  processInput ()
    {
      computeSurfaceNormal ();
      computeLocalFeatures ();
    }

    // Compute the surface normals
    void computeSurfaceNormal ()                //使用NormanEstimation 类来计算点云的法线数据
    {
      normals_ = SurfaceNormal::Ptr (new SurfaceNormal);

      pcl::NormalEstimation<pcl::PointXYZ, pcl::Normal> norm_est;
      norm_est.setInputCloud (xyz_);
      norm_est.setSearchMethod (search_method_xyz_);
      norm_est.setRadiusSearch (normal_radius_);
      norm_est.compute (*normals_);
    }

    // Compute the local feature descriptors  计算快速点特征直方图描述子
    void  computeLocalFeatures ()
    {
      features_ = LocalFeatures::Ptr (new LocalFeatures);

      pcl::FPFHEstimation<pcl::PointXYZ, pcl::Normal, pcl::FPFHSignature33> fpfh_est;
      fpfh_est.setInputCloud (xyz_);
      fpfh_est.setInputNormals (normals_);
      fpfh_est.setSearchMethod (search_method_xyz_);
      fpfh_est.setRadiusSearch (feature_radius_);
      fpfh_est.compute (*features_);
    }

  private:
    // Point cloud data
    PointCloud::Ptr xyz_;
    SurfaceNormal::Ptr normals_;
    LocalFeatures::Ptr features_;
    SearchMethod::Ptr search_method_xyz_;

    // Parameters
    float normal_radius_;
    float feature_radius_;
};

//定义第二个类，用于执行模板配准

class TemplateAlignment
{
  public:

    // A struct for storing alignment results
    struct Result       //定义一个用来存储配准结果的结构体。三个成员，第一个为浮点数变量，衡量配准效果的，第二个为变换矩阵，第三个成员为一个宏
    {
      float fitness_score;
      Eigen::Matrix4f final_transformation;
      EIGEN_MAKE_ALIGNED_OPERATOR_NEW
    };

      TemplateAlignment () : min_sample_distance_ (0.05f), max_correspondence_distance_ (0.01f*0.01f), nr_iterations_ (500)
    {
      // Intialize the parameters in the Sample Consensus Intial Alignment (SAC-IA) algorithm    在构造函数里 初始化类 Sample Consensus Intial Alignment (SAC-IA)
      sac_ia_.setMinSampleDistance (min_sample_distance_);
      sac_ia_.setMaxCorrespondenceDistance (max_correspondence_distance_);
      sac_ia_.setMaximumIterations (nr_iterations_);
    }

    ~TemplateAlignment () {}

    // Set the given cloud as the target to which the templates will be aligned
    void
    setTargetCloud (FeatureCloud &target_cloud) //设置模板点云需要对齐的目标数据集
    {
      target_ = target_cloud;
      sac_ia_.setInputTarget (target_cloud.getPointCloud ());
      sac_ia_.setTargetFeatures (target_cloud.getLocalFeatures ());
    }

    // Add the given cloud to the list of template clouds
    void
    addTemplateCloud (FeatureCloud &template_cloud)    // 定义一个方法来指定哪些模板点云将要被配准，通过该方法将模板点云FeatureClouds的对象存储到TemplateAlignment对象的模板序列中
    {
      templates_.push_back (template_cloud);
    }

    // Align the given template cloud to the target specified by setTargetCloud () 将给定的模板云与setTargetCloud()指定的目标对齐
    void
    align (FeatureCloud &template_cloud, TemplateAlignment::Result &result)
    {
      sac_ia_.setInputCloud (template_cloud.getPointCloud ());
      sac_ia_.setSourceFeatures (template_cloud.getLocalFeatures ());

      pcl::PointCloud<pcl::PointXYZ> registration_output;
      sac_ia_.align (registration_output);

      result.fitness_score = (float) sac_ia_.getFitnessScore (max_correspondence_distance_);
      result.final_transformation = sac_ia_.getFinalTransformation ();
    }

    // Align all of template clouds set by addTemplateCloud to the target specified by setTargetCloud () 将addTemplateCloud设置的所有模板云对齐到setTargetCloud指定的目标
    void
    alignAll (std::vector<TemplateAlignment::Result, Eigen::aligned_allocator<Result> > &results)
    {
      results.resize (templates_.size ());
      for (size_t i = 0; i < templates_.size (); ++i)
      {
        align (templates_[i], results[i]);
      }
    }

    // Align all of template clouds to the target cloud to find the one with best alignment score
    //  最后定一个方法 将所有的模板点云与目标点云进行配准并且返回其最佳的拟合模板点云索引与相应的拟合系数
    int
    findBestAlignment (TemplateAlignment::Result &result)
    {
      // Align all of the templates to the target cloud  将所有模板对齐到目标云
      std::vector<Result, Eigen::aligned_allocator<Result> > results;
      alignAll (results);

      // Find the template with the best (lowest) fitness score  找到适合度得分最高(最低)的模板
      float lowest_score = std::numeric_limits<float>::infinity ();
      int best_template = 0;
      for (size_t i = 0; i < results.size (); ++i)
      {
        const Result &r = results[i];
        if (r.fitness_score < lowest_score)
        {
          lowest_score = r.fitness_score;
          best_template = (int) i;
        }
      }


      // Output the best alignment  输出最佳对准
      result = results[best_template];
      return (best_template);
    }

  private:
    // A list of template clouds and the target to which they will be aligned 模板云的列表和它们将对齐到的目标
    std::vector<FeatureCloud> templates_;
    FeatureCloud target_;

    // The Sample Consensus Initial Alignment (SAC-IA) registration routine and its parameters 样本一致性初始对准(SAC-IA)配准例程及其参数
    pcl::SampleConsensusInitialAlignment<pcl::PointXYZ, pcl::PointXYZ, pcl::FPFHSignature33> sac_ia_;
    float min_sample_distance_;
    float max_correspondence_distance_;
    int nr_iterations_;
};


#endif // GLOBAL_H
