#ifndef FILTER_H
#define FILTER_H

#include <QMainWindow>
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


typedef pcl::PointXYZ PointT;
typedef pcl::PointCloud<pcl::PointXYZ> PointCloud;

namespace Ui {
class Filter;
}

class Filter : public QMainWindow
{
    Q_OBJECT

public:
    explicit Filter(QWidget *parent = 0);
    ~Filter();
        void showScene();
        void showScene2();
        void showScene3();
        void showScene4();
//        void showScene5();
        void showScene6();
        void showScene7();
        void showScene8();




    //手动写一些槽函数，用于connection操作

    public slots:
        void loadScene();
        void loadScene2();
        void loadScene3();
        void loadScene4();
//        void loadScene5();
        void loadScene6();
        void loadScene7();
        void loadScene8();
        void PassThrough();
        void VoxelGrid();
        void StatisticalOutlierRemoval();
        void ExtractIndices();
//        void project_inliers();
        void ConditionalRemoval();
        void RadiusOutlierRemoval();
        void CropHull();
private:
    Ui::Filter *ui;


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

    pcl::SampleConsensusInitialAlignment<PointT,PointT,pcl::FPFHSignature33> m_scia;

    bool m_isSceneReady;



};

#endif // FILTER_H
