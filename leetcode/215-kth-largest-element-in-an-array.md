# 题目链接
[leetcode 215](https://leetcode-cn.com/problems/kth-largest-element-in-an-array/)

# 原文
在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。  
示例 1:  
输入: [3,2,1,5,6,4] 和 k = 2  
输出: 5  
示例 2:  
输入: [3,2,3,1,2,4,5,5,6] 和 k = 4  
输出: 4  
说明:  
你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。

# 思路
- ### **最小堆**
  使用最小堆实时记录K个最大的值，其中顶部固定放的是最大值里面的最小值，最小堆的创建方法是priority_queue<int,vector<int>,greater<int>>，最大堆的话使用的是smaller，维护方法是如果个数没有达到，直接放入，如果达到，则判断是否比顶部的最小的值大，如果大，则替代顶部的值。60 6

# 代码
- C++ 最小堆
```
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> q;
        for(int i=0;i<nums.size();i++){
            if(q.size()<k){
                q.push(nums[i]);
            }
            else if(nums[i]>q.top()){
                q.pop();
                q.push(nums[i]);
            }
        }
        return q.top();
    }
};
```
