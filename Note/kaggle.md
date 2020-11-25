## Titanic

#### 预处理
- 初探数据：加载完必要的包以后，读入数据发现数据是DataFrame格式，和Excel格式差不多，使用info函数和describe函数来初探数据，发现有一些属性缺失了很多数据（比如年龄和Cabin），以及需要从12列属性中尽快找到和最后是否存活相关性最高的属性，用作最后对测试样本的预测；
- 数据初步分析：使用matplotlib.pyplot来画图，对于DataFrame格式可以直接获取其中某一个属性的所有数据，然后使用value_counts().plot函数来绘制图像，其中plot中的参数使用bar是绘制条形图，绘制散点图需要在scatter函数中传入x和y坐标数据，绘制kde图是只需要挑选出需要的属性中的数据并不需要使用value_counts函数，堆叠型条形图首先统计堆叠的两个属性的value_counts，然后使用DataFrame放在一起组成一个新的变量，最后直接plot即可，分析数据中的相关关系；
- 利用表格查看属性之间的关系可以使用groupby函数，参数中放入需要合并考虑的两个或者多个属性，然后将count中的某一个统计个数属性变成DataFrame格式进行打印；
- 对于缺省数据：
```
如果缺值的样本占总数比例极高，可能就直接舍弃了，作为特征加入的话，可能反倒带入noise，影响最后的结果
如果缺值的样本适中，而该属性非连续值特征属性(比如说类目属性)，那就把NaN作为一个新类别加到类别特征中
如果缺值的样本适中，而该属性为连续值特征属性，有时候我们会考虑给定一个step(比如这里的age，
我们可以考虑每隔2/3岁为一个步长)，然后把它离散化，之后把NaN作为一个type加到属性类目中。
有些情况下，缺失的值个数并不是特别多，那我们也可以试着根据已有的值，拟合一下数据，补充上。
```

#### 随机森林
- 引入随机森林的算法包 from sklearn.ensemble import RandomForestRegressor 同时为了防止报错需要把取消报错的2-4行代码加上；
- 为了根据已知对目标缺省属性影响最高的几个属性来回归预测目标缺省数据（一般将数值型特征全部提取出来），首先需要把相关参数以及缺省属性提取出来，直接在中括号中放入属性的名称即可；然后将有缺省数据的属性中缺省部分和完整部分分开来，作为训练集和预测集，将预测集的x和y输入RandomForestRegressor预设好的模型中，然后根据预测集的x预测预测集的y，并替换掉原始数据中所有缺省数据，使用df.loc[]来替换；
- 对于需要将缺省数据全部变成NO类型的属性，直接使用loc定位到所有notnull和isnull的行和列中，然后整体替换即可；

#### 逻辑回归建模
- 在进行回归预测之前，需要将所有输入特征进行因子化，即首先对非数值型特征进行转换，变成某一属性的1和0，而不是YES和NO，转换方法为使用get_dummies函数，然后将因子化以后的数据和原始数值型数据利用concat函数放在一起，然后使用drop函数将不需要的属性全部舍去，其中舍去时需要加入axis和inplace参数，axis=1时代表列方向；
- 处理完非数值型特征以后需要处理原始数值型特征，此类特征主要使用的处理方法是归一化，即将所有的数据放缩到-1到1之间，避免数值幅度的差距过大影响最后的收敛速度；放缩方法使用sklearn中的preprocessing方法，使用preprocessing的StandardScaler模型，其中输入参数时需要首先将DataFrame使用values转为矩阵，然后将大小reshape为(-1,1)，即确保为1列数据；
- 开始逻辑回归建模，首先导入线性回归模型的包from sklearn import linear_model，然后将需要输入的x特征使用filter函数进行筛选，然后使用.values转换成矩阵格式以便于输入训练，然后取出x和y，初始化模型linear_model.LogisticRegression，然后fit（x,y)，即可得到训练好的模型；
- 最后将测试文件进行同样的预处理等操作放入训练好的模型中即可预测到最后的结果；首先查看缺省数据，将Fare中缺省的设为0，然后根据年龄的缺省值补上，方法是使用前面训练好的rfr模型，输入同样数量的属性特征，得到缺省的年龄并使用loc替换掉缺省值，同样处理缺省Cabin值，然后因子化并归一化，最后即可放入clf中进行训练。

## Dogs _vs _cats
#### os [文件目录方法](https://www.runoob.com/python/os-file-methods.html)
- 表示文件夹路径时使用双斜杠\\或者在路径字符串前面加r，代表后面是原始字符串，里面所有特殊符号均本色出演，不进行转义
- [os.getcwd()](http://blog.chinaunix.net/uid-27838438-id-4087978.html) 获取当前路径、os.name 获取当前操作系统、os.remove() 删除指定文件、os.removedirs() 删除指定目录、os.mkdir() 创建新目录、os.chdir() 改变当前路径到指定路径、os.listdir() 返回指定路径下所有目录和文件、os.path.exists()判断括号里的文件是否存在于当前目录、[os.path](https://www.runoob.com/python/python-os-path.html) 模块主要用于获取文件的属性。
- [shutil模块](https://zhuanlan.zhihu.com/p/91829333)主要针对文件的拷贝、删除、移动、压缩和解压操作 copytree拷贝文件夹、rmtree删除文件夹
- os.symlink() 方法用于创建一个软链接，os.symlink(src, dst)符号链接的目的是：在不改变原目录/文件的前提下，起一个方便的别名。


#### python函数
- [filter() 函数](https://www.runoob.com/python/python-func-filter.html)过滤序列，接受两个参数，第一个为函数，第二个为序列，序列的每个元素作为参数传递给函数进行判断，返回True和False
- print(new_list)中的new_list是在以列表形式的情况下可以输出，在无法输出时可以尝试print(list(xx))
- lambda作为一个表达式，定义了一个匿名函数，在x:x+1例的代码中x为入口参数，x+1为函数体
- a=tf.cast(x, dtype, name=None) 待转换的数据（张量）目标数据类型tf.string等
- [tf.train.slice_input_producer](https://blog.csdn.net/dcrmg/article/details/79776876)tensor生成器 生成相同大小的队列
- tf.train.batch tensor队列生成器，作用是按照给定的tensor顺序，把batch_size个tensor推送到文件队列，作为训练一个batch的数据，等待tensor出队执行计算


#### [keras](https://blog.csdn.net/weixin_41065383/article/details/89350475?utm_medium=distribute.pc_relevant.none-task-blog-title-6&spm=1001.2101.3001.4242)
- 由纯python编写的基于theano/tensorflow的深度学习框架，支持CNN和RNN或二者的结合、无缝CPU和GPU切换
- Sequential 序贯模型，单输入单输出，编译速度快 tensorflow1.14.0+keras 2.2.5+python 3.6+CUDA10.1+Cudnn7.4
```
from keras.models import Sequential  
from keras.layers.core import Dense, Dropout, Activation  
from keras.optimizers import SGD  
1.选择模型 model = Sequential()
2.构建网络层
model.add(Dense(500,input_shape=(784,))) # Dense为全连接层 500表示输出未付，784表示输入维度
model.add(Activation('tanh')) # 激活层Activation，激活函数是tanh
model.add(Dropout(0.5)) # 采用50%的dropout，在训练过程中每次更新参数时随机断开一定百分比（rate）的输入神经元，防止过拟合

odel.add(Dense(500)) # 隐藏层节点500个  
model.add(Activation('tanh'))  
model.add(Dropout(0.5))

model.add(Dense(10)) # 输出结果是10个类别，十个输出节点，所以维度是10  
model.add(Activation('softmax')) # 最后一层用softmax作为激活函数
3.编译
sgd = SGD(lr=0.01, decay=1e-6, momentum=0.9, nesterov=True) # 优化函数，设定学习率（lr）等参数  
model.compile(loss='categorical_crossentropy', optimizer=sgd, class_mode='categorical') # 使用交叉熵作为loss函数
4.训练
.fit的一些参数
   batch_size：对总的样本数进行分组，每组包含的样本数量
   epochs ：训练次数
   shuffle：是否把数据随机打乱之后再进行训练
   validation_split：拿出百分之多少用来做交叉验证
   verbose：屏显模式 0：不输出  1：输出进度  2：输出每次的训练结果
(X_train, y_train), (X_test, y_test) = mnist.load_data() # 使用Keras自带的mnist工具读取数据（第一次需要联网）
# 由于mist的输入数据维度是(num, 28, 28)，这里需要把后面的维度直接拼起来变成784维  
X_train = X_train.reshape(X_train.shape[0], X_train.shape[1] * X_train.shape[2]) 
X_test = X_test.reshape(X_test.shape[0], X_test.shape[1] * X_test.shape[2])  
Y_train = (numpy.arange(10) == y_train[:, None]).astype(int) 
Y_test = (numpy.arange(10) == y_test[:, None]).astype(int)
# label的one_hot
model.fit(X_train,Y_train,batch_size=200,epochs=50,shuffle=True,verbose=0,validation_split=0.3)
model.evaluate(X_test, Y_test, batch_size=200, verbose=0)
5.输出
print("test set")
scores = model.evaluate(X_test,Y_test,batch_size=200,verbose=0)
print("")
print("The test loss is %f" % scores)
result = model.predict(X_test,batch_size=200,verbose=0)

result_max = numpy.argmax(result, axis = 1)
test_max = numpy.argmax(Y_test, axis = 1)

result_bool = numpy.equal(result_max, test_max)
true_num = numpy.sum(result_bool)
print("")
print("The accuracy of the model is %f" % (true_num/len(result_bool)))
```























