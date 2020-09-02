# 题目链接
[leetcode 7](https://leetcode-cn.com/problems/reverse-integer/)

# 原文
给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。  
示例 1:  
输入: 123  
输出: 321  
 示例 2:  
输入: -123  
输出: -321  
示例 3:  
输入: 120  
输出: 21  
注意:  
假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−2^31,  2^31 − 1]。请根据这个假设，如果反转后整数溢出那么就返回 0。

# 思路
- ### **数字上下**--->较优
  反转数字使用模板即可，只要原数不为0，即没有反转结束，新数先乘10再加上取余的数，然后原数除以10；此题的难点在于边界范围，对于−2^31,  2^31 − 1的边界，会越界，设置结果为long然后判断是否越界即可。51 38

# 代码
- C++ 数字上下限
```
class Solution {
public:
    int reverse(int x) {
        long upper=pow(2,31)-1;
        long lower=-pow(2,31);
        if(x==0)    return 0;
        long result = 0;
        while(x!=0){
            result = result*10 + x%10;
            x/=10;
        }
        if(result<lower||result>upper)   result=0;
        return result;
    }
};
```
