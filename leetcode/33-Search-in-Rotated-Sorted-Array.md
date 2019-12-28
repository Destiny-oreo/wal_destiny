# 题目链接
[leetcode 33](https://leetcode-cn.com/problems/search-in-rotated-sorted-array/)

# 原文
假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。

你可以假设数组中不存在重复的元素。

你的算法时间复杂度必须是 O(log n) 级别。

示例 1:

输入: nums = [4,5,6,7,0,1,2], target = 0
输出: 4
示例 2:

输入: nums = [4,5,6,7,0,1,2], target = 3
输出: -1



# 思路
- ### **新二分查找**
  使用二分递归查找（传入左右边界），结束条件为左边界大于右边界 或者 当左右边界的中间值等于目标值时返回坐标，否则进行分类讨论：  
  当中间值大于目标值：当**左边界小于等于中间值**，说明左半段是递增的，旋转中心在右边，目标小于中间值可能在左边也可能在右边，当目标值大于等于左边界，递归查找左半段，当目标值小于左边界，递归查找右半段；；；当**左边界大于中间值**，说明左半段有突变点，旋转中心在左半段，递归查找左半段即可。（当左边界等于中间值时，说明长度为2，坐标为0 1，当目标值大于中间值（左边界）时目标值只可能在右边，查找右半段，所以只能放在第一种情况）    
  当中间值小于目标值：当**左边界小于等于中间值**，说明左半段递增，直接查找右半段即可；；；当**左边界大于中间值**，说明旋转中心在左半段，右半段是递增的，目标值比中间值大则左右半段都有可能，当目标值大于等于左边界，在左半段查找，当目标值小于左边界，在右半段查找。（当左边界等于中间值时下标为0 1两位，目标值大于中间值（左边界），在右半段搜索即可）90 74

# 代码
- C++ 新二分查找
```
class Solution {
public:
    int search(vector<int>& nums, int target) {
        return sortarray(nums,target,0,nums.size()-1);
    }
private:
    int sortarray(vector<int>& nums,int target,int left,int right){
        if(left>right)  return -1;
        int mid = left+(right-left)/2;
        if(nums[mid]==target)   return mid;
        else if(nums[mid]>target){
            if(nums[left]>nums[mid]){
                return sortarray(nums,target,left,mid-1);
            }
            else{
                if(nums[left]<=target)   return sortarray(nums,target,left,mid-1);
                else    return sortarray(nums,target,mid+1,right);
            }
        }
        else{//(nums[mid]<target)
            if(nums[left]<=nums[mid])    return sortarray(nums,target,mid+1,right);
            else{
                if(target>=nums[left])   return sortarray(nums,target,left,mid-1);
                else    return sortarray(nums,target,mid+1,right);
            }
        }
    }
};
```