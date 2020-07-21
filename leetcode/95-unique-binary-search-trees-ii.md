# 题目链接
[leetcode 95](https://leetcode-cn.com/problems/unique-binary-search-trees-ii/)

# 原文
给定一个整数 n，生成所有由 1 ... n 为节点所组成的 二叉搜索树 。   
示例：  
输入：3  
输出：  
[  
  [1,null,3,2],  
  [3,2,null,1],  
  [3,1,null,null,2],  
  [2,1,3],  
  [1,null,2,null,3]  
]  
解释：  
以上的输出对应以下 5 种不同结构的二叉搜索树：  
   1         3     3      2      1  
    \       /     /      / \      \  
     3     2     1      1   3      2  
    /     /       \                 \  
   2     1         2                 3  

# 思路
- ### **链表-搜索树**
  二叉搜索树的构造原则是左小右大，总的遍历规则是从小到大，然后递归进行，递归是本题的关键：由于需要区分左子树和右子树，所以需要分开来传递范围，当左边界超过右边界时放入空指针，否则进行新的递归，左右子树构造完毕就需要连接了，构造一个临时树指针，之前需要先存好左子树向量和右子树向量，然后遍历每一个子树，一次放入左右子树然后放入result中。95 95

# 代码
- C++ 链表-搜索树
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
    vector<TreeNode*> generateTrees(int n) {
        if(n<=0)    return vector<TreeNode*>{};
        return bfs(1,n);
    }
private:
    vector<TreeNode*> bfs(int left,int right){
        vector<TreeNode*> result;
        if(left>right){
            result.push_back(nullptr);
            return result;
        }
        for(int i=left;i<=right;i++){
            vector<TreeNode*> lts = bfs(left,i-1);
            vector<TreeNode*> rts = bfs(i+1,right);
            for(auto& lt:lts){
                for(auto& rt:rts){
                    TreeNode* temp = new TreeNode(i);
                    temp->left = lt;
                    temp->right = rt;
                    result.push_back(temp);
                }
            }
        }
        return result;
    }
};
```