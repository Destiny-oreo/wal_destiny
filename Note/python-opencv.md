# 环境搭建
- 安装完anaconda+python以后需要安装tensoflow，但是使用深度学习框架需要GPU，中间就需要安装CUDA来调用显卡进行大量并行计算，显卡920M适合的CUDA版本是8.0版本，去下载时发现要求显卡驱动程序要大于376版本，查询以后发现自带的显卡驱动程序版本为368.70版本，不满足最低要求，所以在官网下载最新配套版本425.31，更新显卡驱动有可能出现不兼容等问题，所以需要将原版本备份，第一是下载了驱动精灵，先备份了原版驱动（驱动精灵是流氓软件，还好安装时候火绒杀毒把病毒隔离了，用完赶紧卸载），然后使用属性中的系统保护设置了系统还原点，如何出现问题也可以还原回4-10号的电脑驱动情况，最后也可以在设备管理器里回滚驱动程序的版本。（安装时第一次安装失败，查询原因后发现需要将windows installer开启才可以，去了管理工具-服务找到并开启即可安装成功）。  
- 安装CUDA8.0.61，结果自带的显卡驱动把我上面安装的驱动又给替换了，换成了376.51版本，好像上面一大段白忙活了。cmd nvcc -V安装成功。  
- pip版本10.0.1，在清华镜像成功下载tensorflow的1.2.0的压缩包，在官网下很久都下不下来，其中下了正常版和rc2版，查阅[资料](https://www.cnblogs.com/shuaishuaidefeizhu/p/11098310.html)后发现rc版是release Candidate版本，没有正常版本稳定，所以下载的两个选用没有RC的那个。在该目录下使用pip install进行安装，结果read timeout错误，查阅[资料](https://blog.csdn.net/qq_31511955/article/details/80837863?depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromBaidu-1&utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromBaidu-1)发现pip -–default-timeout=100 install -U XXXX来安装就成功了。接着安装tensorboard，先要创建一个环境conda create -n tensorflow python=3.6（--name)来操作，可以管理很多[环境](https://blog.csdn.net/u014628771/article/details/80066624?depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromBaidu-2&utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromBaidu-2)，但是一直建立失败，使用python clean -i之后就意外可以了，也不知道什么原因。创建成功以后会要求下载一些包，然后使用activate xx来激活，然后install就行了。由于国外源下载速度太慢，更新为镜像源即可，在lenvo地下新建pip文件夹输入相关文件即可。（在roaming地下新建测试以后没有用）。由于建立的虚拟环境里的包的数量太少，所以回到默认环境中安装了tensorflow、tensorboard、opencv-python、opencv-contrib-python包，测试以后可以使用   
- anaconda[命令记录](https://blog.csdn.net/lovetobelove/article/details/86605194)  conda env list、deactivate 、conda create -n tensorflow python=3.7

# 常用函数及注意事项
- **imread**:单引号内写入图片名称地址，第二个参数小于1原图，等于1灰图，大于1彩色图
- [**shape**](https://blog.csdn.net/likeyou1314918273/article/details/89510234):numpy.core.fromnumeric中的函数，它的功能是查看矩阵或者数组的维数,输入为数时返回0，输入一位矩阵时返回列数，输入二维矩阵时返回 行X列  
- **python main**函数内变量均为全局变量，函数内都可以随意调用  
- res = cv2.**bitwise_and**(frame, frame, mask=fgmask) 抠取mask部分的frame图
- cv.**GaussianBlur**函数 sigmaY=0时，其值自动由sigmaX确定（sigmaY=sigmaX）；sigmaY=sigmaX=0时，它们的值将由ksize.width和ksize.height自动确定；  
- void **putText**( Mat& img, const string& text, Point org, int fontFace,double fontScale，  Scalar color, int thickness=1, int lineType=8 );Point org， 第一个字符左下角坐标，我们设定在图片的Point（50,60）坐标。表示x = 50,y = 60，cv::getTextSize()接口先获取待绘制文本框的大小，以方便放置文本框的中心位置  
- (x,y,w,h) = cv2.**boundingRect**(img)，x，y是矩阵左上点的坐标，w，h是矩阵的宽和高 -->cv2.rectangle(img, (x,y), (x+w,y+h), (0,255,0), 2)画出矩行  
- fgbg = cv2.**createBackgroundSubtractorMOG2**()	(int history = 500,double varThreshold = 16）  
- **defects** = cv2.convexityDefects(contours[indx], hull2) python的缺陷检测输出的类似16*1*4，三维向量第一维缺陷区域个数，第二维坐标，第三维代表起点终点最深点深度值  
- **坐标点**使用(int(x),int(y))来表达——tuple类型 centers = (int(mo['m10'] / mo['m00']), int(mo['m01'] / mo['m00']))  
- **angle** = random.randrange(-90, 90)正逆时针  w=xxshape[1]  h=xxshape[0]   M = cv2.getRotationMatrix2D((w/2,h/2), angle, scale) image = cv2.warpAffine(image,M,(w,h))  
- [**numpy.ravel()**](https://blog.csdn.net/hanshuobest/article/details/78882425)用于降维，多维降成一维,但返回的是视图，修改以后会改变原矩阵，flatten返回的是拷贝  
- **meshrid**函数，绘图时如有两个自变量时需要使用，扩展以后才可以作为坐标轴的范围  
- [**train_test_split**函数](https://www.cnblogs.com/Yanjy-OnlyOne/p/11288098.html)X_train,X_test, y_train, y_test =sklearn.model_selection.train_test_split(train_data,train_target,test_size=0.4, random_state=0,stratify=y_train)  
- [**numpy.loadtxt()**](https://blog.csdn.net/ACID_lv_ing/article/details/87092714)加在csv，json，vml，hdf等文件  
- [**字符串前缀u、b、r**](https://www.cnblogs.com/liangmingshen/p/9274021.html)b:字符串存储为Ascll码，无法存储中文;无前缀或u：可以存储中文；r前缀：主要解决的是 转义字符  
- [**numpy.split()函数**](https://blog.csdn.net/mingyuli/article/details/81227629)indices_or_sections:如果是一个整数，就用该数平均切分，如果是一个数组，为沿轴切分的位置（左开右闭） axis：沿着哪个维度进行切向，默认为0，横向切分。为1时，纵向切分;arange参数为整数时全是uint32，小数时全为float  
- SVM：cls=svm.SVC、cls.fit、cls.score;误差函数为C*()+1/2θ方，C过大，过拟合，不是很大时候才是大边界。逻辑回归sigma曲线将参数变成Z以后方便数学推导，将逻辑回归的代价函数变形以后变成cost函数作为支持向量机的代价函数；参数θ与边界垂直是因为θ坐标(θ1,θ2) 斜率2/1，边界曲线为θTx=θ1x1+θ2x2=0，斜率-1/2，所以垂直。大间距分类器原因：优化目标变成1/2θ方，另一半代价函数作为约束条件，即px|θ|大于1或..θ越小要求p越大，即投影值越大。

# 1课程概述
- 计算机视觉  图像处理 机器人 神经科学 认知科学 机器学习 计算图像学 信息获取 算法 硬件系统  
- 主要研究问题 生成对抗网络GAN 递归神经网络RNN  
- 实践环境 opencv3.4 python3.6 tensorFlow1.9+ keras
- 函数 


# 2图像预处理
#### 图像显示与存储原理
- **颜色空间**：RGB：加法混色，彩色显示器，3通道，像素表达：BGR，取值0-255(8u)或0.0-1.0(float)；CMYK：减法混色，印刷，4通道，取值范围同上；HSV：人类视觉概念，画家配色，3要素 色调 饱和度 明度，取值范围同样；CIE-XYZ：定义最精确，国际照明协会1931,3色刺激  
- **图片储存原理**：单通道 G=R*0.3+G*0.59+B*0.11；
- **图像处理方法**：空间域：点运算（HE CLANE） 形态学运算（膨胀 腐蚀） 邻域运算（卷积 金字塔）  频率域（可以快速计算卷积的方法）：傅里叶变化 小波变换  
#### 图像增强的目标
改善视觉效果，转为更适合人或机器分析处理的形式，突出有意义的信息，抑制无用信息提高图像的使用价值，包括图像锐化 平滑 去噪 灰度调整-对比度增强  
#### 点运算：基于直方图的对比度增强
**直方图**（图片特征分布的统计，区间的概念，对数据空间进行量化）   
**直方图均衡化**（对比度调整，增加图像的局部对比度，有效扩展常用的亮度，非线性拉伸->重分配各个灰度单位的像素点数量）  
**自适应直方图**（包括明显亮或者明显暗，**AHE**对局部区域进行直方图均衡，移动模板滑动做直方图均衡）   
**CLAHE**（AHE会过渡放大图像相对均匀区域的噪声，直方图修建过程，用修建后的直方图均衡图像，显得更加自然，采用（双）线性插值，步骤：分块 计算直方图 修建直方图并均衡，遍历各个块，进行块间双线性插值 与原图做图层滤
#### 形态学处理
膨胀 腐蚀 开操作（目标外的孤立点） 闭运算（目标内的空洞）
#### 空间域处理、卷积的应用：平滑，边缘检测，锐化等
**滤波、卷积**卷积核叠在原图片各个区域进行运算，不同功能需要定义不同的核函数，滤波函数（权重参数）与像素邻域值运算；边界填充padding，核越大补充越多（补0、边界复制、镜像、块复制）  
**均值滤波**：很少使用，去不掉噪声也破坏了图像的细节使图像十分模糊  
**中值滤波**：奇数尺寸，有效去除椒盐噪声  
**高斯滤波**：奇数尺寸，模拟人眼关注中心区域，有效去除高斯噪声，sigma越小，关注区域越集中，变大时非常模糊，用来高斯金字塔变小使用，2D卷积可以拆分成两个相同的1D卷积（K方->2K的复杂度）  
**梯度prewitt滤波卷积**：水平梯度/垂直边缘  垂直梯度/水平边缘，-1 0 1  -1 0 1 -1 0 1
**梯度Sobel滤波卷积**： 更改prewitt，-1 0 1 -2 0 2 -1 0 1（允许中间高一点点的变化，另一边依旧高斯平滑）  
**梯度Laplacian**：二阶微分算子，团块（周边高于或低于中心点）/边缘检测（像素快速变化的区域）——>锐化
#### 卷积的应用：平滑，边缘检测，锐化等
 
#### 频率域处理：傅里叶变换，小波变换
空域卷积 = 频域乘积 ->快速傅里叶、相乘、快速逆傅里叶  
**高斯金字塔**：先图像平滑再降采样，损失信息较少，本质上为信号的多尺度表达法  
**拉普拉斯金字塔**：高频细节信息丢失，保留所有层所丢失的高频信息用于图像恢复，得到的是细节信息——突变的地方。  
**傅里叶变换FT**：（一个信号可以由足够多的个不同频率和幅值的正余弦波组成，Asinwx+Bcoswx）频段滤除，当有竖线存在于图像时，使用傅里叶变换将中心两侧的白色亮点消除即可。np.fft.fft2，fftsshift...  
**短时傅里叶变换SIFT**：添加时域信息设置窗格，认为窗格内的信号是平稳的，然后对窗格内的信号FT；  
**小波变换**：与SIFT思路接近，但把FT的基给换了——将无限长的三角函数基换成有限长的会衰减的小波基。均值为0，时频都局部化，最简单的是Haar小波，
#### 应用案例：平滑，边缘检测，CLAHE等

# 3图像特征与描述
#### 颜色特征：量化颜色直方图，聚类颜色直方图
- **量化颜色直方图**：RGB HSV等 统计落在量化单元上的像素数量，计算高效但是很稀疏  
- **聚类颜色直方图**：Lab等颜色空间，先对所有像素点颜色向量聚类，单元bin有聚类中心代表；lab空间是用数字化的方法描述人的视觉感应。  问题：错开一个bin以后相似度很低，采用二次式距离来解决，或者平滑滤波，使每个bin的像素对于相邻bin也有贡献。
#### 几何特征：Edge,Corner,Blob
- **边缘**：Edge，像素明显变化的区域——>一阶导数的极值区域（对于区域颜色变化不均匀的区域会导致一阶导数很多小的极值点，先高斯去燥平滑，再一阶导数），用于物体识别 几何视角变换等；边缘提取：梯度幅值、梯度方向；标准差的大小决定了边缘尺度的大小

#### 基于关键点的特征描述子：SIFT、SURF、ORB
从不同距离 方向 角度 光照条件等观察时都可以判断成功，即存在理想的特征描述子，描述子的可复现性；  
**关键点**：不同视角的映射关系，可重复、显著性、抗图片变换；可达到图片拼接、追踪、导航、3D重建等  
**Harris角点**：在任何方向上移动小观察窗，导致大的像素变动；偏移后的窗内图像与原图像的相差平方（乘以权重）；直线时一个特征值大另一个小，平面是两个都小，角点时两个都大  
**FAST角点**：若某像素点与周围领域内（16个）足够多的像素点处于不同的区域，阈值t观察3像素半径的圆边界的16个像素，如果有12个连续的像素比中心点+-t都大或者小就说明是角点。复杂度小，但不产生多尺度特征也没有方向信息，失去旋转多样性。  
**斑点Blob**：拉普拉斯梯度（二阶导为0  对噪声敏感）——>高斯拉普拉斯梯度LOG特征，二阶导的极大值为斑点  
**SIFT**：基于尺度空间不变的特征，具有良好的不变性（旋转 尺度缩放 平移 亮度变化 对视角变化等有一定稳定性） 步骤：DOG尺度空间获取极值点（LOG DOG高斯差分比较快 计算量小的多）（使用不同的核进行高斯模糊 在差分得到结果），对关键点处理（精确关键点 去除边缘点） 关键点的方向估计 关键点描述子的生成（区域坐标的旋转 计算采样区域的直方图） **高斯金字塔**：每一层的高斯参数sigma不同；中心点比相邻两维9矩形的26个点都大或者都小才为特征点；特征点方向估计：对8个方向计算梯度直方图最高值的方向  

**Haar-like特征**：边缘特征、线性特征、中心特征、对角线特征——组成了特征模板  
**SURF**：比SIFT速度提高了3倍，变换图为原图每个像素的hessian矩阵行列式的近似值构成的；统计特征点领域内的Haar小波特征，统计6块60度扇形所有点在x和y方向的小波响应总和，将最大值扇形方向作为主方向；先确定候选点，再找最大值，使用Haar模板  
**ORB特征描述**：基于FAST角点的特征点检测与BRIEF特征描述技术，速度非常快，准确率还高。**BRIEF**：先平滑图像，在特征点周围选择一个Patch，通过特定方法挑选点对（有5种生成方式）...

#### 其他特征：LBP、Gabor
**LBP局部二值模式**：将每个像素点与周围点大小比较，要么大要么小，多个bit组成一个数（取最小的排列顺序，解决旋转不变性），统计每个数的直方图——>灰度不变性+旋转不变性  
**Gabor**：用于边缘提取的线性滤波器，类似于人类的视觉系统

# 4未有深度学习之前




# 5神经网络与误差反向传播算法




# 6深度学习基础


# 7图像分类


# 8图像检索



# 9 10目标检测





# 11通用场景图像分割



# 12医疗影像分割


# 13图像描述


# 14图像生成

