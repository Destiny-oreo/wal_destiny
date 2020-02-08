# 题目链接
[leetcode 114](https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/)

# 原文
给定一个二叉树，原地将它展开为链表。

例如，给定二叉树  
    1
   / \
  2   5
 / \   \
3   4   6
将其展开为：  
1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6

# 思路
- ### **二叉树-递归**
  将给定的二叉树展开为链表，根据示例发现就是将二叉树所有节点按照先序遍历的方式放到右子树，即对于每个节点，将左子树插到右子树之前构成链表形式的二叉树；使用递归解决（在没有处理完左右子树之前不能改动此节点的指向，所以使用后序遍历），首先结束结束条件便是当前节点为空，返回空节点，否则先假设次函数已经实现了其功能，所以先用此函数将左右子树做成链表（形式均已经调整即向右展开），然后再合并（递归的最底端是直接操作一个节点），合并即将左子树放到右子树之前，先保存右子树，右子树指针指向左子树，再将左子树的最后一个指向右子树（方法是只要右子树不为空一直往右寻找），最后需要将左子树指向空节点。74 8
- ### **二叉树-后序迭代**
  后序遍历还可以使用迭代的方式实现，创建栈记录访问的节点，一直到达最左子树，处理左子树，即将右子树指向左子树（先保存右子树），左子树置空，接着处理右子树，即将两段子树连接，再继续迭代处理右子树（先将指针移到第一段右子树最低端，再指向第二段右子树，最后判断原右子树是否有左右子树）。96 11 如果在迭代过程中把加入左子树的方式从If改成while，时间复杂度会增加。29 10

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
    void flatten(TreeNode* root) {
        if(root==NULL)  return;
        flatten(root->left);
        flatten(root->right);
        TreeNode* temp = root->right;
        root->right = root->left;
        root->left = NULL;
        while(root->right)  root = root->right;
        root->right = temp;
    }
};
```
- C++ 二叉树-迭代
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
    void flatten(TreeNode* root) {
        stack<TreeNode*> s;
        while(root||!s.empty()){
            if(root){		//while() 1
                s.push(root);
                root = root->left;
            }
            else{		//if(!s.empty()) 2  此两处对应结果为29 10
                root = s.top();
                s.pop();
                TreeNode* temp = root->right;
                root->right = root->left;
                root->left = NULL;
                while(root->right)  root = root->right;
                root->right = temp;
                root = temp;
            }
        }
    }
};
```