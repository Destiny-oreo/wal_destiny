

### 缩略词
> 1. RTOS : Real-time operating system，实时操作系统
> 2. ROS ：Robot Operating System，机器人操作系统
> 3. SLAM ： simultaneous localization and mapping，同步定位与建图
> 4. Monocular ：单目相机
> 5. Stereo ：双目相机
> 6. VO：Visual Odometry，前端视觉里程计
> 7. MAP：Maximum-a-Posteriori，最大后验概率估计
> 8. LG：Linear Gaussian，线性高斯系统 NLNG 非线性非高斯系统
> 9. KF：Kalman Filter，卡尔曼滤波器 EKF 扩展卡尔曼滤波器
> 10. PF：Particle Filter，粒子滤波器
> 11. Eigen：线性代数库









### cmake practice

- 环境搭建和测试

  > 1. 在新建目录下新建main.cpp和CMakeLists.txt；
  > 2. 编写完成以后在当前路径执行cmake .和make生成可执行文件，最后执行
  > 3. 静态库以.a作为后缀名，共享库以.so结尾

  ```cmake
  # 声明要求的cmake最低版本
  cmake_minimum_required(VERSION 2.8)
  # 声明一个cmake工程
  project(main)
  # 添加一个可执行程序
  add_executable(main main.cpp)
  # 添加一个静态库
  add_library(hello libHelloSlam.cpp)
  # 添加一个共享库
  add_library(hello_shared SHARED libHelloSlam.cpp)
  # 指定生成目标
  add_executable(useHello useHello.cpp)
  # 链接到动态库
  target_link_libraries(userHello hello_shared)
  # 查找在某个路径下的所有源文件
  aux_source_directory(< dir > < variable >)
  # 添加一个子目录并构建该子目录。
  add_subdirectory (source_dir [binary_dir] [EXCLUDE_FROM_ALL])
  # 将指定目录添加到编译器的头文件搜索路径之下，指定的目录被解释成当前源码路径的相对路径
  include_directories ([AFTER|BEFORE] [SYSTEM] dir1 [dir2 ...])
  # 引入外部依赖包(以OPENCV为例)
  find_package(OpenCV REQUIRED) include_directories(${OpenCV_INCLUDE_DIRS}) target_link_libraries(img ${OpenCV_LIBS})
  ```
  
  ```shell
  mkdir build
  cd build
  cmake ..
  make
  # cmake --build .
  ```
  
- cmake构建c++代码

  > **同目录：**
  >
  > 1. 首先编写好.h对应.cpp如sort.cpp，首先#include sort.h,然后编写函数；
  >
  > 2. 编写对应.h，`#ifndef __MySort__  #define __MySort__  #endif` 里面如果使用库也需要包含，如<vector> using namespace std;等，再编写声明；
  >
  > 3. 编写main.cpp  需要#include "sort.h"
  >
  > 4. 编写CMakeLists.txt
  >
  >    ```cmake
  >    cmake_minimum_required(VERSION 3.0)
  >    project(sort)
  >    set(CMAKE_CXX_FLAGS "-std=c++11")
  >       
  >    set(srcs main.cpp MySort.cpp)
  >    add_executable(sort ${srcs})
  >    ```
  >    
  >    **不同目录**：
  >    
  >
  > 1. main对应CMakeLists.txt：
  >
  >    ```cmake
  >    cmake_minimum_required(VERSION 3.0)
  >    project(sort)
  >    include_directories(./ ./utils) # 添加到头文件搜索路径 否则要#include "sub/xxx.h"
  >    add_subdirectory(utils) # 添加子目录并构建 否则找不到静态链接库文件
  >
  >    set(srcs main.cpp)
  >    add_executable(sort ${srcs})
  >    target_link_libraries(sort utils) #链接到静态库
  >    ```
  >
  >     `target_link_libraries(sort header)` 表示在生成 sort 时要调用静态链接库 header , 而 header 是在 sort 目录下的 CMakeLists.txt 中的 `add_library(header STATIC sort.cpp)` 中产生的
  >
  > 2. sort对应CMakeLists.txt：
  >
  >    ```cmake
  >    add_library(header STATIC sort.cpp)
  >    ```

- 笔记整理

  ```cmake
  aux_source_directory(<dir> <variable>) #查找指定目录下的所有源文件，然后将结果存进指定变量名
  aux_source_directory(. DIR_SRCS) #查找当前目录下的所有源文件并将名称保存到 DIR_SRCS 变量
  add_subdirectory(math)# 添加 math 子目录，这样 math 目录下的 CMakeLists.txt 文件和源代码也会被处理
  target_link_libraries(Demo MathFunctions)# 添加链接库，可执行文件 main 需要连接一个名为 MathFunctions 的链接库
  add_library (MathFunctions ${DIR_LIB_SRCS})# 子文件夹内使用，生成链接库
  target_link_libraries(${PROJECT_NAME} fmt::fmt)
  include_dirextories()# 添加头文件目录，相当于环境变量中增加路径到INCLIDE_PATH中
  link_directories() # 添加需要链接的库文件目录，相当于环境变量中增加了LIBRARY_PATH
  ```
  
- cmake头文件与链接库

  > 1. 头文件：申明函数接口
  > 2. 库文件：存放函数的定义
  > 3. 关系：库文件通过头文件向外导出接口，用户通过头文件找到库文件中需要的函数来实现代码链接到程序中；
  > 4. 静态链接库lib和动态链接库dll区别：
  >    1. 静态链接库将文件中用到的函数代码直接链接进目标程序，程序运行时不再需要该库文件，动态链接库将被调用的函数所在文件模块dll和在文件中的位置等信息链接进目标程序，程序运行时从dll中寻找相应函数代码；
  >    2. 静态链接库对应lib所有指令全部被包含在最终生成的exe中，动态链接库dll不必要被包含在最终exe中，可以动态的引用和卸载dll；
  >    3. 静态库在程序编译时被链接到目标代码中，动态库在编译时被引用，在程序运行时被载入；





### 十四讲

- 2 初识slam

  - 视觉slam流程

    > 1. 传感器信息读取
    > 2. 前端视觉里程计：通过相邻帧间的图像估计相机运动并恢复场景的空间结构；会导致累计漂移，使用后端优化和回环检测解决；主要是类似图像的特征提取与匹配；
    > 3. 后端非线性优化：处理slam过程中的噪声问题，主要是滤波与非线性优化算法；
    > 4. 回环检测：主要解决位置估计随时间漂移的问题；需要让机器人具有识别到过的场景的能力；
    > 5. 建图：构建地图的过程，可以分为度量地图（精确地图中物体的位置关系）与拓扑地图（强调地图元素之间的关系）两种；

- 3 三维空间缸体运动

  - 旋转矩阵

    >1. 向量内积：ab cos<a,b>  向量外积：ab sin<a,b>
    >2. 反对称矩阵：0 -a3 a2;a3 0 -a1;-a2 a1 0;
    >3. 刚体运动：坐标系的旋转和平移
    >4. （**与P65/88例子结合理解**）欧式空间坐标变换关系：**a1 = R12a2+t12**，R12指把坐标系2的向量变换到坐标系1中（即坐标系1旋转到坐标系2的角度，一般得到的全局四元数是指全局原始坐标系旋转到目标位置坐标系下的角度，是R_x_to_o即Rox），t12指坐标系1原点指向坐标系2原点的向量，在坐标系1下的坐标（即坐标系2的原点在坐标系1的坐标）；**理解：**R12即R_2_to_1，是坐标系1转换到坐标系2需要的角度来得到旋转矩阵，t12即t_2_to_1，需要知道坐标系2原点相对于坐标系1的坐标信息；
    >5. 变换矩阵和齐次坐标：将3维向量末尾加1变成4维向量，成为齐次坐标，旋转矩阵和平移写在一个矩阵里变成变换矩阵（特殊欧式群）；
    >6. Eigen不支持自动类型转换，必须显式对矩阵类型转换

  - 旋转向量和欧拉角

    > 1. 旋转向量到旋转矩阵的转换过程由罗德里格斯公式推导；R=cost*I +(1-cost)*n * n.T + sint *n.^
    > 2. ZYX欧拉角（rpy）：yaw，pitch，roll
    > 3. 万向锁问题：俯仰角为±90°时，第一次旋转和第三次旋转使用了同一个轴，被称为奇异性问题，往往只用于人机交互中；

  - 四元数

    > 1. 一种扩展的复数，既是紧凑的也没有奇异性，拥有一个实部和三个虚部

  - *相似 仿射 射影变换

    > 1. 真实世界到相机照片为射影变换，如果相机焦距无穷大，即为仿射变换（正交投影）
    > 2. 1. 旋转矩阵3x3 EIgen::matrix3d
    >    2. 旋转向量3x1 AngleAxisd
    >    3. 欧拉角3x1 Vector3d
    >    4. 四元数4x1 Quaterniond
    >    5. 欧式变换矩阵4x4 Isometry3d
    >    6. 仿射变换4x4 Affine3d
    >    7. 射影变换4x4 Projective3d

    ```C++
    // Eigen 核心部分
    #include <Eigen/Core>
    // 稠密矩阵的代数运算（逆，特征值等）
    #include <Eigen/Dense>
    // 提供了各种旋转和平移的表示
    #include <Eigen/Geomentry>
    Matrix3d ；//实质上是 Eigen::Matrix<double, 3, 3>
             Vector3d ;//实质上是 Eigen::Matrix<double, 3, 1>，即三维向量
    AngleAxisd rotation_vector(M_PI / 4, Vector3d(0, 0, 1)); //旋转向量，底层不直接是Matrix，z轴旋转45°
    Identity  ；//单位向量进行初始化
    cout.precision(3);// 输出流格式控制 浮点精度
    Isometry3d T = Isometry3d::Identity();// 欧氏变换矩阵使用Isometry
    Quaterniond q = Quaterniond(rotation_vector);// 可以直接把AngleAxis赋值给四元数，反之亦然
    coeff (expr, x)；//返回x前面的系数
    
    ```

- 4 李群与李代数

  - 基础

    > 1. 三维旋转矩阵是特殊正交群SO(3),变换矩阵构成了特殊欧式群 SE(3) ,两者对加法不封闭，对乘法封闭
    > 2. 特殊正交群 SO(3) 是行列式为1的正交矩阵，它的逆就是它自身的转置，表示与其自身相反的旋转；
    > 3. 特殊欧式群 SE(3)，左上角是旋转矩阵R，右侧是平移向量t，左下角为0，右下角为1；
    > 4. 群：有着一个良好的运算的集合；一种集合加上一种运算的代数结构，如一般线性群、特殊正交群、特殊欧式群；
    > 5. 李群：具有连续光滑性质的群；每个李群都有与之对应的李代数，李代数描述了李群的局部性质，是单位元附近的正切空间；
    > 6. 李代数性质：封闭性、双线性、自反性、雅克比等价；
    > 7. ^ 向量到矩阵关系  v从矩阵到向量的关系
    
  - 李代数求导与扰动模型
  
- 5 相机与图像

  - 相机模型

    > 1. 内参数：相机的针孔模型与透镜的畸变模型，能够把外部的三维点投影到相机内部成像平面；
    > 2. 像素坐标系：原点o位于图像的左上角，u轴向右与x轴平行，v轴向下与y轴平行；
    > 3. 相机的内参参数K：fx 0 cx;0 fy cy;0 0 1;
    > 4. 世界坐标、相机坐标、归一化坐标、像素坐标；
    > 5. 单目相机成像过程：世界坐标系下固定点Pw，相机的运动由R,t纪录，所以P的相机坐标Pc为RPw+t，投影到归一化平面，得到Pc=【X/Z.Y/Z.1】，有畸变时根据畸变参数计算畸变后的坐标，最后归一化坐标经过内参得到像素坐标Puv=KPc
    > 6. RGB-D相机模型能够实时测量每个像素点的距离，但容易收到日光或其他传感器发射的红外光干扰，多个RGB-D相机也会互相干扰，无法测量透射材质，成本功耗均有劣势

  - 图像

  - 实践：计算机中的图像 3D视觉

- 6 非线性优化

  - 状态估计问题
  - 非线性最小二乘法
  - 实践：曲线拟合问题

- 7-8 视觉里程计

  - 特征点法
  - 实践：特征提取和匹配
  - 2D-2D 对极几何
  - 三角测量
  - 3D-2D
  - 3D-3D
  - 直接法的引出
  - 2D光流
  - 直接法

- 9-10 后端

- 11 回环检测

- 12 建图

- 13 实践：设计SLAM系统

- 14 SLAM：现在与未来
