# 题目链接
[leetcode 494](https://leetcode-cn.com/problems/target-sum/)

# 原文
给定一个非负整数数组，a1, a2, ..., an, 和一个目标数，S。现在你有两个符号 + 和 -。对于数组中的任意一个整数，你都可以从 + 或 -中选择一个符号添加在前面。  
返回可以使最终数组和为目标数 S 的所有添加符号的方法数。  
示例：  
输入：nums: [1, 1, 1, 1, 1], S: 3  
输出：5  
解释：  
-1+1+1+1+1 = 3  
+1-1+1+1+1 = 3  
+1+1-1+1+1 = 3  
+1+1+1-1+1 = 3  
+1+1+1+1-1 = 3  
一共有5种方法让最终目标和为3。  
提示：  
数组非空，且长度不会超过 20 。  
初始的数组的和不会超过 1000 。  
保证返回的最终结果能被 32 位整数存下。  

# 思路
- ### **动态规划**
  首先尝试了暴力法解题，中间变量很容易超出范围，且复杂度非常高；找到此题的规律发现需要在数组中找到target就是为了找到数组中正元素和负元素，其中正元素抵消掉负元素以后还剩下target，根据公式（p+n=sum,p-n=target,2p=sum+target），所以只要找到数组中组成和为p的子集的个数；使用动态规划，每个数字的子集个数根据当前个数加上dp[j-nums[i]]的公式来决定；由于每个数组元素只能使用一次，如果正向遍历的话会多次使用，所以必须dp数组逆向遍历，导致第一次遍历只有dp[0+nums[0]]得到+1，后面开始慢慢变多。92 54

# 代码
- C++ 动态规划
```
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sums = 0;
        for(int i=0;i<nums.size();i++){
            sums += nums[i];
        }
        if(sums<S||(sums+S)%2!=0) return 0;
        else return func(nums,(sums+S)/2);
    }
private:
    int func(vector<int>& nums,int target){
        vector<int> dp(target+1,0);
        dp[0] = 1;
        for(int i=0;i<nums.size();i++){
            for(int j=target;j>=nums[i];j--){
                dp[j] += dp[j-nums[i]];
            }
        }
        return dp[target];
    }
};
```