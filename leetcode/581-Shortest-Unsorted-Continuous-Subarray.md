# 题目链接
[leetcode 581](https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray/)

# 原文
给定一个整数数组，你需要寻找一个连续的子数组，如果对这个子数组进行升序排序，那么整个数组都会变为升序排序。
你找到的子数组应是最短的，请输出它的长度。
示例 1:
输入: [2, 6, 4, 8, 10, 9, 15]
输出: 5
解释: 你只需要对 [6, 4, 8, 10, 9] 进行升序排序，那么整个表都会变为升序排序。
说明 :
输入的数组长度范围在 [1, 10,000]。
输入的数组可能包含重复元素 ，所以升序的意思是<=。

# 思路
- ### 双指针
正反两次遍历（或者可以合为一次），正序遍历时依次记录最大值，如果当前值小于最大值说明此位以左都需要重新排序，记为right(初始为num[0]);同理反序遍历时记录最小值，如果当前值大于最小值说明此位以右都需要重新排序，即为left(初始为num[n-1])。最后查看双指针值，左右right>left说明存在需要重新遍历的点，返回right-left+1。

# 代码
- C++ 双指针法
```
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        if(n<=1)    return 0;
        int mn = nums[n-1],mx = nums[0],right = 0,left = n-1;
        for(int i=1;i<n;i++){
            if(nums[i]<mx)  right = i;
            else    mx = nums[i];
        }
        for(int i=n-2;i>=0;i--){
            if(nums[i]>mn)  left = i;
            else mn = nums[i];
        }
        return right>left?right-left+1:0;
    }
};
```