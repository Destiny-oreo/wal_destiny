# 题目链接
[leetcode 面试0803](https://leetcode-cn.com/problems/magic-index-lcci/)

# 原文
魔术索引。 在数组A[0...n-1]中，有所谓的魔术索引，满足条件A[i] = i。给定一个有序整数数组，编写一种方法找出魔术索引，若有的话，在数组A中找出一个魔术索引，如果没有，则返回-1。若有多个魔术索引，返回索引值最小的一个。  
示例1:  
 输入：nums = [0, 2, 3, 4, 5]  
 输出：0  
 说明: 0下标的元素为0  
示例2:  
 输入：nums = [1, 1, 1]  
 输出：1   
说明:  
nums长度在[1, 1000000]之间  
此题为原书中的 Follow-up，即数组中可能包含重复元素的版本

# 思路
- ### **遍历**
  暴力秋季，可考虑```i = max(nums[i],i+1);```，因为是递增序列，所以当当前位置不构成魔术索引时，且当当前位置的值比较大时，则说明到当前位置值的索引处之前不可能出现魔术索引。28 69

# 代码
- C++ 遍历
```
class Solution {
public:
    int findMagicIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(nums[i] == i){
                return i;
            }
        }
        return -1;
    }
};
```
