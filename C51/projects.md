## SmartHome
#### ESP8266 MCU
- 首先进行串口通信，152000频率，实现主机与终端的基本通信，通信方式有好几种，如WiFi模块和主机同时加入到局域网（热点）中，或者将WiFi模块作为路由器，主机连接到WiFi模块上，均可进行通信。
- 产生pwn波，使用模拟输出即可，默认1khz，更改输入值以后可以改变占空比。一开始使用循环的思想，在初始化函数中定义好初始变量，然后在loop函数中每隔极短的时间进行接收判断，但是导师说不符合硬件编程的思想，改成使用定时器来出发接收判断，在初始函数中定义好定时器的参数，然后loop中直接为空，在定时器出发函数中进行接收判断，根据接收到的指令来改变占空比。
- 一开始是只接收左右的指令，发现一旦丢包以后，数据会一直错开，没法纠正，所以后来在服务器端就进行占空比计算，计算出来每一个终端WiFi的占空比并分别发出，终端接收到以后直接执行即可，即使某个指令丢包，但是下一个指令接收到时依然可以纠正。

#### UDP服务器
- 为了使通信速度更加快速，使用UDP通信(socket)而不是TCP通信，只需要知道目标终端的IP地址以及端口号即可进行传输，只要不需要接收到终端传回的数据，就不需要终端进行传输，也不需要服务器自身的IP地址。
- 服务器检测指令本来使用的是pyautogui，可以检测鼠标的坐标地址进行判断是否移动，结果发现由于坐标对应的是屏幕的大小，所以到移动到边界时候没法继续移动，所以后面改成滚轮移动（鼠标传感器本身数据没有成功获得，后续可以再尝试一下），滚轮检测使用的是pygame，在弹出的窗口上进行滚轮滚动，检测到以后进行判断向上还是向下，然后立马发送相关指令给终端WiFi，依次计算并发出，所以在滚轮速度特别快的时候会丢包。
- 后续导师新加需求为可控数量，即在服务器一开始输入数量n，根据n计算占空比公式，然后依次控制n个终端轮询。

#### ESP8266编程思路
- 使用到定时器，首先初始化Ticket flipper，然后定义完初始变量以后进入到setup函数；
- 定义串口通信速率，定义WiFi模块需要使用到的端口的情况，然后初始化WiFi模块begin即可（其中输入WiFi的无线网络名称以及密码）；
- 当模块连接到WiFi时需要进行判断，当没有连接上时无法工作，所以一直处于等待来连接的状态，直到连接上以后WiFi.status()==WL_CONNECTED时不再等待；
- 启动UDP监听功能，如果没有监听成功返回，然后开启定时器，没0.1s触发一次；
- 触发函数为检测是否接收到UDP的指令，如果没有接收到，直接结束触发函数，否则继续判断。

#### socket网络通信
- UDP服务器使用socket实现，将服务器实例化时使用socket.socket函数，其中的参数使用(socket.AF_INET, socket.SOCK_DGRAM) ，即代表使用的是UDP通信协议，接着绑定服务器本身的IP地址以及端口号；
- 传输数据时使用实例化的udpServer的sendto函数来进行发送，其中有两个参数，第一个为发送内容的编码以后的变量，第二个参数为目标IP地址以及端口号；
- 通信结束以后需要将服务器进行关闭，使用udpServer.close()

## keras
- 安装完3.8.3的python及anaconda以后，发现版本太高，所以学习安装了虚拟环境，虚拟环境中所有python版本都为3.6.8，对应不同虚拟环境为不同的tensorflow或者keras或者pytorch。
- 对应的tensor2(≥1.14）都需要使用compat.v1等，并且很多兼容问题，所以最后在tensor114中常见的是tensorflow1.14+keras2.2.5+CUDA10.0+cudnn7.4，使用起来很方便（tfgpu使用最新的各个版本，一直报错）。
- 首先运行了mnist的数据集，6万个手写数字，每个28*28，使用load_data无法下载，速度太慢，使用离线下载然后load('mnist.npz')即可，然后再提取出来训练和测试的xy，其中y标签需要使用oneshot类型，即类似编码，而不是预测大小，使用keras.utils的to_categorical即可，同时其他训练数据要换成目标类型float32以及需要归一化/255.0，oneshot传入的是目标最大分类数+1，所有预处理结束。使用卷积神经网络，Conv2D MaxPool2D Flatten Dense层继续搭建模型，然后使用compile定义火车头，其中优化器使用的adam 损失模型使用的是categorical_crossentropy，然后输出中需要使用的metrics=['accuracy']，最后使用fit训练。输出评价参数可以使用model.evaluate(x_test,y_test)[1]进行输出准确率。
- 接下来运行猫狗大战数据，首先一张一张读取图片，使用os.listdir来获取目标文件夹下的所有文件名称，然后使用.split来获取类型名称进行分类，然后使用os.path.join将文件夹和文件名称合并读取，使用cv2.imread来读取，将灰度数据resize以后存在x列表中，同理其他数据。读取完以后为了避免再次读取，使用pickle的dump和load函数进行保存和读取，虽然文件占用空间变大，但是方便传输？....数据获得以后同时进行预处理，转为array类型并规定float32类型，归一化，并设置为3维数据（model.fit需要3维，即使第三维是1）；开始构建模型，和手写数字差不多，两层卷积神经网络+池化，然后展开，两层全连接层进行输出，这回没有选择softmax而是sigmoid激活函数，接着编译，优化器还是adam，损失模型是binary_crossentropy（因为这回没有oneshot，而是0和1的选择，即二值输出...?），为了提高准确率还设置了交叉验证数据集，大小是20%，预测时同样读取test，然后记录id_test，预处理结束以后使用model.predict函数进行预测，得到prediction，得到的均为概率大小，所以使用四舍五入得到二分类，然后panda将id和prediction合并在一起（最后需要排序一下）。训练默认占用全部的GPU显存，且不释放，需要把notebook关闭以后才能释放。解决方法：使用multiprocessing.Process函数进行多进程管理，训练完以后自动关闭该进程。或者使用显存占用比控制，调为30%（感觉没有什么用，还是不会释放）

## pytorch-MNIST
- MNIST学习笔记主要见书签：学习-python-pytorch中关于mnist的笔记；
- 思路：首先加载数据，compose-MNIST-DataLoader;然后定义神经网络层，函数中可以选择不同的网络层以达到不同的效果；接着定义模型训练的相关参数如学习率、损失函数、优化器等，然后选择CPU还是GPU训练；最后定义迭代次数开始训练并保存准确率以及损失。




## OpenPose
- 在安装好python和CUDA和Cudnn的基础上，直接下载openpose文件以及cmake1.19，然后准备编译，第一次使用了VS2019编译，所以可能才能下载好所有需要模型吧，build一定要放入父目录下，否则后面的example无法运行；
- 切换VS工作模式为release，编译OpenPoseDemo以及pyopenpose两个文件生成所需文件
- 重装anaconda：在python3.8.3下面编译完成openpose以后，发现无法使用其他深度学习包，所以准备重装python，在anaconda里使用conda install python以及，发现只是新建了虚拟环境，每次使用都需要activate才行，而且重新编译的文件在jupyter里无法使用，尝试了无数方法还是无法解决，遂卸载anaconda，卸载完成以后发现环境变量没有删除，手动删除（此处大坑），下载安装对应python3.6的anaconda5.2.0，发现cmd无法打开（不知道什么原因导致），查了解决解决办法为WIN+R 输入regredit，找到网上要求的某一个目录下删除exit的数据，被删除数据为（if exsit），然后发现安装anaconda发现还是没有添加环境变量，还好手动删除时留了一个印象，去网上比对着重新手动添加环境变量，anaconda打开正常。
- open pose验证：首先VS里两个文件成功生成解决方案，然后将example下的C++样例设为启动项，编译运行成功，说明C++下可以调用openpose；下面验证python下调用pyopenpose，第一种方案，cmd将工作路径切换到python样例下（d:  cd d/xxx),然后python 01xxx.py即可；第二种方案，将必须的文件（参考[视频教程](https://www.bilibili.com/video/av667869379))移入BIN中，然后cmd切换工作路径到bin里，使用官方方法验证，如OpenPoseDemo.exe --video video.avi即可 或者验证图片集，同时可以进入python并import pyopenpose；第三种方案：首先还原jupyter默认工作路径，然后在bin中写脚步cd %cd%    jupyter notebook，目的是在此环境中启动jupyter，然后成功i吗port pyopenpose。










