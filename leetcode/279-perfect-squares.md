# 题目链接
[leetcode 279](https://leetcode-cn.com/problems/perfect-squares/)

# 原文
给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。  
示例 1:  
输入: n = 12  
输出: 3   
解释: 12 = 4 + 4 + 4.  
示例 2:  
输入: n = 13  
输出: 2  
解释: 13 = 4 + 9

# 思路
- ### **动态规划**
  使用传统动态规划，从1到n依次记录并依赖，每一个数都从1开始遍历到根号i，即使用任何一个平方数，剩下的在dp里寻找最小的数，最后即是dp[i-j*j]+1，代表使用j的平方，然后在减去平方以后使用动态规划保存的结果+1就是最新的结果。71 50
- ### **层次遍历**
  使用层次遍历法，每一步代表从目标位置都能走到哪些地方，最先到达0点的返回步数（一定是最少的步数，因为所有步数同步进行），其中需要建立队列，放入目标数字，同时建立向量记录每一个数字是第几步；对队列循环，取出节点，遍历其最大的根号范围，每到一个点，判断是否到达0点，否则判断是否有其他位置到过该节点，如果已经到过，不记录，否则更新该节点的步数值（node+1），然后把该节点放入队列中。93 17

# 代码
- C++ 动态规划
```
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,0);
        for(int i=1;i<=n;i++){
            int temp = INT_MAX;
            for(int j=1;j*j<=i;j++){
                temp = min(temp,dp[i-j*j]);
            }
            dp[i] = temp+1;
        }
        return dp[n];
    }
};
```
- C++ 层次遍历
```
class Solution {
public:
    int numSquares(int n) {
        vector<int> result(n+1,0);
        queue<int> q;
        q.push(n);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int i=1;i*i<=node;i++){
                if(node-i*i==0) return result[node]+1;
                if(!result[node-i*i]){
                    result[node-i*i] = result[node]+1;
                    q.push(node-i*i);
                }
            }
        }
        return 0;
    }
};
```