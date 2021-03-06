# 题目链接
[leetcode 343](https://leetcode-cn.com/problems/integer-break/)

# 原文
给定一个正整数 n，将其拆分为至少两个正整数的和，并使这些整数的乘积最大化。 返回你可以获得的最大乘积。  
示例 1:  
输入: 2  
输出: 1  
解释: 2 = 1 + 1, 1 × 1 = 1。  
示例 2:  
输入: 10  
输出: 36  
解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。  
说明: 你可以假设 n 不小于 2 且不大于 58。  

# 思路
- ### **找规律**
  找规律发现，n小于等于4时候为特例，当大于4的时候，其中都需要分出来一个3来使结果更大，所以在考虑完特殊情况以后，只要目标大于4就可以分出来一个3（因为4虽然为特殊情况，但是2*2还是等于4，所以不需要分），最后把分出来的所有3相乘再乘以最后小于等于4的剩余即可。100 100

# 代码
- C++ 找规律
```
class Solution {
public:
    int integerBreak(int n) {
        if(n==2)    return 1;
        if(n==3)    return 2;
        int result = 1;
        while(n>4){
            result*=3;
            n = n-3;
        }
        return result*n;
    }
};
```
