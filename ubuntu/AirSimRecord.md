## AirSim

#### hellodrone.py

- **运行无人机时运行脚本，报错：**

  ```python
  raise error.RPCError(self._error)
  msgpackrpc.error.RPCError: rpclib: function 'getImuData' (called with 2 arg(s)) threw an exception. The exception contained this information: No IMU with name  exist on vehicle.
  ```

- **注释IMU以后，报错：**

  ```python
  raise error.RPCError(self._error)
  msgpackrpc.error.RPCError: rpclib: function 'getBarometerData' (called with 2 arg(s)) threw an exception. The exception contained this information: No barometer with name  exist on vehicle.
  ```

- **调试发现，不是函数问题而是airsim返回的参数没有name，想到setting文件，查看[说明](https://github.com/Microsoft/AirSim/blob/master/docs/settings.md)以后发现需要设置vehicles的name才能不报错：**

  ```python
  {
    "SeeDocsAt": "https://github.com/Microsoft/AirSim/blob/master/docs/settings.md",
    "SettingsVersion": 1.2,
    "SimMode":"Multirotor",
    "Vehicles": {
      "SimpleFlight": {
        "VehicleType": "SimpleFlight",
        "DefaultVehicleState": "Armed",
        "AutoCreate": true,
        "PawnPath": "",
        "EnableCollisionPassthrogh": false,
        "EnableCollisions": true,
        "AllowAPIAlways": true,
        "EnableTrace": false,
        "RC": {
          "RemoteControlID": 0,
          "AllowAPIWhenDisconnected": false
        }
      }
    }
  }
  xiyou360.net 1399544050@qq.com @yfz0705
  ```

- **阅读airsim的client代码时发现对Python类的继承不太熟悉，查资料：**

  ```python
  class Person(object):   # 定义一个父类
      def talk(self):    # 父类中的方法
          print("person is talking....")   
  class Chinese(Person):    # 定义一个子类， 继承Person类
      def walk(self):      # 在子类中定义其自身的方法
          print('is walking...')
  c = Chinese()
  c.talk()      # 调用继承的Person类的方法
  c.walk()     # 调用本身的方法
  # 输出
  person is talking....
  is walking...
  ```

- **pyxhook使用：**

  ```python
  import pyxhook
  import time
  # 主体部分：
  hookman = pyxhook.HookManager()
  hookman.KeyDown = kbevenFunc # 事件触发于键盘按键按下的时候
  hookman.HookKeyboard()
  hookman,start()
  while True:
      pass
  hookman.cancel()
  ```

- **airsim添加[静态车辆模型](https://zhuanlan.zhihu.com/p/338812803)，从[网站](https://www.cgtrader.com/)下载车辆模型，需要fbx文件,[解压](https://blog.csdn.net/songbinxu/article/details/80435665)命令：**

  ```Python
  # 解压命令：
  rar: unrar x sth.rar dirs
  zip: unzip -d dirs sth.zip
  tar.gz tgz:tar -zxvf FileName.tar.gz  tar -C DesDirName -zxvf FileName.tar.gz
  ```

- **断点：**

  使用Linux下的UE暂时无法获取可编译的环境，在官网下载却一直下载不下来，看的教程都是在Windows下在软件界面选择新的场景然后再添加车辆，在Linux下应该只能新建场景或者使用默认的blocks场景。


#### keyboard_control.py

- **[基础api](https://microsoft.github.io/AirSim/api_docs/html/index.html#airsim.client.MultirotorClient.moveByVelocityBodyFrameAsync)**

  ```python
  # 开启和关闭键盘监听
  hookman = pyxhook.HookManager()
  hookman.KeyDown = keyEvent
  hookman.HookKeyBoard()
  hookman.start()
  hookman.cnacel() # 关闭键盘监听
  # 连接airsim (确保airsim处于运行状态) 以及断开连接
  client = airsim.MultirotorClient() # 连接飞行器
  client.enableApiControl(True) # 获取API控制权
  client.armDisarm(True) # 解锁飞行器
  client.armDisarm(False) # 上锁
  client.enableApiControl(False) # 释放控制权
  # 基础飞行控制--常用
  client.moveToZAsync(z,velocity).join() # z控制 上升到2米  join代表上升完成以后执行下一条命令
  client.moveToPositionAsync(5,0,height,duration).join() # 位置控制 飞到指定位置
  client.moveByVelocityZAsync(FB,RL,height,t).join # 水平速度控制 1参表前后速度，2参右左速度
  client.moveByVelocityAsync(vx,vy,vz,t) # 全局速度控制
  client.moveByVelocityBodyFrameAsync(vx,vy,vz,t) # 本地NED坐标系
  -------------------------------------------------------
  client.moveByAngleZasync(pitch,roll,z,yaw,t) # 水平姿态角
  moveByAngleThrottleAsync(pitch, roll, throttle, yaw_rate, duration, vehicle_name = '')
  client.rotateToYawAsync(yaw, margin = 5) # 偏航角控制
  client.rotateByYawRateAsync(yaw_rate, duration) # 偏航角速率控制
  # 获取信息
  state = client.simGetGroundTruthKinematics() # 获取状态真值
  height = state.position.z_val
  ```

- **飞行实例**

  ```python
  # 偏航角控制模式 yaw_mode
  drivetrain = airsim.DrivetrainType.MaxDegreeOfFreedom # 手动设置 yaw 角度
  drivetrain = airsim.DrivetrainType.ForwardOnly # 始终朝向速度方向
  # yaw_mode 必须设置为 YawMode() 类型的变量，这个结构体类型包含两个属性：YawMode().is_rate：True - 设置角速度；False - 设置角度 YawMode().yaw_or_rate：可以是任意浮点数
  ---------------------------------------------------------------------------
  # 例 朝向始终与前进方向相差90度
  drivetrain = airsim.DrivetrainType.ForwardOnly
  yaw_mode = airsim.YawMode(False, 90)
  # 绕圆飞行
  首先控制无人机前后左右以及上下 偏航角等控制，验证完成以后，开始加入绕圆飞行功能；将无人机起始位置设置在目标车辆附近(-2500，-4000，202)，目标车辆(-2560，-4730，100)，更改朝向(z -90°)面对车头防止一开始识别不出来；后续使用画圆代码进行成功画圆，此时需要将实时的前置摄像头拍摄图片进行显示，采集数据集时使用的方式是使用R键或者右下角按钮进行保存，不是使用手动读取图片数据进行保存，如今需要对图片进行识别等操作，不需要保存，所以需要使用PIL或者matplotlib等方式进行显示，使用PIL报错file://tmp//tmpfeu8i58b.PNG中找不到文件；使用cv2包可以正常显示与保存；
  ```
  
- **坐标系总结**

  ```python
  # UE4坐标系
  与NED坐标系的差距仅仅在于z方向取反
  # 全局坐标系NED
  x,y,z指向北 东 下，原点位置在UE4的坐标可以设置
  # 机体坐标系NED
  固连到机体本身，x,y,z指向前，右，下，原点位置为机体的重心位置
  
  ```

- **Image.open和imread**

  ```python
  # Image.open读入的是RGB顺序，imread读入BGR顺序，显示的更加蓝
  from PIL import Image
  import cv2
  image = Image.open(path)
  image = cv2.imread("src.png",CV2.IMREAD_COLOR)
  # 显示图片两种方式
  import matplotlib.pyplot as plt
  plt.subplot(121)
  plt.imshow(image)
  plt.show()
  cv2.imshow(image)
  cv2.waitKey(0)
  img = np.array(img) # 转换成ndarray格式以查看shape属性
  # 格式转换
  def PILToCV(path):
      img = Image.open(path)
      plt.imshow(img)
      img2 = cv2.cvtColor(np.array(img),cv2.COLOR_RGB2BGR)
      plt.imshow(img2)
      plt.show()
      
  def CVToPIL(path):
      img = cv2.imread(path)
      plt.imshow(img)
      img2 = Image.fromarray(cv2.cvtColor(img,cv2.COLOR_BGR2RGB))
      plt.imshow(img2)
      plt.show()
  # 差别分析
  Image.open函数只是保持了图像被读取的状态，但是图像的真实数据并未被读取，因为如果需要操作图像的每个元素，需要执行对象的load方法来读取数据；cv2.imwirte()保存图片的时候相当于做了BGR2RGB再去保存，cv2.imshow()采用BGR模式，plt.imshow() 采用RGB模式，img.show() 采用RGB模式
  ```

- **np.max() np.maximum() np.argmax()**

  ```python
  np.max：接受一个参数，返回数组中的最大值
  np.argmax：接受一个参数，返回数组中最大值对应的索引
  np.maximum：接受两个参数，对应数学中的 max 操作
  
  ```

  

- **进度**

  ```python
  # 6-15
  将师兄集成好的car_detection和airsim_control两个python文件修改，目标使用car文件调用airsim文件，在主函数中使用airsim控制功能，绕圈飞行时返回的图片使用car中的detection函数检测并显示，但其中涉及到线程以及两个class的while，需要小修改
  cv2显示：cv2.imshow("src",img_rgb)  cv2.waitKey(5)	返回的需要时BGR
  PIL显示：PIL_Image = Image.fromarray(cv2.cvtColor(img_rgb,cv2.COLOR_BGR2RGB))
  plt.imshow(ac.image)  plt.show()      ... plt.close()
  # 6-16
  新开一个线程用来读取无人机拍摄的照片一直报错，改变思路在绕圈飞行时定期拍摄照片，保存到self.image里同时设置imageFlag来纪录是否更新照片，在主程序中持续读取imageFlag即可，当为true时说明有新的image送进来，进行显示或者检测都可以，使用完将flag设置为False等待下一次送进；在绕圈飞行同时进行检测，在一开始几张检测效果很差，不知道是检测时间太少还是没有来得及显示，接下来读取检测结果中的部分数据进行显示再调整初始位置；为了保存进度，下载录制软件SimpleScreenRecorder(https://www.ixigua.com/6842943258671186439?logTag=jqCi0znvhEM7wp0ehW5cq)；对应脚本：circle_detection与airsim_control
  拷贝脚本成car_detection与airsims自动控制无人机飞行
  起始位置输出output：[[0.0000000e+00 2.1536431e+00 6.3314667e+02 1.9658424e+02 8.9599701e+02
    3.4180728e+02 1.4468974e+00 1.5895796e+00 3.8089020e+00 2.2184706e+00
    1.8280101e+00 9.6974049e+00 2.3785424e+00 5.2353770e-01]]
  ```

  ```python
  # 6.17
  查看四个坐标系的坐标转换关系，整理了组会PPT，列举了目前进展以及遇到的问题，目前能够输出在局部NED坐标系下的车辆重心坐标点以及rotation_y(输入标签的14个数据)，目前可以在画圈或者任意时刻进行开线程获取图像以及保存，detection获取的output返回即可用数据，获取其中置信度最高的一行数据，同时根据x,y,z以及r_y可以控制飞行棋飞到r_y接近1.57的位置，但是发现绕圈飞行的逆时针出现问题，原因yaw_mode顺时针给90°，逆时针需要给-90°；
  完成car3D_Detection.controls函数，实现飞行状态下自动回到检测到的车辆正前方，误差为0.02约为2.3°左右，但由于是绕圆心运动，如果朝向不是车辆重心，需要加入左右运动控制x坐标为0左右，这一步在修复完模型的准确度以后再解决(车辆正前方正确度很低，导致运动问题很大)
  # 6.18
  上午在图书馆准备重新训练的数据集，准备了一半左右，下午3点将所有数据集准备好，准备晚上在原有参数的基础上将所有数据集混入重新训练，此时在网上尽量找到原来最多的数据集进行训练；
  运动检测的问题目前思路是在起始点检测到车辆时，根据x轴距离进行旋转无人机，使x尽量接近0即无人机朝向车辆重心点，然后根据r_y脚绕重点旋转，到达正前方以后再根据z距离调整远近，使无人机处于最合适的位置
  ```
  
  ```python
  # 6.23
  model_final_7481:使用原始7千数据从0参开始训练
  model_final：初始自带模型
  model_final_12481：使用原始数据加车15005数据在原始参数基础上训练结果
  使用融合模型结果变得更加差了，通过对比发现，原有模型对车辆的正面以及少部分正侧面效果较差，即使对于现实中的车辆也有识别不出来的情况，而融合模型对车辆的其他角度识别准确率也下降了很多
  整合controls函数，按键P时进行归位 原点位置：-2100 -3800 202 -120° 
  -1800 -4700 202 180° 7.6m
  -2000                5.6m
  ```
  
  





#### SMOKE

- **数据集**

  ```python
  #软链接：ln -s /home/wal/project/SMOKE/datasets/kitti2 datasets/kitti3 源路径要完整
  #图像复制：SMOKE/dataCreate.py str类型更改数据不能只能更改，需要转为list
  首先导入必要的包shutil 后面可以直接shutil.copy(src,dst)来复制图片
  所以剩下的就是获取原图片路径以及目标图片路径和名称，原路径使用os.listdir来获得所有names
  
  ```

  













### 安装[多版本CUDA](https://blog.csdn.net/yinxingtianxia/article/details/80462892) 以及切换：

- 命令：

  ```python
  # 查看CUDA以及CUDNN版本
  cat /usr/local/cuda/version.txt     或者   nvcc --version
  cat /usr/local/cuda/include/cudnn.h | grep CUDNN_MAJOR -A 2
  stat cuda # 查看当前软链接指向位置
  # 安装10.0.130+6.0.21   10.1.105+7.6.4.38  9.0.176+7.6.4.38
  sudo cp cuda/include/cudnn.h /usr/local/cuda-10.0/include
  sudo cp cuda/lib64/libcudnn* /usr/local/cuda-10.0/lib64
  sudo chmod a+r /usr/local/cuda-10.0/include/cudnn.h 
  sudo chmod a+r /usr/local/cuda-10.0/lib64/libcudnn*
  # 安装cuda9.0时涉及gcc和g++版本 已安装-7-9 需要-6
  sudo update-alternatives --config gcc # 临时切换版本以及查看优先级 gcc --version
  sudo update-alternatives --config g++
  sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-7 70#设置优先级
  sudo sh cuda_9.0.176_384.81_linux.run -override # 安装gcc g++不匹配的CUDA9.0
  # 切换cuda 在local路径下
  sudo rm -rf cuda
  sudo ln -s /usr/local/cuda-10.0 /usr/local/cuda
  ```

  

- python api 解析：

  ```python
  .takeoffAsync().join() # 起飞至地面3m以上
  confirmConnection # 检查连接状态
  armDisarm # 解锁或上锁
  client.moveToPositionAsync(x,y,z,velocity,timeout_sec)# 全局坐标系下的三维位置坐标
  np.linalg.norm：默认参数，矩阵整体元素平方和开根号
  math.atan和math.atan2:反正切，推荐atan2，输入两个参数y x，不需要判断x是否为0(pi/2)
  
  ```

  ## GitHub

- 初始化等 Destiny-oreo wang1997 wal_destiny

  ```python
  # 远程仓库同步至本地
  git config --list
  git init # 初始化
  git remote add origin https://github.com/Destiny-oreo/wal_destiny.git
  git pull https://github.com/Destiny-oreo/wal_destiny.git
  # 远程仓库更改 本地同步 （远程仓库新建文件 最后输入/以新建文件夹 然后创建一个空文件保存）
  git fetch origin # 获得远程更新
  git merge origin/master # 更新内容合并到本地分支
  git push --set-upstream origin master # 建立与上游的跟踪
  # 常用提交等代码
  git status
  git add Note/SimRecord.md  或 git add .
  git commit -m "add some new files"
  git push origin  或   git push -u origin master
  ```

  

