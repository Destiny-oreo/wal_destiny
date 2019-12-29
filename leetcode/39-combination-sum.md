# 题目链接
[leetcode 39](https://leetcode-cn.com/problems/combination-sum/)

# 原文
给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。  
candidates 中的数字可以无限制重复被选取。  
说明：  
所有数字（包括 target）都是正整数。
解集不能包含重复的组合。   
示例 1:  
输入: candidates = [2,3,6,7], target = 7,
所求解集为:
[
  [7],
  [2,2,3]
]  
示例 2:  
输入: candidates = [2,3,5], target = 8,
所求解集为:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]

# 思路
- ### **递归回溯+剪枝（深搜）**
  与背包问题有些区别，每个数字可以被无限制重复选取（即深搜，一直相加直到超过，然后弹出）。首先定义一些必要的变量（result和items变量），可选择对原数组进行排序（方便后面进行剪枝，即当当前数加进来以后当前的递归就可以不用考虑后面的数了），传入核心函数（6个参数）：首先进行判断，如果当前位置超出范围直接返回（总和超过目标值的情况在加之前已经判断过），如果等于目标值则把items放进结果向量，否则：从num开始遍历到数组结尾，每一位相加前先判断是否超过目标值，如果超过则直接停止所有循环返回，不超过将此位加入递归（传入当前位，因为此位可以被无限制重复选取）并弹出继续循环，总体作用是从第一位开始一直加到最大但不超过目标值，然后弹出一个进行下一位的相同步骤，一直加直到超过然后弹出进行下一位，最终前面所有位都弹出进行最后一位，剪枝是当进行某一位时如果已经超过后面便不再尝试，回溯到前面继续弹出才行。（前5次提交1，2没有剪枝，3回溯，4,5再次回溯，并除去结束条件里的大于条件）。100 93

# 代码
- C++ 递归回溯+剪枝
```
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        if(candidates.size()==0)    return result;
        vector<int> items;
        sort(candidates.begin(),candidates.end());
        findSum(candidates,0,target,0,result,items);
        return result;
    }
private:
    void findSum(vector<int>& candidates,int k,int target,int sum,vector<vector<int>>& result, vector<int>& items){
        if(k>=candidates.size())    return;  	//||sum>target可省略
        else if(sum==target)    result.push_back(items);
        else{
            for(int i=k;i<candidates.size();i++){
                if(sum+candidates[i]>target)    break;
                sum+=candidates[i];
                items.push_back(candidates[i]);
                findSum(candidates,i,target,sum,result,items);
                sum-=candidates[i];
                items.pop_back();
            }
        }
    }
};
```