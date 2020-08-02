# 题目链接
[leetcode 238](https://leetcode-cn.com/problems/product-of-array-except-self/)

# 原文
给你一个长度为 n 的整数数组 nums，其中 n > 1，返回输出数组 output ，其中 output[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积。  
示例:  
输入: [1,2,3,4]  
输出: [24,12,8,6]  
提示：题目数据保证数组之中任意元素的全部前缀元素和后缀（甚至是整个数组）的乘积都在 32 位整数范围内。  
说明: 请不要使用除法，且在 O(n) 时间复杂度内完成此题。  
进阶：  
你可以在常数空间复杂度内完成这个题目吗？（ 出于对空间复杂度分析的目的，输出数组不被视为额外空间。）

# 思路
- ### **正反迭代**
  不允许使用除法，同时有需要On的计算乘积，所以考虑将除此位的其余元素的成绩看作是该数左边位置的数累积以及右边位置的数累积，所以建立result向量，首先正向计算累积，从第二位开始计算0~i-1的累积，然后反向迭代，此时不能使用reuslt来记录累积，会重复计算正向的结果，使用新的temp变量即可。87 73

# 代码
- C++ 正反迭代
```
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size(),1);
        for(int i=1;i<nums.size();i++){
            result[i] = result[i-1]*nums[i-1];
        }
        int temp = 1;
        for(int i=nums.size()-2;i>=0;i--){
            temp *= nums[i+1];
            result[i] = result[i]*temp;
        }
        return result;
    }
};
```
