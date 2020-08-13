# 题目链接
[leetcode 43](https://leetcode-cn.com/problems/multiply-strings/)

# 原文
给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。  
示例 1:  
输入: num1 = "2", num2 = "3"  
输出: "6"  
示例 2:  
输入: num1 = "123", num2 = "456"  
输出: "56088"  
说明：  
num1 和 num2 的长度小于110。  
num1 和 num2 只包含数字 0-9。  
num1 和 num2 均不以零开头，除非是数字 0 本身。  
不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。  

# 思路
- ### **字符串=乘法**
  计算两个字符串的乘法，比加法更加难一点，因为需要找到乘法每次的计算规律；首先创建最长的向量来记录结果，从最低位循环开始相乘，每次i和j的相乘结果需要放在i+j和i+j+1两位，但由于需要考虑进位，所以相乘结果首先加上低位i+j+1的进位，然后总结求余赋值给i+j+1，剩下的十位数直接给i+j累加，累加的原因是因为此位原本也有可能存在数字，因为在乘法计算时可能此位为上一行的结果（进位只考虑的是每一行之间的进位），求余的话说明此位之前已经计算过，不是最高位，所以下次计算时就算超过10也会被重新取余；最后整体向量转为字符串即可（需要将高位的0给去除）。52 82

# 代码
- C++ 字符串-乘法
```
class Solution {
public:
    string multiply(string num1, string num2) {
        string result = "";
        int l1 = num1.size(),l2 = num2.size();
        vector<int> num(l1+l2,0);
        for(int i=l1-1;i>=0;i--){
            for(int j=l2-1;j>=0;j--){
                int temp = (num1[i]-'0')*(num2[j]-'0');
                temp += num[i+j+1];
                num[i+j] += temp/10;
                num[i+j+1] = temp%10;
            }
        }
        int start = 0;
        while(start<num.size()-1&&num[start]==0)    start++;
        for(;start<num.size();start++){
            result += (num[start]+'0');
        }
        return result;
    }
};
```