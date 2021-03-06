## 2020研赛
#### 题目
B 降低汽油精制过程中的辛烷值损失模型

### 问题一：数据处理
- 观察附件中的285和313号样本，首先通过题目中要求的处理规则发现3sigma原则进行预处理，然后统计0的个数，发现285号有11列全为0，统计后也为0，和最后附件1的原始数据一致，不需要更改，而313号样本中异常值较多，发现8列全0，两列16个0，两列2个0，一列6个0，处理方法是全部赋值为剩余数的平均值，然后最后对所有时间点的数据取平均值放入到附件1中，其中285全部一致，313有43处不一致。
- 通过对附件1进行最大最小分析以及附件4中的变量范围进行分析，去除20个样本，以及一共23列数据，形成最后的最终版附件1.

### 问题二：寻找建模主要变量
- 通过python的随机森林寻找主要变量，即输入305*345左右的数据集，通过随机森林算法输出的importance变量，输出前30个贡献率最高的变量，然后选择其中0.007左右以上的20多个变量
- 通过对输出的主要变量的相关性分析，去除相关性较高的几个变量作为最终的有独立性的主要变量

### 问题三：建立辛烷值RON损失预测模型
- 由于RON损失值比较小，且变化幅度小，所以选择产品的RON作为因变量进行建模
- 使用支持向量回归机对主要变以及目标量进行回归训练，使用的是F:\software\MATLAB12\Awork\国赛\20研赛的SVR和newSVR代码进行训练，只要更改训练样本和测试样本即可进行运行，最后使用折线图、分布图等形式来展现最后的效果
- 对比使用PLS偏最小二乘法来进行非线性回归，得到BETA2的n个主要变量+1个常数变量的系数。可以对新的样本进行回归预测（训练时需要将样本进行打乱，否则没法考虑不同类别的样本）

### 问题四：主要变量操作方案的优化
- 使用PSO求得主要变量的最优取值，其中求得产品辛烷值的方法是加载了提前训练好的SVR模型以及S模型和两个模型对应的输入输出归一化数据结构，为了求得所有样本的最优取值，使用循环进行粒子群算法，返回值保存在第一个参数里，最后进行保存。





### GoldWave降噪
- 导入音频文件，滚轮方法选择水平线即噪音部分，复制即提取样本，然后全选-效果-过滤-降噪，保存即可
