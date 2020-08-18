# 题目链接
[leetcode 105](https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)

# 原文
根据一棵树的前序遍历与中序遍历构造二叉树。  
注意:  
你可以假设树中没有重复的元素。  
例如，给出  
前序遍历 preorder = [3,9,20,15,7]  
中序遍历 inorder = [9,3,15,20,7]  
返回如下的二叉树：     
    3  
   / \  
  9  20  
    /  \  
   15   7  

# 思路
- ### **二叉树-递归**
  使用前序遍历和中序遍历构造二叉树，需要了解两种遍历方法的区别，前序遍历的第一个一定为根节点，中序遍历前面一段为左子树才到根节点再到右子树，根据这个特性先找到根节点，即在中序遍历中找到先序遍历第一个节点的位置，此位置之前的节点为左子树，之后的节点为右子树，寻找这个位置使用while循环，结束条件为坐标不越界且节点未找到（题目中没有重复的元素所以找到两个值相等即可），然后计算左子树长度，将根节点的左子树指向递归返回的函数中（参数传入左子树的坐标范围即可），右子树指定另一个返回的递归函数中（参数传入右子树的坐标范围），相当于每一次构造了一个节点，同时完成左右子树的连接，返回的节点即为根节点或者父节点的左右子树其中一个节点。67 51

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return func(0,preorder.size()-1,0,inorder.size()-1,preorder,inorder);
    }
private:
    TreeNode* func(int preleft,int preright,int inleft,int inright,vector<int>& preorder,vector<int>& inorder){
        if(preleft>preright||inleft>inright)    return NULL;
        TreeNode* root = new TreeNode(preorder[preleft]);
        int index = inleft;
        while(index<=inright&&inorder[index]!=preorder[preleft])    index++;
        int leftlength = index-inleft;
        root->left = func(preleft+1,preleft+leftlength,inleft,inleft+leftlength-1,preorder,inorder);
        root->right = func(preleft+leftlength+1,preright,inleft+leftlength+1,inright,preorder,inorder);
        return root;
    }
};
```