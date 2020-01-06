# 题目链接
[leetcode 53](https://leetcode-cn.com/problems/maximum-subarray)

# 原文
给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

示例:

输入: [-2,1,-3,4,-1,2,1,-5,4],  
输出: 6  
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。  
进阶:

如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。

# 思路
- ### **动态规划**
  首先考虑动态规划，设置对应的一位数组，其中每一位代表以此为结束的最大子序列的和，所以此位是一定要加上的（因为不管即使时负的，后面也有可能有更大的正的来弥补），但前面的子序列需要判断以后再考虑是否要加上，如果前面的子序列不是正数，那么到此位为止，前面的子序列便一无是处，直接扔掉就行，不会引起任何的变故（因为前面既然不是正数，起不到更大的和，从此位开始一定比加上前面的更优），所以从第二位开始遍历（第一位作为初始的比较结果，也是最初的前面的子序列），判断dp[i-1]再考虑num[i]是否要加上前面的，得到此位的dp[i]以后和result比较更新取最大，最后得到的result就是全程最大的子序列（最后的dp[i]是以最后一位结尾的子序列，不一定是最大的子序列）。44 79
- ### **优化动态规划**
  写完传统动态规划以后，发下dp这个向量有点浪费，每次只需要用到dp[i]和dp[i-1]，所以考虑去掉dp直接用一个last来代表dp[i-1]，初始化与上面一致，每次判断时last就是前面的子序列，大于0才加上作为新的last，否则直接将num[i]赋值给last，最后再考虑更新给result，**注意**，这类的第五次提交专门测试了max和手动比较的性能，发现用max虽然在代码上看来很简便，但是性能很差，尽量避免使用。98 86   

# 代码
- C++ 动态规划
```
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //if(nums.size()==0)  return 0;
        vector<int> dp(nums.size(),nums[0]);
        int result = dp[0];
        for(int i=1;i<nums.size();i++){
            dp[i] = dp[i-1]>=0?dp[i-1]+nums[i]:nums[i];
            result = max(result,dp[i]);
        }
        return result;
    }
};
```
- C++ 优化动态规划
```
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = nums[0],last = nums[0];
        for(int i=1;i<nums.size();i++){
            last = last>0?last+nums[i]:nums[i];
            //result = max(result,last);
            if(result<last) result = last;
        }
        return result;
    }
};
```