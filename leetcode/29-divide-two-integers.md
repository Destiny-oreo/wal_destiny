# 题目链接
[leetcode 29](https://leetcode-cn.com/problems/divide-two-integers/)两数相除

# 原文
给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。  
返回被除数 dividend 除以除数 divisor 得到的商。  
整数除法的结果应当截去（truncate）其小数部分，例如：truncate(8.345) = 8 以及 truncate(-2.7335) = -2  
示例 1:  
输入: dividend = 10, divisor = 3  
输出: 3  
解释: 10/3 = truncate(3.33333..) = truncate(3) = 3  
示例 2:  
输入: dividend = 7, divisor = -3  
输出: -2  
解释: 7/-3 = truncate(-2.33333..) = -2  
提示：  
被除数和除数均为 32 位有符号整数。  
除数不为 0。  
假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−231,  231 − 1]。本题中，如果除法结果溢出，则返回 231 − 1。  

# 思路
- ### **二分-数学**
  无法使用除法等法则，只能一直将除数累加来判断是否到达被除数，由于每次除数累加自己，相当于乘2，所以使用二分思想；首先判断特殊条件，即除数为0的情况，还有为正负1时直接返回；为了累加，首先需要排除负数，所以把符号提取然后进行带入（由于INT_MIN提取符号后超过INT_MAX，所以带入函数使用long变量），所以结果也是用long等，每次只要相加不超过被除数，将result累加（即乘2），然后除数累加乘2，当超过的话，说明剩下的数不够结果乘2，递归剩下的数作为被除数，除数照旧；最后的最后判断结果乘以符号以后的界限即可。100 84

# 代码
- C++ 二分-数学
```
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor==0)  return 0;
        if(divisor==1)  return dividend;
        if(divisor==-1) return dividend==INT_MIN?INT_MAX:-dividend;
        int a = dividend, b =divisor;
        int sign = 1;
        if((a>0&&b<0)||(a<0&&b>0))  sign = -1;
        long result = div(abs(a),abs(b))*sign;
        if(result>INT_MAX)  result = INT_MAX;
        if(result<INT_MIN)  result = INT_MIN;
        return result;
    }
private:
    long div(long a,long b){
        if(a<b) return 0;
        long result = 1,temp = b;
        while(temp+temp<a){
            result = result+result;
            temp = temp+temp;
        }
        return result+div(a-temp,b);
    }
};
```
