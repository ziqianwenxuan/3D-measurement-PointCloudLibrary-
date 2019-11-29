#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVTKWidget.h>
#include <vtkRenderWindow.h>
#include <QWidget>
#include <QMap>
#include <QIcon>
#include <QStandardItemModel>
#include <QTreeView>
#include <QList>
#include <QStandardItem>
#include <QMouseEvent>
#include <pcl/visualization/pcl_visualizer.h>
#include <QVTKWidget.h>
#include <vtkRenderWindow.h>
#include "filterpassthrough.h"
#include "ui_filterpassthrough.h"
#include "filtervoxelgrid.h"
#include "ui_filtervoxelgrid.h"
#include "filterstatiscaloutlier.h"
#include "ui_filterstatiscaloutlier.h"
#include "filterextractindices.h"
#include "ui_filterextractindices.h"
#include<global.h>
#include "filterconditionalremoval.h"
#include "ui_filterconditionalremoval.h"
#include "filterradiusoutlierremoval.h"
#include "ui_filterradiusoutlierremoval.h"
#include "filtercrophull.h"
#include "ui_filtercrophull.h"


//以下是图标的宏设定.如果需要设定图标的时候可以使用
#ifndef TREE_ITEM_ICON_Project
#define TREE_ITEM_ICON_Project QStringLiteral("treeItem_Project")
#endif
#ifndef TREE_ITEM_ICON_folder
#define TREE_ITEM_ICON_folder QStringLiteral("treeItem_folder")
#endif
#ifndef TREE_ITEM_ICON_folderOriginal
#define TREE_ITEM_ICON_folderOriginal QStringLiteral("treeItem_folder-ansys")
#endif
#ifndef TREE_ITEM_ICON_folderAnsys
#define TREE_ITEM_ICON_folderAnsys QStringLiteral("treeItem_folder-ansys")
#endif
#ifndef TREE_ITEM_ICON_TdmsGroup
#define TREE_ITEM_ICON_TdmsGroup QStringLiteral("treeItem_group")
#endif
#ifndef TREE_ITEM_ICON_TdmsChannel
#define TREE_ITEM_ICON_TdmsChannel QStringLiteral("treeItem_channel")
#endif
#ifndef TREE_ITEM_ICON_DataItem
#define TREE_ITEM_ICON_DataItem QStringLiteral("treeItem_dataItem")
#endif


namespace Ui {
class MainWindow;
class FilterPassThrough;

}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

   void initTree(); //一个初始化函数
   void ShowSence();
private slots:

   void on_treeView_clicked(const QModelIndex &index);
   void on_save_button_clicked();
   void on_LoadBUT_clicked();
   void on_excuteButton_clicked();
   void PassThrough();
   void VoxelGrid();
   void StatisticalOutlierRemoval();
   void ExtractIndices();
   void ConditionalRemoval();
   void RadiusOutlierRemoval();
   void CropHull();






private:
    Ui::MainWindow *ui;


    QString treeviewname;
    int view_port1_ = 0;
    int view_port2_ = 1;
    QMap<QString,QIcon> m_publicIconMap;              //< 用于存放公共图标;
    QVTKWidget* qvtkWidget = nullptr;

    FilterPassThrough *pt;
    filtervoxelgrid  *vg;
  FilterStatiscalOutlier *so;
  FilterExtractIndices *ei;
 FilterConditionalRemoval *cr;
 FilterRadiusOutlierRemoval *rr;
 FilterCropHull *ch;



};

#endif // MAINWINDOW_H
