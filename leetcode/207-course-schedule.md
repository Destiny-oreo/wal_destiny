# 题目链接
[leetcode 207](https://leetcode-cn.com/problems/course-schedule/)

# 原文
你这个学期必须选修 numCourse 门课程，记为 0 到 numCourse-1 。  
在选修某些课程之前需要一些先修课程。 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们：[0,1]  
给定课程总量以及它们的先决条件，请你判断是否可能完成所有课程的学习？  
示例 1:  
输入: 2, [[1,0]]   
输出: true  
解释: 总共有 2 门课程。学习课程 1 之前，你需要完成课程 0。所以这是可能的。  
示例 2:  
输入: 2, [[1,0],[0,1]]  
输出: false  
解释: 总共有 2 门课程。学习课程 1 之前，你需要先完成​课程 0；并且学习课程 0 之前，你还应先完成课程 1。这是不可能的。  
提示：  
输入的先决条件是由 边缘列表 表示的图形，而不是 邻接矩阵 。详情请参见图的表示法。
你可以假定输入的先决条件中没有重复的边。  
1 <= numCourses <= 10^5  

# 思路
- ### **图-指向次数**
  已知n门课程，部分课程之间存在依赖关系即指向关系，意思是学某一门课程需要先学习另一门课程，为了确定所有课程是否可以学完，可以记录每门课程的指向次数，次数为0的课程一定是可以直接学习的，次数不为0的可以通过其他所有次数为0的课程学完以后，依赖0课程的其他课程指向次数-1，如果变成0也变成可以学习，放入学习队列，最后将所有学习队列的课程学习完以后，还有没有学习的课程则返回false。99 100 

- ### **图-环**
  换一种方式理解题目就是寻找题目中有没有环，只要没有环，不管什么依赖关系总是可以把所有课程学习完，但是一旦有环就无法学习完；寻找环的过程使用深搜，先确定好图的邻接关系，根据邻接关系neighbor来深搜，同时做好访问记录，当前正在访问的节点标记为0，如果深搜过程中回到改点，则有环，如果深搜过程中找到一个已经遍历的点，同样有环，深搜完所有节点以后，还是没有找到环，才可以返回true，其他的中间过程只能返回false。81 100

# 代码
- C++ 图-指向次数
```
struct graphNode{
    int label;
    vector<graphNode*> neighbers;
    graphNode(int x):label(x){};
};
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<graphNode*> nodes;
        vector<int> degree(numCourses);
        for(int i=0;i<numCourses;i++){
            nodes.push_back(new graphNode(i));
        } 
        for(int i=0;i<prerequisites.size();i++){
            nodes[prerequisites[i][1]]->neighbers.push_back(nodes[prerequisites[i][0]]);
            degree[prerequisites[i][0]]++;
        }
        queue<graphNode*> q;
        for(int i=0;i<numCourses;i++){
            if(degree[i]==0){
                q.push(nodes[i]);
            }
        }
        while(!q.empty()){
            graphNode* temp = q.front();
            q.pop();
            for(int i=0;i<temp->neighbers.size();i++){
                degree[temp->neighbers[i]->label]--;
                if(degree[temp->neighbers[i]->label]==0){
                    q.push(temp->neighbers[i]);
                }
            }
        }
        for(int i=0;i<numCourses;i++){
            if(degree[i]!=0)    return false;
        }
        return true;
    }
};
```
- C++ 图-环
```
struct graphNode{
    int label;
    vector<graphNode*> neighbers;
    graphNode(int x):label(x){};
};
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<graphNode*> nodes;
        visited.resize(numCourses);
        for(int i=0;i<numCourses;i++){
            nodes.push_back(new graphNode(i));
            visited[i] = -1;
        } 
        for(int i=0;i<prerequisites.size();i++){
            nodes[prerequisites[i][1]]->neighbers.push_back(nodes[prerequisites[i][0]]);
        }
        for(int i=0;i<numCourses;i++){
            if(visited[i]==-1&&!dfs(nodes[i]))   return false;
        }
        return true;
    }
private:
    vector<int> visited;
    bool dfs(graphNode* node){
        visited[node->label] = 0;
        for(int i=0;i<node->neighbers.size();i++){
            if(visited[node->neighbers[i]->label]==-1){
                // return dfs(node->neighbers[i]);
                if(!dfs(node->neighbers[i]))    return false;//不可以返回true，在检测到false的时候才能返回false，true的时候不必返回
            }
            else if(visited[node->neighbers[i]->label]==0)  return false;
        }
        visited[node->label] = 8;
        return true;
    }
};
```