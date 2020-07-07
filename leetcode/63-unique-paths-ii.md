# 题目链接
[leetcode 63](https://leetcode-cn.com/problems/unique-paths-ii/)

# 原文
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。

现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？  
网格中的障碍物和空位置分别用 1 和 0 来表示。  
说明：m 和 n 的值均不超过 100。 

# 思路
- ### **动态规划**
  和普通的动态规划寻找路径的区别在于此路径中可能存在障碍，对于障碍的处理方法是，当计算当前格子的路径数时，先判断当前格子是否有障碍，有的话直接置0，否则按照正常方法处理；处理的难点在于，当障碍位于入口或者出口时，直接返回0，当位于某一行的第一个时，需要直接置0，对于其他位置则可以正常相加左边一格以及上面一行的此格。86 100


# 代码
- C++ 动态规划
```
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.size()<1)   return 0;
        if(obstacleGrid[0].size()<1)    return 1;
        int cols = obstacleGrid.size(),rows = obstacleGrid[0].size();
        vector<int> dp(rows,1);
        if(obstacleGrid[0][0]==1)   dp[0] = 0;
        if(obstacleGrid[cols-1][rows-1]==1) return 0;
        for(int i=1;i<rows;i++){
            if(obstacleGrid[0][i]==1){
                dp[i] = 0;
            }
            dp[i] = dp[i]*dp[i-1];
        }
        for(int i=1;i<cols;i++){
            if(obstacleGrid[i][0]==1)   dp[0]=0;
            for(int j=1;j<rows;j++){
                if(obstacleGrid[i][j]==1)   dp[j]=0;
                else    dp[j] = dp[j]+dp[j-1];
            }
        }
        return dp[rows-1];
    }
};
```
