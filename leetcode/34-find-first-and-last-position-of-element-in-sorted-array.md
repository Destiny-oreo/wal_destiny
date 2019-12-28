# 题目链接
[leetcode 34](https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/)

# 原文
给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

你的算法时间复杂度必须是 O(log n) 级别。

如果数组中不存在目标值，返回 [-1, -1]。

示例 1:

输入: nums = [5,7,7,8,8,10], target = 8
输出: [3,4]
示例 2:

输入: nums = [5,7,7,8,8,10], target = 6
输出: [-1,-1]

# 思路
- ### **递归二分查找**
  二分查找标准模板的基础上加上判断是否是两边边界的情况，左右边界的查找需要两个单独的二分查找函数来实现，将得到的结果push进结果向量即可。左边界搜索时当没有搜索到返回-1（即左边界超过右边界时），当中间值等于目标值且中间值即为左边界时（左边没有数或者左边的数不等于目标值）返回下标，否则当目标值小于等于中间值搜索左半段，当目标值大于中间值搜索右半段；；右边界搜索时同理，当中间值等于目标值且中间值即为右边界时（右边没有数或者右边的数不等于目标值）返回中间值下标，否则当目标值大于等于中间值搜索右半段，当目标值小于中间值搜索左半段。50 74
- ### **循环二分查找**
  思路和递归完全一致，但性能更加优。使用左右边界进行循环（begin<=end),计算中间值，符合时直接返回，不符合时改变左右边界继续进行循环，最后退出循环时则代表没有找到，返回-1。需要注意的是，递归养成了将右边界设置为mid-1的习惯，如此做法循环结束条件必须有=，否则无法验证左右边界重合的情况，如果没有=，则右边界必须赋值成mid。88 94

# 代码
- C++ 递归二分查找
```
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        int left = leftbound(nums,target,0,nums.size()-1);
        result.push_back(left);
        int right = rightbound(nums,target,0,nums.size()-1);
        result.push_back(right);
        return result;
    }
private:
    int leftbound(vector<int>& nums,int target,int begin,int end){
        if(begin>end)   return -1;
        int mid = begin+(end-begin)/2;
        if(nums[mid]==target&&(mid==0||target>nums[mid-1]))   return mid;
        else if(target<=nums[mid])  return leftbound(nums,target,0,mid-1);
        else    return leftbound(nums,target,mid+1,end);
    }
    int rightbound(vector<int>& nums,int target,int begin,int end){
        if(begin>end)   return -1;
        int mid = begin+(end-begin)/2;
        if(nums[mid]==target&&(mid==nums.size()-1||target<nums[mid+1]))   return mid;
        else if(target>=nums[mid])  return rightbound(nums,target,mid+1,end);
        else    return rightbound(nums,target,0,mid-1);
    }
};
```
- C++ 循环二分查找
```
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        int left = leftbound(nums,target,0,nums.size()-1);
        result.push_back(left);
        int right = rightbound(nums,target,0,nums.size()-1);
        result.push_back(right);
        return result;
    }
private:
    int leftbound(vector<int>& nums,int target,int begin,int end){
        while(begin<=end){
            int mid = begin+(end-begin)/2;
            if(nums[mid]==target&&(mid==0||target!=nums[mid-1]))    return mid;
            else if(target<=nums[mid])  end = mid-1;
            else    begin = mid+1;
        }
        return -1;
    }
    int rightbound(vector<int>& nums,int target,int begin,int end){
        while(begin<=end){
            int mid = begin+(end-begin)/2;
            if(nums[mid]==target&&(mid==nums.size()-1||target!=nums[mid+1]))    return mid;
            else if(target>=nums[mid])  begin = mid+1;
            else    end = mid-1;
        }
        return -1;
    }
};
```