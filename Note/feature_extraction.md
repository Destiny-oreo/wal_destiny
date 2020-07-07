## opencv9-10.[SURF特征检测](https://blog.csdn.net/dcrmg/article/details/52601010?depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromBaidu-2&utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromBaidu-2)
- 关键特性：  
特征检测 尺度空间 选择不变形（光照 旋转） 特征向量  
- 工作原理   
1. 构建Hessian（黑塞矩阵），生成所有的兴趣点，用于特征的提取；  
2. 构建尺度空间，发现关键点，非最大信号压制    
3. 特征点定位  
4. 特征点主方向分配  
5. 生成特征点描述子  
6. 特征点匹配  
Sift算法的优点是特征稳定，对旋转、尺度变换、亮度保持不变性，对视角变换、噪声也有一定程度的稳定性；缺点是实时性不高，并且对于边缘光滑目标的特征点提取能力较弱。
Surf改进了特征的提取和描述方式，用一种更为高效的方式完成特征的提取和描述

[API:](https://blog.csdn.net/andylanzhiyong/article/details/84676985)  


	
## opencv11-12.SIFT特征检测--尺度不变性特征变化
	API: 
	1.建立尺度空间，寻找极值
	2.关键点定位 寻找关键点准确位置与删除弱边缘
	3.关键点方向指定
	4.关键点描述子
	
## opencv13-14.HOG特征检测
	灰度转化、梯度计算、分网格的梯度方向直方图
	块描述子、块描述子归一化 
	特征数据与检测窗口、匹配方法
	API: HOGDescriptor detector()
