# 题目链接
[leetcode 5471zs](https://leetcode-cn.com/problems/maximum-number-of-non-overlapping-subarrays-with-sum-equals-target/)

# 原文
给你一个数组 nums 和一个整数 target 。  
请你返回 非空不重叠 子数组的最大数目，且每个子数组中数字和都为 target 。  
示例 1：  
输入：nums = [1,1,1,1,1],  target = 2  
输出：2  
解释：总共有 2 个不重叠子数组（加粗数字表示） [1,1,1,1,1] ，它们的和为目标值 2 。  
示例 2：  
输入：nums = [-1,3,5,1,4,2,-9], target = 6  
输出：2  
解释：总共有 3 个子数组和为 6 。  
([5,1], [4,2], [3,5,1,4,2,-9]) 但只有前 2 个是不重叠的。  
示例 3：  
输入：nums = [-2,6,6,3,5,4,1,2,8], target = 10  
输出：3  
示例 4：  
输入：nums = [0,0,0], target = 0  
输出：3  
提示：     
1 <= nums.length <= 10^5  
-10^4 <= nums[i] <= 10^4  
0 <= target <= 10^6  

# 思路
- ### **201周赛-哈希 动态规划 前缀和**
  周赛时写的是针对子序列的做法，没有达到连续子数组的要求，审错题啦；由于子数组，所以动态规划考虑以该位结尾（周赛时候后来发现审错题时第一反应竟然是以该位开始的写法，又错啦），每到一位，计算从头到现在的累加和，再减去目标值得到差值，在hash中寻找是否有前缀和符合要求（所以需要建立哈希表来实时记录开头到每一位的累加和），找到的话说明dp[i]是在dp[j]的基础上加1，同时要和dp[i-1]取最大值，如果没有找到直接等于dp[i-1]即可。100 100   
  使用auto it = map.find()来找到map中的位置（it->second)

# 代码
- C++ 201周赛-哈希 动态规划 前缀和
```
class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        map<int,int> hash;
        vector<int> dp(nums.size()+1,0);
        hash[0] = 0;
        int sum=0;
        for(int i=1;i<=nums.size();i++){
            sum+=nums[i-1];
            auto it = hash.find(sum-target);
            if(it==hash.end()) dp[i] = dp[i-1];
            else    dp[i] = max(dp[i-1],dp[it->second]+1);
            hash[sum] = i;
        }
        return dp[nums.size()];
    }
};
```
