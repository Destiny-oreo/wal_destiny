# 题目链接
[leetcode 406](https://leetcode-cn.com/problems/queue-reconstruction-by-height/)

# 原文
假设有打乱顺序的一群人站成一个队列。 每个人由一个整数对(h, k)表示，其中h是这个人的身高，k是排在这个人前面且身高大于或等于h的人数。 编写一个算法来重建这个队列。  
注意：  
总人数少于1100人。  
示例  
输入:  
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]  
输出:  
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]  

# 思路
- ### **贪心算法-排序-插入**
  本题使用的方法比较关键，思想是贪心思想，即先把可以排序的people给排好，剩下的也都尽可能符合要求排，最后整体就符合要求了；思想：每排一个people项时，需要使用到第二个参数，即前面有几个大于等于自己的，小于的完全不算位置，所以优先排大的，然后排小的时候可以找打相对位置；排序使用sort，由于排的是向量，所以需要自己写**cmp函数**，第一位参数大的优先，相同时第二位小的优先（序号），然后开始放入result中，使用**insert函数**来决定放入的位置。62 92

# 代码
- C++ 贪心算法-排序-插入
```
class Solution {
public:
    static bool cmp(vector<int>& a,vector<int>& b){return a[0]>b[0]||(a[0]==b[0]&&a[1]<b[1]);}
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> result;
        sort(people.begin(),people.end(),cmp);
        for(auto& item:people){
            result.insert(result.begin()+item[1],item);
        }
        return result;
    }
};
```
