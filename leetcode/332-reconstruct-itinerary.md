# 题目链接
[leetcode 332](https://leetcode-cn.com/problems/reconstruct-itinerary/)

# 原文
给定一个机票的字符串二维数组 [from, to]，子数组中的两个成员分别表示飞机出发和降落的机场地点，对该行程进行重新规划排序。所有这些机票都属于一个从 JFK（肯尼迪国际机场）出发的先生，所以该行程必须从 JFK 开始。  
说明:  
如果存在多种有效的行程，你可以按字符自然排序返回最小的行程组合。例如，行程 ["JFK", "LGA"] 与 ["JFK", "LGB"] 相比就更小，排序更靠前  
所有的机场都用三个大写字母表示（机场代码）。  
假定所有机票至少存在一种合理的行程。  
示例 1:  
输入: [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]  
输出: ["JFK", "MUC", "LHR", "SFO", "SJC"]  
示例 2:  
输入: [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]  
输出: ["JFK","ATL","JFK","SFO","ATL","SFO"]  
解释: 另一种有效的行程是 ["JFK","SFO","ATL","JFK","ATL","SFO"]。但是它自然排序更大更靠后。  

# 思路
- ### **深搜**
  首先排序确保最后完成的一定是排序比较靠前的，然后完成深搜确保是个完整的行程；对于深搜，首先为了防止重复搜索，设置visited，然后初始化结果数组为第一个；深搜的结束条件为结果数组大小达标，返回true，否则不达标说明选错行程，需要pop_back并且重置visited，所以需要将dfs设置成bool类型，在选择pop_back之前判断下一层是否成立，成立的话直接返回，不需要下面的尝试，不成立再进行后续尝试。22 90

# 代码
- C++ 深搜
```
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        sort(tickets.begin(),tickets.end(),[](vector<string>& a,vector<string>& b){
            return a[0]<b[0]||(a[0]==b[0]&&a[1]<b[1]);
        });
        result = vector<string>(1,"JFK");
        visited = vector<bool>(tickets.size(),false);
        dfs(tickets);
        return result;
    }//[["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]
private:
    vector<string> result;
    vector<bool> visited;
    bool dfs(vector<vector<string>>& tickets){
        if(result.size()==tickets.size()+1)    return true;
        string temp = result.back();
        for(int i=0;i<tickets.size();i++){
            if(visited[i]||tickets[i][0]!=temp)    continue;
            visited[i] = true;
            result.push_back(tickets[i][1]);
            if(dfs(tickets))    return true;
            result.pop_back();
            visited[i] = false;
        }
        return false;
    }
};
```