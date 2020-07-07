# 题目链接
[leetcode 136](https://leetcode-cn.com/problems/single-number/)

# 原文
给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。

说明：

你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

示例 1:  
输入: [2,2,1]
输出: 1  

示例 2:  
输入: [4,1,2,1,2]
输出: 4

# 思路
- ### **位运算**
  只有一个元素只出现一次，其余元素都出现了偶数次，所以可以利用位运算中的异或来解决，因为异或（初始为0)两次一样的数字后会变回初始值0，即0^1为1，0^0为0，所以循环对每个位进行异或得到的最后结果就是出现一次的那个数字（相当于只有它没有被抵消）。63 63

# 代码
- C++ 位运算
```
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for(int i=0;i<nums.size();i++){
            result =result^nums[i];
        }
        return result;
    }
};
```
