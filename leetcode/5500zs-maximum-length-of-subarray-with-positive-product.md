# 题目链接
[leetcode 5500zs](https://leetcode-cn.com/problems/maximum-length-of-subarray-with-positive-product/) 乘积为正数的最长子数组长度

# 原文
给你一个整数数组 nums ，请你求出乘积为正数的最长子数组的长度。  
一个数组的子数组是由原数组中零个或者更多个连续数字组成的数组。  
请你返回乘积为正数的最长子数组长度。  
示例  1：  
输入：nums = [1,-2,-3,4]  
输出：4  
解释：数组本身乘积就是正数，值为 24 。  
示例 2：  
输入：nums = [0,1,-2,-3,-4]  
输出：3  
解释：最长乘积为正数的子数组为 [1,-2,-3] ，乘积为 6 。  
注意，我们不能把 0 也包括到子数组中，因为这样乘积为 0 ，不是正数。  
示例 3：  
输入：nums = [-1,-2,-3,0,1]  
输出：2  
解释：乘积为正数的最长子数组是 [-1,-2] 或者 [-2,-3] 。  
示例 4：  
输入：nums = [-1,2]  
输出：1  
示例 5：  
输入：nums = [1,2,3,5,-6,4,0,10]  
输出：4  
提示：  
1 <= nums.length <= 10^5  
-10^9 <= nums[i] <= 10^9  

# 思路
- ### **204周赛-向量**
  寻找连续乘积正数的最长长度，关键点是找到负数的位置，同时实时记录最大长度；创建向量专门装在负数的下标，没有负数的话长度为下标减去pre（初始化为-1，弥补下标从0开始的误差）；首先判断是否为特殊情况，负数的话向量中push_back下标位置，为0的话清空所有，pre初始化为此下标，然后判断负数的个数，偶数的话从开头pre到此下标均可以，奇数的话需要从第一个负数的位置开始计算，即vec.front()。100 100   

# 代码
- C++ 204周赛-向量
```
class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int pre = -1,result = 0;
        vector<int> neg;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0)   neg.push_back(i);
            else if(nums[i]==0){
                pre = i;
                neg.clear();
            }
            if(neg.size()%2==0) result = max(result,i-pre);
            else    result = max(result,i-neg.front());
        }
        return result;
    }
};
```