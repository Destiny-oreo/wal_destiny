# 题目链接
[leetcode 1](https://leetcode-cn.com/problems/two-sum/)

# 原文
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

示例:

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]

# 思路
- ### **哈希表**
  本打算用双指针来寻找，但发现本题数组没有排序且需要返回数组下标，则无法排序后使用双指针；采用哈希表记录遍历过的数据，每遇到新的数据则在哈希表中查找是否存在另一个数使和为target，若没有则把当前数据与下标放入哈希表中（所以查找时不存在使用两次当前数的情况），若存在则把当前下标和另一个数的下标放入result数组进行返回。（由于需要返回下标，所以哈希表中的另一个元素必须为对应的下标而不是出现的次数或是否出现）

# 代码
- C++ 哈希表
```
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> hash;
        vector<int> result;
        for(int i=0;i<nums.size();i++){
            if(hash.find(target-nums[i])!=hash.end()){
                result.push_back(i);
                result.push_back(hash[target-nums[i]]);
                break;
            }
            hash[nums[i]] = i;
        }
        return result;
    }
};
```
