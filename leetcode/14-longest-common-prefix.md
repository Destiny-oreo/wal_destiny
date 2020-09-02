# 题目链接
[leetcode 14](https://leetcode-cn.com/problems/longest-common-prefix/)最长公共前缀  

# 原文
编写一个函数来查找字符串数组中的最长公共前缀。  
如果不存在公共前缀，返回空字符串 ""。  
示例 1:  
输入: ["flower","flow","flight"]  
输出: "fl"  
示例 2:  
输入: ["dog","racecar","car"]  
输出: ""  
解释: 输入不存在公共前缀。  
说明:  
所有输入只包含小写字母 a-z 。  

# 思路
- ### **哈希表**
  主要用了字符串的substr函数，首先找到所有字符串的最短长度，然后遍历所有字符串，和第一个字符串进行比较，只要不相等，长度--，直到遍历完所有字符串，剩下的长度就是前缀长度。100 62 

# 代码
- C++ 字符串
```
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0)  return "";
        int len = INT_MAX;
        for(int i=0;i<strs.size();i++){
            if(strs[i].size()<len)  len = strs[i].size();
        }
        for(int i=1;i<strs.size();i++){
            while(len&&strs[0].substr(0,len)!=strs[i].substr(0,len))    len--;
        }
        return strs[0].substr(0,len);
    }
};
```
