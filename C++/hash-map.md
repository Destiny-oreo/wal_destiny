# 使用map
```
#incldude <map>		//注意没有扩展名.h
using namespace std;	//否则后面都要使用std::map
```
定义：`map<int,string> hash_map`  
特点：map中的元素是自动按照key升序排序，不能再使用sort函数  
[特定结构体重载排序时](https://www.cnblogs.com/ZY-Dream/p/10037931.html)
# 经典题目
[leetcode 1 该数组中找出和为目标值的那两个整数的下标](E:/English/GitHub_test/wal_destiny/leetcode/1-Two-Sum.md)  
[leetcode 3 找出其中不含有重复字符的 最长子串 的长度](E:\English\GitHub_test\wal_destiny\leetcode\3-Longest-Substring-Without-Repeating-Characters.md)  
[leetcode 17 返回给定数字能表示的字母组合](E:/English/GitHub_test/wal_destiny/leetcode/17-letter-combinations-of-a-phone-number.md)  
[leetcode 49 将字母异位词组合在一起](E:/English/GitHub_test/wal_destiny/leetcode/49-group-anagrams.md)  

[leetcode 1 该数组中找出和为目标值的那两个整数的下标](E:/English/GitHub_test/wal_destiny/leetcode/1-Two-Sum.md)  

[leetcode 560 找到该数组中和为 k 的连续的子数组的个数](E:/English/GitHub_test/wal_destiny/leetcode/560-Subarray-Sum-Equals-K.md)
# 基本函数
```
begin() 返回指向map头部的迭代器
clear() 删除所有元素
count() 返回指定元素出现的次数
empty() 如果map为空则返回true
end()   返回指向map末尾的迭代器

equal_range()    返回特殊条目的迭代器对

erase() 删除一个元素
find()  查找一个元素
insert()插入元素
max_size()返回可以容纳的最大元素个数
size()  返回map中元素的个数
swap()  交换两个map

get_allocator()  返回map的配置器
key_comp()       返回比较元素key的函数
lower_bound()    返回键值>=给定元素的第一个位置
max_size()       返回可以容纳的最大元素个数
rbegin()         返回一个指向map尾部的逆向迭代器
rend()           返回一个指向map头部的逆向迭代器
upper_bound()     返回键值>给定元素的第一个位置
value_comp()      返回比较元素value的函数
```
# 常见用法
1. ### 插入元素

以下三种插入方法，第一种和第二种完全一样，但当map有相关的关键字后，无法insert，但是第三种插入方法是覆盖的方式，一定插入成功
```
map<int,string> hash;
map.insert(pair<int,string>(000,"student_zero"));

map.insert(map<int,string>::val(001,"student_one"));

map[002] = "student_two";
```
2. ### 查找元素

当查找到关键key时返回数据所在对象的位置，如果没有返回的iter与end的值相同
```
map<int,string>::iterator iter;
iter = hash.find(000);
if(iter != hash.end())	
	cout<<"find it,the value is"<<iter->second<<endl;
else	
	cout<<"not found"<<endl;
```

3. ### 删除与清空元素
```
iter = hash.find(001);
hash.erase(iter);
int n = hash.erase(001);	//如果删除了返回1，否则返回0

hash.erase(hash.begin(),hash.end());
hash.clear();	//两句都是清空元素
```
4. ### map的大小
```
int size = hash.size();
```
5. ### map的遍历
三种方式 正向迭代器 反向迭代器 数组下标
```
map<int,string>::iterator iter;
for(iter = hash.begin();iter!=hash.end();iter++)
	//do something

map<int,string>::reverse_iterator iter2;
for(iter2 = hash.rbegin();iter2!=hash.rend();iter++)
	//also do something

//用数组形式必须map的关键字是顺序的int型等
```



