# 题目链接
[leetcode 459](https://leetcode-cn.com/problems/repeated-substring-pattern/)

# 原文
给定一个非空的字符串，判断它是否可以由它的一个子串重复多次构成。给定的字符串只含有小写英文字母，并且长度不超过10000。  
示例 1:   
输入: "abab"    
输出: True  
解释: 可由子字符串 "ab" 重复两次构成。  
示例 2:   
输入: "aba"  
输出: False  
示例 3:  
输入: "abcabcabcabc"  
输出: True  
解释: 可由子字符串 "abc" 重复四次构成。 (或者子字符串 "abcabc" 重复两次构成。) 

# 思路
- ### **字符串**
  字符串的子串可以使用substr来获得，遍历字符串的所有组成个数，即2-n个，判断是否为n的因数以后，创建新的temp字符串，组成新的字符串并和原字符串相比较，相同则返回true。11 10
- ### **字符串-找规律**
  发现如果可以重复组成的话，将两个字符串拼起来以后，去掉首尾，还是可以在拼成的字符串里找打原字符串，使用string的find函数，返回-1则没有找到。85 27

# 代码
- C++ 字符串
```
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        if(n<=1)    return false;
        for(int i=2;i<=n;i++){
            if(n%i==0){
                string temp="";
                for(int j=0;j<i;j++){
                    temp += s.substr(0,n/i);
                }
                if(temp==s)    return true;
            }
        }
        return false;
    }
};
```
- C++ 字符串-找规律
```
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        if(s.size()<=1) return false;
        string str = s+s;
        str = str.substr(1,str.size()-2);
        if(str.find(s)!=-1) return true;
        return false;
    }
};
```