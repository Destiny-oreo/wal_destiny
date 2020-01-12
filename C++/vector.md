# [向量](https://blog.csdn.net/hancunai0017/article/details/7032383)
- **定义**：vector(向量): C++中的一种数据结构,确切的说是一个类.它相当于一个动态的数组,当程序员无法知道自己需要的数组的规模多大时,用其来解决问题可以达到最大节约空间的目的.  

声明：  
```
#include<vector>
using namespace std;
```
成员函数：
```
1.push_back   在数组的最后添加一个数据
2.pop_back    去掉数组的最后一个数据 
3.at                得到编号位置的数据
4.begin           得到数组头的指针
5.end             得到数组的最后一个单元+1的指针
6．front        得到数组头的引用
7.back            得到数组的最后一个单元的引用
8.max_size     得到vector最大可以是多大
9.capacity       当前vector分配的大小
10.size           当前使用数据的大小
11.resize         改变当前使用数据的大小，如果它比当前使用的大，者填充默认值
12.reserve      改变当前vecotr所分配空间的大小
13.erase         删除指针指向的数据项
14.clear          清空当前的vector
15.rbegin        将vector反转后的开始指针返回(其实就是原来的end-1)
16.rend          将vector反转构的结束指针返回(其实就是原来的begin-1)
17.empty        判断vector是否为空
18.swap         与另一个vector交换数据
```

# 经典题目
[leetcode 56 合并所有重叠的区间](E:/English/GitHub_test/wal_destiny/leetcode/56-merge-intervals.md)  


# [常见用法](https://blog.csdn.net/weixin_41743247/article/details/90635931)
- ## 初始化
```
方式1.
//定义具有10个整型元素的向量（尖括号为元素类型名，它可以是任何合法的数据类型），
不具有初值，其值不确定
vector<int>a(10);  
方式2.
//定义具有10个整型元素的向量，且给出的每个元素初值为1
vector<int>a(10,1)
方式3.
//用向量b给向量a赋值，a的值完全等价于b的值
vector<int>a(b);
方式4.
//将向量b中从0-2（共三个）的元素赋值给a，a的类型为int型
vector<int>a(b.begin(),b.begin+3)
方式5.
 //从数组中获得初值
int b[7]={1,2,3,4,5,6,7};
vector<int> a(b,b+7）;
```

- ## vector对象的常用内置函数使用（举例说明）
```
#include<vector>
vector<int> a,b;
//b为向量，将b的0-2个元素赋值给向量a
a.assign(b.begin(),b.begin()+3);
//a含有4个值为2的元素
a.assign(4,2);
//返回a的最后一个元素
a.back();
//返回a的第一个元素
a.front();
//返回a的第i元素,当且仅当a存在
a[i];
//清空a中的元素
a.clear();
//判断a是否为空，空则返回true，非空则返回false
a.empty();
//删除a向量的最后一个元素
a.pop_back();
//删除a中第一个（从第0个算起）到第二个元素，也就是说删除的元素从a.begin()+1算起  
（包括它）一直到a.begin()+3（不包括它）结束
a.erase(a.begin()+1,a.begin()+3);
//在a的最后一个向量后插入一个元素，其值为5
a.push_back(5);
//在a的第一个元素（从第0个算起）位置插入数值5,
a.insert(a.begin()+1,5);
//在a的第一个元素（从第0个算起）位置插入3个数，其值都为5
a.insert(a.begin()+1,3,5);
//b为数组，在a的第一个元素（从第0个元素算起）的位置插入b的第三个元素到第5个元素（不包括b+6）
a.insert(a.begin()+1,b+3,b+6);
//返回a中元素的个数
a.size();
//返回a在内存中总共可以容纳的元素个数
a.capacity();
//将a的现有元素个数调整至10个，多则删，少则补，其值随机
a.resize(10);
//将a的现有元素个数调整至10个，多则删，少则补，其值为2
a.resize(10,2);
//将a的容量扩充至100，
a.reserve(100);
//b为向量，将a中的元素和b中的元素整体交换
a.swap(b);
//b为向量，向量的比较操作还有 != >= > <= <
a==b;
```
- ## 几个常用的算法
```
 #include<algorithm>
 //对a中的从a.begin()（包括它）到a.end()（不包括它）的元素进行从小到大排列
 sort(a.begin(),a.end());
 //对a中的从a.begin()（包括它）到a.end()（不包括它）的元素倒置，  
但不排列，如a中元素为1,3,2,4,倒置后为4,2,3,1
 reverse(a.begin(),a.end());
  //把a中的从a.begin()（包括它）到a.end()（不包括它）的元素  
复制到b中，从b.begin()+1的位置（包括它）开始复制，覆盖掉原有元素
 copy(a.begin(),a.end(),b.begin()+1);
 //在a中的从a.begin()（包括它）到a.end()（不包括它）的元素中  
查找10，若存在返回其在向量中的位置
  find(a.begin(),a.end(),10);
```