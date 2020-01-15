# 题目链接
[leetcode 79](https://leetcode-cn.com/problems/word-search/)

# 原文
给定一个二维网格和一个单词，找出该单词是否存在于网格中。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

示例:

board =
[  
  ['A','B','C','E'],  
  ['S','F','C','S'],  
  ['A','D','E','E']  
]

给定 word = "ABCCED", 返回 true.  
给定 word = "SEE", 返回 true.  
给定 word = "ABCB", 返回 false.

# 思路
- ### **递归回溯**
  二维网格中按照一定的顺序查找某个单词，总体思路是将二维网格中的每个字母都作为单词的首字母进行尝试查找，如果找到则返回true，否则最后循环搜索完还没有找到则返回false；由于同一个单元格内的字母不允许被重复使用，所以设置记录查找过的字母位置，因为搜索过程为一旦该字母正确，在盖该位置的上下左右位置搜索下个字母（进行越界判断和判断是否使用过），如果该位到达了单词的最后一位，判断该位和单词最后一位是否相等即可，否则递归回溯，如果该首字母不正确，直接返回false进行下次搜索，如果正确，说明确认使用该位，先将该位标记为使用，然后遍历其上下左右位置（同时判断合法性），如果上下左右有符合剩余单词的返回true，否则最后退出上下左右循环（将该位标记为不使用）后总体返回false（当该位不为首字母或为首字母但后续无法使用时的返回结果）。97 81

# 代码
- C++ 递归回溯
```
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size()==0||board[0].size()==0) return false;
        vector<vector<int>> visited(board.size(),vector<int>(board[0].size(),0));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(DFS(i,j,board,word,0,visited))  return true;
            }
        }
        return false;
    }
private:
    const int dx[4]={-1,1,0,0};
    const int dy[4]={0,0,-1,1};
    bool DFS(int i,int j,vector<vector<char>>& board,string& word,int num,vector<vector<int>>& visited){
        //if(num==word.length())  return true;
        if(board[i][j]!=word[num])  return false;
        else{
            if(num==word.length()-1)    return true;
            else{
                visited[i][j] = 1;
                for(int k=0;k<4;k++){
                    if((i+dx[k]>=0)&&(i+dx[k]<board.size())&&(j+dy[k]>=0)&&(j+dy[k]<board[0].size())&&(visited[i+dx[k]][j+dy[k]]==0)){
                        if(DFS(i+dx[k],j+dy[k],board,word,num+1,visited))   return true;
                    }
                }
                visited[i][j] = 0;
                return false;
            }
            
            
        }
    }
//private:
//     const int dx[4] = {-1,1,0,0};
//     const int dy[4] = {0,0,-1,1};
//     bool DFS(int i,int j,int k,string &word,vector<vector<char>>& board,vector<vector<int>>& visited){
//         if(k==word.length()-1)    return word[k]==board[i][j];
//         if(word[k]==board[i][j]){
//             visited[i][j] = 1;
//             for(int m=0;m<4;m++){
//                 int newx = i+dx[m];
//                 int newy = j+dy[m];
//                 if(newx>=0&&newx<board.size()&&newy>=0&&newy<board[0].size()&&visited[newx][newy]==0&&DFS(newx,newy,k+1,word,board,visited))    return true;
//             }
//             visited[i][j] = 0;
//         }
//         return false;
//     }
};
```
