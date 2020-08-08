# 题目链接
[leetcode 337](https://leetcode-cn.com/problems/house-robber-iii/)

# 原文
在上次打劫完一条街道之后和一圈房屋后，小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为“根”。 除了“根”之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 如果两个直接相连的房子在同一天晚上被打劫，房屋将自动报警。  
计算在不触动警报的情况下，小偷一晚能够盗取的最高金额。  
示例 1:  
输入: [3,2,3,null,3,null,1]  
     3  
    / \  
   2   3  
    \   \   
     3   1  
输出: 7   
解释: 小偷一晚能够盗取的最高金额 = 3 + 3 + 1 = 7.  
示例 2:  
输入: [3,4,5,1,3,null,1]  
     3  
    / \  
   4   5  
  / \   \   
 1   3   1  
输出: 9  
解释: 小偷一晚能够盗取的最高金额 = 4 + 5 = 9.

# 思路
- ### **深搜-动态规划**
  后序遍历，节点为空时返回0，否则返回以该节点为结尾的最大值，同时为了避免重复节点，使用动态规划记录每个节点的最大值；后序遍历以后，设置两个比较变量，一个为当前节点的值，另一个初始化为左右子树遍历返回的结果，第二个变量是不考虑当前节点的最大值，已经计算完毕，第一个节点还需要加上左右子树的继续左右子树的最大值（所以深搜时候必须实时继续最大值更更改节点的val），最后选出更大的值赋值给当前节点并返回；赋值给当前节点是为了后面继续选取该节点时可以直接返回选了该节点即其子树的最大值；不可以使用层次遍历，因为左右的和右边的不一定要同一层同一层的取，或者说左右和右边的隔壁层也可以一起取到。96 90

# 代码
- C++ 深搜-动态规划
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
    int rob(TreeNode* root) {
        if(!root)   return 0;
        int left = rob(root->left);
        int right = rob(root->right);
        int cur = root->val,nex = left+right;
        if(root->left){
            if(root->left->left)    cur += root->left->left->val;
            if(root->left->right)    cur += root->left->right->val;
        }
        if(root->right){
            if(root->right->left)    cur += root->right->left->val;
            if(root->right->right)    cur += root->right->right->val;
        }
        int reuslt = max(cur,nex);
        root->val = reuslt;
        return reuslt;
    }
};
```