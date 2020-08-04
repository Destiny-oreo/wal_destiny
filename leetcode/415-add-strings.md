# 题目链接
[leetcode 415](https://leetcode-cn.com/problems/add-strings/)

# 原文
给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。  
注意：  
num1 和num2 的长度都小于 5100.  
num1 和num2 都只包含数字 0-9.  
num1 和num2 都不包含任何前导零。  
你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式。

# 思路
- ### **字符串**
  计算两个字符串型的数字的和，反向遍历，实时继续加法和同时记录进位，转成string类型使用的是to_string函数，转换以后是反向的，所以最后需要使用reverse函数将字符串反转；对于每一个的遍历，首先判断是否越界，然后利用-'0'来提取出真实的数字，相加以后再处理另一个字符串，继续相加，由于进位原则，每次放入string中都只放各位，十位留着和下次的进位。51 48

# 代码
- C++ 字符串
```
class Solution {
public:
    string addStrings(string num1, string num2) {
        string result;
        int temp = 0,index1 = num1.size()-1,index2 = num2.size()-1;
        while(index1>=0||index2>=0){
            if(index1>=0)   temp+=num1[index1--]-'0';
            if(index2>=0)   temp+=num2[index2--]-'0';
            result += to_string(temp%10);
            temp /= 10;
        }
        if(temp!=0) result += to_string(temp);
        reverse(result.begin(),result.end());
        return result;
    }
};
```
