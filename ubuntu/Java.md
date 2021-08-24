### 安装

- jdk1.8和jdk1.11为用的比较多的两个LTS版本，推荐使用1.8作为默认的开发环境，Ubuntu20.04的源仓库已经包含了两个OpenJDK软件包JDK和JRE，JRE主要包含了JVM即JAVA虚拟机，允许运行Java程序的二进制包，JDK主要包含了JRE和用于构建jJava应用的开发和调试工具以及库文件。

  ```python
  sudo apt update
  sudo apt install openjdk-11-jdk  # "11.0.11"  1.8.0_292
  # 由于var在终端中的不稳定 改用11
  java -version
  sudo update-alternatives --config java # 修改默认版本
  # 设置JAVA_HOME环境变量
  sudo gedit /etc/environment
  JAVA_HOME="/usr/lib/jvm/java-8-openjdk-amd64"
  export JAVA_HOME="/usr/lib/jvm/java-8-openjdk-amd64"
  export PATH=$PATH:$JAVA_HOME/bin
  export CLASSPATH=.:$JAVA_HOME/lib/dt.jar:$JAVA_HOME/lib/tools.jar
  source /etc/environment
  echo $JAVA_HOME
  #卸载
  sudo apt remove openjdk-11-jdk
  # Eclipse
  tar -C .../Eclipse -zxvf ...gz
  /usr/share/applications$ sudo touch Eclipse.desktop
  sudo gedit Eclipse.desktop
  
  [Desktop Entry]
  Encoding=UTF-8
  Name=Eclipse
  Comment=Eclipse IDE
  Exec=/home/wal/software/apps/java/eclipse/eclipse/eclipse
  Icon=/home/wal/software/apps/java/eclipse/eclipse/icon.xpm
  Terminal=false
  StartupNotify=true
  Type=Application
  Categories=Application;Development;
  NoDisplay=false
  
  sudo chmod u+x Eclipse.desktop #完成 从软件列表打开并保存到收藏夹即可正常使用
  ```

- 


### windows安装
- jdk 11.0.11 idea 2021.1.2 U 