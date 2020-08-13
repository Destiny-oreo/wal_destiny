# 题目链接
[leetcode 416](https://leetcode-cn.com/problems/partition-equal-subset-sum/)

# 原文
给定一个只包含正整数的非空数组。是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。  
注意:  
每个数组中的元素不会超过 100  
数组的大小不会超过 200  
示例 1:  
输入: [1, 5, 11, 5]  
输出: true  
解释: 数组可以分割成 [1, 5, 5] 和 [11].  
示例 2:  
输入: [1, 2, 3, 5]  
输出: false  
解释: 数组不能分割成两个元素和相等的子集.  

# 思路
- ### **动态规划**
  要敢做！不要怕时间和空间复杂度！整天想着On要死的！此题首先把一些特殊情况处理完，然后计算综合，奇数的话直接返回；偶数的话直接建立一个大小为和的一半+1的向量，开始使用动态规划；首先遍历各个数组元素，如果符合或直接不符合要求进行判断，然后开始遍历dp数组，由于需要判断dp[s]，且所有元素只能使用一次，所以从大到小遍历，结束条件为此位比数组元素大，然后进行dp[j-nums[i]]的判断（dp[0]已经初始化为true），同时为了防止变成true已经再次被影响，使用dp[j]||上面的操作。61 96

# 代码
- C++ 动态规划
```
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if(nums.size()<=1)  return false;
        else if(nums.size()==2) return nums[0]==nums[1];
        int sum = 0;
        for(int i=0;i<nums.size();i++)  sum+=nums[i];
        if(sum%2!=0)    return false;
        sum = sum/2;
        vector<bool> dp(sum+1,false);
        dp[0] = true;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>sum) return false;
            else if(nums[i]==sum)   return true;
            for(int j=sum;j>=nums[i];j--){
                dp[j] = dp[j]||dp[j-nums[i]];
            }
            if(dp[sum]) return true;
        }
        return dp[sum];
    }
};
```