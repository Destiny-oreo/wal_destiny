
### Linux
#### 常用命令
```
sudo apt-get update：更新软件列表，防止下载老版本软件；sudo为了提权，获取最高权限，apt为高级工具包工具，apt-get与获取安装软件包相关；
sudo apt-get upgrade：把本地已安装的软件同软件列表的版本进行对比，如果版本过低则更新；
pwd：显示当前工作目录的完整路径
cd：切换当前工作路径  cd .切换到当前工作目录
ls：显示当前目录下的所有文件信息
touch：创建和修改文件
mkdir：创建目录
cp：复制文件和目录
rm：删除文件和目录
mv：移动或者重命名文件和目录
find：搜索文件和目录
du：计算文件和目录的占用空间

```
#### Linux系统简介
- 芬兰大学生李纳斯自己的unix，成为linux；
- 主分区、扩展分区（1个）、逻辑分区（扩展分区中）；
- 启动电源以后在启动页面按F2进入BIOS页面进行计算机基本信息的修改，将默认的硬盘启动换成光盘启动，
- 鼠标切换，ctrl和alt按键一起；全屏 CTRL ALT ENTER;
- 设置地址`ifconfig eth0 192.168.1.156`

#### 安装双系统记录
- 下载20.04iso镜像，下载rufus（其实不用，win10自带iso读取功能），烧录至U盘中
- 关闭电源快速启动  F2+F7进入传统BIOS 关闭安全系统security boot
- shift+重启 选择其他设备启动 选择可移除U盘启动   进入GRUB 按e 修改代码（解决显卡驱动不一致得问题）  然后进入UBUNTU安装  一切正常  再分区时/ 和/home是必需得两项（后来准备重装时加个/boot省的启动时混淆）
- 安装完成以后重新进入GRUB时按e  再次修改代码（两次代码均见chrome 学习-操作系统-双系统-18.04收藏夹）  重新启动并修改附加驱动即可
- 卸载原因在于每次启动都进入grub页面 且一直无法解决   虽然也可以使用  但速度降低了很多 另外使用EasyBCD  选择windows以后还可以再次进入UBUNTU系统  但是和前面得grub页面就很重复  导致开机时间更加得长  遂卸载
- 存在问题：EasyBCD删除ubuntu选项 且window自动启动取消等待；删除卷 扩展卷；删除grub页面  但是系统启动文件一直没有彻底删除 准备使用最复杂得EasyUEFI方法但是却无法安装 今日暂时放弃  后面有心气捯饬时候再说  mbrfix为了修复mbr使用 好像无效；Rufus_V3.12.1710烧录镜像文件 WIN10不需要；EasyBCD-2.2.exe 建立从WINDOWS进入ubuntu得启动项；uiso9_cn.exe rufus得替代品 也是烧录软件 没有用到 毕竟rufus是官方推荐使用
- WIN7+Ubuntu：使用ultroiso制作U盘启动盘，直接使用WIN10时制作的启动盘没有效果，制作完成压缩盘，由于是双系统，所以为了引导盘需要单独设立一个/boot分区，且需要和WIN引导盘在一起，所以C盘压缩出来250M左右作为引导盘，E盘压缩出来52个G作为Ubuntu磁盘；重启按F12进入BIOS，选择U盘 HDD，开始安装，一切正常，分盘时主分区需要最后一步划分，首先4G的交换分区，不需要挂载，然后20G的/分区，剩余32G的/home分区用于存放文件，最后250M的/boot主分区，用于存放引导程序，最下面选择/boot分区。重启以后进入Windows，打开EasyBCD添加引导项即可。

#### 解决boot空间不足

- 每当系统升级时，旧的内核不会被清理，boot一共就250M不到，内存不足时需要卸载旧的版本[内核](https://blog.csdn.net/qq_49814035/article/details/116035670)

  ```python
  dpkg --get-selections |grep linux-image # 查看已安装的内核版本
  uname -a # 查看系统当前使用的内核版本
  sudo apt purge linux-image-5.8.0-50-generic # 删除旧的内核版本 不能删除新的
  无法卸载时sudo mv /boot/initrd.img-5.8.0-53-generic /home/wal/software/Files/TempBoot
  sudo apt purge linux-image-5.8.0-53-generic linux-image-5.8.0-55-generic
  sudo apt --fix-broken install
  # sudo dpkg -P linux-image-extra-4.4.0-31-generic # 卸载残留信息
  df # 查看内存剩余情况 查看最右一列/boot
  
  #显卡驱动出现问题
  sudo apt install dkms
  ls /usr/src | grep nvidia # 查看当前显卡驱动版本 465.27
  sudo dkms install -m nvidia -v 465.27
  
  #设置默认启动内核
  grub-install --version # 查看当前grub版本 后续使用不同命令 见小标题内核链接
  grep 'menuentry' /boot/grub/grub.cfg # 查看内核版本
  sudo gedit /etc/default/grub
  GRUB_DEFAULT="gnulinux-advanced-ad0d2b4f-68aa-4b9b-ad1b-42289eb944af>gnulinux-5.8.0-59-generic-advanced-ad0d2b4f-68aa-4b9b-ad1b-42289eb944af" # 初始Ubuntu，Linux 4.15.0-33-generic，warning以后再更改
  sudo update-grub # warning以后再次重复编辑grub
  sudo reboot
  
  ```
  
- 禁止[更新内核](https://blog.csdn.net/weixin_40522162/article/details/80302735) [链接](https://blog.csdn.net/davidhzq/article/details/102651588)

  ```python
  # 禁止更新
  sudo apt-mark hold linux-image-5.8.0-59-generic
  [sudo] wal 的密码： 
  linux-image-5.8.0-59-generic 设置为保留。
  # 禁止更新内核，需时间来验证
  sudo apt-mark hold linux-image-x.xx.x-xx-generic
  sudo apt-mark hold linux-image-extra-x.xx.x-xx-generic
  # 如果需要恢复原来的设定的话即允许更新内核，执行如下命令即可：
  sudo apt-mark unhold linux-image-x.xx.x-xx-generic
  sudo apt-mark unhold linux-image-extra-x.xx.x-xx-generic
  另外 根据链接 选择软件与更新中的从不 提醒新版本更新
  
  ```

  

### PS
#### 常用命令
- ALT+滑轮 放大缩小页面；CTRL+滚轮左右移动页面
- CTRL+0将页面以最大效果显示在页面
- 右下区域图层锁住时无法操作，可以解锁以后移动或者裁剪，调整大小时不是使用裁剪工具
- 像素调整：图像-图像大小-像素点->更改整个比例
- 或者：解锁图层防止同时被裁减，调整画布大小，然后CTRL+T进行缩放或者旋转
- 合成照片时，可以解锁图层，移动图层到目标图层，CTRL+T移动，多余部分可以橡皮擦或者椭圆选取并反选，但是无法还原
- 蒙版（可以保持原像素信息：选中图层，右下角添加蒙版，选中画笔，颜色通过左侧工具栏设置前景色等切换，大小通过[]来调整，需要调整细节时可以使用上侧工具栏的流量和不透明度来调整，当消除过度时，切换前景色重新把消失的部分弥补回来即可；
- 校色方法：加载以后习惯性**CTRL+J复制一个图层**，然后把原始图层隐藏（图层里把选中取消即可，错误方法（图像-调整-曲线，上部分拉弯代表亮度，下部分拉弯可调整对比度，色调调整在图像-调整-色彩平衡，可调颜色偏向以及中间调） 正确方法（右下工具栏 创建新的填充或者调整图层 曲线 色彩平衡 对以下所有图层均有效，如果想要对单一图层有效，右击修改 创建剪贴蒙版即可；
- 钢笔：CTRL+鼠标移动 ALT+鼠标变成曲线 油漆桶在渐变工具右击项里面 新建图层在最右下角 **ALT+DELETE快速填充**；
- 小技巧：双击图层选择（如文字 在选择图册给属性旁边的字符），或CTRL+T调出自由变换，ALT+SHIFT同比缩放  蒙版使用时需要注意混合模式 不透明度 流量等参数
- 总结：右下角：蒙版、调整图层、合并组、新图层      左侧：画笔 钢笔 切换前后景 油漆桶 修复工具等  上侧：流量 不透明度 合并模式    

#### 敬伟PS教程
##### A系列
- 左侧工具面板  上侧选项面板：对工具的参数调节面板  下侧工具信息栏：文档尺寸 移动工具 长按左键得到文件信息等  右侧面板      RGB显示屏图片  CMYK印刷用色
- shift+油漆桶 填充工作区；window+shift+s截图；x切换前景色和背景色；双击缩放工具快速回到正常大小；
- 双击PS空白工作区打开文件；点击ALT+图层小眼睛快速观察单独的图层效果；选中图层以后按住ALT可以复制一份；
- 按住**空格键时鼠标变成抓手** 移动图片最常用的方法；T字体 H抓手 V移动工具 G油漆桶；
- 移动图层时，使用SHIFT可以保持图层中物体的绝对位置，可选择自动选择来随意选择移动图层对象 或者**CTRL图层多选**
- M选区  CTRL+D取消选择或者单机外部区域 选取只是为了划定范围 选取可以保存  选择M后 shift可以切换选区叠加 alt可以选取减操作 **ALT+DELETE**快速填充颜色 在填充颜色之前最好先新建图层，这样填充区域可以移动；
- 套索和魔法棒：不规则选取




### 3Dmax
#### 快捷键