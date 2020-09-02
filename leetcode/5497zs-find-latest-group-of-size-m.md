# 题目链接
[leetcode 5497zs](https://leetcode-cn.com/problems/find-latest-group-of-size-m/)

# 原文
给你一个数组 arr ，该数组表示一个从 1 到 n 的数字排列。有一个长度为 n 的二进制字符串，该字符串上的所有位最初都设置为 0 。  
在从 1 到 n 的每个步骤 i 中（假设二进制字符串和 arr 都是从 1 开始索引的情况下），二进制字符串上位于位置 arr[i] 的位将会设为 1 。  
给你一个整数 m ，请你找出二进制字符串上存在长度为 m 的一组 1 的最后步骤。一组 1 是一个连续的、由 1 组成的子串，且左右两边不再有可以延伸的 1 。  
返回存在长度 恰好 为 m 的 一组 1  的最后步骤。如果不存在这样的步骤，请返回 -1 。  
示例 1：  
输入：arr = [3,5,1,2,4], m = 1  
输出：4  
解释：  
步骤 1："00100"，由 1 构成的组：["1"]  
步骤 2："00101"，由 1 构成的组：["1", "1"]  
步骤 3："10101"，由 1 构成的组：["1", "1", "1"]  
步骤 4："11101"，由 1 构成的组：["111", "1"]  
步骤 5："11111"，由 1 构成的组：["11111"]  
存在长度为 1 的一组 1 的最后步骤是步骤 4 。  
示例 2：  
输入：arr = [3,1,5,4,2], m = 2  
输出：-1   
解释：  
步骤 1："00100"，由 1 构成的组：["1"]  
步骤 2："10100"，由 1 构成的组：["1", "1"]  
步骤 3："10101"，由 1 构成的组：["1", "1", "1"]  
步骤 4："10111"，由 1 构成的组：["1", "111"]  
步骤 5："11111"，由 1 构成的组：["11111"]  
不管是哪一步骤都无法形成长度为 2 的一组 1 。  
示例 3：  
输入：arr = [1], m = 1  
输出：1  
示例 4：  
输入：arr = [2,1], m = 2  
输出：2  
提示：  
n == arr.length  
1 <= n <= 10^5  
1 <= arr[i] <= n  
arr 中的所有整数 互不相同  
1 <= m <= arr.length  

# 思路
- ### **203周赛-set**
  此次周赛的第三题，周赛时使用暴力法一直超时；看题解使用逆序思考，每一次看生成的新的序列是否满足长度需求，长度的计算使用set来记录左右边界，判断完特殊情况以后开始插入初始边界0和n+1；然后逆序遍历，找到新的0地位置，判断0所在区间的左右两个边界（均为0，所以长度为*it-index-1)，边界的寻找方法为lower_bound，即包含与此元素相等的索引，小的边界使用it--来获得。100 100   
- ### **203周赛-并查集**
  第一次使用并查集，正向思考，私有变量设置好大小n和父向量parent和连续1的长度cnt，使用模板写好find和join函数（根据题意进行一点改编），然后开始编写主函数：首先初始化相关变量，所有父向量初始化为-1,代表没有被变1即初始为0，cnt应该初始为0然后每次遍历再变为1（直接初始为1也可以，因为有parent在看守），遍历每个arr成员，更改parent代表此处已经为1，可以处理，然后判断左右是否有1，有的话需要合并两个子集，没有的话直接判断此处的连续1是否符合要求；合并时首先判断合并的一侧是否会减少目标数量，即cnt[某一侧根节点]是否符合目标，符合的话需要数量--，然后将两处合并为一个子集（合并函数里包含将cnt合并的功能，即合并的子集根节点cnt+=被合并根节点cnt，被合并cnt置0），合并完左右侧以后判断新子集长度是否符合，最后只要又符合目标的子集，record向量此步骤就标记为true，最后反向遍历record即可，遇到true就返回i+1，全是false返回-1。100 100   

# 代码
- C++ 203周赛-set
```
class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        int n = arr.size();
        if(n==m)   return n;
        set<int> s;
        s.insert(0);
        s.insert(n+1);
        for(int i=n-1;i>=0;i--){
            int index = arr[i];
            auto it = s.lower_bound(index);
            if(*it-index-1==m)    return i;
            it--;
            if(index-*it-1==m)    return i;
            s.insert(index);
        }
        return -1;
    }
};
```
- C++ 203周赛-并查集
```
class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        n = arr.size();
        parent = vector<int>(n,-1);
        cnt = vector<int>(n,1);
        int counts = 0;
        vector<bool> record(n,false);
        for(int i=0;i<n;i++){
            int index = arr[i]-1;
            parent[index] = index;
            if(index>0&&parent[index-1]!=-1){
                if(cnt[find(index-1)]==m)   counts--;
                join(index-1,index);
            }
            if(index<n-1&&parent[index+1]!=-1){
                if(cnt[find(index+1)]==m)   counts--;
                join(index+1,index);
            }
            if(cnt[find(index)]==m)   counts++;
            if(counts>0)    record[i] = true;
        }
        for(int i=n-1;i>=0;i--){
            if(record[i])   return i+1;
        }
        return -1;
    }
private:
    int n;
    vector<int> parent;
    vector<int> cnt;
    int find(int a){
        if(parent[a]==a)    return a;
        return (parent[a] = find(parent[a]));
    }
    void join(int a,int b){
        int fa = find(a);
        int fb = find(b);
        if(fa!=fb){
            parent[fa] = fb;
            cnt[fb] += cnt[fa];
            cnt[fa] = 0;
        }
    }
};
```