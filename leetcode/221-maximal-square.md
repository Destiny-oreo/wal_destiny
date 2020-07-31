# 题目链接
[leetcode 221](https://leetcode-cn.com/problems/maximal-square/)

# 原文
在一个由 0 和 1 组成的二维矩阵内，找到只包含 1 的最大正方形，并返回其面积。  
示例:  
输入:   
1 0 1 0 0  
1 0 1 1 1  
1 1 1 1 1  
1 0 0 1 0  
输出: 4

# 思路
- ### **动态规划**
  其中dp的每一位值代表以此位结尾的最大正方形，如果此位的matrix为0，直接不考虑，使用初始化的0即可，当为1时，可进行状态转移，转移的影响因素有左上角、上面、左边三个因素，使用其中自小的正方形个数+1即可（也考虑了当左和上是1时坐上+1来处理，但需要考虑特殊情况即只包括左上的情况）。9 49

# 代码
- C++ 动态规划
```
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size()==0)    return 0;
        vector<vector<int>> dp(matrix.size()+1,vector<int>(matrix[0].size()+1,0));
        int result = 0;
        for(int i=1;i<=matrix.size();i++){
            for(int j=1;j<=matrix[0].size();j++){
                if(matrix[i-1][j-1]=='1'){
                    dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
                    result = max(result,dp[i][j]);
                }
            }
        }
        return result*result;
    }
};
```
