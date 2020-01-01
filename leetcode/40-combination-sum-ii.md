# 题目链接
[leetcode 40](https://leetcode-cn.com/problems/combination-sum-ii/)

# 原文
给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。  
candidates 中的每个数字在每个组合中只能使用一次。  
说明：  
所有数字（包括目标数）都是正整数。
解集不能包含重复的组合。   
示例 1:   
输入: candidates = [10,1,2,7,6,1,5], target = 8,
所求解集为:
[  
  [1, 7],  
  [1, 2, 5],  
  [2, 6],  
  [1, 1, 6]  
]  
示例 2:  
输入: candidates = [2,5,2,1,2], target = 5,  
所求解集为:  
[  
  [1,2,2],  
  [5]  
]

# 思路
- ### **递归回溯（set查重）**
  背包问题（附加一些条件如去重），首先排序方便后面剪枝（一旦加上此位超过目标值所以以后加上任意一个都会超过，直接返回），对每一种符合结果的答案进行查重（使用set来查重，对一种符合答案的结果进行查找），如果找不到添加进去并放进结果数组，否则进行下次递归（先把此位放进去），然后把此位去掉再进行下次递归。6 32
- ### **递归回溯**
  不使用set查重，因为set使用红黑树效率比较低，所以在递归时直接使用算法进行去重。排序方便剪枝（见上），然后传入函数，当目标值为0时放入结果向量，否则从0位开始遍历，（第一层递归）对每一位遍历时说明此位是第一位，如果加上此位已经超过目标值直接停止后面所有循环，在某一位便利时如果第一位就重复了也直接跳过此位（前面同样一位作为开头时绝对完全考虑过次位作为开头的所有情况）。 有点乱...->递归函数作用：当目标值为0时（结束条件是结果达到时）存入并返回，返回的即是所有符合条件的结果数组，对于一个待选数组，从第一位遍历到最后一位，对于某一位，存在选与不选（如果此位已超过目标值直接不考虑后面所有），选了此位则直接调用本函数寻找此位以后符合目标差值的结果，如果不选，则注意去重，即本位不选也不选后面任何一个与此位相等的位。（此位选于不选的所有情况肯定不会互相重复，重复的是此位选了下位不选 和 此位不选下位选这两种，去除后者即可，即当i不为0时说明前面的位置已经全部不选，若此位与前面相等直接跳过）。71 96
- ### **递归回溯2**
  继续在上面代码上优化，首先排序后取出数组中大于目标值的所有单个值，直接不予考虑；传入向上面函数一样的递归函数，只是多加了常数代表数组的结尾，递归函数：判断是否达到目标值（k如果超过下标不进行任何操作，目标值小于0的情况在选择时候就进行了判断，所以此处可以不用再次考虑），如果达到进行保存，否则进行选择，对于每一位有选与不选两种操作，选了以后直接递归传给下层递归函数，区别在于数组起始位后移一位，目标值减小，不选的话i便不等于k，所以进行判断，如果前面不选，后面相同的数便不再进行考虑，以达到去重的作用。93 97

# 代码
- C++ 递归回溯
```
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> items;
        set<vector<int>> setres;
        sort(candidates.begin(),candidates.end());
        findSum(candidates,target,0,0,items,result,setres);
        return result;
    }
private:
    void findSum(vector<int>& candidates,int target,int k,int sum,vector<int>& items,vector<vector<int>>& result,set<vector<int>>& setres){
        if(k>=candidates.size()||sum>target)    return;
        sum+=candidates[k];
        items.push_back(candidates[k]);
        if(sum==target&&setres.find(items)==setres.end()){
            result.push_back(items);
            setres.insert(items);
        }
        findSum(candidates,target,k+1,sum,items,result,setres);
        sum-=candidates[k];
        items.pop_back();
        findSum(candidates,target,k+1,sum,items,result,setres);
    }
};
```
- C++ 递归回溯
```
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> items;
        sort(candidates.begin(),candidates.end());
        findSum(candidates,target,0,result,items);
        return result;
    }
private:
    void findSum(vector<int>& candidates,int target,int k,vector<vector<int>>& result,vector<int>& items){
        if(target==0){
            result.push_back(items);
            return;
        }
        for(int i=k;i<candidates.size();i++){
            if(target-candidates[i]>=0){
                if(i==k||candidates[i]!=candidates[i-1]){
                    items.push_back(candidates[i]);
                    findSum(candidates,target-candidates[i],i+1,result,items);
                    items.pop_back();
                }
            }
            else    break;
        }
    }
};
```
```
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> items;
        sort(candidates.begin(),candidates.end());
        int end = 0;
        for(;end<candidates.size();end++){
            if(candidates[end]>target)  break;
        }
        findSum(candidates,target,result,items,0,end==candidates.size()?end-1:end);
        return result;
    }
private:
    void findSum(vector<int>& candidates,int target,vector<vector<int>>& result,vector<int>& items,int k,int end){
        //if(k>end) return;
        if(target==0){
            result.push_back(items);
            return;
        }
        for(int i=k;i<=end;i++){
            if(target-candidates[i]>=0){
                if(i==k||candidates[i]!=candidates[i-1]){
                    items.push_back(candidates[i]);
                    findSum(candidates,target-candidates[i],result,items,i+1,end);
                    items.pop_back();
                }
            }
            else    break;
        }
    }
};
```