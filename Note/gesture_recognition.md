# C++ opencv
## 注意事项
- **size_t和int**：前者在32位系统中为4字节，64位系统为8字节，且为无符合，后者总是4字节有符号，为-2147483648~2147483647，无符号4字节为0~4294967495。

- 函数


# 凸包手势识别
### 帧差法+形态学
使用三帧差法获得二值图像（两两进行差运算，然后进行与运算得到diffFrame），效果并不是很好，所以在阈值后分别进行核为3的膨胀，然后与的结果再进行中值滤波（均值滤波即blur,只有模糊的作用，中值滤波不改变细节，去除噪声，但是核为5的效果好却十分耗时，只能选取核为3），最后进行核为3的开操作去除噪声，开运算会损失细节，所以核不能太大。传入二值图像时再进行膨胀来使轮廓全部连接起来，取了核为5的膨胀。

### 凸包
convexHull()函数检测包含输入轮廓所有点的最小凸多边形，返回的是包含各个拐点的点集合，但是所有点按顺序连接起来即可得到凸多边形（其中输入凸多边形来获取手的质心不准确，因为手指的区域本来不大，但是在凸多边形里占了很大的比例，并且凸多边形的很多顶点距离太近，需要层层筛选才能得到指尖） ；  
convexityDefects()函数检测凸包与手形轮廓的凸缺陷，可以使用手指间缺陷区域的最大深度来筛选指尖点，其中输入的必须为convexHull()函数输出的int集合，不可以为Point集合。   
- 掌心定位  
1.缺陷点的平均值（基于特征提取的掌心实时定位，缺陷区域大多处于上面，易误判）  
2.最小圆心坐标（基于手指间凹槽点来计算掌心，但是当只有少数手指伸出来时候很难识别）  
3.距离变换（内部必须完全填充，当轮廓确实一部分以后距离计算完全混乱，对轮廓要求高）  
4.直接凸包轮廓计算图像矩（无法排除手指及手腕对掌心的影响，凑合着用）    

- 指尖检测  
1.深度阈值(作为初次筛选即可，去除一些深度值很小的缺陷区域或者一些超大的深度值)  
2.角度阈值（需要将重复的点去除同时单手指需要单独考虑，可以使用）  
3.距离之比（也可以作为判断条件的一种）  
4.[曲率分析法](https://blog.csdn.net/zouxy09/article/details/8711461?depth_1-utm_source=distribute.pc_relevant.none-task&utm_source=distribute.pc_relevant.none-task)（对手形轮廓的分割结果要求极高，对噪声或者缺陷及其敏感）  


### [图像矩](https://blog.csdn.net/qq826309057/article/details/70039397?depth_1-utm_source=distribute.pc_relevant.none-task&utm_source=distribute.pc_relevant.none-task)
质心：x=m10/m00;y=m01/m00;

### [hu矩——>特征点](https://www.cnblogs.com/sddai/p/11430732.html)将图像矩moment函数的中心距输出给予humoment函数，输出double hu[7]，即可得到7个hu特征点  
在对图片中物体的[识别过程](https://www.cnblogs.com/skyseraph/archive/2011/07/19/2110183.html)中，只有1和2不变性保持的比较好，其他的几个不变矩带来的误差比较大，有学者认为只有基于二阶矩的不变矩对二维物体的描述才是真正的具有旋转、缩放和平移不变性（ 和 刚好都是由二阶矩组成的）。由Hu矩组成的特征量对图片进行识别，优点就是速度很快，缺点是识别率比较低，对于已经分割好的手势轮廓图，识别率也就30%左右，对于纹理比较丰富的图片，识别率更是不堪入眼，只有10%左右。这一部分原因是由于Hu不变矩只用到低阶矩（最多也就用到三阶矩），对于图像的细节未能很好的描述出来，导致对图像的描述不够完整。Hu不变矩一般用来识别图像中大的物体，对于物体的形状描述得比较好，图像的纹理特征不能太复杂，像识别水果的形状，或者对于车牌中的简单字符的识别效果会相对好一些。

# 背景建模
### 固定背景
使用中值法或均值法实时更新背景，主要为了筛去图像中混入的噪声以及运动物体，保持原始背景的更新，在亮度变化后长时间的背景均变化，所以此方法可以有效的更新背景，当短时间内有运动物体混入时，由于前面很长一段时间背景都没有运动物体，所以依然保持为原背景。  

### 非固定背景
单高斯分布背景模型：只适合处理微小变化或者缓慢变化的场景  
混合高斯模型：变化较大较快时实用

### 统计背景建模
固定的不稳定，非固定的计算太复杂，使用文献中提到的统计背景建模法与肤色检测法相结合，可以较好的识别手形轮廓。首先将前一帧保存进preFrame一共帧差使用，再初始化累加帧acc和计数帧count，然后遍历每一帧时先转换成灰度固定大小，然后帧差阈值和肤色检测，两者先与操作后进行形态学操作，即可进行下一步处理，最后需要实时更新背景，即在帧差的二值图的基础上将黑色区域（无运动物体）累加进acc，然后在计数帧的对应像素点++，然后更新背景图像为累加图的每个像素点除以每个像素点的累加次数，转为8位后的背景图即可参与差操作。  

# 支持向量机
[机器学习四类](https://blog.csdn.net/kiss__soul/article/details/81625275)分类 回归 聚类 降维  
### 原理
#### 优化目标
- 前半部分使用C替换2m，后面正则化参数λ/m直接去除，整体效果变成前面的约束而不是参数的约束 
#### 大边界的直观理解 
- C非常大时——>大间距分类器  过拟合  

#### 核函数1

### 代码
**函数**  
- [range](https://blog.csdn.net/u013066730/article/details/88852240)用来表示矩阵的多个连续的行或者多个连续的列  Range表示范围从start到end，包含start，但不包含end；  
- sprintf_s与sprintf的不同:sprintf_s是sprintf的安全版本，指定缓冲区长度来避免sprintf()存在的溢出风险，主要差在sprintf_s第二个参数，可以控制缓冲区大小  
- [c_str()](https://blog.csdn.net/u013682388/article/details/39547773)生成一个const char*指针，指向以空字符终止的数组，内容与本string串相同，现用先转换，要么把它的数据复制到用户自己可以管理的内存中。  
- [遍历目录](https://blog.csdn.net/wangqingchuan92/article/details/77979669?depth_1-utm_source=distribute.pc_relevant.none-task&utm_source=distribute.pc_relevant.none-task)使用这个结构体才能够将文件的信息存储到该结构体的内存空间，需要_findfirst（）、_findnext（）和_fineclose（）三个函数的搭配使用  
- [intptr_t](https://blog.csdn.net/cs_zhanyb/article/details/16973379?depth_1-utm_source=distribute.pc_relevant.none-task&utm_source=distribute.pc_relevant.none-task)在64位的机器上，intptr_t和uintptr_t分别是long int、unsigned long int的别名；在32位的机器上，intptr_t和uintptr_t分别是int、unsigned int的别名,为了提高程序的可移植性（在32位和64位的机器上）  
- [assign()](https://blog.csdn.net/zhanglu5227/article/details/8605237)字符串赋值的常用函数  
- 参数初始化  CvSVMParams::CvSVMParams（） : svm_type（CvSVM::C_SVC）， kernel_type（CvSVM::RBF）， degree（0），  
    gamma（1）， coef0（0）， C（1）， nu（0）， p（0）， class_weights（0）  
{  
    term_crit = cvTermCriteria（ CV_TERMCRIT_ITER+CV_TERMCRIT_EPS， 1000， FLT_EPSILON ）;  
}  
**数据集**
- 采集1000个左右的正样本
- 待采集更多的负样本
- 养图分解成多个样本时，使用range函数来获取局部信息，将多个图合成一个大图时使用rect以及copyto函数
- 访问文件信息需要添加io头文件，以及使用getfile函数（自定义）

### 特征检测
- **hu矩**  
在使用所有像素点作为样本输入训练以后，发现可以提取图像的特征以后再训练，效率会更加高，然后首先使用的便是最基本的hu矩，检测到7个hu矩值以后使用前四个作为一个样本进行训练，最后发现特征不是很明显导致训练的效果没法看，可能是参数没有调好吧，可能还是需要用线性核而不是RBF核吧，因为RBF核完全使用的是默认的参数来训练。

- **SURF+BOW**  
使用其他提取图像特征的算法，优先看到的是SURF SIFT HOG等，由于SURF是优化版的SIFT，所以只考虑SURF，其他的都可以在此基础上修改即可。首先对于每个样本用SURF检测得到几十个特征点，维度是64（SIFT是128维），由于个数不固定导致无法像之前的一样直接变成一行就可以成为样本，现在将考虑对此特征进行聚类（不是降维，降维是针对维度较高的问题，是优化，而此时面临的问题是特征个数不统一的话根本没有办法训练），所以使用基于K-MEANS的BOW算法以后可以得到1000*64的字典（具体见BOW算法），其中关于2和3版本opencv对featureDectect的定义不同白忙活了一天，最后发现全使用独立的PTR<SURF>初始化即可。最后使用字典重新遍历一遍所有样本，对检测到的不固定的特征点映射到字典上，大致意思就是统计字典的每个特征出现的次数作为唯一特征，即输出1*1000的向量作为训练的样本。由于每次BOW降维非常耗时，1450个样本检测到的特征点（大致几万个特征点）降维成1000个需要差不多20多分钟，所以考虑把训练的vocab保存下来，下回直接读取即可，学习到FileStorage函数，直接可以对xml文件进行读取，最后记得释放即可。