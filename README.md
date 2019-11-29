#  DHVisionTest_zhenzhang

#### 介绍
pcl 学习过程中遇到的一些坑和捷径，
目的是把PCL中的算子研究清楚，主要是参数的调节
知道有哪些东西，才能够去应用。

#### 软件架构
软件架构说明
主控制台下包含四个模块：滤波Filter,分割Segmentation,配准Registration，转换Transformation。

##滤波模块。
1.直通滤波PassThrough
2.下采样滤波 VoxelGrid
3.统计学滤波 StatisticalOutlierRemoval
4.分割索引滤波 ExtractIndices(基于随机一致性）
5.投影滤波ModelCoefficients 使用参数化模型）
6.自定义条件滤波ConditionalRemoval 
7.半径密度滤波RadiusOutlierRemoval
8.多边形形状滤波CropHull

##分割模块。
1.基于随机一致性的平面分割
2.基于随机一致性的法线圆柱体分割
3.基于随机一致性的法线球体分割
4.基于区域生长的聚类分割
5.基于图割法的最小割算法
6.基于法线微分的多尺度分割法
7.基于VCCS的超体素分割
8.基于形态学滤波的地面背景分割
8.基于条件欧式距离的聚类点云分割

##配准模块。
1.一种简单快速的粗配准方法
2.一种不需要调参的ICP配准方法
3.一种需要调参的SACIA配准方法
4.一种需要调参的ICP精配准方法
5.一种先进行SACIA粗配准，再进行ICP精配准的方法
6.一种基于NDT的特征直方图配准方法 

##转换模块。-----------待完成
1.点云图转换深度图
2.点云图转彩虹图
3.点云图转灰度图
4.点云图转高度图
5.点云图转2D图








