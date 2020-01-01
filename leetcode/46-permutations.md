# 题目链接
[leetcode 46](https://leetcode-cn.com/problems/permutations/)

# 原文
给定一个没有重复数字的序列，返回其所有可能的全排列。

示例:

输入: [1,2,3]
输出:  
[  
  [1,2,3],  
  [1,3,2],  
  [2,1,3],  
  [2,3,1],  
  [3,1,2],  
  [3,2,1]  
]

# 思路
- ### **递归回溯**
  依旧为回溯算法，依靠专门的visited数组进行回溯判断，首先从头开始装进items向量，然后回溯弹出该位，记录在visited里面，每次访问时仅访问没有被访问过的，所以不同的排列组合最终结束条件是items的长度达到nums长度，又由于每次加入时多进行了判断，所以不会存在重复的现象，所有的排列组合是靠回溯完成的，因为共有2的n此方，即每一位都有两种可能，所以体现为放与不放两种操作，不放的由于没有记录在visited里面，所以在吧后面的作为头部加入以后会重新考虑此位（刚刚不放的这一位），从而遍历所有的排列组合。65 51

# 代码
- C++ 递归回溯
```
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> items;
        int visited[nums.size()] = {0};
        DFS(nums,items,visited);
        return result;
    }
private:
    vector<vector<int>> result;
    void DFS(vector<int> &nums,vector<int> &items,int visited[]){
        if(items.size()==nums.size())   result.push_back(items);
        for(int i=0;i<nums.size();i++){
            if(visited[i]==0){
                items.push_back(nums[i]);
                visited[i] = 1;
                DFS(nums,items,visited);
                items.pop_back();
                visited[i] = 0;
            }
        }
    }
};