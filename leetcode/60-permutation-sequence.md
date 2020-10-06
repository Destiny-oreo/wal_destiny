# 题目链接
[leetcode 60](https://leetcode-cn.com/problems/permutation-sequence/)第k个排列

# 原文
给出集合 [1,2,3,…,n]，其所有元素共有 n! 种排列。  
按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下：  
"123"  
"132"  
"213"  
"231"  
"312"  
"321"  
给定 n 和 k，返回第 k 个排列。  
说明：  
给定 n 的范围是 [1, 9]。  
给定 k 的范围是[1,  n!]。  
示例 1:  
输入: n = 3, k = 3  
输出: "213"  
示例 2:  
输入: n = 4, k = 9  
输出: "2314"  

# 思路
- ### **全排列-ceil**
  找到规律，每一位上的数字都和K和阶乘结果有关，所以最后根据规律来列方程，由于需要算出处于第几个流程中，所以需要用到ceil()函数，且其中变量需要不为int。100 6

# 代码
- C++ 全排列-ceil
```
class Solution {
public:
    string getPermutation(int n, int k) {
        const vector<int> factor={1,1,2,6,24,120,720,5040,40320,362880};     
        string result = "";
        vector<char> rec={'1','2','3','4','5','6','7','8','9'};
        for(int i=n;i>=1;i--){
            int temp = ceil((float)k/factor[i-1]);
            temp = temp==0?1:temp;
            result += rec[temp-1];
            rec.erase(rec.begin()+temp-1);
            k = k-factor[i-1]*(temp-1);
        }
        return result;
    }
};
```