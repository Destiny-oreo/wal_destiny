# 题目链接
[leetcode 90](https://leetcode-cn.com/problems/subsets-ii/)

# 原文
给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例:

输入: [1,2,2]
输出:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]

# 思路
- ### **递归回溯**
  使用递归回溯解决每一位数字选与不选两种选择，由于整数数组可能包含重复元素，所以使用set来解决重复的问题（由于set中加入的是向量，所以对于原数组首先需要排序，否则相同的组合但是位置不同对于set来说就无法识别了），空集首先加入，然后调用回溯函数，回溯的结束条件为当前位到达数组最后，直接返回，否则说明当前位是有效的，将当前位数字放入items，进行查重，如果不重复说明是有效的一个答案，放入结果中并在查重集合中加入，否则说明此结果重复，删除后进行下面的递归。88 6

# 代码
- C++ 递归回溯
```
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        result.push_back(items);
        generate(nums,0);
        return result;
    }
private:
    vector<int> items;
    vector<vector<int>> result;
    set<vector<int>> repeat;
    void generate(vector<int>& nums,int k)
    {
        if(k>=nums.size())  return;
        items.push_back(nums[k]);
        if(repeat.find(items)==repeat.end()){
            result.push_back(items);
            repeat.insert(items);
            generate(nums,k+1);
        }
        items.pop_back();
        generate(nums,k+1);
    }
};
```
