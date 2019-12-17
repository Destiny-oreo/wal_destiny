# 背景
2019-2020学年第一学期最后两周进行光电综合设计实验课，课题选择了光照度计系统综合设计，其中仿真和代码部分查了较多资料（包含AT89C52最小系统、ADC0832模块、DS18B20温度传感器、LCD1602模块），特此记录。

## 放大电路
使用LM324N设计放大电路，其中只用一个放大器可设计成最简单的放大电路，但比较不稳定，所以设计了使用三个放大器的[仪表放大器](https://blog.csdn.net/sinat_25400221/article/details/94012940)，可以在一定程度上更好的抗干扰，使用差分放大。
## [51最小系统](http://m.elecfans.com/article/608156.html)
对51系列单片机来说，单片机+晶振电路+复位电路便组成了最小系统，同时也会经常加上按键输入和显示输出到该最小系统中。[制作图](https://blog.csdn.net/zerokkqq/article/details/79254926)
- **晶振电路**
  通常在引脚XTAL1和XTAL2跨接石英晶体和两个补偿电容构成自激振荡器，晶振一般选择11.0592MHz，电容可选30pF左右的瓷片电容。
- **复位电路**
  采用上电自动复位和手动按键复位两种方式实现系统的复位操作。上电复位要求接通电源后，自动实现复位操作。手动复位要求在电源接通的条件下，在单片机运行器件，用按钮开关操作使单片机复位。上电自动复位通过CAP-POL极性电容来实现，手动按键复位通过按键将电阻R2和VCC接通来实现。

## [ADC083](https://blog.csdn.net/zenghuanyu_big/article/details/78178799)
- **介绍**：是8脚双列直插式双通道A/D转换器，能分别对两路模拟信号实现模—数转换，可以用在单端输入方式和差分方式下工作。ADC0832采用串行通信方式，通过DI 数据输入端进行通道选择、数据采集及数据传送。8位的分辨率（最高分辨可达256级），可以适应一般的模拟量转换要求。其内部电源输入与参考电压的复用，使得芯片的模拟电压输入在0~5V之间。具有双数据输出可作为数据校验，以减少数据误差，转换速度快且稳定性能强。独立的芯片使能输入，使多器件挂接和处理器控制变的更加方便。
- **电压换算**：检测0-5V，返回0-255的数，故需要除以256乘以5得到最后的电压值。
```
#include "ad832.h"
unsigned char read_adc0832(unsigned char CH)		//标准读取AD转换结果的函数
{
	unsigned char i,test,adval;
	adval = 0x00;
	test = 0x00;
	Clk = 0;       //初始化
	DATI = 1;
	_nop_();
	CS = 0;
	_nop_();
	Clk = 1;
	_nop_();
   if ( CH == 0x00 )      //通道选择 通道0->DATI=0X00
   {
			Clk = 0;
			DATI = 1;      //通道0的第一位
			_nop_();
			Clk = 1;
			_nop_();
			Clk = 0;
			DATI = 0;      //通道0的第二位
			_nop_();
			Clk = 1;
			_nop_();
    } 
    else					//通道1->DATI=0X01
    {
			Clk = 0;
			DATI = 1;      //通道1的第一位
			_nop_();
			Clk = 1;
			_nop_();
			Clk = 0;
			DATI = 1;      //通道1的第二位
			_nop_();
			Clk = 1;
			_nop_();
    }
      Clk = 0;
      DATI = 1;
    for( i = 0;i < 8;i++ )      //读取前8位的值
    {
       _nop_();
       adval <<= 1;
       Clk = 1;
       _nop_();
       Clk = 0;
       if (DATO)
          adval |= 0x01;
      else
          adval |= 0x00;
    }
      for (i = 0; i < 8; i++)      //读取后8位的值
      {
           test >>= 1;
           if (DATO)
              test |= 0x80;
           else 
              test |= 0x00;
          _nop_();
          Clk = 1;
          _nop_();
          Clk = 0;
      }
      if (adval == test)      //比较前8位与后8位的值，如果不相同舍去。若一直出现显示为零，请将该行去掉
           dat = test;
      _nop_();
       CS = 1;        //释放ADC0832
       DATO = 1;
       Clk = 1;
      return dat;
}
```
## [DS18B20](https://blog.csdn.net/u013151320/article/details/50253199)
- **介绍**：是一种单总线数字温度传感器，测试温度范围-55℃-125℃，具有体积小，硬件开销低，抗干扰能力强，精度高的特点。单总线，意味着没有时钟线，只有一根通信线。单总线读写数据是靠控制起始时间和采样时间来完成，所以时序要求很严格，这也是DS18B20驱动编程的难点。
- **温度换算**：默认12位精度，返回底8位和高8位，低4位为小数部分，所以转为10进制时直接乘以0.0625即可。
```
#include "ds18b20.h"

void dsreset(void)       //初始化
{
  uint i;
  DS=0;
  i=103;
  while(i>0)i--;
  DS=1;
  i=4;
  while(i>0)i--;
}
bit tmpreadbit(void)       //读1bit
{
   uint i;
   bit dat;
   DS=0;i++;          //i++ for dalay1ms
   DS=1;i++;i++;
   dat=DS;
   i=8;while(i>0)i--;
   return (dat);
}
uchar tmpread(void)   //读1byte
{
  uchar i,j,dat;
  dat=0;
  for(i=1;i<=8;i++)
  {
    j=tmpreadbit();
    dat=(j<<7)|(dat>>1);   //读出的数据最低位在最前面，这样刚好一个字节在DAT里
  }
  return(dat);
}
void tmpwritebyte(uchar dat)   //写命令
{
  uint i;
  uchar j;
  bit testb;
  for(j=1;j<=8;j++)
  {
    testb=dat&0x01;
    dat=dat>>1;
    if(testb)     //write 1
    {
      DS=0;
      i++;i++;
      DS=1;
      i=8;while(i>0)i--;
    }
    else
    {
      DS=0;       //write 0
      i=8;while(i>0)i--;
      DS=1;
      i++;i++;
    }

  }
}
void tmpchange(void)  //芯片驱动
{
  dsreset();
  dalay1ms(1);
  tmpwritebyte(0xcc);  // 跳过读序号列号的操作
  tmpwritebyte(0x44);  // 启动温度转换
}
uint tmp()               //计算温度
{
  float tt;
  uchar a,b;
  dsreset();
  dalay1ms(1);
  tmpwritebyte(0xcc);	//跳过ROM操作命令（仅有1个DS18B20
  tmpwritebyte(0xbe);	//读温度寄存器命令
  //共16位，高五位符号位 低四位小数部分 中间7位整数部分
  a=tmpread();		//低8位
  b=tmpread();		//高8位
  temp=b;			//uint temp 为16位
  temp<<=8;             
  temp=temp|a;		//组合完毕 高8位为b 低8位为a
  tt=temp*0.0625;	//16位温度转换为10进制的温度（默认12位精度 *0.0625
  temp=tt*10+0.5;	//保留一位小数 并四舍五入 如26.5131->265.6->265
  return temp;
}
```
## [LCD1602](https://wenku.baidu.com/view/a00fb241fe4733687e21aa1b.html)
- 51系列单片若P0口控制D0-D7时需要单独加上拉电阻，若为其他IO口则自带了上拉电阻。
- 关键脚为4管脚寄存器选择RS和6管脚使能端E。
- [显示位置](http://www.51hei.com/bbs/dpj-112219-1.html)16*2，最高位必须置1
```
#include "lcd1602.h"
void write_com(uchar com)	//标准LCD写命令函数 先选择寄存器 再制造下降沿
{
	P0=com;
	rs=0;	//指令寄存器
	lcden=0;
	dalay1ms(10);
	lcden=1;
	dalay1ms(10);
	lcden=0;	//下降沿 执行
	
}

void write_data(uchar date)		//标准LCD写数据函数
{
	P0=date;
	rs=1;	//数据寄存器
	lcden=0;
	dalay1ms(10);
	lcden=1;
	dalay1ms(10);
	lcden=0;
	
}
void init()	//LCD初始设置
{
	write_com(0x38);	//显示模式设置 16*2
	dalay1ms(20);
	write_com(0x0e);	//显示开 有光标 光标闪烁 0f->0c
	dalay1ms(20);
	write_com(0x06);	//光标右移 字符不变
	dalay1ms(20);
	write_com(0x01);	//清屏
	dalay1ms(20);	
}

void string_display(unsigned char *p)	//写第一行数据
{
   unsigned int n=0;
   while(*p!='\0')
  {
    write_com(0x80+n);
    write_data(*p);
    p++;
    n++;
  }
}

void string_display1(unsigned char *p)	//写第二行数据
{
   unsigned int n=0;
   while(*p!='\0')
  {
    write_com(0x80+0x40+n);
    write_data(*p);
    p++;
    n++;
  }
}
```
## 主函数
添加.c和.h文件时，.h文件只是提供各函数或者变量等的声明，主函数和对应的.c文件都需要包含.h，主函数能够找到对应.c文件的原因是要把以写好的.c文件加入到对应的项目中，如需要用到其他文件的全局变量，可以extern+数据类型+变量名。.h标准格式为`#ifndef #define #endif`
```
#include<reg52.h>
#include<intrins.h>
#include "ad832.h"
#include "lcd1602.h"
#include "ds18b20.h"
#define uchar unsigned char
#define uint unsigned int
uint temp; 
unsigned char code nums[]="0123456789" ;	//数据放在ROM里面
unsigned char code first_line[]="   B16030910";			//无法在更改
//unsigned char code second_line[]="temp:";
unsigned char lx_result[]={0x00, 0x00, 0x00, 0x00}; 
unsigned char dat = 0x00;
unsigned char t_result[]= {0x00, 0x00, 0x00};  
void dalay1ms(uint x)	//标准1ms延迟函数
{
	uint a,b;
	for(a=x;a>0;a--)
		for(b=125;b>0;b--); 
}

void convdata(unsigned char i,unsigned int t)	// 计算光照度和温度  分别更新至相应的数组中以待显示
{	 
  int temper;
  float vol;
  int vo;
  int lxsum;
  temper=t;
  t_result[0]=temper/100;
  t_result[1]=temper%100/10;
  t_result[2]=temper%100%10;

  vol=(i*5.0)/256;		//8位ADC,返回的i是0-255，即0V=0,5V=255
  lxsum=(int)(vol*100);
  //lxsum=6*vo;		//估计是拟合函数 lx = 6*v   且放大100倍 说明原来被分成100份
  lx_result[0]=lxsum/1000;
  lx_result[1]=lxsum%1000/100;
  lx_result[2]=lxsum%1000%100/10;
  lx_result[3]=lxsum%1000%100%10;

}




void display()	//更新LCD显示
{
	string_display(first_line);		//写 lx:
	//string_display1(second_line);	//写 temp:
	write_com(0x80+0x40);
	write_data(nums[lx_result[1]]);
	write_com(0x81+0x40);
	write_data('.');
	//write_data(nums[lx_result[2]]);
	write_com(0x82+0x40);
	write_data(nums[lx_result[2]]);
	write_com(0x83+0x40);
	write_data(nums[lx_result[3]]);
	write_data(' ');
	write_data('V');
	write_data(' ');
	write_data(' ');
	write_data(' ');
	write_com(0x80+0x49);
	write_data(nums[t_result[0]]);
	write_com(0x81+0x49);
	write_data(nums[t_result[1]]);
	write_com(0x82+0x49);
	write_data('.');
	write_com(0x83+0x49);
	write_data(nums[t_result[2]]);
	write_com(0x84+0x49);
	write_data('C');
}
void main()
{
	unsigned char da_value;
	init();	//初始化LCD
	while(1)
	{
		tmpchange();	//初始化ds18b20
		display();		//更新所有显示
		da_value=read_adc0832(0x00);	//选择通道0进行AD采样
		convdata(da_value,tmp());		//计算光照度和温度
	}
}

```
