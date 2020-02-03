# 题目链接
[leetcode 94](https://leetcode-cn.com/problems/binary-tree-inorder-traversal/)

# 原文
给定一个二叉树，返回它的中序 遍历。

示例:

输入: [1,null,2,3]
   1
    \
     2
    /
   3

输出: [1,3,2]
进阶: 递归算法很简单，你可以通过迭代算法完成吗？

# 思路
- ### **二叉树-递归**
  将二叉树使用中序遍历的方式读入向量，即先读入左子树的值再读取当前节点的值最后处理右子树的值；使用最简单的递归算法处理，先定义好最后的结果向量，然后向递归函数传入当前根节点，递归函数结构：首先完成结束条件，即当前节点为空节点，直接返回，否则先处理左子树，将左子树节点传入递归函数即可，不需要管左子树传入后的操作，然后处理当前节点，即将当前节点的数值传入向量，最后传入右子树节点给递归函数即可（当传入的子树为空时相当于没有传入，直接处理当前节点或进行下一步操作，如果有值得话即把传入的节点作为根节点再次处理判断，最后返回时已经把左子树全部处理完毕，实现中序遍历。100 14

# 代码
- C++ 二叉树-递归
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
    vector<int> inorderTraversal(TreeNode* root) {
        func(root);
        return result;
    }
private:
    vector<int> result;
    void func(TreeNode* head){
        if(head==NULL)  return;
        func(head->left);
        result.push_back(head->val);
        func(head->right);
    }
};
```
