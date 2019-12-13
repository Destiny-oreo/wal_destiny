# 二叉树的定义
- ### [树](https://www.jianshu.com/p/bf73c8d50dc2)
  树是n（n>=-0）个节点的有限集，且这些节点满足如下关系：  
 （1）有且仅有一个节点没有父结点，该节点称为树的根。  
 （2）除根外，其余的每个节点都有且仅有一个父结点。  
 （3）树中的每一个节点都构成一个以它为根的树。
- ### 二叉树
  - 每个节点最多有两个孩子（子树），这两个子树有左右之分，次序不可颠倒
  - 定义： 
```
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
```

# 搜索算法
- ### 深度优先搜索DFS
  对一个分支进行深层遍历
- ### 广度优先搜索BFS
  一层一层搜索
- ### 二叉搜索树



# 经典题目
[leetcode 617 合并两个给定二叉树各对应节点上的值](E:/English/GitHub_test/wal_destiny/leetcode/617-Merge-Two-Binary-Trees.md)
