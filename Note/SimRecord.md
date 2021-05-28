## AirSim

#### hellodrone.py

- 运行无人机时运行脚本，报错：

  ```python
  raise error.RPCError(self._error)
  msgpackrpc.error.RPCError: rpclib: function 'getImuData' (called with 2 arg(s)) threw an exception. The exception contained this information: No IMU with name  exist on vehicle.
  ```

- 注释IMU以后，报错：

  ```python
  raise error.RPCError(self._error)
  msgpackrpc.error.RPCError: rpclib: function 'getBarometerData' (called with 2 arg(s)) threw an exception. The exception contained this information: No barometer with name  exist on vehicle.
  ```

- 调试发现，不是函数问题而是airsim返回的参数没有name，想到setting文件，查看[说明](https://github.com/Microsoft/AirSim/blob/master/docs/settings.md)以后发现需要设置vehicles的name才能不报错：

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

- 阅读airsim的client代码时发现对Python类的继承不太熟悉，查资料：

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

- pyxhook使用：

  ```python
  import pyxhook
  import time
  # 主体部分：
  hookman = pyxhook.HookManager()
  hookman.KeyDown = kbevenFunc
  hookman.HookKeyboard()
  hookman,start()
  while True:
      pass
  hookman.cancel()
  ```

- airsim添加[静态车辆模型](https://zhuanlan.zhihu.com/p/338812803)，从[网站](https://www.cgtrader.com/)下载车辆模型，需要fbx文件,[解压](https://blog.csdn.net/songbinxu/article/details/80435665)命令：

  ```Python
  # 解压命令：
  rar: unrar x sth.rar dirs
  zip: unzip -d dirs sth.zip
  tar.gz tgz:tar -zxvf FileName.tar.gz  tar -C DesDirName -zxvf FileName.tar.gz
  ```
  
- 安装[多版本CUDA](https://blog.csdn.net/yinxingtianxia/article/details/80462892) 以及切换：

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
  
  
  
  ```

  ## GitHub

- 初始化等 Destiny-oreo wang1997 wal_destiny

  ```python
  # 远程仓库同步至本地
  git init # 初始化
  git remote add origin https://github.com/Destiny-oreo/wal_destiny.git
  git pull https://github.com/Destiny-oreo/wal_destiny.git
  # 远程仓库更改 本地同步 （远程仓库新建文件 最后输入/以新建文件夹 然后创建一个空文件保存）
  git fetch origin # 获得远程更新
  git merge origin/master # 更新内容合并到本地分支
  git push --set-upstream origin master # 建立与上游的跟踪
  # 常用提交等代码
  git status
  git add Note/SimRecord.md
  git commit -m "add some new files"
  git push origin  或   git push -u origin master
  ```

  

