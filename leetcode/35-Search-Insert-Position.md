# 题目链接
[leetcode 35](https://leetcode-cn.com/problems/search-in-rotated-sorted-array/)

# 原文
给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

你可以假设数组中无重复元素。

示例 1:

输入: [1,3,5,6], 5
输出: 2
示例 2:

输入: [1,3,5,6], 2
输出: 1
示例 3:

输入: [1,3,5,6], 7
输出: 4
示例 4:

输入: [1,3,5,6], 0
输出: 0

# 思路
- ### **新二分查找**
  使用二分循环查找，在寻找的数存在于数组中时直接使用经典二分查找即可，当不存在时需要进行修改判断（但不可影响存在时的二分查找总框架），此时结束条件不再是没有找到（left>right)而是找到了一个位置（一定存在），所以先设置结果为-1，当结果找到以后便不再为-1，退出循环；循环开始，和经典二分一样，先计算中间值，若直接相等，赋值给结果，自动退出，若**不相等**，此时在经典二分传入左右半段时需要判断（有可能不在左右半段，在中间分界处），**传入左半段**的条件为小于中间值且大于中间左边一个的值（边界条件为中间值就是第一个，所以附加在条件中，用||连接），传入左半段，否则说明目标值不在数组中，且存在于中间值与中间值左边数之间，把中间坐标赋值给结果自动退出；**传入右半段**的条件为大于中间值且小于中间右边一个的值（边界条件为中间值就是最后一个），传入右半段，否则说明目标值存在于中间值与中间右边一个数之间，把中间右边一个数的左边赋值给结果自动退出。（如此即可保证目标值一定在搜索的区间内，且有保留了经典二分的结构）64 88
- ### **递归**
  尝试使用递归强行完成，递归相对于循环来说时间会增加一些，但是空间复杂度可能要降低一些；首先是判断当left大于right的时候，说明说明中间值本是和left相同，但是还是要小一些，所以判断位置应该代表left；接下来正常计算mid即可，相等时直接返回，当大于时需要先判断左右是否相等，相等则代表未找到，在后面一位即可，否则递归；当小于时也判断是否相等或者已经为0位置，直接返回mid即可，否则递归。36 100 （使用上述二分查找思路来完成递归，时间上更加快）96 100

# 代码
- C++ 新二分查找
```
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left=0,right=nums.size()-1,result=-1;
        while(result==-1){
            int mid = left+(right-left)/2;
            if(nums[mid]==target)   result = mid;
            else if(target<nums[mid])   {
                if(mid==0||target>nums[mid-1])  result = mid;
                else    right = mid-1;
            }
            else{
                if(mid==nums.size()-1||target<nums[mid+1])  result = mid+1;
                else    left = mid+1;
            }
        }
        return result;
    }
};
```
- C++ 递归
```
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return func(nums,0,nums.size()-1,target);
    }
private:
    int func(vector<int>& nums,int left,int right,int target){
        if(left>right)  return left;
        int mid = left +(right-left)/2;
        if(nums[mid]==target)   return mid;
        else if(target>nums[mid]){
            if(left==right) return right+1;
            else    return func(nums,mid+1,right,target);
        }
        else{
            if(left==right||mid==0) return left;
            else    return func(nums,left,mid-1,target);
        }
    }
};
```