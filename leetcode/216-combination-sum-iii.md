# 题目链接
[leetcode 216](https://leetcode-cn.com/problems/combination-sum-iii/)组合总和 III

# 原文
找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。  
说明：  
所有数字都是正整数。  
解集不能包含重复的组合。   
示例 1:   
输入: k = 3, n = 7  
输出: [[1,2,4]]  
示例 2:  
输入: k = 3, n = 9  
输出: [[1,2,6], [1,3,5], [2,3,4]]

# 思路
- ### **递归回溯**
  使用回溯算法，递归的序号不是下标，而是1-9的数字，最后的结束条件就是items的size达到要求k；思路是首先写完结束条件，判断完以后说明当前items没有超过边界条件，然后判断当前数字的合法性，如果超过有效数字或者目标大小直接返回，否则在items中放入该元素，然后递归下一个元素，同时目标只需要减去选择的这个数字，然后放弃选择这个数字即pop_back，然后继续递归；依次下去就是相当于首先选择连续的数字组合，不符合以后慢慢更改最后一位数（回溯的思想），直到最后到达9开头的第一位数便利完成以后。46 11

# 代码
- C++ 递归回溯
```
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        if(n<1)   return result;
        dfs(1,k,n);
        return result;

    }
private:
    vector<vector<int>> result;
    vector<int> items;
    void dfs(int num,int k,int n){
        if(items.size()==k){
            if(n==0){
                result.push_back(items);
            }
            return;
        }
        if(num>n||num>9)    return;
        items.push_back(num);
        dfs(num+1,k,n-num);
        items.pop_back();
        dfs(num+1,k,n);
    }
};
```
