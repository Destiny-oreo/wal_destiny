# [栈](https://blog.csdn.net/u011630575/article/details/79735350)
- **[定义](https://blog.csdn.net/u011630575/article/details/79735350)**：栈实现了一个先进后出（FILO）的数据结构，c++ stl栈的头文件为:     `#include <stack>`      
栈（stack）是限制插入和删除只能在一个位置上进行的线性表，该位置在表的末端，叫做栈顶。添加元素只能在尾节点后添加，删除元素只能删除尾节点，查看节点也只能查看尾节点。添加、删除、查看依次为入栈（push）、出栈（pop）、栈顶节点（top）。形象的说，栈是一个先进后出（FILO）表，先进去的节点要等到后边进去的节点出来才能出来。   
**成员函数**介绍：  
empty() 堆栈为空则返回真  
pop() 移除栈顶元素 （删除）  
push() 在栈顶增加元素 （增加）  
size() 返回栈中元素数目  
top() 返回栈顶元素，不删除（获取）   
  
- **结构**：栈有两种是实现结构，一种是**顺序存储**结构，也就是利用[数组](https://blog.csdn.net/zichen_ziqi/article/details/80807989)实现，一种是**链式存储**结构，可以用单链表实现。数组实现栈很简单，用一个下标标记top来表示栈顶，top==-1时，栈空，top==0时，表示栈里只有一个元素，通过访问top为下标的数组元素即可。出栈top自减，入栈top自加就OK了;单链表实现栈要比单链表的实现简单点。我们通过在表的尾端插入来实现push，通过删除尾节点来实现pop，获取尾节点的元素来表示top。[自定义栈](https://blog.csdn.net/qq_20366761/article/details/70053813)

# 经典题目

[leetcode 20 判断符号字符串是否有效](E:/English/GitHub_test/wal_destiny/leetcode/20-Valid-Parentheses.md)  


### set
vector封装数组，list封装了链表，map和set封装了二叉树,set元素唯一，即使重复插入也不会多次计数，lower_bound显示小于等于 upper大于，find显示下标，默认升序排列   
[自定义比较函数](https://www.cnblogs.com/xjyxp/p/11447091.html)不适用friend只能有一个参数，使用friend以后才可以传入两个参数进行[重载](https://www.cnblogs.com/lengbingshy/p/3491192.html)
include < set>；  
set<int/char/string/基本数据类型/自定义类型/结构体类型/.....>iset   
```	set<infos> s;
	for (int i = 0; i < dn.size(); i++) {
		infos temp;
		temp.po = dn[i];
		temp.dis = distance(dn[i], center);
		s.insert(temp);
	}
	set<infos>::iterator it = s.begin();
	for (; it != s.end(); it ++ ) {
		printf("%d %d \n", (*it).po.x, (*it).po.y);
	} 
```

### [pair](https://www.cnblogs.com/Sunrises/p/10363394.html)
#include < utility> #include< algorithm>(sort)  
```
pair<int,int>Item[n];    //定义pair对象数组Item[n]
sort(Item, Item+n); 　　//默认对Item的first的值进行排序 默认是按元素从小到大排序
bool cmp（pair<int, int>a, pair<int, int>b）
{
    return a.first<b.first;            //根据fisrt的值升序排序
} 
sort(Item, Item+n, cmp);       // 按照自定义的顺序进行排序
```
直接使用vector也可以[排序](https://www.cnblogs.com/zhouxiaosong/p/5557990.html)  
`sort(a.begin(), a.end());`




