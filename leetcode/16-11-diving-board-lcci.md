# 题目链接
[leetcode 16.11](https://leetcode-cn.com/problems/diving-board-lcci/)

# 原文
你正在使用一堆木板建造跳水板。有两种类型的木板，其中长度较短的木板长度为shorter，长度较长的木板长度为longer。你必须正好使用k块木板。编写一个方法，生成跳水板所有可能的长度。

返回的长度需要从小到大排列。

示例：

输入：
shorter = 1  
longer = 2  
k = 3  
输出： {3,4,5,6}  
提示：  
0 < shorter <= longer
0 <= k <= 100000

# 思路
- ### **记忆法-循环**
  基本题目，首先找到特殊情况专门处理，再解决一般情况；一般情况的处理是：首先最小的组合是k个较小的数相加，然后依次把较小的数换成大的数，换的次数即是k的大小；对于这种一般处理方法，特殊情况是当两个数相等时，会放入k个相同的数，所以相同时放入一个即返回，同时当k小于1时，还是会默认放入一个0，不符合题意，检测到小于1直接返回空向量。76 100

# 代码
- C++ 记忆法-循环
```
class Solution {
public:
    vector<int> divingBoard(int shorter, int longer, int k) {
        vector<int> result;
        if(k<=0)    return result;
        else if(shorter==longer){
            result.push_back(longer*k);
            return result;
        }
        else{
            result.push_back(shorter*k);
            for(int i=1;i<=k;i++){
                result.push_back(shorter*k-i*shorter+i*longer);
            }
            return result;
        }
    }
};
```
