# 题目链接
[leetcode 226](https://leetcode-cn.com/problems/invert-binary-tree/)

# 原文
翻转一棵二叉树。
示例：
输入：
     4
   /   \
  2     7
 / \   / \
1   3 6   9
输出：
     4
   /   \
  7     2
 / \   / \
9   6 3   1
备注:
这个问题是受到 Max Howell 的 原问题 启发的 ：

# 思路
- ### **树-递归**
  最基础的递归操作，首先是结束条件，节点为空时停止操作，返回空节点，然后开始处理，目标作用是交换左右节点，首先保存一边节点，然后此处连接向翻转后的另一边子树，然后另一边连接反转后的保存好的一边节点最后返回当前节点。60 93

# 代码
- C++ 树-递归
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
    TreeNode* invertTree(TreeNode* root) {
        if(!root)   return root;
        TreeNode* temp = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(temp);
        return root;
    }
};
```
