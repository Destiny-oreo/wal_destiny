# 题目链接
[leetcode 5474周赛](https://leetcode-cn.com/problems/number-of-good-leaf-nodes-pairs/)

# 原文
给你二叉树的根节点 root 和一个整数 distance 。  
如果二叉树中两个 叶 节点之间的 最短路径长度 小于或者等于 distance ，那它们就可以构成一组 好叶子节点对 。  
返回树中 好叶子节点对的数量 。  
示例 1：  
输入：root = [1,2,3,null,4], distance = 3  
输出：1  
解释：树的叶节点是 3 和 4 ，它们之间的最短路径的长度是 3 。这是唯一的好叶子节点对。  
示例 2：  
输入：root = [1,2,3,4,5,6,7], distance = 3  
输出：2  
解释：好叶子节点对为 [4,5] 和 [6,7] ，最短路径长度都是 2 。但是叶子节点对 [4,6] 不满足要求，因为它们之间的最短路径长度为 4 。  
示例 3：  
输入：root = [7,1,4,6,null,5,3,null,null,null,null,null,2], distance = 3  
输出：1  
解释：唯一的好叶子节点对是 [2,5] 。  
示例 4：  
输入：root = [100], distance = 1  
输出：0  
示例 5：  
输入：root = [1,1,1], distance = 2  
输出：1  
提示：  
tree 的节点数在 [1, 2^10] 范围内。  
每个节点的值都在 [1, 100] 之间。  
1 <= distance <= 10  

# 思路
- ### **深搜**
  199场周赛第三题，5分，没有做出来直接放弃；使用深搜，同时记录节点数量，s向量代表的是此节点下存在的叶子据此的距离，所以空节点时返回全0，叶子时返回010...，代表距离一个单位，其他时候需要计算叶子之前距离是否符合distance要求，然后更新距离向量，所有i位置的叶子数为子树的I-1数量相加。


# 代码
- C++ 深搜
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
    int countPairs(TreeNode* root, int distance) {
        dfs(root,distance);
        return result;
    }
private:
    int result = 0;
    vector<int> dfs(TreeNode* node,int distance){
        vector<int> s(distance+1);
        if(!node)   return s;
        if(!node->left&&!node->right){
            s[1] = 1;
            return s;
        }
        vector<int> lefts = dfs(node->left,distance);
        vector<int> rights = dfs(node->right,distance);
        for(int i=1;i<distance;i++){
            for(int j=1;j<=distance-i;j++){
                result +=lefts[i]*rights[j];
            }
        }
        for(int i=2;i<=distance;i++){
            s[i] = lefts[i-1]+rights[i-1];
        }
        return s;
    }
};
```