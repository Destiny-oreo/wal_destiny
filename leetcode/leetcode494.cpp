/**
494. 目标和
给定一个非负整数数组，a1, a2, ..., an, 和一个目标数，S。现在你有两个符号 + 和 -。对于数组中的任意一个整数，你都可以从 + 或 -中选择一个符号添加在前面。

返回可以使最终数组和为目标数 S 的所有添加符号的方法数。

示例 1:

输入: nums: [1, 1, 1, 1, 1], S: 3
输出: 5
解释: 

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

一共有5种方法让最终目标和为3。
 */
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {   //dp[i][j] = d[i-1][j]+dp[i-1][j-nums[i]]
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum<S||(S+sum)%2!=0) return 0;
        else return func(nums,(S+sum)/2);
    }
private:
    int func(vector<int>& nums,int sum){
        vector<int> dp(sum+1,0);
        dp[0] = 1;
        for(int i=0;i<nums.size();i++){
            for(int j=sum;j>=nums[i];j--){
                dp[j] = dp[j]+dp[j-nums[i]];
            }
        }
        return dp[sum];
    }
};