# 题目链接
[leetcode 617](https://leetcode-cn.com/problems/merge-two-binary-trees/)

# 原文
给定两个二叉树，想象当你将它们中的一个覆盖到另一个上时，两个二叉树的一些节点便会重叠。

你需要将他们合并为一个新的二叉树。合并的规则是如果两个节点重叠，那么将他们的值相加作为节点合并后的新值，否则不为 NULL 的节点将直接作为新二叉树的节点。

示例 1:
```
输入: 
	Tree 1                     Tree 2                  
          1                         2                             
         / \                       / \                            
        3   2                     1   3                        
       /                           \   \                      
      5                             4   7                  
输出: 
合并后的树:
	     3
	    / \
	   4   5
	  / \   \ 
	 5   4   7
```
注意: 合并必须从两个树的根节点开始。

# 思路
- ### 先序遍历
递归完成更改，由于必须从根节点开始所以采用先序遍历，先检测两个节点是否为空，有一个空即立马返回另一个节点，另一个节点也为空时则反悔了NULL；接着首先合并根节点，在t1节点上进行更改，接着遍历左右子树，由于函数返回值为节点，所以直接令返回的左右子树赋值给当前节点的左右指针即可，当传入的某以节点为空值直接返回另一个节点。（用指针访问左右子树或者节点值时只能使用->，当是节点对象时可以使用.来访问。）

# 代码
- C++ 先序遍历
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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1==NULL)    return t2;
        if(t2==NULL)    return t1;
        t1->val+=t2->val;
        t1->left = mergeTrees(t1->left,t2->left);
        t1->right = mergeTrees(t1->right,t2->right);
        return t1;
    }
};
```