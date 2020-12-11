### 快捷键
- 在当前cell上方新建cell：A（按ESC退出编辑状态）  
- 在当前cell下方新建cell：B
- 执行当前cell，并自动跳到下一个cell：Shift Enter  
- 执行当前cell，执行后不自动调转到下一个cell：Ctrl-Enter

### 注意事项
- u表示将后面跟的字符串以unicode格式存储
- plt.rcParams['font.sans-serif']=['SimHei'] #用来正常显示中文标签 
- plt.rcParams['axes.unicode_minus']=False #用来正常显示负号
- anaconda查看安装列表 pip list



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
- [reshape](https://blog.csdn.net/qq_29831163/article/details/90112000)numpy.arange(n).reshape(a, b)    依次生成n个自然数，并且以a行b列的数组形式显示
- [numpy的stack(),hstack() vstack()](https://blog.csdn.net/csdn15698845876/article/details/73380803/?utm_medium=distribute.pc_relevant.none-task-blog-baidulandingword-2&spm=1001.2101.3001.4242)stack函数时，对第一个参数进行堆叠，具体见链接，hstack(水平方向堆叠)和vtack(垂直方向堆叠)函数作用相反

#### 线性代数模块


#### 随机模块（random）

### Python的可视化包 – Matplotlib

#### 2D图表
- plt.gca( )中完成，gca就是get current axes的意思
- [fill_between](https://blog.csdn.net/kabuto_hui/article/details/84979606)

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
- df=pd.DataFrame({u'获救':Survived_1, u'未获救':Survived_0})  
df.plot(kind="bar",stacked=True) ##注意哪个才是x轴，分类依据，stacked堆叠条形图
- [df.loc【】](https://blog.csdn.net/u014712482/article/details/85080864)[]里边为先行后列
- [get_dummies函数](https://blog.csdn.net/binbigdata/article/details/84842179)将指定列因子化以后变成新的多列数据，可以加在原始数据以后或者变成新的DataFrame数据
- concat和[drop](https://blog.csdn.net/lhy2239705435/article/details/90052681)分别为合并和删除函数，axis=0时行，axis=1时列df = pd.concat([data_train, dummies_Cabin, dummies_Embarked, dummies_Sex, dummies_Pclass], axis=1)，df.drop(['Pclass', 'Name', 'Sex', 'Ticket', 'Cabin', 'Embarked'], axis=1, inplace=True)inplace表示是否在原来的数据上改变
- [dataframe.filter函数](https://blog.csdn.net/weixin_44668131/article/details/99437698)主要用来对DataFrame进行筛选
- [数据选取、切片](https://blog.csdn.net/yoonhee/article/details/76168253?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-2.channel_param&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-2.channel_param)
- to_csv("logistic.csv",index=False)，其中要提交的话必须保证结果是np.int32类型
- [groupby以及df常用函数](https://www.cnblogs.com/Yanjy-OnlyOne/p/11217802.html)


### Scikit-learn
- [sklearn常用算法](https://blog.csdn.net/hzp123123/article/details/77744420/)
- [算法小结](https://www.cnblogs.com/rix-yb/p/9787728.html)
- [sklearn preprocessing （预处理）](https://www.cnblogs.com/keye/p/8194539.html) [正则二值化等预处理](https://blog.csdn.net/weixin_40807247/article/details/82793220)标准化方法
- [cross_val_score](https://blog.csdn.net/FontThrone/article/details/79220127?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-2.channel_param&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-2.channel_param)交叉验证的cv参数
- [绘制学习曲线](https://blog.csdn.net/gracejpw/article/details/102370364)
- clf:classifier  rfr:RandomForestRegressor

### [随机森林](https://blog.csdn.net/colourful_sky/article/details/82082854)
- [参数详解](https://blog.csdn.net/u012102306/article/details/52228516)
- [性能评估](https://www.jianshu.com/p/591523125637)
- [启用警告](https://www.coder.work/article/1263350)


### 爬虫
#### [requests库](https://www.cnblogs.com/wkfvawl/p/9496323.html)
- 7个方法

```
1.requests.request():构造一个请求，支撑以下各方法的基础方法
2.requests.get():获取HTML网页的主要方法，主要对应于HTTP的GET
3.requests.post():向HTML网页提交POST请求的方法，对应于HTTP的POST
4.resquests.head():获取HTML网页头信息的方法，对应于HTTP的HEAD
5.requests.put():向HTML网页提交PUT请求的方法，对应于HTTP的PUT
6.requests.patch():向HTML网页提交局部修改请求，对应于HTTP的PATCH
7.requests.delete():向HTML网页提交删除请求，对应于HTTP的DELETE
Response的5个对象属性：
r.status_code	HTTP 请求的返回状态，200 表示连接成功，404 表示失败
r.text	HTTP 响应内容的字符串形式，即，url 对应的页面内容
r.encoding	从 HTTP header 中猜测的响应内容编码方式
r.apparent_encoding	从内容中分析出的响应内容编码方式（备选编码方式）
r.content	HTTP 响应内容的二进制形式（图片的还原）
```

#### [lxml](https://wangxin1248.github.io/python/2018/08/python3-spider-4.html)
- Xpath用来查找HTML节点或者元素，是一门在XML文档中查找信息的语言，在使用Xpath之前需要把HTML文档转为XML文档，使用的是etree包下的HTML方法来实现。