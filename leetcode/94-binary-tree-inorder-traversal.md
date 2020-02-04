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
- ### **二叉树-迭代**
  中序遍历除了使用递归还可以使用迭代的方式来实现，先把左子树处理完再处理当前节点，但需要把找到左子树的路线全部记录下来，同时最先记录的需要最后访问，适合栈的特性；所以首先设置好栈和结果向量，然后先把左子树放入栈，开始对栈的元素进行循环，只要栈不为空就一直循环，把栈顶拿出，先放入结果向量，接下来需要访问的节点要么时右子树要么是父节点，如果是父节点直接进行下次循环即可（因为父节点已经在栈里），如果存在右子树则需要优先访问右子树等节点，所以在判断以后将节点移到右节点，重复上面的while循环把当前节点的左右左子树放入栈再次循环即可。72 25
- ### **二叉树-迭代**
  将上面一种做法整理成一种if-else的处理方式，不再先装stack再处理节点再装stack，而是在当前节点不为空或者栈不为空时一直循环（即当当前节点已经是空且栈里没有父节点时退出），当当前节点不为空时，将当前节点放入栈中，且说明还可以继续向左节点移动，否则说明当前节点已经到达边界，需要取出栈的栈顶节点放入结果向量并且将节点更新到右节点，下一次判断时如果右节点不为空还要放入栈中且还可以遍历左子树，如果为空则又可以取出栈顶元素。17 19

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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> result;
        while(root){
            s.push(root);
            root = root->left;
        }
        while(!s.empty()){
            TreeNode* temp = s.top();
            s.pop();
            result.push_back(temp->val);
            if(temp->right){
                temp = temp->right;
                while(temp){
                    s.push(temp);
                    temp = temp->left;
                }
            }
        }
        return result;
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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> result;
        while(root||!s.empty()){
            if(root){
                s.push(root);
                root = root->left;
            }
            else{
                root = s.top();
                s.pop();
                result.push_back(root->val);
                root = root->right;
            }
        }
        return result;
    }
};
```