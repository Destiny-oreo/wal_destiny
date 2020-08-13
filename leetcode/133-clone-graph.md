# 题目链接
[leetcode 133](https://leetcode-cn.com/problems/clone-graph/)

# 原文
给你无向 连通 图中一个节点的引用，请你返回该图的 深拷贝（克隆）。  
图中的每个节点都包含它的值 val（int） 和其邻居的列表（list[Node]）。  
class Node {    
    public int val;  
    public List<Node> neighbors;  
}  
测试用例格式：  
简单起见，每个节点的值都和它的索引相同。例如，第一个节点值为 1（val = 1），第二个节点值为 2（val = 2），以此类推。该图在测试用例中使用邻接列表表示。  
邻接列表 是用于表示有限图的无序列表的集合。每个列表都描述了图中节点的邻居集。  
给定节点将始终是图中的第一个节点（值为 1）。你必须将 给定节点的拷贝 作为对克隆图的引用返回。  
示例 1：  
输入：adjList = [[2,4],[1,3],[2,4],[1,3]]  
输出：[[2,4],[1,3],[2,4],[1,3]]  
解释：  
图中有 4 个节点  。  
节点 1 的值是 1，它有两个邻居：节点 2 和 4 。  
节点 2 的值是 2，它有两个邻居：节点 1 和 3 。  
节点 3 的值是 3，它有两个邻居：节点 2 和 4 。  
节点 4 的值是 4，它有两个邻居：节点 1 和 3 。  
示例 2：  
输入：adjList = [[]]  
输出：[[]]  
解释：输入包含一个空列表。该图仅仅只有一个值为 1 的节点，它没有任何邻居。  
示例 3：  
输入：adjList = []  
输出：[]  
解释：这个图是空的，它不含任何节点。  
示例 4：  
输入：adjList = [[2],[1]]  
输出：[[2],[1]]  
提示：  
节点数不超过 100 。  
每个节点值 Node.val 都是唯一的，1 <= Node.val <= 100。  
无向图是一个简单图，这意味着图中没有重复的边，也没有自环。  
由于图是无向的，如果节点 p 是节点 q 的邻居，那么节点 q 也必须是节点 p 的邻居。  
图是连通图，你可以从给定节点访问到所有节点。  

# 思路
- ### **深搜DFS-图**
  题目主要涉及的图，对于图的遍历本题使用深搜，由于是深拷贝，所以每一个新的节点都必须new，且由于后面的尾结点需要和前面新建立的头节点相接以及需要记录是否访问，所以建立的visited数组既可以代表是否访问过，又可以记录每一个新创建的节点，便于后面新建立的节点的neighbour的push_back，对于每一个邻接点，如果没有访问过，说明没有建立，递归调用本函数创建新节点，如果已经建立过，通过visited找到创建的节点引用即可。67 71

# 代码
- C++ 深搜DFS-图
```
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    
    Node* cloneGraph(Node* node) {
        if(node==NULL)  return NULL;
        Node* root = new Node(node->val,vector<Node*>{});
        visited[node->val] = root;
        for(int i=0;i<node->neighbors.size();i++){
            if(!visited[node->neighbors[i]->val])
                root->neighbors.push_back(cloneGraph(node->neighbors[i]));
            else
                root->neighbors.push_back(visited[node->neighbors[i]->val]);
        }
        return root;
    }
private:
    Node* visited[101]={NULL};
};
```
