### 综述

- 专有名词

  > 1. SFM structure from motion 从运动中恢复结构
  > 2. 开源软件。用于商业目的
  > 3. meshroom：一款基于AliceVision的三维重建软件
  > 4. AliceVision：摄影测量计算机视觉框架，提供3D重建和相机跟踪算法
  > 5. openmvs：面向计算机视觉的库，尤其是针对多视图立体重建，输入是一组摄影机姿势加上稀疏的点云，输出是带纹理的网格
  > 6. openmvg：提供端到端的3D重建，由图像框架组成，包含库、二进制文件和管道

- 基于单目视觉的三维重建算法

  > 1. 包含三个方面，基于SFM的运动恢复结构，基于DeepLearning的深度估计和结构重建（Monocular、Multiocular），以及基于RGB-D深度摄像头的三维重建
  > 2. SFM 基于多视觉几何原理，从无时间序列的2D图像中推算三维信息；是一个估计相机参数及三维点位置的问题；
  > 3. 流程：多视角图像，图像特征提取匹配，稀疏重建SFM，稠密重建MVS，点云模型化，三维模型
  > 4. 分类：增量式 全局式 混合式 层次式；基于语义的sfm，基于深度学习的sfm

- SFM与三维重建

  > 流程：提取图像特征sift surf等---利用特征计算图像之间的特征匹配---基于匹配的特征进行稀疏重建 得到各个图像的相机位姿和稀疏的特征点云SFM---基于相机位姿进行稠密重建得到稠密点云---基于点云重建网格 体素和纹理
  >
  > 1. 三维重建概述：计算机视觉两个基本方向：物体识别和三维重建
  > 2. [对极几何](https://blog.csdn.net/weixin_43822880/article/details/105636219)

## openMVg+openMVS

#### [环境搭建](https://jiajiewu.gitee.io/post/tech/slam-sfm/openmvg-openmvs/)--[参考](https://blog.csdn.net/shanwenkang/article/details/103196001)

> **#Prepare and empty machine for building:**
> sudo apt-get update -qq && sudo apt-get install -qq
> sudo apt-get -y install git cmake libpng-dev libjpeg-dev libtiff-dev libglu1-mesa-dev
> main_path=`pwd`  `可以不执行，后续输入真实路径即可`
>
> **#[Eigen](https://blog.csdn.net/qq_36594547/article/details/102955881) (Required)**  `cat /usr/include/eigen3/Eigen/src/Core/util/Macros.h` 3.2.10
>
> - 最烦人的一步，网上教程都是一定改成3.2版本，然后在最后sudo make时一直报
>
>   ```
>   [ 44%] Building CUDA object libs/MVS/CMakeFiles/MVS.dir/PatchMatchCUDA.cu.o
>   /usr/local/include/eigen3/Eigen/src/Core/DenseCoeffsBase.h(137): error: no suitable conversion function from "const Eigen::ReturnByValue<Eigen::internal::homogeneous_left_product_impl<Eigen::Homogeneous<Eigen::CwiseUnaryOp<Eigen::internal::scalar_cast_op<int, float>, const Eigen::Matrix<int, 2, 1, 0, 2, 1>>, 0>, Eigen::Matrix<float, 3, 3, 0, 3, 3>>>::YOU_ARE_TRYING_TO_ACCESS_A_SINGLE_COEFFICIENT_IN_A_SPECIAL_EXPRESSION_WHERE_THAT_IS_NOT_ALLOWED_BECAUSE_THAT_WOULD_BE_INEFFICIENT" to "const float" exists
>   ```
>
>   然后查了所有环境，opencv3.4.14重新编译，更改cuda版本，Boost重新安装1.71，ceres改成1.14和1.12等，eigen改成3.2.10 3.2.3 3.3.4最后改成3.4才可以通过  make install以后默认安装在`/usr/local/include`，自己在/usr/include/上加了软链接（/home/wal/project/Files/Githubs/3D/openMVS），只能手动更换版本
>
> git clone https://gitlab.com/libeigen/eigen.git --branch 3.4
> mkdir eigen_build && cd eigen_build
> cmake . ../eigen
> make && sudo make install
> cd ..
>
> **#Boost (Required)**  `dpkg -S /usr/include/boost/version.hpp`：： `libboost1.71-dev:amd64: /usr/include/boost/version.hpp`  
> sudo apt-get -y install libboost-iostreams-dev libboost-program-options-dev libboost-system-dev libboost-serialization-dev
>
> **#OpenCV (Required)**
> sudo apt-get -y install libopencv-dev
>
> **#CGAL (Required)**
> sudo apt-get -y install libcgal-dev libcgal-qt5-dev
>
> **#VCGLib (Required)**
> git clone https://github.com/cdcseacave/VCG.git vcglib
>
> **#Ceres (Optional)**  `对engen有版本依赖`
> sudo apt-get -y install libatlas-base-dev libsuitesparse-dev
> git clone https://ceres-solver.googlesource.com/ceres-solver ceres-solver
> mkdir ceres_build && cd ceres_build
> cmake . ../ceres-solver/ -DMINIGLOG=ON -DBUILD_TESTING=OFF -DBUILD_EXAMPLES=OFF
> make -j2 && sudo make install
> cd ..
>
> **#GLFW3 (Optional)**
> sudo apt-get -y install freeglut3-dev libglew-dev libglfw3-dev
>
> **#OpenMVS**
> git clone https://github.com/cdcseacave/openMVS.git openMVS
> mkdir openMVS_build && cd openMVS_build
> cmake . ../openMVS -DCMAKE_BUILD_TYPE=Release -DVCG_ROOT="$main_path/vcglib"
>
> #If you want to use OpenMVS as shared library, add to the CMake command:
> `-DBUILD_SHARED_LIBS=ON`不能添加 否则有DSO missing from command line collect2: error: ld returned 1 exit statu错误
>
> #Install OpenMVS library (optional):
> make -j2 && sudo make install

#### 代码分析

- openMVG

  > ```python
  > os.path.dirname #去掉文件名，返回目录
  > os.path.abspath(__file__) # 返回文件绝对路径 
  > os.chdir() #方法用于改变当前工作目录到指定的路径。
  > subprocess #模块允许我们启动一个新进程，并连接到它们的输入/输出/错误管道，从而获取返回值。
  > ```
  >
  > openMVG
  >
  > ```python
  > 1.openMVG_main_SfMInit_ImageListing#您生成一个 sfm_data.json 文件，openMVG 将其用作场景描述
  > 2.openMVG_main_ComputeFeatures#计算给定 sfm_data.json 文件的图像描述。对于每个视图，它计算图像描述（局部区域）并将它们存储在磁盘,输出svg文件
  > 3.openMVG_main_ComputeMatches#图像描述，我们建立相应的假定光度匹配并使用一些强大的几何过滤器过滤结果对应
  > 4.1.openMVG_main_IncrementalSfM#增量管道，旨在在 sfm_data.json 文件和一些预先计算的匹配项上运行
  > 4.2.openMVG_main_GlobalSfM#全局融合，当视图被增量处理时，这种外部校准可能会发生漂移，这与均匀分布残差的全局方法相反。在这里，该方法提出了一种基于图像对之间相对运动融合的新全局校准方法，旨在在 sfm_data.json 文件和一些预先计算的匹配项上运行。该链将仅考虑具有已知近似焦距的图像。具有无效内部 ID 的图像将被忽略。
  > ---------------------------------------------
  > 11.openMVG_main_ComputeSfM_DataColor#计算 sfm_data 场景结构的颜色，旨在在 sfm_data.json 文件上运行
  > 12.openMVG_main_ComputeStructureFromKnownPoses#该应用程序计算相应的特征，并根据已知相机内在特征和姿势的几何形状对它们进行稳健的三角测量。
  > ---------------------------------------------
  > 21.openMVG_main_ExportUndistortedImages#此应用程序从已知的相机参数内在导出未失真的图像。
  > ```
  >
  > ```python
  > ComputeMatches -i sfm_data.json -o xx         -g ar 1
  > ComputeMatches -i /matches/ sfm_data.json-o /matches    -g ar 0.6
  > ComputeFeatures -i /matches/sfm_data.json -o /matches -p ULTRA
  > ComputeMatches -i /matches/sfm_data.json -o /matches -g a -r 0.8
  > 
  > 
  > ```
  >
  > 

- openMVS

  > ```python
  > 1.openMVG_main_openMVG2openMVS -i sfm_data.bin -o s1.mvs#sfm_data.bin包含相机姿势和稀疏点云的文件,使用OpenMVG转换为OpenMVS项目scene.mvs
  > 2.DensifyPointCloud s1.mvs #密集点云重建，如果场景部分丢失，密集重建模块可以通过估计密集点云来恢复它们，默认情况下采用 Patch-Match 方法
  > 3.ReconstructMesh -d 4 s1_dense.mvs#粗糙网格重建，将前面步骤中得到的稀疏或密集点云作为网格重建模块的输入：
  > 3.1.RefineMesh s1_dense_mesh.mvs --max-face-area 16#网格细化（可选），从稀疏或密集点云获得的网格可以进一步细化以恢复所有精细细节甚至更大的缺失部分。接下来，仅从稀疏点云中获得的粗糙网格被细化
  > 4.TextureMesh s1_dense_mesh_refine.mvs#网格纹理，将前面步骤中得到的网格作为网格纹理模块的输入
  > 5.Viewer s1_dense_mesh_texture.mvs
  > ```

- 运动结构恢复sfm

  - 全局式

    > 先对所有的图像计算匹配关系，进行三角化生成三维点，通过pnp估计出位姿，然后用BA(Bundle Ajustment)进行一个整体的优化，效率较高，鲁棒性较差
    >
    > ```python
    > 0.1 openMVG_main_SfMInit_ImageListing#("-i", self.input_dir, "-o", self.matches_dir, "-d", camera_file_params, "-c", "3")
    > 0.2 openMVG_main_ComputeFeatures#("-i", self.matches_dir+"/sfm_data.json", "-o", self.matches_dir, "-m", "SIFT", "-f" , "1")
    > 0.3 openMVG_main_ComputeMatches#("-i", self.matches_dir+"/sfm_data.json", "-o", self.matches_dir+"/matches.putative.bin", "-f", "1", "-n", "ANNL2")
    > 2.1 openMVG_main_GeometricFilter#("-i", self.matches_dir+"/sfm_data.json", "-m", self.matches_dir+"/matches.putative.bin" , "-g" , "e" , "-o" , self.matches_dir+"/matches.e.bin")
    > 2.2 openMVG_main_SfM#("--sfm_engine", "GLOBAL", "--input_file", self.matches_dir+"/sfm_data.json", "--match_file", self.matches_dir+"/matches.e.bin", "--output_dir", self.global_dir)
    > 2.3 openMVG_main_ComputeSfM_DataColor#("-i", self.global_dir+"/sfm_data.bin", "-o", os.path.join(self.global_dir,"colorized0.ply"))
    > 2.4 openMVG_main_ComputeStructureFromKnownPoses#("-i", self.global_dir+"/sfm_data.bin", "-m", self.matches_dir, "-o", os.path.join(self.global_dir,"robust0.ply"))
    > ```
    >
    > 
  
  - 增量式
  
    > 先选出两张影像激进行初始化，接着一张张图像进行配准以及点的三角化，一边三角化和pnp，一边进行局部BA，效率较低，鲁棒性较高，在无序图像数据集重建中应用最广泛
    >
    > ```python
    > 0.1 openMVG_main_SfMInit_ImageListing#("-i", self.input_dir, "-o", self.matches_dir, "-d", camera_file_params, "-c", "3")相机型号类型针孔径向3（默认）
    > 0.2 openMVG_main_ComputeFeatures#("-i", self.matches_dir+"/sfm_data.json", "-o", self.matches_dir, "-m", "SIFT", "-f" , "1") -m用于描述图像的方法：-f强制重新计算数据
    > 0.3 openMVG_main_ComputeMatches#("-i", self.matches_dir+"/sfm_data.json", "-o", self.matches_dir+"/matches.putative.bin", "-f", "1", "-n", "ANNL2")-n最近匹配方法
    > 1.1 openMVG_main_GeometricFilter#("-i", self.matches_dir+"/sfm_data.json", "-m", self.matches_dir+"/matches.putative.bin" , "-g" , "f" , "-o" , self.matches_dir+"/matches.f.bin")
    > 1.2 openMVG_main_SfM#("--sfm_engine", "INCREMENTAL", "--input_file", self.matches_dir+"/sfm_data.json", "--match_dir", self.matches_dir, "--output_dir", self.sequential_dir)
    > 1.3 openMVG_main_ComputeSfM_DataColor#("-i", self.sequential_dir+"/sfm_data.bin", "-o", os.path.join(self.sequential_dir,"colorized1.ply"))
    > 1.4 openMVG_main_ComputeStructureFromKnownPoses#("-i", self.sequential_dir+"/sfm_data.bin", "-m", self.matches_dir, "-o", os.path.join(self.sequential_dir,"robust1.ply"))
    > ```
    >
    > 
  
  - 层级式
  
    > 先将影像进行分组，每组进行配准，再对上一步的结果进行配准重建

#### 进度

- 12.20

  > 1. 使用python标定相机，代码保存在`mycobot/tools`下面，calibrate是相机标定程序，disparity是使用imgs下面的图像进行三维重建，一次只能输入两张图片，因为使用的方法是opencv进行重建，所以效果很差，但是标定程序具有参考意义（使用时需要修改#31calibration_paths以及#15chessboard_size，其中棋盘大小为行数-1乘以列数-1）
  > 2. 寻找其他三维重建的开源框架，最终确定了openMVG和openMVS相结合的框架，花了两三天的时间进行环境配置，最终12.17左右配置完成，到20号左右将其中代码逻辑以及数据集制作流程大致看了一遍，将流程代码汇总进了sfm_demo.py脚本中，可以自由选择一键进行三维重建，只需要指定输入路径以及输出路径即可
  > 3. 检查输入数据集时发现官方流程并没有输入位姿以及焦距 畸变参数等信息，只是输入了传感器宽度摄像机数据集，从里面自动查找相机焦距，但是并没有讲明如何查找的焦距信息，查询资料后发现输入数据集自带exif信息，可以使用exiftool工具进行查看，源代码下载安装了exiftool 12.37，查看照片信息格式以及尝试添加修改信息

- 重建参数整理

  > 1. ./Viewer -v 2 -i ~/mvs_input/model.mvs查看点云
  > 2. openMVGSpherical2Cubic OpenMVG2OpenMVS 导出器用于球形图像场景或球形到立方体导出器可能也有问题
  > 3. 仅从离相机足够近的表面生成密集点云，使用openMVG设置参数并增加误差以增加生产点数，如何在使用openMVS 生成致密点云时设置参数，即使接收到的注册点较少

### [使用opencv三维重建](https://blog.csdn.net/qccz123456/article/details/86593000)

#### 1.立体三维重建所需步骤

- [立体重建三部曲](https://www.yanxishe.com/TextTranslation/1412)

  > 1. 基本前提：需要一张尽量精确的深度图，图中每一个像素表示的都会深度信息而不是颜色信息，以灰度图的形式展现
  > 2. 传感器：可以是简单相机（RGB相机）或其他传感器如激光雷达、红外线等，类型决定深度图的精确程度；
  > 3. 根据传感器类型，决定了获取深度图所需的步骤，如Kinect使用红外传感器和RGB相机相结合，可以直接得到一张深度图，而普通摄像头需要做立体重建，和大脑、眼睛理解深度的原理一样，它的要旨在于从两个不同的角度看同一幅画，从两幅画中寻找相同的东西，并根据位置的不同推断深度，叫立体匹配
  > 4. 为了做立体匹配，多张图片必须具有完全相同的特性，需要知道摄像机的光学中心和焦距，所以步骤如下：
  >    1. 相机矫正：利用一组图片推断相机的光学中心和焦距
  >    2. 图像畸变：消除重建所用图像中的镜头畸变
  >    3. 特征匹配：在多张图片中寻找相似的特征并构建深度图
  >    4. 重投影点：使用深度映射将像素重投影到三维空间
  >    5. 建立点云：生成一个新的文件，这个文件中包含了三维空间中的点
  >    6. 构建网格来得到实际的三维模型

#### 2.代码[矫正相机](https://zhuanlan.zhihu.com/p/41152930)

- 立体重建三部曲

  > ls /dev/video*
  >
  > ls -ltrh /dev/video*
  >
  > 1. 输入照片存在失真，纠正此问题需要知道相机的内部参数
  >
  > 2. 打印棋盘图案，尽量使每个正方形都是30mm，然后使背景尽量纯白平坦，节省矩阵计算时间；确保较好的光照背景，从不同角度拍摄图片，20-64张左右，此博客中采用python实现，可考虑c++实现
  >
  > 3. 编程
  >
  >    ```python
  >    tqdm # 使用进度条形式提示循环进度
  >    glob.glob(path+'*.py') # 得到某个格式下所有文件列表，带有路径文件的列表
  >    os.listdir(path) # 得到path下所有文件列表，没有文件路径只有文件名字
  >    np.prod # 返回给定轴上数组元素的乘积
  >    cv2 .waitKey (0) & 0 xFF # 只关心按下键的ascll码，无视NumLock是否按下
  >    ret,corners = cv2.findChessboardCorners # 找到角点坐标
  >    cv2.cornerSubPix(gray_image, corners, (5,5), (-1,-1), criteria) # 找到小数点更加精确的亚像素角点
  >    calibratecamera ：
  >    	# ret 重投影的总均方根误差
  >        # k 内参矩阵
  >        # dist 畸变矩阵
  >        # rvecs 旋转向量
  >        # tvecs 位移向量
  >    ```
  >
  > 

#### 3.重建





### 背景知识

- 串联机器人

  > 1. 给定一组关节角的值，计算操作臂末端执行器的位置和姿态；正运动学问题是计算工具坐标系相对于基坐标系的位置和姿态，成为关节空间描述到笛卡尔空间描述的操作臂位置表示；
  > 2. 末端执行器的工具坐标系描述操作臂的位置，与工具坐标系相对应的是与操作臂固定底座相连的基坐标系；
  > 3. **操作臂逆运动学**：给定操作臂末端执行器的位置和姿态，计算所有可达给定位置和姿态的关节角；
  > 4. 空间描述：
  >    1. d1=131.56mm
  >    2. a2=110.4mm
  >    3. a3=96mm
  >    4. d4=64.62mm
  >    5. d5=73.18mm
  >    6. d6=48.6mm

- DH参数

  > 1. 连杆坐标系：
  >
  >    Axis_i-1:Link_i-1的驱动轴
  >
  >    Asix_i对应Link_i-1的传动轴以及Link_i的驱动轴
  >
  > 2. 参数
  >
  >    theta_i代表前后坐标系x轴的夹角，也就是Axis_i的旋转角度
  >
  >    d_i代表O_I相对于O_I-1在z_i-1的偏移量
  >
  >    alpha_i代表Link_i的驱动轴和传动轴之间的夹角
  >
  >    a_i代表Link_i的数学意义上的长度
  >
  >    | Joint | alpha |   a    |   d    |  theta  | offset |
  >    | ----- | :---: | :----: | :----: | :-----: | :----: |
  >    | 1     |   0   |   0    | 131.56 | theta_1 |   0    |
  >    | 2     | PI/2  |   0    |   0    | theta_2 | -PI/2  |
  >    | 3     |   0   | -110.4 |   0    | theta_3 |   0    |
  >    | 4     |   0   |  -96   | 64.62  | theta_4 | -PI/2  |
  >    | 5     | PI/2  |   0    | 73.18  | theta_5 |  PI/2  |
  >    | 6     | -PI/2 |   0    |  48.6  | theta_6 |   0    |

- 电子背景知识

  > 1. 运算器：算数逻辑导员ALU，累加器，寄存器等组成，有两个功能
  >
  >    执行各种算数运算
  >
  >    执行各种逻辑运算，并进行逻辑测试
  >
  > 2. 控制器：由程序计数器、指令寄存器、指令译码器、时序发生器和操作控制器等，主要功能有：
  >
  >    从内存中取出一条指令，并指出下一条指令在内存中的位置；
  >
  >    对指令进行译码和测试，并产生相应的操作控制信号，以便于执行规定的动作
  >
  >    指挥并控制CPU、内存和输入输出设备之间数据流动的方向

- 电机与舵机知识

  - 电机

    > 1. 按工作电源种类划分：
    >    1. 直流电机：
    >       1. 无刷
    >       2. 有刷
    >          1. 永磁：稀土、铁氧体、铝镍钴
    >          2. 电磁：串励、并励、他励、复励
    >    2. 交流电机：
    >       1. 单相电机
    >       2. 三相电机
    > 2. 按用途划分：
    >    1. 驱动用电动机
    >    2. 控制用电动机：步进电动机、伺服电动机

  - 舵机（伺服电机）

    > 1. 指在伺服系统中控制机械元件运转的发动机，是一种补助马达间接变速装置，可使控制速度、位置精度非常精确，可以将电压信号转化为转矩和转速以驱动控制对象。
    > 2. 伺服主要靠脉冲来定位，使物体的位置、方位、状态等输出被控量能够跟随输入目标的任意变化的自动控制系统。
    > 3. 优点：
    >    1. 精度：实现了位置、速度和力矩的闭环控制，克服了步进电机失步的问题
    >    2. 转速：高速性能好，一般额定转速能达到2000～3000转；
    >    3. 适应性：抗过载能力强，能承受三倍于额定转矩的负载，对有瞬间负载波动和要求快速起动的场合特别适用；
    >    4. 稳定：低速运行平稳，低速运行时不会产生类似于步进电机的步进运行现象。适用于有高速响应要求的场合；
    >    5. 及时性：电机加减速的动态相应时间短，一般在几十毫秒之内；
    >    6. 舒适性：发热和噪音明显降低。

























