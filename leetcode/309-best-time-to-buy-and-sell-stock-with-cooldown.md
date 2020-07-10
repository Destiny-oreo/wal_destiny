# 题目链接
[leetcode 309](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/)

# 原文
给定一个整数数组，其中第 i 个元素代表了第 i 天的股票价格 。​  
设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:  
你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
示例:

输入: [1,2,3,0,2]
输出: 3 
解释: 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出]

# 思路
- ### **动态规划**
  使用两个向量来进行动态规划，因为实时记录最大效益还要求实时的购买费用（其实只需要三个格子的——当前格子和前两个格子的），先初始化前两个格子，最小购买费用时前一个购买最小费用或者选择购买当前物体时前面一个节点一定不买且前面两个节点一定有收益，所以最新的购买费用可以用-sell[i-2]+price[i]来计算，最大的效益也分为卖和不卖当前物品，不卖就是sell[i-1],卖的话计算方法是当前物体的价格减去到前面一个物体截止的购买价格。86 14 优化：sell使用三个空间即可，buy实时更新使用一个空间即可，buy代表上一次买入时花的钱，sell代表实时的效益。

# 代码
- C++ 动态规划
```
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n<=1)    return 0;
        vector<int> buy(n,0),sell(n,0);
        buy[0] = -prices[0];
        buy[1] = max(buy[0],0-prices[1]);
        sell[1] = max(sell[0],prices[1]+buy[0]);
        for(int i=2;i<n;i++){
            buy[i] = max(buy[i-1],sell[i-2]-prices[i]);
            sell[i] = max(sell[i-1],prices[i]+buy[i-1]);
        }
        return sell[n-1];

    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n<=1)    return 0;
        vector<int> sell(3,0);
        int buy = prices[0];
        sell[1] = max(sell[0],prices[1]-buy);
        buy = min(buy,prices[1]-0);
        for(int i=2;i<n;i++){
            sell[2] = max(sell[1],prices[i]-buy);
            buy = min(buy,prices[i]-sell[0]);
            sell[0] = sell[1];
            sell[1] = sell[2];
        }
        return sell[1];
    }
};
```