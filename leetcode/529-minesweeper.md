# 题目链接
[leetcode 529](https://leetcode-cn.com/problems/minesweeper/)

# 原文
让我们一起来玩扫雷游戏！  
给定一个代表游戏板的二维字符矩阵。 'M' 代表一个未挖出的地雷，'E' 代表一个未挖出的空方块，'B' 代表没有相邻（上，下，左，右，和所有4个对角线）地雷的已挖出的空白方块，数字（'1' 到 '8'）表示有多少地雷与这块已挖出的方块相邻，'X' 则表示一个已挖出的地雷。   
现在给出在所有未挖出的方块中（'M'或者'E'）的下一个点击位置（行和列索引），根据以下规则，返回相应位置被点击后对应的面板：  
如果一个地雷（'M'）被挖出，游戏就结束了- 把它改为 'X'。   
如果一个没有相邻地雷的空方块（'E'）被挖出，修改它为（'B'），并且所有和其相邻的未挖出方块都应该被递归地揭露。  
如果一个至少与一个地雷相邻的空方块（'E'）被挖出，修改它为数字（'1'到'8'），表示相邻地雷的数量。  
如果在此次点击中，若无更多方块可被揭露，则返回面板。  
示例 1：  
输入:   
[['E', 'E', 'E', 'E', 'E'],  
 ['E', 'E', 'M', 'E', 'E'],  
 ['E', 'E', 'E', 'E', 'E'],  
 ['E', 'E', 'E', 'E', 'E']]  
Click : [3,0]  
输出:   
[['B', '1', 'E', '1', 'B'],  
 ['B', '1', 'M', '1', 'B'],  
 ['B', '1', '1', '1', 'B'],  
 ['B', 'B', 'B', 'B', 'B']]  
解释:  
示例 2：  
输入:    
[['B', '1', 'E', '1', 'B'],  
 ['B', '1', 'M', '1', 'B'],  
 ['B', '1', '1', '1', 'B'],  
 ['B', 'B', 'B', 'B', 'B']]  
Click : [1,2]  
输出:   
[['B', '1', 'E', '1', 'B'],  
 ['B', '1', 'X', '1', 'B'],  
 ['B', '1', '1', '1', 'B'],  
 ['B', 'B', 'B', 'B', 'B']]  
解释:  
注意：  
输入矩阵的宽和高的范围为 [1,50]。  
点击的位置只能是未被挖出的方块 ('M' 或者 'E')，这也意味着面板至少包含一个可点击的方块。  
输入面板不会是游戏结束的状态（即有地雷已被挖出）。  
简单起见，未提及的规则在这个问题中可被忽略。例如，当游戏结束时你不需要挖出所有地雷，考虑所有你可能赢得游戏或标记方块的情况。  

# 思路
- ### **宽搜-pair**
  寻找每一个点的周围8个点的状态，找完以后再决定当前点的状态，所以优先使用广度优先搜索；首先先判断起始点是否为特殊点，不是的话开始使用队列；对于队列中的点取出最前方的点，初始化为0，然后遍历八个邻点，有雷的话就++，最后判断如果还是0即没有雷，则开始最重要的操作：改此位为B，然后将周围没有遍历过的点放入队列中，为了避免重复入队列，所以每一个放入队列中的点都需要暂时更改字符为除了已出现字符的任意字符。91 91
- ### **深搜**
  在查完每一个点的周围8个点的情况可以，可以使用深搜，代码比较常规，下面深搜代码开头和深搜前的条件重复，可删去一处；对于深搜代码：首先是结束条件，然后计算此点周围8点的雷的数量，根据数量来进行深搜；如果为0，可以深搜，更改此点字符以后重新遍历8个点即可；如果不为0，则更改此点字符即可。98 34

# 代码
- C++ 宽搜-pair
```
class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if(board.size()==0||board[0].size()==0) return board;
        if(board[click[0]][click[1]]=='M'){
            board[click[0]][click[1]] = 'X';
            return board;
        }
        queue<pair<int,int>> q;
        q.push(make_pair(click[0],click[1]));
        while(!q.empty()){
            for(int i=q.size()-1;i>=0;i--){
                auto ind = q.front();
                q.pop();
                board[ind.first][ind.second] = '0';
                for(int j=0;j<8;j++){
                    int newx = ind.first+dx[j];
                    int newy = ind.second+dy[j];
                    if(newx>=0&&newx<board.size()&&newy>=0&&newy<board[0].size()&&board[newx][newy] == 'M'){
                        board[ind.first][ind.second]++;
                    }
                }
                if(board[ind.first][ind.second] == '0'){  //无地雷 把所有没有E的邻位放入q
                    board[ind.first][ind.second] = 'B';
                    for(int j=0;j<8;j++){
                        int newx = ind.first+dx[j];
                        int newy = ind.second+dy[j];
                        if(newx>=0&&newx<board.size()&&newy>=0&&newy<board[0].size()&&board[newx][newy]=='E'){
                            q.push(make_pair(newx,newy));
                            board[newx][newy] = 'b';
                        }
                    }
                }
            }
        }
        return board;
    }
private:
    const int dx[8] = {-1,-1,-1,0,0,1,1,1};
    const int dy[8] = {-1,0,1,-1,1,-1,0,1};
};
```
- C++ 深搜
```
class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if(board.size()==0||board[0].size()==0) return board;
        if(board[click[0]][click[1]]=='M'){
            board[click[0]][click[1]] = 'X';
            return board;
        }
        dfs(board,click[0],click[1]);
        return board;
    }
private:
    // E 未遍历
    // M 未点击的地雷 X 点击的地雷
    // B 已遍历且周围无地雷
    const int dx[8] = {-1,-1,-1,0,0,1,1,1};
    const int dy[8] = {-1,0,1,-1,1,-1,0,1};
    void dfs(vector<vector<char>>& board,int& row,int& col){
        if(row<0||col<0|row>=board.size()||col>=board[0].size()||board[row][col]!='E')  return;
        int ms = 0;
        for(int i=0;i<8;i++){
            int newx = row+dx[i];
            int newy = col+dy[i];
            if(newx>=0&&newx<board.size()&&newy>=0&&newy<board[0].size()&&board[newx][newy] == 'M')
                ms++;
        }
        if(ms==0){
            board[row][col] = 'B';
            for(int i=0;i<8;i++){
                int newx = row+dx[i];
                int newy = col+dy[i];
                if(newx>=0&&newx<board.size()&&newy>=0&&newy<board[0].size()&&board[newx][newy] == 'E')
                    dfs(board,newx,newy);
            }
        }
        else{
            board[row][col] = '0'+ms;
        }
    }
};
```