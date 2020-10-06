# 题目链接
[leetcode 257](https://leetcode-cn.com/problems/binary-tree-paths/)二叉树的所有路径

# 原文
给定一个二叉树，返回所有从根节点到叶子节点的路径。  
说明: 叶子节点是指没有子节点的节点。  
示例:  
输入:  
   1  
 /   \  
2     3  
 \   
  5  
输出: ["1->2->5", "1->3"]  
解释: 所有根节点到叶子节点的路径为: 1->2->5, 1->3  

# 思路
- ### **深搜**
  使用深搜来获得所有路径，只有存在子树时进行深搜，然后判断是否有子树，没有的话说明到达叶节点，处理以后放入结果数组中；此题还有一个关键点就是数字转换成字符串，由于有负数和大数的存在，所有无法直接+'0'，所以使用库函数to_string()进行转换。19 26

# 代码
- C++ 深搜
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
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root)   return result;
        string temp = "";
        temp += to_string(root->val);
        if(!root->left&&!root->right){
            result.push_back(temp);
            return  result;
        }
        if(root->left)    dfs(root->left,temp);
        if(root->right)    dfs(root->right,temp);
        return result;
    }
private:
    vector<string> result;
    void dfs(TreeNode* root,string temp){
        temp = temp+'-'+'>';
        temp += to_string(root->val);
        if(!root->left&&!root->right){
            result.push_back(temp);
            return;
        }
        else{
            if(root->left)    dfs(root->left,temp);
            if(root->right)    dfs(root->right,temp);
        }
    }
};
```
