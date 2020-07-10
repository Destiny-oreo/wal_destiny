# 题目链接
[leetcode 139](https://leetcode-cn.com/problems/word-break/)

# 原文
哦，不！你不小心把一个长篇文章中的空格、标点都删掉了，并且大写也弄成了小写。像句子"I reset the computer. It still didn’t boot!"已经变成了"iresetthecomputeritstilldidntboot"。在处理标点符号和大小写之前，你得先把它断成词语。当然了，你有一本厚厚的词典dictionary，不过，有些词没在词典里。假设文章用sentence表示，设计一个算法，把文章断开，要求未识别的字符最少，返回未识别的字符数。

注意：本题相对原题稍作改动，只需返回未识别的字符数  
示例：   
输入：  
dictionary = ["looked","just","like","her","brother"]
sentence = "jesslookedjustliketimherbrother"
输出： 7
解释： 断句后为"jess looked just like tim her brother"，共7个未识别字符。
提示：

0 <= len(sentence) <= 1000
dictionary中总字符数不超过 150000。
你可以认为dictionary和sentence中只包含小写字母。

# 思路
- ### **找规律**
  首先返回的是未识别的字符，按照遍历顺序每遍历一个需要增加一个，当当前节点找到完整结尾的单词时，当前节点为止的未识别字符就是当前位置减去单词长度位置的未识别数量；大循环是遍历句子的所有节点0-n-1，然后第一个节点按道理初始化为1，后面按道理为前面位置+1，所以dp数组多申请一位为了方便0+1，接着当前节点判断是否存在完整结尾的单词，遍历每一个单词（使用auto&快速提取单词），然后使用substr提取句子中的单词，当前节点为结尾的话，单词的长度不能超过i+1，所以size<=i+1才可以，然后判断是否存在，内循环相当于把所以符合以当前位置结尾的单词全部查询一遍，若存在则选择性更新dp[i+1]（不更新的情况是已经存在更长字符的单词时，dp已经更新为更小的数字）。84 100

# 代码
- C++ 找规律
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
