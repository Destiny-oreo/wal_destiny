# 题目链接
[leetcode 121](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/)

# 原文
给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。

如果你最多只允许完成一笔交易（即买入和卖出一支股票），设计一个算法来计算你所能获取的最大利润。

注意你不能在买入股票前卖出股票。

示例 1:

输入: [7,1,5,3,6,4]
输出: 5
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
  注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。  
示例 2:

输入: [7,6,4,3,1]
输出: 0
解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。

# 思路
- ### **动态规划**
  使用动态规划，设计结果变量记录最优解，初始化为0，同时记录已经经过的最低报价，然后试试计算在当前报价时卖出的最优解，选择更新为result；由于最低价需要初始化为数组第一个报价，所以需要确保数组有数据，即判断size即可，接着开始从第二位（下标为1）开始循环，先计算如果当前价位卖出的利润和0取最大值，接着把最低价和当前价位取最小值，一直循环下去即可，动态计算最优解和最低进价。40 9

# 代码
- C++ 动态规划
```
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2) return 0;
        int result = 0,lows = prices[0];
        for(int i=1;i<prices.size();i++){
            result = max(prices[i]-lows,result);
            lows = min(lows,prices[i]);
			// max_money = max_money>(prices[i]-min_price)?max_money:prices[i] -   
            // min_price;  //12->8ms
            //min_price = min_price<prices[i]?min_price:prices[i];
            //if(prices[i]<minprice)  minprice = prices[i];
        }
        return result;
    }
};
```
