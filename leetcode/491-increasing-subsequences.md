# 题目链接
[leetcode 491](https://leetcode-cn.com/problems/increasing-subsequences/)

# 原文
给定一个整型数组, 你的任务是找到所有该数组的递增子序列，递增子序列的长度至少是2。  
示例:  
输入: [4, 6, 7, 7]  
输出: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]  
说明:  
给定数组的长度不会超过15。  
数组中的整数范围是 [-100,100]。  
给定数组中可能包含重复数字，相等的数字应该被视为递增的一种情况。

# 思路
- ### **深搜**
  经典深搜，每一位先判断以后放入，递归以后再取出，进行下一层循环；由于不能有重复的序列，所以使用set，最后转换成向量的方式是直接新建vector<vector<int>>(res.begin(),res.end())来返回；对于深搜函数，首先判断向量是否大于等于2，是的话说明有递增序列，直接加入set不用查重，然后开始以此层递归，对于某一层index，需要先判断传入是temp是否需要加入set中，然后从此位开始往后循环递归，对于每一位，首先判断是否可以加入向量中，不可以加入的条件为当前位置小于向量的最后一位（前提向量不为空），选择加入以后进行下一层递归，结束以后把此位加入的情况全考虑了，然后弹出，考虑不加入此位的所有情况。34 61

# 代码
- C++ 深搜
```
class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> temp;
        dfs(nums,0,temp);
        return vector<vector<int>>(res.begin(),res.end());
    }
private:
    set<vector<int>> res;
    void dfs(vector<int>& nums,int index,vector<int>& temp){
        if(temp.size()>=2)  res.insert(temp);
        for(int j=index;j<nums.size();j++){
            if(!temp.empty()&&nums[j]<temp.back())  continue;
            temp.push_back(nums[j]);
            dfs(nums,j+1,temp);
            temp.pop_back();
        }
    }
};
```