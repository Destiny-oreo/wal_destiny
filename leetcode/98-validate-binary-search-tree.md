# 题目链接
[leetcode 98](https://leetcode-cn.com/problems/validate-binary-search-tree/)

# 原文
给定一个二叉树，判断其是否是一个有效的二叉搜索树。 

假设一个二叉搜索树具有如下特征：

节点的左子树只包含小于当前节点的数。  
节点的右子树只包含大于当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。
示例 1:

输入:  
    2
   / \
  1   3  
输出: true  
示例 2:

输入:   
    5
   / \
  1   4
     / \
    3   6  
输出: false  
解释: 输入为:  [5,1,4,null,null,3,6]。根节点的值为 5 ，但是其右子节点值为 4 。

# 思路
- ### **二叉搜索树-中序遍历递归**
  判断一个给定的二叉树是否符合二叉搜索树，使用递归来判断的话就是首先寻找结束条件，当到达边界时即遇到null时才返回，且返回的true，其次，对于当年节点的处理分为先序遍历、中序遍历和后序遍历，如果是先序遍历的话需要判断两次，一次是左子树小于等于当前节点的值，一次是右子树大于等于当前节点的值，比较麻烦，如果用中序遍历的话，，先把节点移到最左端，然后第一次返回时为true（边界的左子树为null），然后即可判断当前节点和上一个节点（上一个节点初始化为null，一旦到达边界以后开始后续操作时赋值到当前节点的值），当上一节点有值时说明已经保存了其上一个应该比它小的值得节点，判断即可，如果大于等于则返回false，接着更新pre节点，最后判断其右子是否符合即可，整体构成中序遍历。（pre节点需要定义成指针形式，因为在初始化时需要定义为一个固定的值代表没有被赋值，后面一旦到达边界需要赋值成任意一个数值，所以只有null才可以区分开）77 17
- ### **二叉搜索树-迭代**
  从96题总结来的对于二叉树的中序遍历的迭代版的标准框架，首先设计好栈，然后判断当前节点不为空或栈不为空，如果节点不为空，说明还有左子树可以访问，将当前节点放入栈中保存并且将当前节点更新到左子树，如果当前节点为空，说明上一个节点（栈顶）已经是最左的节点，取出以后进行处理：首先判断其是否符合二叉搜索树的特点（pre指针不为空且大于等于--同上递归思路），接着更新pre指针，最后判断其是否有右子树（不能直接不更新root，否则会造成死循环，因为root刚取出来，不会为空，下一次循环会再放入栈中，所以更新root为其右子树，如果有的话下次会自动放入栈中而不重复，且可以进而判断左子树，如果没有的话，root为空，会直接取出栈顶，即父节点）。77 26

# 代码
- C++ 二叉搜索树-中序遍历递归
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
    bool isValidBST(TreeNode* root) {
        if(root==NULL)  return true;
        else{
            if(isValidBST(root->left)==false)   return false;
            if(pre!=NULL&&*pre>=root->val)  return false;
            pre = &root->val;
            return isValidBST(root->right);
        }
    }
private:
    int* pre = NULL;
};
```
- C++ 二叉搜索树-迭代
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
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> s;
        while(root||!s.empty()){
            if(root){
                s.push(root);
                root = root->left;
            }
            else{
                root = s.top();
                s.pop();
                if(pre!=NULL&&pre->val>=root->val)  return false;
                pre = root;
                root = root->right;
            }
        }
        return true;
    }
private:
    TreeNode* pre = NULL;
};
```