# 题目链接
[leetcode 438](https://leetcode-cn.com/problems/find-all-anagrams-in-a-string/)

# 原文
给定一个字符串 s 和一个非空字符串 p，找到 s 中所有是 p 的字母异位词的子串，返回这些子串的起始索引。  
字符串只包含小写英文字母，并且字符串 s 和 p 的长度都不超过 20100。  
说明：  
字母异位词指字母相同，但排列不同的字符串。  
不考虑答案输出的顺序。  
示例 1:  
输入:  
s: "cbaebabacd" p: "abc"  
输出:  
[0, 6]  
解释:  
起始索引等于 0 的子串是 "cba", 它是 "abc" 的字母异位词。  
起始索引等于 6 的子串是 "bac", 它是 "abc" 的字母异位词。  
 示例 2:  
输入:  
s: "abab" p: "ab"  
输出:  
[0, 1, 2]    
解释:  
起始索引等于 0 的子串是 "ab", 它是 "ab" 的字母异位词。  
起始索引等于 1 的子串是 "ba", 它是 "ab" 的字母异位词。  
起始索引等于 2 的子串是 "ab", 它是 "ab" 的字母异位词。  

# 思路
- ### **哈希表**
  题目主要为了完成如何判断前面一个字符串的子字符串与后面一个字符串是否为异位词，使用的方法是哈希表，统计其中每个单词出现的次数进行比较即可；对于前面一个长字符串，每次更新不需要全部重新计算，仅需要把被更新掉的位置--以及新加入的位置++即可，然后判断两个哈希表是否相等，相等的话把当前下标放入结果字符串即可。90 95

# 代码
- C++ 哈希表
```
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        int m=s.size(),n=p.size();
        if(m<n)   return result;
        vector<int> target(26,0),hash(26,0);
        for(int i=0;i<p.size();i++){
            target[p[i]-'a']++;
            hash[s[i]-'a']++;
        }
        for(int i=0;i<m-n+1;i++){
            if(i==0){
                if(match(hash,target))  result.push_back(0);
            }
            else{
                hash[s[i-1]-'a']--;
                hash[s[i+n-1]-'a']++;
                if(match(hash,target))   result.push_back(i);
            }
        }
        return result;
    }
private:
    
    bool match(vector<int>& a,vector<int>& b){
        for(int i=0;i<26;i++){
            if(a[i]!=b[i])  return false;
        }
        return true;
    }
};
```