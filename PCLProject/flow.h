#ifndef FLOW_H
#define FLOW_H

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


namespace Ui {
class Flow;
}

class Flow : public QMainWindow
{
    Q_OBJECT

    void showTemplate();
    void showScene();
    void showTemplate2();
    void showScene2();
    //手动写一些槽函数，用于connection操作

    public slots:
        void loadTemplate();
        void loadScene();
        void loadTemplate2();
        void loadScene2();
        void computeTemplateSIFT();
        void computeSceneSIFT();
        void computeTemplateNorMal();
        void computeSceneNorMal();
        void computeTemplateFPFH();
        void computeSceneFPFH();

        void SAC();
        void ICP();




public:
    explicit Flow(QWidget *parent = 0);
    ~Flow();

        QString str;

private slots:
        void on_pushButton_clicked();

        void on_pushButton_2_clicked();

        void on_pushButton_3_clicked();

        void on_pushButton_4_clicked();

        void on_pushButton_5_clicked();

        void on_pushButton_6_clicked();

        void on_pushButton_7_clicked();

        void on_pushButton_8_clicked();

private:
    Ui::Flow *ui;

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
      Eigen::Matrix4f sac_trans;
      Eigen::Matrix4f icp_trans;
      Eigen::Matrix4f ndt_trans;
      Eigen::Matrix4f DSC_trans;
      Eigen::Matrix4f PSC_trans;
      pcl::PointCloud<PointT>::Ptr m_templatePointCloud;


      SurfaceNormal::Ptr m_templateSurfaceNormal;
      LocalFeatures::Ptr m_templateLocalFeatures;


      pcl::PointCloud<PointT>::Ptr m_scenePointCloud;
      SurfaceNormal::Ptr m_sceneSurfaceNormal;
      LocalFeatures::Ptr m_sceneLocalFeatures;

      bool m_isTemplateReady;
      bool m_isSceneReady;

      pcl::visualization::PCLVisualizer *m_pclTemplateViewer;
      pcl::visualization::PCLVisualizer *m_pclSceneViewer;
      pcl::visualization::PCLVisualizer *m_pclTemplateViewer2;
      pcl::visualization::PCLVisualizer *m_pclSceneViewer2;

   SurfaceNormal::Ptr TemplateNormal = SurfaceNormal::Ptr(new SurfaceNormal);
   SurfaceNormal::Ptr sceneNormal = SurfaceNormal::Ptr(new SurfaceNormal);

     pcl::PointCloud<pcl::PointWithScale> Templatekeypoints;
     pcl::PointCloud<pcl::PointWithScale> scenekeypoints;

//     pcl::PointCloud<PointT>::Ptr m_templatekeypoints;
//     pcl::PointCloud<PointT>::Ptr m_scenekeypoints;



    LocalFeatures::Ptr TemplateFeatures = LocalFeatures::Ptr(new LocalFeatures);
    LocalFeatures::Ptr sceneFeatures = LocalFeatures::Ptr(new LocalFeatures);

//
//   pcl::PointCloud<PointT>::Ptr inputAlignedSAC;
};

#endif // FLOW_H
