# 题目链接
[leetcode 104](https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/)

# 原文
给定一个二叉树，找出其最大深度。

二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

说明: 叶子节点是指没有子节点的节点。

示例：
给定二叉树 [3,9,20,null,null,15,7]，  
    3
   / \
  9  20
    /  \
   15   7
返回它的最大深度 3 。

# 思路
- ### **二叉树-深搜递归**
  此题考察的为深度优先搜索，首先考虑使用递归来搜索：**由上向下**：传入的为上一层的层数，先判断此层是否存在节点，不存在返回上一层的层数，否则层数++，并且计算此节点下层是否还存在子树，返回左右子树层数较大的一个即可。93 5（50）   **由下向上**：不创建新的递归函数，直接使用原函数递归搜索，层数直接返回，到最底层时返回0，其它层时直接用底层+的层数++即可。73 5 或者使用private的变量记录层数可能内存消耗会更小。
- ### **二叉树-深搜迭代**
  可以使用队列法来实现层次遍历，使用标准框架：先判断完是否为空以后放入队列，接着先判断该层的节点数量，全部挨个取出并访问保存子树节点，最后一层访问完以后将深度++。93 38

# 代码
- C++ 二叉树-深搜递归
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
    int maxDepth(TreeNode* root) {
        return func(root,0);
    }
private:
    int func(TreeNode* root,int k){
        if(root==NULL)  return k;
        else{
            k++;
            int a = func(root->left,k),b = func(root->right,k);
            if(a>b) return a;
            else    return b;		//50
            //return max(func(root->left,k),func(root->right,k));	//5
        }
    }
};
```
```
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL)  return 0;
        else    return max(maxDepth(root->left),maxDepth(root->right))+1;
    }
};
```
- C++ 二叉树-深搜迭代
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
    int maxDepth(TreeNode* root) {
        if(root==NULL)  return 0;
        int depth = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int num = q.size();
            depth++;
            for(int i=0;i<num;i++){
                root = q.front();
                q.pop();
                if(root->left)  q.push(root->left);
                if(root->right) q.push(root->right);
            }
        }
        return depth;
    }
};
```