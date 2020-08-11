# 题目链接
[leetcode 130](https://leetcode-cn.com/problems/surrounded-regions/)

# 原文
给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。   
找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。  
示例:  
X X X X  
X O O X  
X X O X  
X O X X  
运行你的函数后，矩阵变为：  
X X X X  
X X X X  
X X X X  
X O X X  
解释:  
被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 任何不在边界上，或不与边界上的 'O' 相连的 'O' 最终都会被填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。  
  
# 思路
- ### **深搜DFS**
  理解题意以后可以使用深搜或者广搜，先使用的深搜，晚上可以试试广搜，着手点也可以选择中间的节点或者边缘的节点，使用边缘节点方便一些，因为是必须需要处理的节点，中点围着的就太多了；在边缘，如果遇到O，则开始对它进行深搜，首先为了防止成为一个环，先把自己改掉，变成别的字母，然后四方向深搜，如果符合范围要求并且是O的，继续深搜，不符合的直接跳过，最后主函数里再把所有改掉的字母改回O，所有原来的O填充成X。52 83。宽搜BFS。82 51

# 代码
- C++ 深搜DFS
```
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.size()<3||board[0].size()<3)  return;
        int m=board.size(),n=board[0].size();
        for(int i=0;i<n;i++){
            if(board[0][i]=='O')    dfs(board,0,i);
            if(board[m-1][i]=='O')  dfs(board,m-1,i);
        }
        for(int i=1;i<m-1;i++){
            if(board[i][0]=='O')    dfs(board,i,0);
            if(board[i][n-1]=='O')  dfs(board,i,n-1);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='n')    board[i][j] = 'O';
                else    board[i][j] = 'X';
            }
        }

    }
private:
    const int dx[4]={-1,1,0,0};
    const int dy[4]={0,0,-1,1};
    void dfs(vector<vector<char>>& board,int row,int col){
        board[row][col] = 'n';
        for(int i=0;i<4;i++){
            int newx = row+dx[i];
            int newy = col+dy[i];
            if(newx>=0&&newx<board.size()&&newy>=0&&newy<board[0].size()&&board[newx][newy]=='O'){
                dfs(board,newx,newy);
            }
        }
    }
};
```
- C++ 宽搜BFS
```
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.size()<3||board[0].size()<3)  return;
        int m=board.size(),n=board[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            if(board[0][i]=='O')    q.push(make_pair(0,i));
            if(board[m-1][i]=='O')  q.push(make_pair(m-1,i));
        }
        for(int i=1;i<m-1;i++){
            if(board[i][0]=='O')    q.push(make_pair(i,0));
            if(board[i][n-1]=='O')  q.push(make_pair(i,n-1));
        }
        while(!q.empty()){
            int row = q.front().first,col = q.front().second;
            board[row][col] = 'n';
            q.pop();
            for(int i=0;i<4;i++){
                int newx = row+dx[i];
                int newy = col+dy[i];
                if(newx>=0&&newx<board.size()&&newy>=0&&newy<board[0].size()&&board[newx][newy]=='O'){
                q.push(make_pair(newx,newy));
            }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='n')    board[i][j] = 'O';
                else    board[i][j] = 'X';
            }
        }

    }
private:
    const int dx[4]={-1,1,0,0};
    const int dy[4]={0,0,-1,1};

};
```