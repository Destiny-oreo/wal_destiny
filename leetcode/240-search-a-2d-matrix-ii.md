# 题目链接
[leetcode 240](https://leetcode-cn.com/problems/search-a-2d-matrix-ii/)

# 原文
编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target。该矩阵具有以下特性：  
每行的元素从左到右升序排列。  
每列的元素从上到下升序排列。  
示例:  
现有矩阵 matrix 如下：  
[  
  [1,   4,  7, 11, 15],  
  [2,   5,  8, 12, 19],  
  [3,   6,  9, 16, 22],  
  [10, 13, 14, 17, 24],  
  [18, 21, 23, 26, 30]  
]  
给定 target = 5，返回 true。  
给定 target = 20，返回 false。 

# 思路
- ### **分治**
  使用分治思想，从右上角或者左下角看时这个矩阵为一个二叉搜索树，从该位置出发进行遍历比较，结束条件是下标时超过矩阵范围，每到一个点时判断是否找到目标值，找到的话返回true，没有的话再继续比较大小，大的话往递增的方向遍历，小的话往递减的方向遍历，最终全都没有找到的话返回false。21 74

# 代码
- C++ 分治
```
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i=matrix.size()-1,j=0;
        while(i>=0&&j<matrix[0].size())
            if(matrix[i][j]==target)    return true;
            else if(matrix[i][j]<target)    j++;
            else if(matrix[i][j]>target)    i--;    
        return false;
    }
};
```
