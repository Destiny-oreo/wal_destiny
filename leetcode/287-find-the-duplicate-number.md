# 题目链接
[leetcode 287](https://leetcode-cn.com/problems/find-the-duplicate-number/)

# 原文
给定一个包含 n + 1 个整数的数组 nums，其数字都在 1 到 n 之间（包括 1 和 n），可知至少存在一个重复的整数。假设只有一个重复的整数，找出这个重复的数。  
示例 1:  
输入: [1,3,4,2,2]  
输出: 2  
示例 2:  
输入: [3,1,3,4,2]  
输出: 3   
说明：  
不能更改原数组（假设数组是只读的）。  
只能使用额外的 O(1) 的空间。  
时间复杂度小于 O(n2) 。   
数组中只有一个重复的数字，但它可能不止重复出现一次。

# 思路
- ### **快慢指针**
  由于存在一个重复的数字，且数组下标和数值范围基本是一样的，所以使用num[index]来作为新的index，且由于重复的数字会造成一个环，所以使用环的思想来找到重复的位置一直数字；使用快慢指针，快指针每次更新两次，慢指针更新一次，相遇时慢指针归位，然后咦同步的速度再次遍历即可扎到重复的点。84 34  

# 代码
- C++ 快慢指针
```
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0,fast = 0;
        while(true){
            fast = nums[nums[fast]];
            slow = nums[slow];
            if(fast == slow){
                slow = 0;
                while(fast!=slow){
                    fast = nums[fast];
                    slow = nums[slow];
                }
                return fast;
            }
        }
        return 0;
    }
};
```