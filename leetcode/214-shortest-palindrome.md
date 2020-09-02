# 题目链接
[leetcode 214](https://leetcode-cn.com/problems/shortest-palindrome/)最短回文串  

# 原文
给定一个字符串 s，你可以通过在字符串前面添加字符将其转换为回文串。找到并返回可以用这种方式转换的最短回文串。  
示例 1:  
输入: "aacecaaa"  
输出: "aaacecaaa"  
示例 2:  
输入: "abcd"  
输出: "dcbabcd"  

# 思路
- ### **哈希思想-回文-反转**
  理解题意就是找到已知字符串的最长回文字符串，然后将后面不是回文的字符串进行反转放在原字符串前面进行返回；最长回文字符串可以使用哈希思想，需要用每个字符的ascll码进行计算，只有回文字符串的正序和逆序的ascll码相加相等，为了避免超过上下限，设置mod，中间计算结果用long保存，然后取模后赋值给哈希；其中，计算方法是：正序是pos=pos*base+s[i]，base是进制需要超过所有ascll的质数，逆序是新字符乘的数是base的n次方，所以是rev=rev+s[i]*mul，其中mul初始化为1，然后每次乘以base，取模以后相等即符合回文，记录位置，最后将此位置以后的字符串反转以后赋值给temp放在字符串开头即可。52 83

# 代码
- C++ 哈希思想-回文-反转
```
class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        if(n<=1) return s;
        int loc = 0,base = 131,mod = 1e9+7,mul = 1;
        int pos = 0,rev = 0;
        for(int i=0;i<n;i++){
            pos = ((long)pos*base+s[i])%mod;
            rev = (rev+(long)s[i]*mul)%mod;
            mul = ((long)mul*base)%mod;
            if(pos==rev)    loc = i;
        }
        string temp = loc==n-1?"":s.substr(loc+1,n-loc-1);
        reverse(temp.begin(),temp.end());
        return temp+s;
    }
};
```
