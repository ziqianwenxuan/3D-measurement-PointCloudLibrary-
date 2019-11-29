#ifndef PCLSEGMENTATION_H
#define PCLSEGMENTATION_H

#include <QMainWindow>
#include <pcl/visualization/pcl_visualizer.h>

#include <QVTKWidget.h>
#include <vtkRenderWindow.h>

#include <pcl/features/normal_3d.h>
#include <pcl/features/fpfh.h>

#include <pcl/registration/ia_ransac.h>
#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include "global.h"
#include <pcl/sample_consensus/method_types.h>
#include <pcl/sample_consensus/model_types.h>
#include <pcl/segmentation/sac_segmentation.h>

namespace Ui {
class PCLSegmentation;
}

class PCLSegmentation : public QMainWindow
{
    Q_OBJECT

public:
    explicit PCLSegmentation(QWidget *parent = 0);
    ~PCLSegmentation();

    void showScene();
    void showScene2();
    void showScene3();
    void showScene4();
    void showScene5();
    void showScene6();
    void showScene7();
    void showScene8();




//手动写一些槽函数，用于connection操作

public slots:
    void loadScene();
    void loadScene2();
    void loadScene3();
    void loadScene4();
    void loadScene5();
    void loadScene6();
    void loadScene7();
    void loadScene8();
    void PlanSegmetion();
    void PassThrough();
    void ComputerNormal();
    void SegmetionPlan();
    void SegmetionCylinder();
    void RegionGrowingSegmetion();
   void MinCutSegmentation();
   void DONSegmentation();
   void SupervoxelClustering();
  void ProgressiveMorphologicalFilter();
  void ConditionalEuclideanClustering();

private:
    Ui::PCLSegmentation *ui;

    pcl::visualization::PCLVisualizer *m_pclSceneViewer;
    pcl::visualization::PCLVisualizer *m_pclSceneViewer2;
    pcl::visualization::PCLVisualizer *m_pclSceneViewer3;
    pcl::visualization::PCLVisualizer *m_pclSceneViewer4;
    pcl::visualization::PCLVisualizer *m_pclSceneViewer5;
    pcl::visualization::PCLVisualizer *m_pclSceneViewer6;
    pcl::visualization::PCLVisualizer *m_pclSceneViewer7;
    pcl::visualization::PCLVisualizer *m_pclSceneViewer8;


    pcl::PointCloud<PointT>::Ptr m_scenePointCloud;

    FeatureCloud m_sceneFCloud;



    bool m_isSceneReady;



};

#endif // PCLSEGMENTATION_H


