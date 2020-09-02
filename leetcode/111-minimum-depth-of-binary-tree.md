# 题目链接
[leetcode 111](https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/)

# 原文
给定一个二叉树，找出其最小深度。  
最小深度是从根节点到最近叶子节点的最短路径上的节点数量。  
说明: 叶子节点是指没有子节点的节点。  
示例:  
给定二叉树 [3,9,20,null,null,15,7],  
    3  
   / \  
  9  20    
    /  \  
   15   7  
返回它的最小深度  2.  

# 思路
- ### **广搜**
  使用广度优先搜索，只要搜到某一层存在一个没有任何子树的节点，则广搜到此结束，直接返回深度值，如果存在任何一个子树则不算结束，继续将存在的子树放入队列中。84 30
- ### **递归**
  递归完成操作，每一个节点分情况讨论，空节点返回0，只有一个节点不能结束，递归该节点，有两个节点或者没有节点时返回其中较小的一个并+1。23 16

# 代码
- C++ 广搜
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
    int minDepth(TreeNode* root) {
        if(!root)   return 0;
        // if(!root->left&&!root->right)   return 1;
        // if(!root->left||!root->right)   return 2;
        int result = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            result++;
            for(int i=q.size()-1;i>=0;i--){
                TreeNode* temp = q.front();
                q.pop();
                if(!temp->left&&!temp->right)   return result;
                if(temp->left)  q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }
        return result;
    }
};
```
- C++ 递归
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
    int minDepth(TreeNode* root) {
        if(!root)   return 0;
        if(root->left&&!root->right)    return 1+minDepth(root->left);
        else if(root->right&&!root->left)   return 1+minDepth(root->right);
        else    return 1+min(minDepth(root->left),minDepth(root->right));
    }
};
```