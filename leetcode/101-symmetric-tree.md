# 题目链接
[leetcode 101](https://leetcode-cn.com/problems/symmetric-tree/)

# 原文
给定一个二叉树，检查它是否是镜像对称的。

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

    1
   / \
  2   2
 / \ / \
3  4 4  3
但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

    1
   / \
  2   2
   \   \
   3    3
说明:

如果你可以运用递归和迭代两种方法解决这个问题，会很加分。

# 思路
- ### **二叉树-递归**
  使用递归来判断是否对称的问题，首先新建一个bool函数（与原函数的区别在于此函数有两个传入量，分别代表相对称的两个节点），传入两次根节点，然后进行判断：对于对称的两个节点来说，如果两个节点都为空（也包含根节点就是空的这种情况），返回true，否则两个节点有一个节点为空时直接为不对称的情况，返回false，否则说明两个节点都有值，进行判断，首先这两个节点的值应该相同，其次这两个节点的下方所属的对应的子树也应该对称，传入下层的两个对应节点即可。64 18
- ### **二叉树-迭代**
  。77 26

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
    bool isSymmetric(TreeNode* root) {
        return ismirror(root,root);
    }
private:
    bool ismirror(TreeNode* left,TreeNode* right){
        if(left==NULL&&right==NULL) return true;
        else if(left==NULL||right==NULL)    return false;
        else{
            return (left->val==right->val)&&(ismirror(left->left,right->right))&&(ismirror(left->right,right->left));
        }
    }
};
```
- C++ 二叉树-迭代
```

```