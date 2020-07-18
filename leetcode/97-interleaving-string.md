# 题目链接
[leetcode 97](https://leetcode-cn.com/problems/interleaving-string/)

# 原文
给定三个字符串 s1, s2, s3, 验证 s3 是否是由 s1 和 s2 交错组成的。  
示例 1:  
输入: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"  
输出: true  
示例 2:  
输入: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"  
输出: false

# 思路
- ### **动态规划**
  涉及到字符串的混合，一般考虑动态规划，否则时间复杂度上会达不到要求；然后开始考虑dp的含义，一维dp达不到，考虑二维，dp[i][j]代表第i+j-1的s3是否成功组成，组成的前提考虑的是dp[i-1][j]&&s1[i-1]==s3[i+j-1]（代表前面一位已经由s1组成且此时需要有s1的i-1组成才行）或者dp[i][j-1]&&s2[j-1]==s3[i+j-1](代表前面一位已经由s2组成且此时需要由s2的j-1组成才行)；对dp的初始化是第一行第一列，即第一行代表上s3单独由s1组成，第一列代表s3单独由s2组成。59 100

# 代码
- C++ 动态规划
```
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length()+s2.length()!=s3.length())    return false;
        int n1 = s1.length(),n2 = s2.length();
        vector<vector<bool>> dp(n1+1,vector<bool>(n2+1));
        dp[0][0] = true;
        for(int i=1;i<=n1;i++){
            dp[i][0] = dp[i-1][0]&&(s1[i-1]==s3[i-1]);
        }
        for(int i=1;i<=n2;i++){
            dp[0][i] = dp[0][i-1]&&(s2[i-1]==s3[i-1]);
        }
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                dp[i][j] = (dp[i-1][j]&&s1[i-1]==s3[i-1+j])||(dp[i][j-1]&&s2[j-1]==s3[i-1+j]);
            }
        }
        return dp[n1][n2];

    }
};
```