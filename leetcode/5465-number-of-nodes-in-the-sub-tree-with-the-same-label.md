# 题目链接
[leetcode 5465](https://leetcode-cn.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/)

# 原文
给你一棵树（即，一个连通的无环无向图），这棵树由编号从 0  到 n - 1 的 n 个节点组成，且恰好有 n - 1 条 edges 。树的根节点为节点 0 ，树上的每一个节点都有一个标签，也就是字符串 labels 中的一个小写字符（编号为 i 的 节点的标签就是 labels[i] ）  
边数组 edges 以 edges[i] = [ai, bi] 的形式给出，该格式表示节点 ai 和 bi 之间存在一条边。  
返回一个大小为 n 的数组，其中 ans[i] 表示第 i 个节点的子树中与节点 i 标签相同的节点数。

树 T 中的子树是由 T 中的某个节点及其所有后代节点组成的树。  
示例 1：  
输入：n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], labels = "abaedcd"  
输出：[2,1,1,1,1,1,1]  
解释：节点 0 的标签为 'a' ，以 'a' 为根节点的子树中，节点 2 的标签也是 'a' ，因此答案为 2 。注意树中的每个节点都是这棵子树的一部分。  
节点 1 的标签为 'b' ，节点 1 的子树包含节点 1、4 和 5，但是节点 4、5 的标签与节点 1 不同，故而答案为 1（即，该节点本身）。  
示例 2：  
输入：n = 4, edges = [[0,1],[1,2],[0,3]], labels = "bbbb"  
输出：[4,2,1,1]  
解释：节点 2 的子树中只有节点 2 ，所以答案为 1 。  
节点 3 的子树中只有节点 3 ，所以答案为 1 。  
节点 1 的子树中包含节点 1 和 2 ，标签都是 'b' ，因此答案为 2 。  
节点 0 的子树中包含节点 0、1、2 和 3，标签都是 'b'，因此答案为 4 。  
示例 3：  
输入：n = 5, edges = [[0,1],[0,2],[1,3],[0,4]], labels = "aabab"  
输出：[3,2,1,1,1]  
示例 4：  
输入：n = 6, edges = [[0,1],[0,2],[1,3],[3,4],[4,5]], labels = "cbabaa"  
输出：[1,2,1,1,2,1]  
示例 5：  
输入：n = 7, edges = [[0,1],[1,2],[2,3],[3,4],[4,5],[5,6]], labels = "aaabaaa"  
输出：[6,5,4,1,3,2,1]  
提示：  
1 <= n <= 10^5  
edges.length == n - 1  
edges[i].length == 2  
0 <= ai, bi < n  
ai != bi  
labels.length == n  
labels 仅由小写英文字母组成

# 思路
- ### **198周赛-深搜**
  由于最底层的节点也会影响最顶层节点的值，所以必须先把最底层的节点先处理完才可以处理顶层节点，考虑使用深度优先搜索；首先将每个节点的邻接点给记录下来，新建map，同时由于线段是无向性的，所以不知道edges里面谁是父节点谁是子节点，所以在记录时edge[1]要加入到edge[0]里面同时edge[0]要加入edge[1]里面（由于会记录已经访问过的节点visited，所以不用担心处理子节点时会深搜到父节点，同时由于已知根节点是0，所以不会先处理任何一个子节点从而影响父节点）；为了记录每个节点下面共有多少个字母，所以使用字典思想（周赛时未使用这个思想直接一个一个比较的话，在n=100000时超出时间限制），新建长度为26的向量；先深搜0节点，将当前节点标记为已访问，然后将本身带的字母位置+1，开始深搜子节点(auto& m:map[num])，每遇到一个子节点，先判断是否已经访问，没有访问的话开始深搜，深搜以后子节点的tab已经做好，下面需要更新本节点的tab，即把所有子节点的tab对应数值加到当前节点的tab中即可。

# 代码
- C++ 198周赛-深搜
```
class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        map.resize(n),tab.resize(n),visited.resize(n);
        for(int i=0;i<n;i++)   {
            tab[i].resize(26);
            //visited[i] = false;
        }
        for(auto& edge:edges){
            map[edge[0]].push_back(edge[1]);
            map[edge[1]].push_back(edge[0]);
        }
        dfs(0,labels);

        vector<int> result;
        for(int i=0;i<n;i++){
            result.push_back(tab[i][labels[i]-'a']);
        }
        return result;
    }
private:
    vector<vector<int>> map;
    vector<vector<int>> tab;
    vector<bool> visited;
    void dfs(int num,string& labels){
        visited[num] = true;
        tab[num][labels[num]-'a'] = 1;
        for(auto& m:map[num]){
            if(!visited[m])  {
                dfs(m,labels);
                for(int i=0;i<26;i++){
                    tab[num][i] += tab[m][i];
                }
            }
        }
    }
};
```
```
class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int> result(n,1);
        vector<vector<int>> lay(n);
        for(int i=0;i<edges.size();i++){
            lay(edges[i][0]).push_back(edges[i][1]);          
                        
            if(string[edges[i][0]==string[edges[i][1])  result[edges[i][0]]++;
        }
        for(int i=0;i<edges.size();i++){
            result[i] = func(lay[i]);        
                        
            if(string[edges[i][0]==string[edges[i][1])  result[edges[i][0]]++;
        }
        return result;
    }
private:
    int func(vector<int>& vec,vector<vector<int>>& lay){
        int result = 0;
        for(int i=0;i<vec.size();i++){
            result = reuslt + func(lay[vec[i]]);
        }
        return result;
    }
};
```