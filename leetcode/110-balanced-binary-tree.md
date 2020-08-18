# 题目链接
[leetcode 110](https://leetcode-cn.com/problems/balanced-binary-tree/)

# 原文
给定一个二叉树，判断它是否是高度平衡的二叉树。  
本题中，一棵高度平衡二叉树定义为：  
一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。  
示例 1:  
给定二叉树 [3,9,20,null,null,15,7]  
    3  
   / \  
  9  20  
    /  \  
   15   7  
返回 true 。  
示例 2:  
给定二叉树 [1,2,2,3,3,null,null,4,4]  
       1  
      / \  
     2   2  
    / \  
   3   3  
  / \  
 4   4  
返回 false 。

# 思路
- ### **双重递归**
  使用了双重递归，两个函数都先写好结束条件，然后主函数递归判断是否是否符合每个节点都是平衡二叉树，次函数主要是判断一棵树的高度，返回子树的最高高度，主函数在检测完当前节点符合平衡二叉树的条件以后开始判断两个子节点是否符合，全部符合才能返回true。15 68

# 代码
- C++ 双重递归
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
    bool isBalanced(TreeNode* root) {
        if(!root)   return true;
        if(abs(depth(root->left)-depth(root->right))<=1)  return isBalanced(root->left)&&isBalanced(root->right);
        else    return false;
    }
private:
    int depth(TreeNode* root){
        if(!root)   return 0;
        return max(depth(root->left),depth(root->right))+1;
    }
};
```