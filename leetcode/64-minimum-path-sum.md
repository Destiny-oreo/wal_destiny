# 题目链接
[leetcode 64](https://leetcode-cn.com/problems/minimum-path-sum/)

# 原文
给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。  
说明：每次只能向下或者向右移动一步。  
示例:  
输入:    
[    
  [1,3,1],    
  [1,5,1],  
  [4,2,1]    
]  
输出: 7  
解释: 因为路径 1→3→1→1→1 的总和最小。

# 思路
- ### **动态规划**
  跳过二维动态规划，直接使用一维动态规划；除了第一行第一列是累加关系外（因为此方向只有一条路可走，路径数字和为累加关系），其余位置递归关系为左位置和上位置的路径和取最小值和此位置的路径数相加；所以代码首先预处理，设置好一维dp，将第一行累加即可，然后开始二维循环，第一层为第二行到最后一行，第二层为所有的列，由于每次循环中的第一列需要特殊处理，所以增加了if-else判断，如果是第一列直接累加上一个dp[i]和此位置grid[i]，如果不是第一列则先比较再相加，取dp[i-1]和dp[i]中的最小值和grid[i]相加，最后输出的就是dp的最后一个位置。57 90
- ### **动态规划优化**
  避免每次判断是否是第一位即可，而是在第一层循环时先把第一位给设置好就行了。99 74

# 代码
- C++ 动态规划
```
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size()==0||grid[0].size()==0)  return 0;
        vector<int> dp(grid[0].size(),grid[0][0]);
        for(int i=1;i<grid[0].size();i++){
            dp[i] = grid[0][i]+dp[i-1];
        }
        for(int i=1;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(j==0)    dp[j] = dp[j]+grid[i][j];
                else{
                    if(dp[j-1]<=dp[j])  dp[j] = dp[j-1]+grid[i][j];
                    else    dp[j] = dp[j]+grid[i][j];
                }
            }
        }
        return dp[grid[0].size()-1];
    }
};
```
- C++ 动态规划优化
```
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size()==0||grid[0].size()==0)  return 0;
        vector<int> dp(grid[0].size(),grid[0][0]);
        for(int i=1;i<grid[0].size();i++){
            dp[i] = grid[0][i]+dp[i-1];
        }
        for(int i=1;i<grid.size();i++){
            dp[0] = dp[0]+grid[i][0];
            for(int j=1;j<grid[0].size();j++){
                if(dp[j-1]<=dp[j])  dp[j] = dp[j-1]+grid[i][j];
                else    dp[j] = dp[j]+grid[i][j];
            }
        }
        return dp.back();
    }
};
```