# 图像分割算法

## K-Means方法
- 概述  
  无监督学习方法  
  分类问题，输入分类的数目，初始化中心位置  
  硬分类方法，以距离度量  
  迭代分类为聚类    
- 基本流程  
  输入参数--初始化中心点--根据距离计算聚类编号--计算新的中心位置--迭代  
- API  
  double kmeans(inputarray data,  
  int k,表示分类的数目  
  inputoutputarray beastlabels,所有点的分类编号  
  TermCriteria criteria,停止条件（精度或者次数）  
  int attempts,尝试几次 2-3次  
  int flags, kmeans_pp中心初始化算法    kmeans_random随机初始化   kmeans_use_initial用户指定的，比较少用
  ouputArray centers=noArrays) 输出分类中心点的坐标，根据距离或图像颜色的关联度

- 应用到图像分割
  读入图像，定义相关参数，从原始图像的RGB数据转化到样本数据，进行训练
  一般3分类或者4分类就可以把背景给提取出来，但是一般不作为实时提取背景抠图的方法

## GMM方法


## [分水岭方法](https://blog.csdn.net/fengye2two/article/details/79116105?depth_1-utm_source=distribute.pc_relevant.none-task&utm_source=distribute.pc_relevant.none-task)
- 分水岭分割方法  
  图像形态学——腐蚀与膨胀、开闭操作  
- 分水岭分割方法原理  
  基于浸泡理论的分水岭分割方法  
  基于连通图的方法  
  **基于距离变换的方法**
- 基于距离的分水岭分割流程  
  输入-转换灰度-二值化-距离变换-寻找种子-生成marker-分水岭变换-输出
  distanceTransform  
  [watershed](https://blog.csdn.net/iracer/article/details/49225823)  域间的值被置为-1（边界）没有标记清楚的区域被置为0  
  pyrMeanShiftFiltering 均值偏移滤波,将图像中灰度值相近的像素点聚类为一个灰度级    
  [distanceTransform](https://blog.csdn.net/liubing8609/article/details/78483667)  
  [CV_<bit_depth>(S|U|F)C<number_of_channels>](https://blog.csdn.net/Young__Fan/article/details/81868666) S--代表---signed int---有符号整形 U--代表--unsigned int--无符号整形 F--代表--float---------单精度浮点型     
- 分水岭计数  
  原图src——均值偏移滤波shifted使更加接近——灰度及二值化binary——二值化图像进行闭操作，使白色突出区域的噪声变少——使用距离变换并归一化，使用二值化突出山头得到32FC1——转为8UC1发现轮廓输出contours——在全黑32SC1底色新图上绘画轮廓得到markers——使用watershed函数得到最终markers——（为观察输出markers，转为8UC1并使用非操作）——将最终markers的各个编号使用不同颜色标记，其中需要随机生成contours.size()个颜色备用，然后在全新图8UC3上逐像素判断markers结果，若是0或者-1说明是背景或者边界，若有编号则是第几个区域，使用颜色标记即可  


## GrabCut方法


## 案例一 证件照背景更换


## 案例二 视频绿幕背景替换


## [图像阈值化处理](https://zhuanlan.zhihu.com/p/93630299)