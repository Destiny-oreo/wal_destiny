# 题目链接
[leetcode 107](https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/)二叉树的层次遍历 II

# 原文
给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）  
例如：  
给定二叉树 [3,9,20,null,null,15,7],  
    3  
   / \    
  9  20  
    /  \  
   15   7  
返回其自底向上的层次遍历为：  
[  
  [15,7],  
  [9,20],  
  [3]  
]  

# 思路
- ### **层次遍历**
  使用队列进行层次遍历，十分基础的题目，最后使用向量的reverse进行翻转来获得从下向上的层次遍历。91 18

# 代码
- C++ 层次遍历
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if(!root)   return result;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> items;
            for(int i=q.size()-1;i>=0;i--){
                TreeNode *node = q.front();
                q.pop();
                items.push_back(node->val);
                if(node->left)  q.push(node->left);
                if(node->right) q.push(node->right);
            }
            result.push_back(items);
        }
        reverse(result.begin(),result.end());
        return result;
    }
};
```