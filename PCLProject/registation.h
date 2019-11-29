#ifndef REGISTATION_H
#define REGISTATION_H

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

//定义一些类模板
typedef pcl::PointXYZ PointT;
typedef pcl::PointCloud<pcl::Normal> SurfaceNormal;
typedef pcl::PointCloud<pcl::FPFHSignature33> LocalFeatures;
typedef pcl::search::KdTree<PointT> SearchMethod;


namespace Ui {
class Registation;
}

class Registation : public QMainWindow
{
    Q_OBJECT

    void showTemplate();
    void showScene();
        void showScene2();
        void showScene3();
        void showScene4();
    //手动写一些槽函数，用于connection操作

    public slots:
        void loadTemplate();
        void loadScene();
        void loadScene2();
        void loadScene3();
        void loadScene4();
        void computeTemplate();
        void computeScene();


        void SAC();
        void DSC_ICP1();
        void DSC_ICP2();
        void ICP();
        void PCS_ICP1();
        void PCS_ICP2();
        void SAC_ICP1();
        void SAC_ICP2();
//         void NDT();
        void NDT_ICP1();
        void NDT_ICP2();

        void matrix2angle(Eigen::Matrix4f &result_trans,Eigen::Vector3f &result_angle);

public:
    explicit Registation(QWidget *parent = 0);
    ~Registation();

private:
    Ui::Registation *ui;


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
      Eigen::Matrix4f ndt_trans;
      Eigen::Matrix4f DSC_trans;
      Eigen::Matrix4f PSC_trans;

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
};

#endif // REGISTATION_H


