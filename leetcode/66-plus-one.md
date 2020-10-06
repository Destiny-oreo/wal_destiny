# 题目链接
[leetcode 66](https://leetcode-cn.com/problems/plus-one/)加一

# 原文
给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。  
最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。  
你可以假设除了整数 0 之外，这个整数不会以零开头。  
示例 1:  
输入: [1,2,3]  
输出: [1,2,4]  
解释: 输入数组表示数字 123。  
示例 2:  
输入: [4,3,2,1]  
输出: [4,3,2,2]  
解释: 输入数组表示数字 4321。  

# 思路
- ### **数组**
  尾数加一即可，最主要的问题是首位需要进位，所以最后进位不为0时push_back一个新位置，然后所有数据后移一位，然后首位置为carry。100 33

# 代码
- C++ 数组
```
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1,n = digits.size();
        for(int i=n-1;i>=0;i--){
            int temp = digits[i]+carry;
            digits[i] = temp%10;
            carry = temp/10;
        }
        if(carry!=0){
            digits.push_back(carry);
            for(int i=n;i>0;i--){
                digits[i] = digits[i-1];
            }
            digits[0] = carry;
        }
        return digits;
    }
};
```
