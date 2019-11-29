#ifndef FEATURE_H
#define FEATURE_H

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

namespace Ui {
class Feature;
}

class Feature : public QMainWindow
{
    Q_OBJECT

public:
    explicit Feature(QWidget *parent = 0);
    ~Feature();

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
    void ISSKeypoint3D();
    void SIFTKeypoint();
    void SHOTKeypoint();
    void Harris3DKeypoint();
     void NARFKeypoint();

private:
    Ui::Feature *ui;

    pcl::visualization::PCLVisualizer *m_pclSceneViewer;
    pcl::visualization::PCLVisualizer *m_pclSceneViewer2;
    pcl::visualization::PCLVisualizer *m_pclSceneViewer3;
    pcl::visualization::PCLVisualizer *m_pclSceneViewer4;
    pcl::visualization::PCLVisualizer *m_pclSceneViewer5;

    pcl::PointCloud<PointT>::Ptr m_scenePointCloud;

    FeatureCloud m_sceneFCloud;



    bool m_isSceneReady;

};

#endif // FEATURE_H
