# 题目链接
[leetcode 3](https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/)  无重复字符的最长子串  

# 原文
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。  
示例 2:
输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。  
示例 3:
输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
# 思路
- ### **哈希表**
  涉及到重复的问题可以考虑使用哈希表，每遍历一位都查询一次哈希表，本打算在哈希表存入字符串，发现复杂度太高，基本每种组合都得存进去，于是考虑存入字符，最多就存入26个key，所以此时哈希表中存入的是当前的子串，最长的长度只能在过程中保存下来。循环开始，每访问一个，判断哈希表中是否存在（即以当前字符结尾的子串是否重复），若不重复，更新子串word+=s[i]，并更新result（长度）；若重复，则从子串开头开始去除，直到s[i]在哈希表中不再大于1（即不重复），去除完毕清空子串word，并从新的begin位置到i重新加入到word中。
- ### **循环**--->最优  
  思路同上，但不适用哈希表也可以判断当前字符是否重复，即每循环到新的一位i即从begin开始遍历到i，如果存在一位与当前相同，使begin位赋值为相同位+1，每次重新比较result与i-begin+1的大小。有动态规划的味道，即每一次判断，上一次的子串已经不含重复子串，所以当前子串如果有重复子串也是当前字符可能重复。


# 代码
- C++ 哈希表
```
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> hash;
        int begin = 0,result = 0;
        string word = "";
        for(int i=0;i<s.length();i++){
            hash[s[i]]++;
            if(hash[s[i]]==1){
                word+=s[i];
                result = max(result,(int)word.length());
            }
            else{
                word = "";
                while(hash[s[i]]>1){
                    hash[s[begin]]--;
                    begin++;
                }
                for(int j=begin;j<=i;j++){
                    word+=s[j];
                }
            }
        }
        return result;
    }
};
```
- C++ 循环
```
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int result=0,begin=0;
        for(int i=0;i<s.length();i++){
            for(int j=begin;j<i;j++){
                if(s[j]==s[i]){
                    begin = j+1;
                }
            }
            result = max(result,i-begin+1);
        }
        return result;
    }
};
```