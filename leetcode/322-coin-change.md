# 题目链接
[leetcode 322](https://leetcode-cn.com/problems/coin-change/)

# 原文
给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。   
示例 1:  
输入: coins = [1, 2, 5], amount = 11  
输出: 3   
解释: 11 = 5 + 5 + 1  
示例 2:  
输入: coins = [2], amount = 3  
输出: -1  
说明:  
你可以认为每种硬币的数量是无限的。

# 思路
- ### **动态规划**
  比较经典的动态规划题目，每一个硬币都可能使用到前面已经得到的最优的小金额的结果，使用dp数组以后依次完成dp0-amount，对于每一个金额，都需要遍历所有硬币，首先判断硬币大小，低于金额数开始计算，如果使用该硬币以后的金额有最优解，则算作一种结果进行min运算，否则直接跳过，最后判断目标金额是否存在最优解，存在的话返回dp数值即可，不存在返回-1。20 47

# 代码
- C++ 动态规划
```
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0)   return 0;
        vector<int> dp(amount+1,INT_MAX);
        for(int i=0;i<coins.size();i++){
            if(coins[i]>0&&coins[i]<=amount){
                dp[coins[i]] = 1;
            }
        }
        if(dp[amount]!=INT_MAX)   return dp[amount];
        for(int i=1;i<=amount;i++){
            if(dp[i]==1)    continue;
            for(int j=0;j<coins.size();j++){
                if(coins[j]<i&&dp[i-coins[j]]!=INT_MAX){
                    dp[i] = min(dp[i],dp[i-coins[j]]+1);
                }
            }
        }
        if(dp[amount]!=INT_MAX)    return dp[amount];
        else    return -1;
    }
};
```
```
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        if(n==0)    return -1;
        vector<int> dp(amount+1,INT_MAX);
        dp[0] = 0;
        for(int i=1;i<=amount;i++){
            for(int j=0;j<n;j++){
                if(i>=coins[j]&&dp[i-coins[j]]!=INT_MAX){
                    dp[i] = min(dp[i],dp[i-coins[j]]+1);
                }
            }
        }
        return dp[amount]==INT_MAX?-1:dp[amount];
    }   
};
```