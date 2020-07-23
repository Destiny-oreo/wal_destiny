# 题目链接
[leetcode 200](https://leetcode-cn.com/problems/number-of-islands/)

# 原文
给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。  
岛屿总是被水包围，并且每座岛屿只能由水平方向或竖直方向上相邻的陆地连接形成。  
此外，你可以假设该网格的四条边均被水包围。  
示例 1:  
输入:  
[  
['1','1','1','1','0'],  
['1','1','0','1','0'],  
['1','1','0','0','0'],  
['0','0','0','0','0']  
]  
输出: 1  
示例 2:  
输入:  
[  
['1','1','0','0','0'],  
['1','1','0','0','0'],  
['0','0','1','0','0'],  
['0','0','0','1','1']  
]   
输出: 3  
解释: 每座岛屿只能由水平和/或竖直方向上相邻的陆地连接而成。  

# 思路
- ### **深搜**
  找到岛屿的数量，任何相邻的1都是一个岛屿的一部分，所以一旦找到一块岛屿，其他部分必须全部遍历完才能继续寻找后面的岛屿，遍历方法就是深搜；使用dfs之前，先判断当前节点是否已经搜过同时当前节点是否是岛屿的一部分，是的话计数+1，然后开始深搜；深搜第一步将当前节点标记已经搜索，然后寻找上下左右存在的岛屿部分，依次继续深搜，搜过的部分也会标记，所以深搜完此岛屿的所有连接部分全部标记完，则可以继续循环新的未标记节点。8 100

# 代码
- C++ 深搜
```
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // mark.resize(grid.size(),grid[0].size());
        for(int i=0;i<grid.size();i++){
            mark.push_back(vector<bool>(grid[0].size()));
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(mark[i][j]==false&&grid[i][j] == '1'){
                    result++;
                    dfs(grid,i,j);
                }
            }
        }
        return result;
    }
private:
    int result = 0;
    vector<vector<bool>> mark;
    const int dx[4] = {-1,1,0,0};
    const int dy[4] = {0,0,-1,1};
    void dfs(vector<vector<char>>& grid,int i,int j){
        mark[i][j] = true;
        for(int k=0;k<4;k++){
            if(i+dx[k]>=0&&i+dx[k]<=grid.size()-1&&j+dy[k]>=0&&j+dy[k]<=grid[0].size()-1){
                if(mark[i+dx[k]][j+dy[k]]==false&&grid[i+dx[k]][j+dy[k]] == '1')
                    dfs(grid,i+dx[k],j+dy[k]);
            }
        }
    }
};
```
