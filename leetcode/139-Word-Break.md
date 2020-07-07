# 题目链接
[leetcode 139](https://leetcode-cn.com/problems/word-break/)

# 原文
给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。  
说明：  
拆分时可以重复使用字典中的单词。
你可以假设字典中没有重复的单词。  
示例 1：  
输入: s = "leetcode", wordDict = ["leet", "code"]
输出: true
解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。  
示例 2：  
输入: s = "applepenapple", wordDict = ["apple", "pen"]
输出: true
解释: 返回 true 因为 "applepenapple" 可以被拆分成 "apple pen apple"。
     注意你可以重复使用字典中的单词。  
示例 3：  
输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
输出: false

# 思路
- ### **动态规划**
  对于给定的字符串，必须是要遍历大部分字符的，但是可以不从头到尾；对于遍历取下来的小字符串，首先需要将字典取出，用来判断取出的小字符串是否存在（因为给的向量无法判断），所以使用set来装所有的字典选项，然后遍历时结束项从最短的结尾到达字符串的结尾，开始项从距离结束项最远的距离（不超过最长的字典选项，也不小于0），遍历到距离结束项距离最短字典选项的距离，如果开始项前面一个字符是存在的并且开始项到结束项也是存在与set容器中，则在结束项成立一个true，最后使用动态规划的思想判断最后一个字符是否是true即可。84 100

# 代码
- C++ 动态规划
```
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.length()+1,false);
        set<string> m(wordDict.begin(),wordDict.end());
        int minlen = INT_MAX,maxlen = 0;
        for(int i=0;i<wordDict.size();i++){
            maxlen = max((int)wordDict[i].length(),maxlen);
            minlen = min((int)wordDict[i].length(),minlen);
            //minlen = minlen==0?(int)wordDict[i].length():min(minlen,(int)wordDict[i].length());
        }
        dp[0]=true;
        for(int i=minlen;i<=s.length();i++){
            for(int j=max(0,i-maxlen);j<i;j++){
                if(dp[j]&&m.find(s.substr(j,i-j))!=m.end()){
                    dp[i] = true;
                    break;
                }

            }
        }
        return dp[s.length()];
    }
};
```
