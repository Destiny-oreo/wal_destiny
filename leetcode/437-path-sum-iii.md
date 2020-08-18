# 题目链接
[leetcode 437](https://leetcode-cn.com/problems/path-sum-iii/)

# 原文
给定一个二叉树，它的每个结点都存放着一个整数值。  
找出路径和等于给定数值的路径总数。  
路径不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。  
二叉树不超过1000个节点，且节点数值范围是 [-1000000,1000000] 的整数。  
示例：  
root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8  
      10  
     /  \  
    5   -3   
   / \    \  
  3   2   11  
 / \   \   
3  -2   1  
返回 3。和等于 8 的路径有:  
1.  5 -> 3  
2.  5 -> 2 -> 1  
3.  -3 -> 11  

# 思路
- ### **暴力双重递归**
  没有找到更巧妙的方法，直接暴力查找，每一个节点有取和不取两种选择，即以每一个节点为起点进行搜索；首先以头节点进行搜索，然后递归调用本函数，依旧带入sum代表头节点不选择继续寻找；每一个搜索过程仍然是递归函数，首先判断结束条件，然后判断是否符合条件，不管符不符合都要继续递归，递归方法是确定取本节点，所以带入的值是target-root->val。90 42

# 代码
- C++ 暴力双重递归
```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if(!root)   return 0;
        func(root,sum);
        pathSum(root->left,sum);
        pathSum(root->right,sum);
        return result;
    }
private:
    int result = 0;
    void func(TreeNode* root,int target){
        if(!root)   return;
        if(root->val==target)   result++;
        func(root->left,target-root->val);
        func(root->right,target-root->val);        
    }
};
```