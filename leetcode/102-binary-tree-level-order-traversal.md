# 题目链接
[leetcode 102](https://leetcode-cn.com/problems/binary-tree-level-order-traversal/)

# 原文
给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。

例如:  
给定二叉树: [3,9,20,null,null,15,7],  
    3  
   / \  
  9  20  
    /  \  
   15   7  
返回其层次遍历结果：  
[  
  [3],  
  [9,20],  
  [15,7]   
]

# 思路
- ### **二叉树-队列**
  层次遍历二叉树即为广度优先搜索，可以使用队列迭代的方式来访问（每次刚开始访问时队列中存放的都是一层的节点，先保存节点数量，再一个一个访问并弹出）；首先设立好队列，将根节点放入（先判断是否为空），然后进行循环（结束条件为队列不为空），首先保存该层节点的数量，再按照数量进行访问处理，保存完该节点数值以后保存其存在的子树，最后访问完毕以后将保存的该层数值放进结果向量。70 25
- ### **二叉树-广搜递归**
  广搜还可以使用递归的方式来查找，只是需要随时记录访问到的层数，否则无法将节点值放入到正确的向量中；首先结束条件为节点为空，接着判断层数，如果层数大于等于result的大小说明当前层的向量在result中还没有创建，需要在result中创建一个向量，然后统一在result中的层数一级加入当前节点的数值即可，然后递归遍历下去左右节点。94 5

# 代码
- C++ 二叉树-队列
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root==NULL)  return result;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int num = q.size();
            vector<int> items;
            for(int i=0;i<num;i++){
                root = q.front();
                q.pop();
                items.push_back(root->val);
                if(root->left)  q.push(root->left);
                if(root->right) q.push(root->right);
            }
            result.push_back(items);
        }
        return result;
    }
};
```
- C++ 二叉树-广搜递归
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        //if(root==NULL)  return result;
        func(root,0);
        return result;
    }
private:
    vector<vector<int>> result;
    void func(TreeNode* root,int k){
        if(root==NULL)  return;
        if(k>=result.size()){
            vector<int> items;
            result.push_back(items);//result.push_back(vector<int>()); 7%
        }
        result[k].push_back(root->val);
        func(root->left,k+1);
        func(root->right,k+1);
    }
};
```