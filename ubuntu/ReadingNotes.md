# Linux高性能服务器编程

## 一 TCP/IP协议详解

### 1 tcp/ip协议族

- **基本概念**

  ```
  四层协议系统：数据链路层(ARP地址解析协议 RARP)、网络层(ICMP IP)、传输层(TCP UDP)、应用层(ping telnet OSPF DNS)
  ```

- **ICMP协议**

- **ARP协议**

- **DNS协议**

- **socket**

  ```
  1.将应用程序数据从用户缓冲区中复制到TCP/UDP内核发送缓冲区，或从内核接收缓冲区中复制数据到用户缓冲区
  2.应用程序通过修改内核中各层协议的某些头部信息或其他数据结构从而精细地控制底层通信
  ```

### 2 ip协议详解

### 3 tcp协议详解

### 4 tcp/ip通信案例

## 二  深入解析高性能服务器编程

### 5 Linux网路编程基础api

### 6 高级i/p函数

### 7 Linux服务器程序规范

### 8 高性能服务器程序框架

### 9 i/o复用

### 10 信号

### 11 定时器

### 12 高性能i/o框架库libevent

### 13 多进程编程

### 14 多线程编程

### 15 进程池和线程池



## 三 高性能服务器优化与检测

### 16 服务器调制  调试和测试

### 17 系统检测工具



# Java核心技术 卷1

## 1 Java程序设计概述

## 2 Java程序设计环境

- 图形化界面：报错 在Eclipse里使用var正常 在终端使用javac时报var无法识别  猜测是jdk-8的var不稳定

## 3 Java的基本程序设计结构

- **简单的Java程序：**

  ```
  java中main为void类型，没有返回值，当main正常退出，程序的退出代码为0，如果希望在终止时返回其他的代码，需要调用System.exit(x)
  ```

- **注释：/* */不能嵌套，中间含有嵌套注释时会出错**

- **数据类型**

  ```java
  整型：int short long byte 4 2 8 1字节数量与平台无关
  浮点型：float double
  char  boolean：0不代表false
  ```

- **变量**

  ```
  1.不区分变量的声明和定义
  2.final指示常量，只能被赋值1次，常量名一般使用全大写
  ```

- **运算符**

  ```
  1.添加import static java.lang.Math.*即可以直接使用Math的方法如sqrt(PI)
  2.boolean的强制类型转换：b?1:0
  3.常见运算符：!= == ^(xor) ~(not) >>>用0填充高位 >>用符号位填充高位
  4.枚举类型：enum
  ```

- **字符串 不可变字符串**

  ```
  1.子串：str.substring(a,b) /b为不想复制的第一个位置
  2.拼接：+ 多用于输出语句，字符串可与非字符串拼接  String.join(result,args)  在args中用定界符分割
  3.字符串相等 s.equals(t)  或s.compareTo("hello")==0
  4.码点与代码单元：str.charAt(0)
  java.lang.string 1.0
  5.字符串构建器：StringBuilder builder 添加:builder.append() 构建:String = builder.toString
  ```

- **输入输出**

  ```
  1.Scanner in = new Scanner(System.in); in.nextInt next nextInt
  2.格式化输出：System.out.printf("%8.2f",x) String.format("...",xxx)
  3.文件输入输出：Scanner in = new Scanner(Paths.get("file.txt"),"UTF-8")
  ```

- **控制流程**

  ```
  1.块作用域内无法重定义一个变量
  2.if else if else;  switch (choice){case 1:...;break;}
  3.中断控制流程语句：read_data:  break read_data;
  ```

- **大数值**

  ```
  BigInteger  java.math.*
  BigDecimal  add miltiply
  ```

- **数组**

  ```
  1.声明与初始化：int[] a = new int[100]
  2.for each循环：for (int element:a)	..print(element) 或 Array.toString(a)
  3.拷贝：浅拷贝 = ；深拷贝 arrays.copyOf(a,len)可增加数组大小  没有指针运算
  4.命令行参数：java HelloWorld -h wal args[0] = -h
  5.排序 Array.sort(a) Math.random 0-1 不含1
  6.快速打印：Ayyay.deepToString(a)
  ```

## 4 对象与类

- **用户自定义类**

  ```
  1.Java对象都是在堆中构造，构造器伴随着new操作符一起使用
  2.隐式参数 可使用this.salary来编写
  ```
  
- **静态域和静态方法**

  ```
  1.静态域：不属于任何独立的对象，唯一的标识码
  2.静态常量：public static final double xx = 3.14
  3.静态方法：可以访问静态域
  ```

- **方法参数**

  ```
  1.Java传入参数为拷贝，对象引用按值传递
  ```

- **包**

  ```
  1.将因特网名以逆序形式作为包名，包与子包没有任何关系
  2.将类放在包中，首行加入package com.xxx.java等，否则被放置在默认包中，
  ```

## 5 继承

- **类、超类和子类**

  ```
  1.子类：public class Manager extends Employee 使用super.x调用父覆盖方法
  
  ```
  
  











## 6 接口 lambda表达式与内部类



## 7 异常 断言和日志



## 8 泛型程序设计



## 9 集合



## 10 图形程序设计



## 11 事件处理



## 12 Swing用户界面组件



## 13 部署Java应用程序



## 14 并发

































