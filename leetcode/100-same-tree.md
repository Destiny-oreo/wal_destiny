# 题目链接
[leetcode 100](https://leetcode-cn.com/problems/same-tree/)

# 原文
给定两个二叉树，编写一个函数来检验它们是否相同。  
如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。  
示例 1:  
输入:       1         1  
          / \       / \  
         2   3     2   3  
        [1,2,3],   [1,2,3]  
输出: true  
示例 2:  
输入:      1          1  
          /           \  
         2             2  
        [1,2],     [1,null,2]  
输出: false  
示例 3:  
输入:       1         1  
          / \       / \  
         2   1     1   2  
        [1,2,1],   [1,1,2]  
输出: false  

# 思路
- ### **递归**
  最基本的递归判断，首先判断当前节点是否符合条件，然后递归子节点，当前节点首先要判断是否为空，均为空时或者一方为空或者均不为空三种情况，均不为空的情况再继续判断子节点。48 26

# 代码
- C++ 递归
```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p&&!q)  return true;
        else if(!p||!q) return false;
        else{
            if(q->val==p->val)  return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
            else    return false;
        }
    }
};
```
