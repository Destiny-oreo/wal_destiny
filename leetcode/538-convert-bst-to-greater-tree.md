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
