# 题目链接
[leetcode 538](https://leetcode-cn.com/problems/convert-bst-to-greater-tree/)

# 原文
给定一个二叉搜索树（Binary Search Tree），把它转换成为累加树（Greater Tree)，使得每个节点的值是原来的节点值加上所有大于它的节点值之和。  
例如：  
输入: 原始二叉搜索树:  
              5  
            /   \  
           2     13  
输出: 转换为累加树:    
             18   
            /   \  
          20     13  
注意：本题和 1038: https://leetcode-cn.com/problems/binary-search-tree-to-greater-sum-tree/ 相同

# 思路
- ### **中序遍历**
  中序遍历来处理。先处理右子树，累加和，然后处理当前节点，最后处理左子树；首先判断是否为空节点，然后递归右子树，然后处理当前节点，更新当前节点，然后赋值给累加和，最后递归左子树。37 97
- ### **深搜**
  在查完每一个点的周围8个点的情况可以，可以使用深搜，代码比较常规，下面深搜代码开头和深搜前的条件重复，可删去一处；对于深搜代码：首先是结束条件，然后计算此点周围8点的雷的数量，根据数量来进行深搜；如果为0，可以深搜，更改此点字符以后重新遍历8个点即可；如果不为0，则更改此点字符即可。98 34

# 代码
- C++ 中序遍历
```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        if(!root)   return NULL;
        convertBST(root->right);
        root->val += sums;
        sums =root->val;
        convertBST(root->left);
        return root;

    }
private:
    int sums = 0;
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