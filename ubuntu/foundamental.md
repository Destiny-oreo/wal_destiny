> 计算机组成原理、操作系统、计算机网络

## [计组](https://blog.csdn.net/qq_27009517/article/details/108054464)

#### 概述篇

- 计算机的发展历史

  > 1. 第一阶段：电子管计算机 集成度低 体积大 功耗高 运行速度慢 操作复杂
  > 2. 第二阶段：晶体管计算机 相较于电子管，体积小 速度快 功耗低 可靠性高 配备显示器
  > 3. 第三阶段：集成电路计算机 操作系统诞生
  > 4. 第四阶段：超大规模集成电路计算机 集成度高 速度快 体积小 价格低 用途广泛
  > 5. 未来：生物计算机、量子计算机

- 计算机的分类

  > 超级计算机、大型计算机、迷你计算机、工作站、微型计算机

- 计算机的体系与结构

  > 冯诺依曼体系：将程序指令和数据一起存储的计算机设计概念结构，存储器+控制器+运算器+输入设备+输出设备
  >
  > CPU = 运算器+控制器

- 现代计算机的结构

  > 以存储器为核心，解决冯诺依曼体系的瓶颈问题
  >
  > CPU = 运算器+控制器+存储器

- 计算机的层次

  > 应用层
  >
  > <u>高级语言层</u> 以下三层为虚拟机
  >
  > <u>汇编语言层</u>
  >
  > <u>操作系统层</u>  计算机五层结构
  >
  > <u>传统机器层</u>  物理机
  >
  > <u>微程序机器层</u> 物理机
  >
  > 硬件逻辑层

- 计算机的字符与编码集

  > 字符编码集：ASCII码->Extended ASCII码
  >
  > 中文编码集：GB2312->GBK->Unicode统一码 万国码

#### 组成篇

- 计算机的总线与IO设备

  > 1. 计算机的总线 Bus
  >    1. 概述：连接多个设备或者接入点的数据传输通路
  >    2. 作用：解决不同设备之间的通信问题
  >    3. 分类：片内总线（高集成度内部的信息传输线）、系统总线（数据总线、地址总线、控制总线，是CPU、主内存、IO设备、各组件之间的信息传输线）
  >    4. 总线的仲裁：为了解决总线使用权的冲突问题，三种方法：链式查询、计时器定时查询、独立请求
  > 2. 常见的输入输出设备
  >    1. 字符输入设备：键盘
  >    2. 图形输入设备：鼠标、数位板、扫描仪
  >    3. 图像输出设备：显示器、打印机、投影仪
  > 3. 输入输出接口的通用设计
  >    1. 数据线：IO设备与主机进行数据交换的传送线（单向和双向）
  >    2. 状态线：IO设备状态向主机报告的信号线
  >    3. 命令线：CPU向IO设备发送命令（读写信号、启动停止信号）的信号线
  >    4. 设备选择线：主机选择IO设备进行操作的信号线
  > 4. CPU与IO设备的通信
  >    1. 程序中断：提供低速设备通知CPU的一种异步方式，CPU可以在高速运转的同时兼顾低速设备的相应
  >    2. 直接存储器访问DMA：当主存与IO设备交换信息时，不需要中断CPU，可以提高CPU的效率

- 计算机的存储器

  > 1. 存储器的分类
  >    1. 按照存储介质：半导体存储器（内存、U盘、固态硬盘）、磁存储器（磁带、磁盘）
  >    2. 按照存取方式：随机存储器RAM（随机读取，与位置无关）、串行存储器（按顺序查找，与位置有关）、只读存储器ROM（只读不写）
  >
  > 2. 存储器的层次结构
  >    1. CPU--高速缓存--主存--辅存
  >    2. 缓存-主存层次：局部性原理，在CPU与主存之间增加一层速度快容量小的Cache，解决主存速度不足的问题
  >    3. 主存-辅存层次：局部性原理，主存之外增加辅助存储器，解决主存容量不足
  >    4. 局部性原理：CPU访问存储器时，无论是存取指令还是存取数据，所访问的存储单元都趋于聚集在一个较小的连续区域中
  > 3. 计算机的主存储器
  >    1. 内存RAM（随机存取存储器）：通过电容存取数据，掉电将丢失所有数据
  > 4. 计算机的高速缓存
  >    1. 命中率是衡量缓存的重要性能指标，理论上CPU每次都能从高速缓存取数据的时候，命中率为1（访问Cache次数除以访问Cache和主存次数总和）
  >    2. 高速缓存的替换时间：当缓存没有数据时需要从主存载入数据
  >    3. 替换策略：随机算法、先进先出算法、最不经常使用算法LFU、最近最少使用算法LRU

- 计算机的CPU

  > 1. 计算机的指令系统
  >
  >    1. 机器指令的形式：操作码（指令所要完成的操作）+地址码（操作数和操作数地址）
  >    2. 机器指令的操作类型：数据传输、算术逻辑操作、移位操作、控制指令
  >    3. 机器指令的寻址方式：指令寻址（顺序寻址+跳跃寻址）、数据寻址（立即寻址+直接寻址+间接寻址）
  >
  > 2. 计算机的控制器
  >
  >    1. 作用：控制器时协调和控制计算机运行的
  >
  >    2. 组成：程序计数器、时序发生器、指令译码器、指令寄存器、主存地址寄存器、主存数据寄存器、通用寄存器
  >
  >    3. 运算器：进行数据运算加工，由数据缓冲器、ALU、状态字以及寄存器、通用寄存器组成
  >
  >    4. 计算机指令执行过程：取指令--分析指令--执行指令
  >
  >       从缓存取指令 送到指令寄存器
  >
  >       指令译码器译码 发出控制信号 程序计数器+1 
  >
  >       装载数据到寄存器 ALU处理数据 纪录运算状态 送出运算结果
  >
  >    5. CPU流水线涉及：因运算器和控制器不能同时工作，CPU的综合利用率不高，所以流水线涉及可以提高CPU的利用率大概3倍

#### 计算篇

- 进制运算的基础知识

- 二进制数据的表示方法

  > 1. 有符号数和无符号数
  > 2. 二进制的补码表示法
  > 3. 二进制的反码表示法

- 二进制数据的运算

  > 1. 定点数与浮点数
  > 2. 定点数的加减法运算
  > 3. 浮点数的加减法运算
  > 4. 浮点数的乘除法运算

#### 实践篇

- 实现双向链表
- 实现FIFO缓存置换算法
- 实现LRU缓存置换算法
- 实现LFU缓存置换算法

#### 面试题

- [总结1](https://codeantenna.com/a/ypsjtU4ybX)

  > 1. 翻译与解释
  >
  >    前者：将一种语言编写的程序全部翻译成另一种语言，然后再执行
  >
  >    后者：将一种语言编写的程序的一条语句翻译成另一种语言的一条或多条语句，执行完再解释下一条
  >
  > 2. 计算机系统结构、计算机组成
  >
  >    前者指能够被程序员看到的计算机属性，如指令集、数据类型等
  >
  >    后者指如何实现计算机体系结构所体现出来的属性
  >
  > 3. 冯诺依曼主要特点：
  >
  >    1. 由运算器、控制器、存储器、输入、输出五部分组成
  >    2. 指令和数据存储在存储器中，并可以按地址访问，均以二进制表示
  >    3. 指令由操作码和地址码组成，前者指明操作的性质，后者表示操作数在存储器中的位置
  >    4. 指令在存储器中按顺序存放，通常按照自动的顺序取出执行
  >    5. 机器以运算器为中心，IO设备与存储器交换数据也要通过运算器
  >    
  > 4. 什么是存储单元、存储字、存储字长、存储体
  >
  >    1. 存储一个存储字并具有特定存储地址的存储单元
  >    2. 一个存储单元中存放的所有二进制数据，按照某个地址访问存储单元获取得数据
  >    3. 存储字中二进制数据的位数，按照某个地址访问存储单元获取二进制数据的位数
  >    4. 由多个存储单元构成的存储器件
  >
  > 5. 主存储器中，MAR MDR是什么，存储器的最大容量由什么决定
  >
  >    1. 存储地址寄存器，保存需要访问的存储单元的地址，反映存储单元的个数
  >    2. 存储数据寄存器，缓存读出写入存储单元的数据，反映存储字长
  >    3. 由MAR的位数以及MDR的位数决定
  >
  > 6. 机器字长与存储字长
  >
  >    1. CPU一次能够处理的二进制数据的位数
  >    2. 按照某个地址访问某个存储单元可以获取的二进制数据位数
  >
  > 7. 假设MAR寄存器16位，MDR寄存器16位，存储器最大容量是多少
  >
  >    1. MAR表示地址个数由2的16次方个，即64K
  >
  >    2. MDR表示存储字长16位，即2个字节
  >
  >       一共64K*2B=128K Byte、、
  >
  >    - CPU将内存中的数据读出来，放入到CPU流水线的寄存器中，再对数据进行运算处理
  >    - RAM是随机存储器，是计算机内部储存器的一种，半导体存储器，其读取和写入的信息与存储位置无关，与顺序存储器（SAM 如磁带）不同，具有易失性 内存
  >    - ROM只读存储器，内部储存器的一种，写入后数据固话，掉电不影响，主板BIOS芯片属于ROM，硬盘 SSD等外部存储器不属于ROM概念
  >
  > 第三章 系统总线
  >
  > 1. 总线
  >
  >    冯诺依曼结构中，各个部件之间均有单独连线，线多导致扩展IO口不容易，引入总线连接方式
  
- 一、CPU执行代码

## C++ 基础知识

#### 基本语言

- static关键字作用

  > 1. 全局静态变量
  >
  >    在全局变量前添加static，作用域为全局，文件开始到文件末尾，保存在静态存储区，整个程序运行期间都存在，自动初始化为0，但自动对象的初始化值是任意的
  >
  > 2. 局部静态变量
  >
  >    局部变量前添加static，保存在静态存储区，作用域为局部作用域，但局部静态变量离开作用域后不会被销毁，驻留在内存中，不能再次访问，一旦函数再次被调用，局部静态变量的值不变
  >
  > 3. 静态函数
  >
  >    多个cpp复用函数，不能在头文件中声明static全局函数，不能在cpp内声明非static全局函数
  >
  > 4. 类的静态变量
  >
  >    实现多个对象的数据共享，不会破坏隐藏的原则，只存储一次
  >
  > 5. 类的静态函数
  >
  >    不是对象成员，调用不需要对象名，实现中不能直接引用类的非静态成员，如果非要引用非静态成员，可以通过对象引用
  >
  > #### ---------------------------------------------------------------------------------------------------------------
  >
  > 1. 静态成员
  >    - 静态数据成员在类的内部声明，在类的外部定义，在类的外部不能指定static，在类的定义时候进行初始化
  >    - 静态数据成员只能在类的外部初始化，特例是const static
  >    - 静态数据成员的类型可以是类类型，而非静态数据成员只能是类类型的引用或指针
  >    - 静态数据成员可以用作类成员函数的默认实参
  >    - 静态数据成员的值可以更改
  > 2. 区别
  >    - 静态成员在类被实例化后创建，类和对象都可以访问，而非静态只能对象访问
  >    - 一个类的所有实例对象的同一静态成员值相同，非静态成员值可以不同
  >    - 静态函数的实现不能使用非静态成员，如非静态变量和非静态函数
  > 3. 静态成员函数特点
  >    - 静态成员函数没有this指针，可以访问静态成员，不能访问非静态成员
  >    - 可以在类内部定义也可以在类外部定义，在外部定义时不能重复指定static关键字

- c++和c的区别

  > 1. c++是面向对象，c是面向过程的结构化编程语言
  > 2. c++具有封装 继承 多态三大特性，增加了类型安全的功能，如强制类型转换，以及c++支持范式编程，比如模板类和函数模板

- C++11新特性

  > 1. auto，根据变量的初始值自动推导出变量的类型
  > 2. 三个智能指针，auto（c++98） unique shared weak，解决内存管理的问题
  > 3. nullptr也是新增特性，可以被转换为任意其他的指针类型
  > 4. 初始化列表，可以对类进行初始化
  > 5. 基于范围的for循环
  > 6. 右值引用

- c++四中cast转换

  > 隐式转换：编译器私下进行的类型转换，从小倒大的范围，保证不丢失精度 如int a = true（explicit禁止隐式转换）
  >
  > 显式（强制）类型转换：int(x)
  >
  > 1. const_cast
  >
  >    对于未定义const版本的成员函数，用来将const转为非const
  >
  > 2. static_cast
  >
  >    用于隐式转换，完成基础数据类型，同一个继承体系中类型的转换，任意类型与void*的转换；比如非const到const，void*转指针，用于多态向上转化，向下能成功但不安全
  >
  > 3. dynamic_cast
  >
  >    动态类型转换，用于含有虚函数的类，用于类层次间的向上和向下转化，只能转指针和引用，向下转化时，非法指针返回NULL，非法引用抛异常
  >
  > 4. reinterpret_cast
  >
  >    几乎什么都可以转，可能会出问题，少用
  >
  > 5. 为什么不用c的强制转换
  >
  >    看起来功能强大，但转化不够明确，不能进行错误检查导致出错

- 指针和引用的区别

  > 1. 指针有自己的空间，引用只是一个别名
  > 2. 指针用sizeof查看的话是4个字节，引用的大小是实际被引用对象的大小
  > 3. 指针可以有多级指针，引用只有一级
  > 4. 指针可以在使用过程中指向别的对象，引用只能是一个对象的引用，不能被修改
  > 5. 指针可以被初始化为nullptr，引用必须是一个已有对象的引用
  > 6. 参数传递时指针必须被解引用才可以对对象进行操作，饮用可以直接对原有对象进行修改
  > 7. 指针有const指针，引用没有
  > 8. 指针和引用使用++运算符的意义不同
  
- c++四个智能指针

  > 1. auto_ptr：c++98的方案，c++11被抛弃，采用所有权模式，其他指针会剥夺前指针的所有权，再次访问前指针时会报错，存在潜在的内存崩溃问题
  > 2. unique_ptr：替换了auto_ptr，实现独占式拥有或严格拥有概念，保证同一时间内只有一个智能指针可以指向该对象，避免了资源泄露
  > 3. shared_ptr：共享式概念，多个智能指针可以指向同一个对象，相关资源在最后一个引用被销毁时自动释放，可以使用use_count查看当前资源的所有者个数
  > 4. weak_ptr：是一种不控制对象生命周期的智能指针，指向shared_ptr管理的对象，协助shared_ptr工作，构造和析构不会引起计数的增加或减少，解决shared_ptr的死锁问题（[循环引用](https://www.cnblogs.com/wxquare/p/4759020.html)），在访问所引用的对象前必须先转换为shared_ptr
  >
  > 其他：
  >
  > 1. [实现](https://www.cnblogs.com/wxquare/p/4759020.html) explicit：防止类构造函数的隐式自动转换，只对一个参数的类构造函数有效
  > 2. 语义：java中可以生成对象的多个不同引用
  
- [new delete malloc free](https://blog.csdn.net/wfei101/article/details/80100318)

  > 1. new和delete是c++的运算符，malloc和free是c++的标准库函数，前者调用对象所在类的构造函数或析构函数，后者进行直接申请或释放内存空间，但无法满足动态对象的要求，由于是库函数，所以编译器无法获得控制权限，需要new和delete来动态内存分配和初始化、自动清理和释放内存等工作
  
- c++面向对象的特点

  > 多态 继承 封装

- 子类父类的构造析构顺序

  > 调用子类的构造函数时，会先调用父类的构造函数，然后调用子类的构造函数
  >
  > 调用子类的析构函数时，会先调用子类的析构函数，然后调用父类的析构函数
  >
  > 其他：
  >
  > - 析构函数设置为虚函数：
  >
  >   保证被子类继承时，new一个子类，使用基类指针指向该对象时，释放基类指针即可释放掉子类的空间，防止内存泄露
  >
  > - c++默认析构函数不是虚函数
  >
  >   因为虚函数需要格外的虚函数表和虚表指针，占用额外的内存，如果类不需要被继承，会浪费空间，只有需要作为父类时，需要设置为虚函数

- 多态、虚函数和纯虚函数

  > 多态是指对于不同的对象接收相同的信息时产生不同的动作，分为编译时多态（重载）和运行时多态（虚函数）
  >
  > 编译时多态：（在编译时就能确定用哪个方法）
  >
  >  	1. 体现在函数和运算符的重载上
  >
  > 运行时多态（虚函数）：（在运行时才能确定用哪个方法）
  >
  > 	1. 在基类冠以virtual关键字，提供了一种接口界面，允许在派生类中对基类的虚函数重新定义
  > 	2. 纯虚函数：为派生类保留一个函数的名字，作为接口而存在，没有被实现，一般不能直接被调用（从基类继承而来的纯虚函数，在派生类中仍是虚函数，如果一个类中至少有一个纯虚函数，这个类是抽象类）
  >
  > **重载 重写 重定义对比：**
  >
  > 	1. 重载是指在同一个类中，方法名相同，参数个数不同或类型不同，编译器会根据这些函数的不同参数列表，将同名函数名称做修饰，未体现多态（允许存在多个同名函数，但不看返回类型）
  > 	2. 重写是在继承关系中出现，子类重写定义父类的相同名称相同参数的虚函数，必须是virtual的才可以重写，重写的访问修饰符可以不同，体现了多态
  > 	3. 重定义是指在子类中重新定义父类相同名称的非虚函数，参数列表可以相同可以不同，会直接覆盖父类的方法，未体现多态

- 结构和联合的区别

  > 1. 结构和联合都是由不同的数据类型成员组成，但是在任一时刻，联合只存放一个被选中的成员（所有成员共享一个地址空间），而结构体是所有成员同时存在，不同成员的存放地址不同
  > 2. 对联合的不同成员进行赋值时，将会对其他成员重写，相当于成员之前的值都不在了，而结构的不同成员赋值是互不影响的

- 哪几种情况只能用initialization不能用assignment

  > 类中有const 引用成员变量时

- 类型安全

  > c++不是类型安全的，两个不同类型的指针是可以强制转换的，用reinterpret cast，c#是类型安全的

- main函数执行之前，还会执行什么

  > 执行全局对象的构造函数

- 描述内存分配的方式

  > 1. 静态存储区分配内存：内存在程序编译时就已经分配好了，在整个程序运行的期间都存在，比如全局变量或static变量
  > 2. 在栈上创建，在执行函数时，函数局部变量的存储单元都可以在栈上创建，函数执行结束后这些存储空间自动被释放；栈内存分配运算内置于处理器的指令集
  > 3. 在堆上创建，也成动态内存分配，程序运行过程中由malloc或new申请任意空间的内存，由程序员自己负责在何时free或delete释放掉，动态内存的声明周期由程序员决定，使用灵活，但也容易产生问题

- const和define区别

  > 1. const可以修饰变量 函数参数 函数返回值，被修饰的都受到强制保护，不可以被改变
  > 2. 编译器对前者进行类型安全检查，对后者只是字符替换，不进行安全检查，可能出现错误
  > 3. 有的集成化调试工具可以对const常量进行调试，对宏常量不可以
  
- 虚函数表

  



## 操作系统

- 进程与线程

  > 基本概念
  >
  > 1. 进程是对运行时程序的封装，是系统进行资源调度和分配的基本单位，实现操作系统的并发，而线程是进程的子任务，是CPU调度和分派的基本单位，用于保证程序的实时性，实现进程内部的并发，是操作系统可识别的最小执行和调度单位。每个线程独自占用一个虚拟处理器，肚子的寄存器组 指令计数器和处理器状态
  >
  > 区别
  >
  > 1. 一个线程只输入一个进程，一个进程可以有多个线程，但是至少一个线程
  > 2. 进程在执行的过程中拥有独立的内存单元，而多个线程共享进程的内存
  > 3. 进程是资源分配的最小单元，线程是CPU调度的最小单位
  > 4. 进程切换的开销远大于线程切换的开销（线程切换只需保存和设置少量寄存器的内容，并不涉及存储器管理方面的操作）
  > 5. 同一进程的多个线程具有相同的地址空间，所以它们之间的同步和通信变得比较容易，线程间通信可以直接读写进程数据段（如全局变量）
  > 6. 进程编程调试简单可靠，开销大，线程开销小，切换速度快，但调试相对复杂
  > 7. 进程之间不会相互影响，而一个线程挂掉将导致整个进程挂掉
  > 8. 进程适应与多核 多机分配，线程适用于多核
  >
  > 进程之间通信方式（管道、系统IPC（包括消息队列 信号量 信号 共享内存等）以及套接字socket）
  >
  > - 管道（无名管道 命名管道）
  >   - 管道用于父子进程间的通信，有名管道还可以用于无亲缘关系进程间的通信
  >   - 普通管道PIPE：半双工 父子 兄弟进程，不属于任何文件系统，只存在于内存中
  >   - 命名管道FIFO：无关进程之间交换数据，有路径名与之关联，以一种特殊设备文件形式存在于文件系统中
  > - 系统IPC
  >   - 消息队列：面向记录的，有特定的格式和优先级；独立于发送和接收进程，进程终止时不会被删除；可以实现消息的随机访问，不一定先进先出，也可以按消息的类型读取
  >   - 信号量：计数器，控制多个进程对共享资源的访问，实现进程间的互斥和同步，不用于存储进程间通信数据；若要传递数据需要结合共享内存；基于操作系统的PV操作，程序对信号量的操作都是原子操作；每次对信号量的PV操作不仅限于信号量加一减一，可以加减任意正整数，支持信号量组
  >   - 信号：用于通知接收进程某个事件已经发生
  >   - 共享内存：使多个进程可以访问同一内存空间，不同进程可以看到对方进程中对共享内存中数据的更新，依靠同步操作如互斥锁和信号量；是最快的IPC，进程直接对内存存取
  
- 一、进程之间通信方式

  > 1. 管道：`netstat -tulnp | grep 8080`,将前一条命令的输出作为后一条命令的输入，此为匿名管道，单向通信；`mkfifo test`为命名管道，类似于缓存，效率低下，只能等b进程取了数据以后a进程才能返回，不适合频繁通信的进程
  > 2. 消息队列：实现a进程将数据放进消息队列后会自动返回，b进程在需要的时候再去读取，a进程无需等待，但是如果数据比较大就不适合消息队列了，因为数据的拷贝需要花很多时间来访问内存，效率又会变低。
  > 3. 共享内存：解决数据比较大的问题，直接把数据放在共享内存空间中，无需拷贝，虽然每个进程拥有自己独立的内存空间，但分配的都是虚拟内存空间，可以将两个虚拟内存空间映射到同一块物理内存空间，实现内存共享。
  > 4. 信号量：共享内存存在的问题是多个进程竞争访问共享内存，类似于线程安全，信号量的本质就是一个计数器，比较初始为1，a进程访问时发现是1，继续访问，设为0，b进程发现是0，不继续访问
  > 5. socket：可以实现不在同一主机的多个进程的访问，类似于浏览器发送的http请求，服务端返回对应的数据

- 二、经典的进程调度算法

  > 批处理时代：
  >
  > 1. FCFS 先到先服务，按照到达顺序排序，依次服务，缺点是短进程的响应时间太长
  > 2. SPN 短进程优先，将预计处理时间短的进程提到最前面，优先服务，缺点是长进程会有饥饿现象
  > 3. HRRN 高响应比优先，综合考虑等待时间和要求服务时间两个属性，响应比=（等待时间+服务时间）/服务时间
  >
  > 并发时代：
  >
  > 1. RR 时间片轮转算法，切换进程使用的FCFS算法，但时间片不宜取太短，因为切换上下文也需要耗费CPU资源，所以需要看交互时间来决定
  > 2. VRR 虚拟时间片轮转算法，使IO密集型进程在阻塞解除后进入辅助队列，优先选择这些进程
  > 3. 优先级调度，在用户进程太多时，需要优先处理内核进程，每个进程根据自身情况确定优先级数值，但是用户进程的优先级不准高于内核进程的优先级，等待时间长的进程也会适当提高优先级避免饥饿

- 三、彩票调度算法

  > 1. 比例份额调度 公平份额调度，不需要记录任何状态，轻量
  >
  > 2. 没有广泛使用：
  >
  >    1. 不能很好的适合I/O
  >    2. 票数分配问题没有确定的解决方式
  >
  >    在某些容易确定份额比例的领域中，比例份额调度程序更有用

- 四、用户级线程和内核级线程

  > 1. 用户级线程：
  >
  >    用函数库实现了线程，线程库中包含创建线程、终止线程等，如 `pthread_creat  pthread_exit pthread_join pthread_yield`,用户级线程只能占用一个核，做不到并行加速，由于透明性，操作系统不能主动切换线程，线程一旦阻塞，整个进程的其他线程全部阻塞，因此出现了jacket，把一个产生阻塞的系统调用转换成一个非阻塞的系统调用
  >
  >    两个缺点：1 还是在单独的核上运行，无法并行 2 一个线程阻塞，整个进程阻塞
  >
  >    优先：线程切换开销小，可以有多个调度算法  解决阻塞—jacketing（不直接调用系统级的IO例程，让线程调用应用级的IO jacketing例程，检查是否忙，忙则切换线程）
  >
  > 2. 内核级线程：
  >
  >    内核里有纪录系统所有线程的线程表，系统看得见线程，可以做到并行实行，且一个线程被阻塞，其他线程不会被阻塞，缺点是：每次线程切换，系统会陷入内核态，用户态到内核态的开销是比较大的，所以切换代价比用户级线程大，且表是存放在操作系统固定的表格空间或堆栈空间里，数量优先，扩展性不及用户级线程

- 五、线程的来龙去脉

  > 1. 进程拆成线程，将进程的执行流拆开给多个线程，进程包含资源所有权（对内存、IO设备、IO通道及文件等的控制权）和执行流
  > 2. 进程切换信息保存在PCB中，线程切换信息保存在TCB中

- 六、进程的线程的简单解释

  > 1. “信号量“——相当于多把锁，防止多个线程不会互相冲突
  > 2. 操作系统的设计：
  >    1. 多进程形式，允许多个任务同时进行
  >    2. 多线程形式，允许单个任务分成不同的部分运行
  >    3. 提供协调机制，防止进程之间和线程之间冲突，也允许进程之间和线程之间共享资源

- 七、协程

  > 1. 进程：操作系统在资源分配时使用的最小单位
  > 2. 线程：操作系统在执行程序时的单位，多线程共享进程的资源（加锁），一个核心一次只能运行一个线程，需要频繁上下文切换，操作系统切换线程实在内核空间完成，实际程序的线程是运行在用户空间的
  > 3. 操作系统：分为内核空间和用户空间
  > 4. 协程：一个线程中有多个协程，多协程之间也可以并发运行，不需要加锁，因为位于同一个线程内；切换在用户空间完成，不需要操作系统的干预；协程的实现需要语言本身的完全支持
  > 5. 函数：代码中有了协程，代码的执行路径不再是确定的，单线程内并发执行

- 八、互斥锁

  > 1. 屏蔽时钟中断：虽然可以禁止进程切换，但是过于危险
  > 2. 加锁：TSL(test and set lock) 锁关闭时循环等待，直到打开，浪费CPU资源
  > 3. 信号量：P检测（s=s-1if(s<0)不为正值时阻塞进程） V增量（s=s+1if(s<=0)唤醒被阻塞的进程），用来控制多个进程互斥访问，也可以通过设置两个操作的信号量不同来达到同步

- 九、各种锁

  > 1. 重量级锁：同步 线程安全->获取不到锁的时候立马进去阻塞状态
  > 2. 自旋锁：等待一段时间再进入阻塞状态
  > 3. 自适应自旋锁：自适应调整循环次数，经常拿到这个锁则循环多次，很少拿到循环几次
  > 4. 轻量级锁：不加锁，做标记，CAS机制-原子操作，出现竞争时再调整为重量级锁
  > 5. 偏向锁：首次进入采用CAS机制，同时纪录ID，退出以后不改变ID，下次来时候发现ID改了，升级为轻量级锁
  > 6. 悲观锁：重量级锁 自旋锁 自适应自旋锁
  > 7. 乐观锁：轻量级锁

#### Linux操作系统

- [常考命令](https://www.jianshu.com/p/4bca8fe8a878)

  > 1. cd 切换当前目录，绝对路径和相对路径均可
  > 2. pwd 输出当前工作绝对路径
  > 3. ls 查看文件与目录（list），-a显示全部文件包含隐藏 -l显示详细资料 -R递归显示子目录 
  > 4. cp 复制文件 -a复制特性 -p复制属性 -i覆盖时询问 -r递归复制 用于复制目录 -u有差异时的复制
  > 5. mv 移动文件 目录 更名，-f强制移动覆盖 -i询问 -u文件已存在且更新才会更新
  > 6. rm 删除文件 目录 -f忽略不存在文件 不警告 -i询问是否操作 -r递归删除
  > 7. cat 查看文本文件内容：more less head tail...
  > 8. find 文件搜索：find path -name file1 -user user1
  > 9. chmod文件权限设置：ls -lh显示权限，chmod ugo+rwx file1
  > 10. chown 改变文件的所有者：chown user1 file1
  > 11. chgrp：改变文件所属用户组
  > 12. grep 文本处理 分析一行的信息：正则表达式 grep xxx /var/.../exam.txt
  > 13. paste 文本处理 合并内容：paste file1 file2
  > 14. sort 排序：sort file1 file2 | uniq 取出并集 -u删除交集 -d取出交集
  > 15. comm 比较：comm -num file1 file2 -1只删除1的内容 -2只删除2的内容 -3只删除共有内容
  > 16. tar 打包：-c新建打包文件 -C指定解压目录  tar -C dirs -zxvf sth.tar.gz
  > 17. jps 显示当前系统的java进程和id号
  > 18. ps 将某个时间点的进程运行情况选取下来并输出 process之意 ps aux 
  > 19. kill: kill pid
  > 20. killall
  > 21. top 性能分析工具，实时显示系统各个进程的资源占用状况
  > 22. netstat -tunlp|grep 端口号：查看进程端口号 

- 操作系统的概念

  > 1. 特征：并发、共享、虚拟和异步（并发和共享是互为存在的关系 ）（虚拟是吧物理上的实体变成若干个逻辑上的对应物，前者实际存在，后者用户感受到的，没有并发性就不需要虚拟性）（异步性 由于资源有限，进程的执行不是一贯到底的，不可预知的速度推进 只有有并发性，才可能导致异步性）
  > 2. 资源共享方式
  >    - 互斥共享：可供多个进程使用，但一个时间段只允许一个访问
  >    - 同时共享：允许同一时间段多个进程同时访问
  > 3.  系统调用和库函数：系统调用需要在核心态下进行，有时会将系统调用封装成库函数，隐藏系统调用的一些细节，不是所有库函数都封装了系统调用；陷入指令唯一一个只能在用户态执行，不可在核心态执行，执行后引发一个内中断；系统调用会使处理器从用户态进入核心态

- 进程

  > 1. 程序段在低地址部分，数据段在高地址部分
  >
  > 2. 程序段 数据段 PCB（进程控制块）组成了进程实体，PCB是进程存在的唯一标志
  >
  > 3. 进程是进程实体的运行过程，是系统进行**资源分配和接受调度的一个独立单位**
  >
  > 4. 状态与转换：
  >
  >    - 运行态：占有CPU并运行
  >    - 就绪态：具有除了CPU以外所有条件，等待空闲CPU
  >    - 阻塞态：等待某一事件
  >
  > 5. 进程控制：
  >
  >    - 原语实现进程控制，不允许中断（关中断 开中断）
  >
  > 6. 进程通信：进程之间的信息交换 
  >
  >    - 共享存储：分配共享空间（必须互斥  PV操作）基于数据结构 基于存储区
  >    - 消息传递：交换以格式化消息为单位 直接通信 间接通信
  >    - 管道通信：用于连接读写进程的一个共享文件，内存中大小固定的缓冲区 半双工 互斥访问，没写满不许读，没读空不许写
  >
  > 7. **线程**
  >
  >    - 进程是程序的一次执行，线程可以增加进程的并发度
  >    - 传统：进程是程序执行流的最小单位  
  >    - 引入线程：线程是程序执行流的最小单位，是一个基本的CPU执行单元
  >    - 资源分配给进程，再将资源分配给线程；**进程是资源分配的最小单位，线程是调度的基本单位**
  >    - 内核级线程：核心态，有操作系统内核完成  用户级线程：用户态   内核级线程才是处理器分配的单位
  >
  > 8. 处理机调度
  >
  >    - 高级调度（作业调度）：每个作业只会被调用一次
  >
  >    - 中级调度（内存调度）：挂起状态，PCB不会调到外村
  >
  >      五状态模型：创建 就绪 运行 阻塞 终止
  >
  >      七状态模型：五+就绪挂起 阻塞挂起（挂起态是将进程映像调到外存中）
  >
  >    - 低级调度（进程调度）：是操作系统中最基本的一种调度
  >
  >      - 主动放弃 被动放弃     
  >      - 不能调度与切换的情况：处理中断、进程在操作系统内核程序临界区（临界区：访问临街资源的代码  内核程序临街区访问内核数据结构 会上锁）、院子操作过程中
  >
  >    - 调度方式：抢占式（可由操作系统剥夺）  非抢占式（主动放弃）
  >
  > 9. 调度算法的评价
  >
  >    - CPU利用率  系统吞吐量 周转时间 带权周转时间 等待时间 响应时间
  >
  > 10. 调度算法
  >
  >     - 先来先服务：FCFS 对长作业有利  对短作业有利 不会导致饥饿
  >     - 短作业优先：SJF 默认非抢占式 对短作业有利 长作业不利 会导致
  >     - 高响应比优先：HRRN 响应比=等待时间+服务时间 / 服务时间 权衡这种 不会导致
  >     - 时间片轮转调度RR： 时钟中断 抢占式  时间片要适中 不导致
  >     - 优先级调度：适用于作业调度 进程调度 IO调度（系统进程>用户进程 前台>后台 偏好IO进程--相对的是计算型进程） 适用实时  导致饥饿
  >     - 多级反馈队列调度：进程调度 抢占式 折中权衡 会导致饥饿
  >
  > 11. 进程同步 互斥
  >
  >     - 同步：直接制约关系，在某些位置上协调它们的工作次序而产生的制约关系
  >     - 互斥：（资源共享方式：互斥共享  同时共享）进入区 临界区 退出区 剩余区
  >
  > 12. 互斥的软件实现方法：
  >
  >     - 单标志法：轮流访问，违背空闲让进原则
  >     - 双标志法：先检查会同时进入，违背忙则等待 后检查会都无法进入，产生饥饿
  >     - Peterson算法：三步走 flag[2]+turn 孔融让梨，最后一个谦让的进行等待 但为遵循让权等待
  >
  > 13. 互斥的硬件实现方法：
  >
  >     - 中断屏蔽方法：适合单核  
  >     - TestAndSet指令：硬件实现，不允许被中断，将临界区资源上锁 ，适合多处理机
  >     - Swap指令：交换两个变量的值  两个指令都不满足让权等待
  >
  > 14. 信号量机制（进程互斥和同步 让权等待）
  >
  >     - 整型信号量：初始化 P操作 V操作  wait和signal原语操作，检查上锁一气呵成  不满足让权等待
  >     - 记录型信号量：解决忙等，结构体，解决让权等待 不会忙等
  >     - P(S) V(S)实现系统资源的申请和释放
  >     
  > 15. 管程（解决信号量机制编程麻烦、易出错问题）
  >
  >     - 局部于管程的数据只能被局部与管程的过程访问
  >     - 每次仅允许一个进程在管程内执行某个内部过程
  
- 死锁

  > 1. 死锁：各进程互相等待对方手里的资源，导致个进程都阻塞（必要条件：互斥条件、不剥夺条件、请求和保持条件、循环等待条件）
  >
  >    饥饿：长期得不到想要的资源，如短进程优先算法SPF（策略不合理）
  >
  >    死循环：某进程执行过程中一直跳不出某个循环的现象（代码逻辑的错误）
  >
  > 2. 预防死锁
  >
  >    - 

#### 计算机网络

- 计算机如何通信

  > 1. 五层模型：
  >
  >    应用层：
  >
  >    传输层：
  >
  >    网络层：
  >
  >    数据链路层：
  >
  >    物理层：
