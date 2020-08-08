### 快捷键
- 在当前cell上方新建cell：A（按ESC退出编辑状态）  
- 在当前cell下方新建cell：B
- 执行当前cell，并自动跳到下一个cell：Shift Enter  
- 执行当前cell，执行后不自动调转到下一个cell：Ctrl-Enter

### 注意事项
- u表示将后面跟的字符串以unicode格式存储
- plt.rcParams['font.sans-serif']=['SimHei'] #用来正常显示中文标签 
- plt.rcParams['axes.unicode_minus']=False #用来正常显示负号
- 


## [常用函数](https://www.cnblogs.com/tdalcn/p/7818895.html) 
### numpy
#### 基本类型
- 浅拷贝： c=a.view()   深拷贝：c=a.copy()  
- shape、size（为一共的大小）后不用加小括号
- 生成序列：a=np.arange(0,40,10) 以10为间隔
- m=np.linspace(0, 6, 5)# 等差数列，0到6之间5个取值，([ 0., 1.5, 3., 4.5, 6.])
- 将a当做一个块复制成3*5个a：b=np.tile(a,(3,5))
- y=argmax f(t) ：y是f(t)函数取到最大值时的参数t
- np.save('p.npy', p)     # 保存到文件，q = np.load('p.npy')    # 从文件读取
- 

#### 线性代数模块


#### 随机模块（random）

### Python的可视化包 – Matplotlib

#### 2D图表


#### 3D图表

### [Pandas](https://blog.csdn.net/aasdad1/article/details/91812714)    
from pandas import Series,DataFrame
#### 数据结构
- Series：一维数组，与Numpy中的一维array类似。二者与Python基本的数据结构List也很相近，其区别是：List中的元素可以是不同的数据类型，而Array和Series中则只允许存储相同的数据类型，这样可以更有效的使用内存，提高运算效率。
- Time- Series：以时间为索引的Series。

- DataFrame：二维的表格型数据结构。很多功能与R中的data.frame类似。可以将DataFrame理解为Series的容器。以下的内容主要以DataFrame为主。

- Panel ：三维的数组，可以理解为DataFrame的容器。

#### series
- Series 就如同列表一样，一系列数据，每个数据对应一个索引值。
- In [5]: s.index Out[5]: RangeIndex(start=0, stop=4, step=1)  
In [8]: s.values  Out[8]: array([1, 4, 'ww', 'tt'], dtype=object)
- 列表的索引只能是从 0 开始的整数，Series 数据类型在默认情况下，其索引也是如此。不过，区别于列表的是，Series 可以自定义索引：s2 = Series(['wangxing','man',24],index=['name','sex','age'])
- value_counts()是一种查看表格某列中有多少个不同值的快捷方法，并计算每个不同值有在该列中有多少重复值。value_counts()是Series拥有的方法，一般在DataFrame中使用时，需要指定对哪一列或行使用
- [kde](https://blog.csdn.net/helloworld0906/article/details/103214392):密度图


#### DataFrame


### Scikit-learn


#### 



