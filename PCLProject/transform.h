#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <QMainWindow>
#include <QMainWindow>
#include <QVTKWidget.h>
#include <vtkRenderWindow.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/registration/ndt.h>
#include <pcl/filters/approximate_voxel_grid.h>
#include <pcl/features/normal_3d.h>
#include <pcl/features/fpfh.h>

#include <pcl/registration/ia_ransac.h>

#include "global.h"

typedef pcl::PointXYZ PointT;
typedef pcl::PointCloud<pcl::Normal> SurfaceNormal;
typedef pcl::PointCloud<pcl::FPFHSignature33> LocalFeatures;
typedef pcl::search::KdTree<PointT> SearchMethod;

namespace Ui {
class Transform;
}

class Transform : public QMainWindow
{
    Q_OBJECT


    void showScene();
        void showScene2();
        void showScene3();
        void showScene4();
        void showScene5();

    public slots:

        void loadScene();
        void loadScene2();
        void loadScene3();
        void loadScene4();
        void loadScene5();

        void  range_image();
        void  ColorImage();
        void  HeightImage();
        void  GrayImage();
        void  IntensityImage();


public:
    explicit Transform(QWidget *parent = 0);
    ~Transform();

private:
    Ui::Transform *ui;

    //定义一些 成员函数
      SurfaceNormal::Ptr computeSurfaceNormal(pcl::PointCloud<PointT>::Ptr inputCloud,
                                              SearchMethod::Ptr searchMethod,
                                              double normalRadius);
      LocalFeatures::Ptr computeLocalFeatures(pcl::PointCloud<PointT>::Ptr inputCloud,
                                              SurfaceNormal::Ptr inputNormal,
                                              SearchMethod::Ptr searchMethod,
                                              double featureRadius);

      FeatureCloud m_templateFCloud;
      FeatureCloud m_sceneFCloud;
      TemplateAlignment m_templateAlign;

      SearchMethod::Ptr m_searchMethod;
      Eigen::Matrix4f m_matrix;
      pcl::PointCloud<PointT>::Ptr m_templatePointCloud;
      SurfaceNormal::Ptr m_templateSurfaceNormal;
      LocalFeatures::Ptr m_templateLocalFeatures;

      pcl::PointCloud<PointT>::Ptr m_scenePointCloud;
      SurfaceNormal::Ptr m_sceneSurfaceNormal;
      LocalFeatures::Ptr m_sceneLocalFeatures;

      pcl::SampleConsensusInitialAlignment<PointT,PointT,pcl::FPFHSignature33> m_scia;
      bool m_isTemplateReady;
      bool m_isSceneReady;




      pcl::visualization::PCLVisualizer *m_pclTemplateViewer;
      pcl::visualization::PCLVisualizer *m_pclSceneViewer;

      pcl::visualization::PCLVisualizer *m_pclSceneViewer2;

      pcl::visualization::PCLVisualizer *m_pclSceneViewer3;
      pcl::visualization::PCLVisualizer *m_pclSceneViewer4;
       pcl::visualization::PCLVisualizer *m_pclSceneViewer5;

};

#endif // TRANSFORM_H
