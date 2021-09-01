# 题目链接
[leetcode 50](https://leetcode-cn.com/problems/powx-n/)  pow(x,n)

# 原文
实现 pow(x, n) ，即计算 x 的 n 次幂函数。  
示例 1:  
输入: 2.00000, 10  
输出: 1024.00000  
示例 2:  
输入: 2.10000, 3  
输出: 9.26100  
示例 3:  
输入: 2.00000, -2  
输出: 0.25000  
解释: 2-2 = 1/22 = 1/4 = 0.25  
说明:  
-100.0 < x < 100.0  
n 是 32 位有符号整数，其数值范围是 [−231, 231 − 1] 。  

# 思路
- ### **二分查找**
  使用二分查找的思想，相当于把n一直除以2，所以即使n是32位有符号数，也最多计算30多次；首先处理特殊情况，当x是正负1的时候，不需要计算太多；然后考虑当n是负数的情况，考虑到上下限需要判断INT_MIN，然后把x处理一下；最后开始二分查找，只要(long)times*2小于等于n，说明可以继续二分，则x = x*x；最后大于时返回result*myPow(x,n-times)。100 98

# 代码
- C++ 二分查找
```
class Solution {
public:
    double myPow(double x, int n) {
        if(x==1)    return 1;
        else if(x==-1)  return n%2==0?1:-1;
        if(n<0){
            x = 1/x;
            if(n==INT_MIN){
                x = x*x;
                n = -(n/2);
            }
            else    n = -n;
        }
        if(n==0)    return 1;
        else if(n==1)   return x;
        int times = 1;
        double result = x;
        while((long)times*2<=n){
            result = result*result;
            times = times*2;
        }
        return result*myPow(x,n-times);
    }
};
```
