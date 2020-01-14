# 题目链接
[leetcode 78](https://leetcode-cn.com/problems/subsets/)

# 原文
给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例:

输入: nums = [1,2,3]
输出:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

# 思路
- ### **递归回溯**
  数组中不含重复元素，所以对于每一位可以不用判断直接进行选与不选两种操作；首先设置好结果向量和中间向量，然后开始递归添加，传入原数组和遍历到的位数，对于递归回溯函数：先判断是否已经处理完所有位数，如果处理完此位已经到达数组的长度，所以如果等于size时将中间向量放入结果向量，然后返回，否则将此位放入中间向量并递归下去，然后回溯将中间向量弹出，然后再传入，总体效果是对于每一位都实现了选与不选的操作，最后一位再次弹出时所有数组都为空，空集最后也放入了结果向量。100 9
- ### **层次遍历**
  遇到一个新的数就把所有子集加上该数构成新的子集放入最终结果中，最初子集为空集（为任何数组的子集），如果没有新的数就返回，否则遇到新的数就把原有子集加上该数立马放入结果子集，然后把新数弹出以保存原有子集，每一层（即遇到的每一个新数）都会将子集数量翻倍；在代码体现的思路便是首先放入空集，然后遍历，判断是否还有新数，没有的话返回，否则每遇到一个新数，加入中间向量并放入子集，弹出保存原有子集，然后下一层前面所有子集都会伸向这个新的数构成新的子集，后面依次如此，每次加入新的数的子集数等于不加上这个新数的子集数。100 10

# 代码
- C++ 递归回溯
```
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        //result.push_back(items);
        DFS(nums,0);
        return result;
    }
private:
    vector<vector<int>> result;
    vector<int> items;
    void DFS(vector<int>& nums,int i){
        if(i==nums.size()){
            result.push_back(items);
            return;
        }
        else{
            items.push_back(nums[i]);
            DFS(nums,i+1);
            items.pop_back();
            DFS(nums,i+1);
        }
    }
};
```
- C++ 层次遍历
```
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        result.push_back(items);
        DFS(nums,0);
        return result;
    }
private:
    vector<vector<int>> result;
    vector<int> items;
    void DFS(vector<int>& nums,int i){
        if(i==nums.size()){
            return;
        }
        else{
            items.push_back(nums[i]);
            result.push_back(items);
            DFS(nums,i+1);
            items.pop_back();
            DFS(nums,i+1);
        }
    }
};
```