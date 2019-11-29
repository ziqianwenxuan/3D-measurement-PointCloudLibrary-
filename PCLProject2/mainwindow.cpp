#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>
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
#include "global.h"
#include"QDateTime"


VTK_MODULE_INIT(vtkRenderingOpenGL)
VTK_MODULE_INIT(vtkInteractionStyle)
VTK_MODULE_INIT(vtkRenderingContextOpenGL)
VTK_MODULE_INIT(vtkRenderingFreeType)


typedef pcl::PointXYZ PointT;
typedef pcl::PointCloud<pcl::PointXYZ> PointCloud;

//pcl::visualization::PCLVisualizer *m_pclSceneViewer;
//pcl::PointCloud<PointT>::Ptr m_scenePointCloud;
//FeatureCloud m_sceneFCloud;
//bool m_isSceneReady;
//QVTKWidget* vtk_widget_ = nullptr;

 boost::shared_ptr< pcl::visualization::PointCloudColorHandlerGenericField<pcl::PointXYZ> > cloud_in_color_;
 pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_in_;
boost::shared_ptr< pcl::visualization::PointCloudColorHandlerGenericField<pcl::PointXYZ> >cloud_out_color_;
pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_out_;
boost::shared_ptr<pcl::visualization::PCLVisualizer> pcl_visualizer_;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pt = new FilterPassThrough(this);
    ui->stackedWidget->addWidget(pt);
    vg = new filtervoxelgrid(this);
    ui->stackedWidget->addWidget(vg);
    so = new FilterStatiscalOutlier(this);
    ui->stackedWidget->addWidget(so);
    ei = new FilterExtractIndices(this);
    ui->stackedWidget->addWidget(ei);
    cr = new FilterConditionalRemoval(this);
    ui->stackedWidget->addWidget(cr);
    rr = new FilterRadiusOutlierRemoval(this);
    ui->stackedWidget->addWidget(rr);
    ch = new FilterCropHull(this);
    ui->stackedWidget->addWidget(ch);


    //代码中m_publicIconMap是定义好的图标其在之前进行初始化
    m_publicIconMap[TREE_ITEM_ICON_Project] = QIcon(QStringLiteral(":/treeIcon/res_treeItemIcon/Project.png"));
    m_publicIconMap[TREE_ITEM_ICON_folder] = QIcon(QStringLiteral(":/treeIcon/res_treeItemIcon/folder.png"));
    m_publicIconMap[TREE_ITEM_ICON_folderAnsys] = QIcon(QStringLiteral(":/treeIcon/res_treeItemIcon/folder-ansys.png"));
    m_publicIconMap[TREE_ITEM_ICON_TdmsGroup] = QIcon(QStringLiteral(":/treeIcon/res_treeItemIcon/group.png"));
    m_publicIconMap[TREE_ITEM_ICON_TdmsChannel] = QIcon(QStringLiteral(":/treeIcon/res_treeItemIcon/channel.png"));
    m_publicIconMap[TREE_ITEM_ICON_folderOriginal] = QIcon(QStringLiteral(":/treeIcon/res_treeItemIcon/folder_original.png"));
    m_publicIconMap[TREE_ITEM_ICON_DataItem] = QIcon(QStringLiteral(":/treeIcon/res_treeItemIcon/dataItem.png"));
   qDebug() << "init11" ;
    initTree();

    cloud_in_.reset(new pcl::PointCloud<pcl::PointXYZ>());
    cloud_in_color_.reset(new pcl::visualization::PointCloudColorHandlerGenericField< pcl::PointXYZ>(cloud_in_, "z"));
    cloud_out_.reset(new pcl::PointCloud<pcl::PointXYZ>());
    cloud_out_color_.reset(
        new pcl::visualization::PointCloudColorHandlerGenericField<
            pcl::PointXYZ>(cloud_out_, "z"));
    pcl_visualizer_.reset( new pcl::visualization::PCLVisualizer("pcl_visualizer_in_", false));

    // 下面的函数 是将一个view一分为二的关键算法

    pcl_visualizer_->createViewPort(0.0, 0.0, 0.5, 1.0, view_port1_);
    pcl_visualizer_->createViewPort(0.5, 0.0, 1.0, 1.0, view_port2_);
    pcl_visualizer_->addPointCloud(cloud_in_, *cloud_in_color_, "cloud_in_", view_port1_);
    pcl_visualizer_->addPointCloud(cloud_out_, *cloud_out_color_, "cloud_out_", view_port2_);
    pcl_visualizer_->setupInteractor(ui->qvtkWidget->GetInteractor(),  ui->qvtkWidget->GetRenderWindow());
    pcl_visualizer_->setShowFPS(false);
    pcl_visualizer_->addText("Before", 0, 0, std::string(""), view_port1_);
    pcl_visualizer_->addText("After", 0, 0, std::string(""), view_port2_);
    ui->qvtkWidget->SetRenderWindow(pcl_visualizer_->getRenderWindow());


//    QDateTime *datatime = new QDateTime (QDateTime::currentDateTime());
//    ui->dateTimeEdit->setDateTime(datatime->Data());




}

MainWindow::~MainWindow()
{
    delete ui;
}






void MainWindow::initTree()
{


    qDebug() << "init22" ;
   #pragma execution_character_set("utf-8"); //解决乱码的神器
    QStandardItemModel* model = new QStandardItemModel(ui->treeView);

    ui->treeView->setEditTriggers(0);// 将节点的信息设置为不可编辑的状态
    model->setHorizontalHeaderLabels(QStringList()<<QStringLiteral("Function"));  //添加表头信息
    //QStandardItem的appendRow和setChild方法等价于QStandardItemModel的appendRow和setItem
    QStandardItem* itemProject = new QStandardItem(m_publicIconMap[QStringLiteral("treeItem_Project")],QStringLiteral("Camera"));//创建父点信息
    model->appendRow(itemProject);
    QStandardItem*itemFolder = new QStandardItem(m_publicIconMap[QStringLiteral("treeItem_folder")],QStringLiteral("Connect"));  //添加子节点信息
    itemProject->appendRow(itemFolder);  //添加树形控件的根条目可以使用appendRow函数，setItem也可以

    itemProject = new QStandardItem(m_publicIconMap[QStringLiteral("treeItem_Project")],QStringLiteral("Image"));
    model->appendRow(itemProject);
     itemFolder = new QStandardItem(m_publicIconMap[QStringLiteral("treeItem_folder")],QStringLiteral("Transform"));
    itemProject->appendRow(itemFolder);

    itemProject = new QStandardItem(m_publicIconMap[QStringLiteral("treeItem_Project")],QStringLiteral("Filter"));
    model->appendRow(itemProject);
     itemFolder = new QStandardItem(m_publicIconMap[QStringLiteral("treeItem_folder")],QStringLiteral("PassThrough"));
    itemProject->appendRow(itemFolder);
    itemFolder = new QStandardItem(m_publicIconMap[QStringLiteral("treeItem_folder")],QStringLiteral("VoxelGrid"));
    itemProject->appendRow(itemFolder);
    itemFolder = new QStandardItem(m_publicIconMap[QStringLiteral("treeItem_folder")],QStringLiteral("StatisticalOutlierRemoval"));
    itemProject->appendRow(itemFolder);
    itemFolder = new QStandardItem(m_publicIconMap[QStringLiteral("treeItem_folder")],QStringLiteral("ExtractIndices"));
    itemProject->appendRow(itemFolder);
    itemFolder = new QStandardItem(m_publicIconMap[QStringLiteral("treeItem_folder")],QStringLiteral("project_inliers"));
    itemProject->appendRow(itemFolder);
    itemFolder = new QStandardItem(m_publicIconMap[QStringLiteral("treeItem_folder")],QStringLiteral("ConditionalRemoval"));
    itemProject->appendRow(itemFolder);
    itemFolder = new QStandardItem(m_publicIconMap[QStringLiteral("treeItem_folder")],QStringLiteral("RadiusOutlierRemoval"));
    itemProject->appendRow(itemFolder);
    itemFolder = new QStandardItem(m_publicIconMap[QStringLiteral("treeItem_folder")],QStringLiteral("CropHull"));
    itemProject->appendRow(itemFolder);


    itemProject = new QStandardItem(m_publicIconMap[QStringLiteral("treeItem_Project")],QStringLiteral("Segmentation"));
    model->appendRow(itemProject);
    itemFolder = new QStandardItem(m_publicIconMap[QStringLiteral("treeItem_folder")],QStringLiteral("SegmetionPlan"));
    itemProject->appendRow(itemFolder);
    itemFolder = new QStandardItem(m_publicIconMap[QStringLiteral("treeItem_folder")],QStringLiteral("SegmetionCylinder"));
    itemProject->appendRow(itemFolder);
    itemFolder = new QStandardItem(m_publicIconMap[QStringLiteral("treeItem_folder")],QStringLiteral("SegmetionGlobe "));
    itemProject->appendRow(itemFolder);
    itemFolder = new QStandardItem(m_publicIconMap[QStringLiteral("treeItem_folder")],QStringLiteral("RegionGrowingSegmetion"));
    itemProject->appendRow(itemFolder);
    itemFolder = new QStandardItem(m_publicIconMap[QStringLiteral("treeItem_folder")],QStringLiteral("MinCutSegmentation"));
    itemProject->appendRow(itemFolder);
    itemFolder = new QStandardItem(m_publicIconMap[QStringLiteral("treeItem_folder")],QStringLiteral("DONSegmentation"));
    itemProject->appendRow(itemFolder);
    itemFolder = new QStandardItem(m_publicIconMap[QStringLiteral("treeItem_folder")],QStringLiteral("SupervoxelClustering"));
    itemProject->appendRow(itemFolder);
    itemFolder = new QStandardItem(m_publicIconMap[QStringLiteral("treeItem_folder")],QStringLiteral("ProgressiveMorphologicalFilter"));
    itemProject->appendRow(itemFolder);
    itemFolder = new QStandardItem(m_publicIconMap[QStringLiteral("treeItem_folder")],QStringLiteral("ConditionalEuclideanClustering"));
    itemProject->appendRow(itemFolder);

    itemProject = new QStandardItem(m_publicIconMap[QStringLiteral("treeItem_Project")],QStringLiteral("Registation"));
    model->appendRow(itemProject);
    itemFolder = new QStandardItem(m_publicIconMap[QStringLiteral("treeItem_folder")],QStringLiteral("SAC_IA"));
    itemProject->appendRow(itemFolder);
    itemFolder = new QStandardItem(m_publicIconMap[QStringLiteral("treeItem_folder")],QStringLiteral("ICP"));
    itemProject->appendRow(itemFolder);
    itemFolder = new QStandardItem(m_publicIconMap[QStringLiteral("treeItem_folder")],QStringLiteral("SAC_ICP "));
    itemProject->appendRow(itemFolder);
    itemFolder = new QStandardItem(m_publicIconMap[QStringLiteral("treeItem_folder")],QStringLiteral("NDT_ICP"));
    itemProject->appendRow(itemFolder);
    itemFolder = new QStandardItem(m_publicIconMap[QStringLiteral("treeItem_folder")],QStringLiteral("3DSC)ICP"));
    itemProject->appendRow(itemFolder);

    itemProject = new QStandardItem(m_publicIconMap[QStringLiteral("treeItem_Project")],QStringLiteral("KeyPoint"));
    model->appendRow(itemProject);
    itemFolder = new QStandardItem(m_publicIconMap[QStringLiteral("treeItem_folder")],QStringLiteral("NARF"));
    itemProject->appendRow(itemFolder);
    itemFolder = new QStandardItem(m_publicIconMap[QStringLiteral("treeItem_folder")],QStringLiteral("ISS"));
    itemProject->appendRow(itemFolder);
    itemFolder = new QStandardItem(m_publicIconMap[QStringLiteral("treeItem_folder")],QStringLiteral("SIFT"));
    itemProject->appendRow(itemFolder);
    itemFolder = new QStandardItem(m_publicIconMap[QStringLiteral("treeItem_folder")],QStringLiteral("SHOT"));
    itemProject->appendRow(itemFolder);
    itemFolder = new QStandardItem(m_publicIconMap[QStringLiteral("treeItem_folder")],QStringLiteral("Harris3D"));
    itemProject->appendRow(itemFolder);

    ui->treeView->setModel(model);  // 去掉这一行 treeview 就无法显示了
 qDebug() << "init33" ;
}

void MainWindow::on_treeView_clicked(const QModelIndex &index)
{

     treeviewname = QStringLiteral("%1").arg(index.data().toString());
     ui->label->setText(treeviewname);
        qDebug() <<treeviewname ;
   if(treeviewname =="PassThrough")
   {
     ui->stackedWidget->setCurrentWidget(pt);
        qDebug() <<"TRUE"<<treeviewname ;
   }
   if(treeviewname =="VoxelGrid")
   {
     ui->stackedWidget->setCurrentWidget(vg);
        qDebug() <<"TRUE"<<treeviewname ;
   }

   if(treeviewname =="StatisticalOutlierRemoval")
   {
     ui->stackedWidget->setCurrentWidget(so);
        qDebug() <<"TRUE"<<treeviewname ;
   }
   if(treeviewname =="ExtractIndices")
   {
     ui->stackedWidget->setCurrentWidget(ei);
        qDebug() <<"TRUE"<<treeviewname ;
   }
   if(treeviewname =="ConditionalRemoval")
   {
     ui->stackedWidget->setCurrentWidget(cr);
        qDebug() <<"TRUE"<<treeviewname ;
   }
   if(treeviewname =="RadiusOutlierRemoval")
   {
     ui->stackedWidget->setCurrentWidget(rr);
        qDebug() <<"TRUE"<<treeviewname ;
   }

   if(treeviewname =="CropHull")
   {
     ui->stackedWidget->setCurrentWidget(ch);
        qDebug() <<"TRUE"<<treeviewname ;
   }
}

void MainWindow::on_save_button_clicked()
{
    if (cloud_out_->empty())
    {
        QMessageBox::critical(this, "Critical", QString("Cloud out is empty!"),
                              QMessageBox::Ok, QMessageBox::Ok);
        return;
    }
    QString file_path =
        QFileDialog::getSaveFileName(this, "Save Point Cloud File",qApp->applicationDirPath() + QString("/") +treeviewname, "pcd(*.pcd);; ply(*.ply)");

    if (!file_path.isEmpty())
    {
        qDebug() << file_path;
        QFileInfo file_info(file_path);
        qDebug() << file_info.suffix();
        QMessageBox message_box(QMessageBox::Information, "Waiting"," on the way  ", QMessageBox::Ok,this);
        message_box.show();
        message_box.repaint();
        QElapsedTimer elapsed_timer;
        elapsed_timer.start();
        if (file_info.suffix() == QString("pcd")) {
            do {
                if (0 != pcl::io::savePCDFileBinary<pcl::PointXYZ>(
                             file_path.toStdString(), *cloud_out_)) {
                    QMessageBox::critical(
                        this, "Critical",
                        QString("Save file ") + file_path + QString(" Fail!"),
                        QMessageBox::Ok, QMessageBox::Ok);
                    break;
                }
            } while (0);
        } else if (file_info.suffix() == QString("ply")) {
            do {
                if (0 != pcl::io::savePCDFileBinary<pcl::PointXYZ>(
                             file_path.toStdString(), *cloud_out_)) {
                    QMessageBox::critical(
                        this, "Critical",
                        QString("Save file ") + file_path + QString(" Fail!"),
                        QMessageBox::Ok, QMessageBox::Ok);
                    break;
                }
            } while (0);
        }
        qDebug() << "Used" << elapsed_timer.elapsed() << "ms";
        ui->label->setText("save path:"+ file_path +"\n"+"format:"+file_info.suffix() +"\n"+"save used time:"+elapsed_timer.elapsed()+"    ms");
    }
}

void MainWindow::on_LoadBUT_clicked()
{
    QString file_path = QFileDialog::getOpenFileName(this, "Load Point Cloud File",
                                     qApp->applicationDirPath(), "*.pcd *.ply");
    if (!file_path.isEmpty()) {
        qDebug() << file_path;
        QFileInfo file_info(file_path);
        qDebug() << file_info.suffix();
        QMessageBox message_box(QMessageBox::Information, "Waiting", "  hard working  ", QMessageBox::Ok, this);
        message_box.show();
        message_box.repaint();
        QElapsedTimer elapsed_timer;
        elapsed_timer.start();
        if (file_info.suffix() == QString("pcd"))
        {
            do {
                if (0 != pcl::io::loadPCDFile<pcl::PointXYZ>(
                             file_path.toStdString(), *cloud_in_))
                {
                    QMessageBox::critical(
                        this, "Critical",
                        QString("Load file ") + file_path + QString(" Fail!"),
                        QMessageBox::Ok, QMessageBox::Ok);
                    break;
                }

            } while (0);
        } else if (file_info.suffix() == QString("ply")) {
            do {
                if (0 != pcl::io::loadPLYFile<pcl::PointXYZ>(
                             file_path.toStdString(), *cloud_in_)) {
                    QMessageBox::critical(
                        this, "Critical",
                        QString("Load file ") + file_path + QString(" Fail!"),
                        QMessageBox::Ok, QMessageBox::Ok);
                    break;
                }

            } while (0);
        }
        int time =elapsed_timer.elapsed();
        ui->label->setText("Load path:"+ file_path +"\n"+"format:"+file_info.suffix() +"\n"+"Load used time:"+time+"    ms");
        qDebug() << "Load used" << elapsed_timer.elapsed() << "ms";
        pcl_visualizer_->updatePointCloud(cloud_in_, *cloud_in_color_, "cloud_in_");
        pcl_visualizer_->resetCamera();
        ui->qvtkWidget->update();
    }
}

void MainWindow::ShowSence()
{
   pcl_visualizer_->removeAllPointClouds();
   pcl_visualizer_->updatePointCloud(cloud_in_, *cloud_in_color_, "cloud_in_");
   pcl_visualizer_->resetCamera();
   ui->qvtkWidget->update();
}

void MainWindow::on_excuteButton_clicked()
{
if (cloud_in_->empty()) {
    QMessageBox::critical(this, "Critical", QString("Cloud in is empty!"),
                          QMessageBox::Ok, QMessageBox::Ok);
    return;
}
QMessageBox message_box(QMessageBox::Information, "Waiting",
                        "                          ", QMessageBox::Ok,
                        this);
message_box.show();
message_box.repaint();
if(treeviewname =="PassThrough")
{
  PassThrough();
}else if (treeviewname =="VoxelGrid")
{
    VoxelGrid();
}else if (treeviewname =="StatisticalOutlierRemoval")
{
    StatisticalOutlierRemoval();
}else if (treeviewname =="ExtractIndices")
{
    ExtractIndices();
}/*else if (treeviewname =="project_inliers")
{
    VoxelGrid();
}*/else if (treeviewname =="ConditionalRemoval")
{
    ConditionalRemoval();
}else if (treeviewname =="RadiusOutlierRemoval")
{
    RadiusOutlierRemoval();
}else if (treeviewname =="CropHull")
{
    CropHull();
}

}

void MainWindow::PassThrough()
{
    // 创建滤波器对象
    pcl::PassThrough<pcl::PointXYZ> pass;
    pass.setInputCloud (cloud_in_);
    pass.setFilterFieldName ("z");
   float lowerlimit = pt->ui->LLBox->value();
   float upperlimit = pt->ui->ULBox->value();
    pass.setFilterLimits (lowerlimit, upperlimit);
    pass.setFilterLimitsNegative (true); //true 表示过滤掉0-10的点
    pass.filter (*cloud_out_);
    pcl_visualizer_->updatePointCloud(cloud_out_, *cloud_out_color_, "cloud_out_");   //仅仅这个cloud_out_ 或者cloud_in_  决定了显示在左边还是右边
//    pcl_visualizer_->addPointCloud(cloud_filtered,"cloud1");    //后续应该考虑如何将其变为彩虹图.cloud_in_color_ 只对cloud_in_ 起作用，所以除非是将cloud_filtered转换为cloud_in_                                                                   // 让输入输出同名也解决不了问题
    pcl_visualizer_->resetCamera();
    ui->qvtkWidget->update();
}

void MainWindow::VoxelGrid()
{
    pcl::VoxelGrid<pcl::PointXYZ> vgz;
    float leafSize = vg->ui->leafSizeSBox->value();
    vgz.setInputCloud (cloud_in_);
    vgz.setLeafSize(leafSize,leafSize,leafSize);
    vgz.filter (*cloud_out_);
    pcl_visualizer_->updatePointCloud(cloud_out_, *cloud_out_color_, "cloud_out_");   //仅仅这个cloud_out_ 或者cloud_in_  决定了显示在左边还是右边
    pcl_visualizer_->resetCamera();
    ui->qvtkWidget->update();
}

void MainWindow::StatisticalOutlierRemoval()
{
    pcl::StatisticalOutlierRemoval<pcl::PointXYZ> sor;
    sor.setInputCloud (cloud_in_);
    sor.setMeanK (so->ui->MKBox->value());
    sor.setStddevMulThresh (so->ui->SMTBox->value());
    sor.filter (*cloud_out_);
    pcl_visualizer_->updatePointCloud(cloud_out_, *cloud_out_color_, "cloud_out_");   //仅仅这个cloud_out_ 或者cloud_in_  决定了显示在左边还是右边
    pcl_visualizer_->resetCamera();
    ui->qvtkWidget->update();
}

void MainWindow::ExtractIndices()
{
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered_blob (new pcl::PointCloud<pcl::PointXYZ>);
//    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_p (new pcl::PointCloud<pcl::PointXYZ>), cloud_f (new pcl::PointCloud<pcl::PointXYZ>);
    // 创建滤波器对象:使用叶大小为1cm的下采样
     pcl::VoxelGrid<pcl::PointXYZ> sor;
     sor.setInputCloud (cloud_in_);
     sor.setLeafSize (1.0f, 1.0f, 1.0f);
     sor.filter (*cloud_filtered_blob);
     pcl::ModelCoefficients::Ptr coefficients (new pcl::ModelCoefficients ());
     pcl::PointIndices::Ptr inliers (new pcl::PointIndices ());
     // 创建分割对象
      pcl::SACSegmentation<pcl::PointXYZ> seg;
      // 可选
      seg.setOptimizeCoefficients (true);
      // 必选
      seg.setModelType (pcl::SACMODEL_PLANE);
      seg.setMethodType (pcl::SAC_RANSAC);

      seg.setMaxIterations (ei->ui->MIBox->value());
      seg.setDistanceThreshold (ei->ui->DTBox->value());
      // 创建滤波器对象
      pcl::ExtractIndices<pcl::PointXYZ> extract;
      int i = 0, nr_points = (int) cloud_in_->points.size ();
      // 当还有30%原始点云数据时
      while (cloud_in_->points.size () > 0.3 * nr_points)
      {
        // 从余下的点云中分割最大平面组成部分
        seg.setInputCloud (cloud_filtered_blob);
        seg.segment (*inliers, *coefficients);
        if (inliers->indices.size () == 0)
        {
          break;
        }
        // 分离内层
        extract.setInputCloud (cloud_filtered_blob);
        extract.setIndices (inliers);
        extract.setNegative (false);
        extract.filter (*cloud_out_);
        // 创建滤波器对象
//        extract.setNegative (true);
//        extract.filter (*cloud_f);
//        cloud_filtered_blob.swap (cloud_f);
        i++;
      }
      pcl_visualizer_->updatePointCloud(cloud_out_, *cloud_out_color_, "cloud_out_");   //仅仅这个cloud_out_ 或者cloud_in_  决定了显示在左边还是右边
      pcl_visualizer_->resetCamera();
      ui->qvtkWidget->update();
}

void MainWindow::ConditionalRemoval()
{
    // 创建滤波器对象

    pcl::ConditionAnd<pcl::PointXYZ>::Ptr range_cond (new pcl::ConditionAnd<pcl::PointXYZ> ());
        float gt = static_cast<float>(cr->ui->GTBox->value());
        float lt = static_cast<float>(cr->ui->LTBox->value());
    range_cond->addComparison (pcl::FieldComparison<pcl::PointXYZ>::ConstPtr (new pcl::FieldComparison<pcl::PointXYZ> ("z", pcl::ComparisonOps::GT, gt)));
    range_cond->addComparison (pcl::FieldComparison<pcl::PointXYZ>::ConstPtr (new pcl::FieldComparison<pcl::PointXYZ> ("z", pcl::ComparisonOps::LT, lt)));
    // 创建滤波器
    pcl::ConditionalRemoval<pcl::PointXYZ> condrem (range_cond);
    condrem.setInputCloud (cloud_in_);
    condrem.setKeepOrganized(true);
    // 应用滤波器
    condrem.filter (*cloud_out_);
    pcl_visualizer_->updatePointCloud(cloud_out_, *cloud_out_color_, "cloud_out_");   //仅仅这个cloud_out_ 或者cloud_in_  决定了显示在左边还是右边
    pcl_visualizer_->resetCamera();
    ui->qvtkWidget->update();
}

void MainWindow::RadiusOutlierRemoval()
{

    // 创建环境

        pcl::RadiusOutlierRemoval<pcl::PointXYZ> outrem;
        // 创建滤波器
        outrem.setInputCloud(cloud_in_);
        outrem.setRadiusSearch(rr->ui->BJBox->value());
        outrem.setMinNeighborsInRadius (rr->ui->LJBox->value());
        // 应用滤波器
        outrem.filter (*cloud_out_);

        pcl_visualizer_->updatePointCloud(cloud_out_, *cloud_out_color_, "cloud_out_");   //仅仅这个cloud_out_ 或者cloud_in_  决定了显示在左边还是右边
        pcl_visualizer_->resetCamera();
        ui->qvtkWidget->update();
}

void MainWindow::CropHull()
{
    // 创建环境
    pcl::PointCloud<pcl::PointXYZ>::Ptr boundingbox_ptr (new pcl::PointCloud<pcl::PointXYZ>);
    boundingbox_ptr->push_back(pcl::PointXYZ(0.1, 0.1, 0));
    boundingbox_ptr->push_back(pcl::PointXYZ(0.1, -0.1,0 ));
    boundingbox_ptr->push_back(pcl::PointXYZ(-0.1, 0.1,0 ));
    boundingbox_ptr->push_back(pcl::PointXYZ(-0.1, -0.1,0 ));
    boundingbox_ptr->push_back(pcl::PointXYZ(0.15, 0.1,0 ));

    pcl::ConvexHull<pcl::PointXYZ> hull;
    hull.setInputCloud(boundingbox_ptr);
    hull.setDimension(ch->ui->aBox->value());
    std::vector<pcl::Vertices> polygons;
    pcl::PointCloud<pcl::PointXYZ>::Ptr surface_hull (new pcl::PointCloud<pcl::PointXYZ>);
    hull.reconstruct(*surface_hull, polygons);
    pcl::CropHull<pcl::PointXYZ> bb_filter;
    bb_filter.setDim(ch->ui->bBox->value());
    bb_filter.setInputCloud(cloud_in_);
    bb_filter.setHullIndices(polygons);
    bb_filter.setHullCloud(surface_hull);
    bb_filter.filter(*cloud_out_);
    pcl_visualizer_->updatePointCloud(cloud_out_, *cloud_out_color_, "cloud_out_");   //仅仅这个cloud_out_ 或者cloud_in_  决定了显示在左边还是右边
    pcl_visualizer_->resetCamera();
    ui->qvtkWidget->update();
}







































