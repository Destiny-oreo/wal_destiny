# 题目链接
[leetcode 300](https://leetcode-cn.com/problems/longest-increasing-subsequence/)

# 原文
给定一个无序的整数数组，找到其中最长上升子序列的长度。  
示例:  
输入: [10,9,2,5,3,7,101,18]  
输出: 4   
解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。  
说明:  
可能会有多种最长上升子序列的组合，你只需要输出对应的长度即可。  
你算法的时间复杂度应该为 O(n2) 。  
进阶: 你能将算法的时间复杂度降低到 O(n log n) 吗?

# 思路
- ### **动态规划-On²**
  使用时间复杂度较大的动态规划算法，即每遍历到一个新的位置，依次与前面所有数字进行比较，找打比本位置小的数（构成递增）则取较大的一个序列长度，并实时记录最大长度为reuslt。6 9

- ### **二分查找**
  二分查找用在更新最长的递增序列上，初始化dp数组用来装目标序列，第一位初始化为nums[0]，后面逐个遍历，每遇到一个新的数，首先判断是否比当前递增序列的末尾大，大的话直接加一位，否则进行二分查找来找到需要替换的位置；由于需要替换的那一个位置的特点是比前一位大但是比此位小，所以进行更新l或者r时先判断当前位置是否大于dp[mid]，大的话mid+1，否则mid-1（理由：如果计算mid时靠左，和当前位置相等时需要替换当前位置，所以最后一定需要右边界r越界才能结束循环，即r=mid-1，所以等于的情况和小于的情况一样；最后之所以使用l来更新时因为如果推出循环时左边界更新为mid+1的情况是数值比当前位置大，应更新在后一个即l，右边界更新为mid-1的情况是小于等于，应更新在此位置即不动的l）。100 80

# 代码
- C++ 动态规划-On²
```
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==0)  return 0;
        vector<int> dp(nums.size(),1);
        int result = 1;
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]) dp[i] = max(dp[i],dp[j]+1);
                result = max(result,dp[i]);
            }
        }
        return result;
    }
};
```
- C++ 二分查找
```
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==0)  return 0;
        vector<int> dp(nums.size(),nums[0]);
        int result = 0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>dp[result]){
                result++;
                dp[result] = nums[i];
            }
            else{
                int l = 0,r = result;
                while(l<=r){
                    int mid = l + (r-l)/2;
                    if(nums[i]>dp[mid])   l = mid+1;
                    else    r = mid-1;
                }
                if(l<0)    l = 0;
                dp[l] = nums[i];
            }
        }
        return result+1;
    }
};
```