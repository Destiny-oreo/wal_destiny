# 题目链接
[leetcode 17](https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/)

# 原文
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

示例:

输入："23"
输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

# 思路
- ### **回溯 BFS 哈希**
  - 需要输出每个按钮的组合输出，一个按钮对应着几种不同的输出，为经典的回溯算法。建立DFS函数，判断当前节点是否为末尾，若是，将当前的组合放进结果数组，若不是，将当前节点对应的不同字符分别依次放进items进行递归，同时再取出来放入另外的字符进行递归，这种先放入递归再取出放入别的字符进行递归的思路即为回溯。72 80  
  - map初始化使用{{}，{}，{}}
  - 哈希表效率不是很高，可以使用字符串数组代替哈希表，即`string maps[10]={"","",""...};`

# 代码
- C++ 回溯 BFS 哈希
```
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(digits.length()==0)  return  result;
        DFS(digits,0,result,"");
        return result;
    }
private:
    map<char,string> hash = {{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},        {'8',"tuv"},{'9',"wxyz"}};
    void DFS(string digits,int k,vector<string>& result,string items){
        if(k==digits.length()){
            result.push_back(items);
            return;
        }
        for(int i=0;i<hash[digits[k]].length();i++){
            items.push_back(hash[digits[k]][i]);
            DFS(digits,k+1,result,items);
            items.pop_back();
        }

    }
};
```
