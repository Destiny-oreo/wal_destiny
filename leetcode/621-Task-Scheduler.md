# 题目链接
[leetcode 621](https://leetcode-cn.com/problems/task-scheduler/)

# 原文
给定一个用字符数组表示的 CPU 需要执行的任务列表。其中包含使用大写的 A - Z 字母表示的26 种不同种类的任务。任务可以以任意顺序执行，并且每个任务都可以在 1 个单位时间内执行完。CPU 在任何一个单位时间内都可以执行一个任务，或者在待命状态。

然而，两个相同种类的任务之间必须有长度为 n 的冷却时间，因此至少有连续 n 个单位时间内 CPU 在执行不同的任务，或者在待命状态。

你需要计算完成所有任务所需要的最短时间。

示例 1：

输入: tasks = ["A","A","A","B","B","B"], n = 2
输出: 8
执行顺序: A -> B -> (待命) -> A -> B -> (待命) -> A -> B.
注：

任务的总个数为 [1, 10000]。
n 的取值范围为 [0, 100]。

# 思路
- ### **找规律**
读完题目发现调度的重点涉及到出现频率最高的一个字母的次数count、频率最高的字母种类max_num，以及以上与n+1的关系；总结如下：  
1.如`AAABBC,n=2`（频率最高的种类为1），则只需考虑`AXX AXX A`，即`(count-1)×(n+1)`个循环才能将频率最高的字符完成完毕，最后再加上一个A即可；  
2.如`AAABBBCC,N=2`（频率最高的种类大于1），则循环n+1次以后需要加上AB，即频率最高的字符种类，所以就是加上max_num；  
3.如`AAABBBCCCDDDEEEHFKJFH`(字符种类足够多的时候，可以不需要考虑n的存在），此时直接将每个字符实现即可，无需多余任何的等待；
4.最终直接取`max(tasks.size(),(count-1)×(n+1)+max_num)`。

# 代码
- C++ 找规律
```
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {//(count-1)*(n+1)+1
        vector<int> a(26,0);
        for(int i=0;i<tasks.size();i++){
            a[tasks[i]-'A']++;
        }
        sort(a.begin(),a.end());
        int max_num = 1;
        for(int i=24;i>=0;i--){
            if(a[i]!=a[25]) break;
            max_num++;
        }
        return max((int)tasks.size(),(int)(a[25]-1)*(n+1)+max_num);
    }
};
```