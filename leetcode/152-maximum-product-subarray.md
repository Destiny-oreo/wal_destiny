# 题目链接
[leetcode 152](https://leetcode-cn.com/problems/maximum-product-subarray/)

# 原文
给你一个整数数组 nums ，请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。  
示例 1:  
输入: [2,3,-2,4]  
输出: 6  
解释: 子数组 [2,3] 有最大乘积 6。  
示例 2:  
输入: [-2,0,-1]  
输出: 0  
解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。  

# 思路
- ### **动态规划**
  使用动态规划实时记录需要的最大值，同时为了防止负负得正的最大值错过，同时需要记录最小值，所以每遍历一位，需要拿之前的最大最小值乘以当前位置的值，然后为了防止有0出现，在当前位置、最小值、最大值之前寻找真正的最大最小值，然后记录最大值即可。40 6

# 代码
- C++ 动态规划
```
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        if(n<1) return 0;
        int result = INT_MIN,mins=1,maxs=1;
        for(int i=0;i<n;i++){
            int tempmin = mins*nums[i];
            int tempmax = maxs*nums[i];
            mins = min(nums[i],min(tempmin,tempmax));
            maxs = max(nums[i],max(tempmin,tempmax));
            result = max(result,maxs);
        }
        return result;
    }
};
```
