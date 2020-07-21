# 题目链接
[leetcode 167](https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/)

# 原文
给定一个已按照升序排列 的有序数组，找到两个数使得它们相加之和等于目标数。  
函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2。  
说明:  
返回的下标值（index1 和 index2）不是从零开始的。  
你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。  
示例:  
输入: numbers = [2, 7, 11, 15], target = 9  
输出: [1,2]  
解释: 2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。

# 思路
- ### **双指针**
  由于是排序数组，所以可以考虑两头的双指针操作，首先左右边界设置好初始指针，然后和目标值进行比较，小的话左指针右移，大的话右指针左移，一定可以找到符合条件的答案。（return vector<int>(a,a+2);也可以使用数组装答案，然后使用vector初始化来返回答案）100 41

# 代码
- C++ 双指针
```
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result(2,-1);
        if(numbers.size()<=1)   return result;
        int left = 0,right = numbers.size()-1;
        while(left!=right){
            if(numbers[left]+numbers[right]==target)    break;
            else{
                if(numbers[left]+numbers[right]<target) left++;
                else    right--;
            }
        }
        result[0] = left+1,result[1] = right+1;
        return result;
    }
};
```
