# 题目链接
[leetcode 22](https://leetcode-cn.com/problems/generate-parentheses/)

# 原文
给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。

例如，给出 n = 3，生成结果为：

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]

# 思路
- ### **宽搜**
  又是固定长度的字符串，每位有两种选择，但最后两种选择需要相等且中间需要满足符合的特点；所以先考虑递归，同时对于每一位进行宽搜（在判断后进行宽搜），首先就是左括号数量大于0，则先放入左括号，如果右括号大于左括号的数量则也对有括号进行递归（括号的特点就是必须先有左括号再有右括号）；最后结束的条件为左右括号均为0的情况下，此时将传入的items字符串放入结果数组。77 26

# 代码
- C++宽搜
```
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        bfs(result,n,n,"");
        return result;
    }
private:
    void bfs(vector<string>& result,int left,int right,string items){
        if(left==0&&right==0){
            result.push_back(items);
            return;
        }

        //if(left>0)  generate(left-1,right,result,str+'(');
        //if(right>left)  generate(left,right-1,result,str+')');

        if(left==right){
            items.push_back('(');
            bfs(result,left-1,right,items);
        }
        else if(left<right){
            if(left>0){
                items.push_back('(');
                bfs(result,left-1,right,items);
                items.pop_back();
            }
            if(right>0){
                items.push_back(')');
                bfs(result,left,right-1,items);
            }
        }
    }
};
```