# 题目链接
[leetcode 5490zs](https://leetcode-cn.com/problems/minimum-number-of-days-to-eat-n-oranges/)

# 原文
厨房里总共有 n 个橘子，你决定每一天选择如下方式之一吃这些橘子：  
吃掉一个橘子。  
如果剩余橘子数 n 能被 2 整除，那么你可以吃掉 n/2 个橘子。  
如果剩余橘子数 n 能被 3 整除，那么你可以吃掉 2*(n/3) 个橘子。  
每天你只能从以上 3 种方案中选择一种方案。  
请你返回吃掉所有 n 个橘子的最少天数。  
示例 1：  
输入：n = 10  
输出：4  
解释：你总共有 10 个橘子。  
第 1 天：吃 1 个橘子，剩余橘子数 10 - 1 = 9。  
第 2 天：吃 6 个橘子，剩余橘子数 9 - 2*(9/3) = 9 - 6 = 3。（9 可以被 3 整除）  
第 3 天：吃 2 个橘子，剩余橘子数 3 - 2*(3/3) = 3 - 2 = 1。  
第 4 天：吃掉最后 1 个橘子，剩余橘子数 1 - 1 = 0。  
你需要至少 4 天吃掉 10 个橘子。  
示例 2：  
输入：n = 6  
输出：3  
解释：你总共有 6 个橘子。  
第 1 天：吃 3 个橘子，剩余橘子数 6 - 6/2 = 6 - 3 = 3。（6 可以被 2 整除）  
第 2 天：吃 2 个橘子，剩余橘子数 3 - 2*(3/3) = 3 - 2 = 1。（3 可以被 3 整除）  
第 3 天：吃掉剩余 1 个橘子，剩余橘子数 1 - 1 = 0。  
你至少需要 3 天吃掉 6 个橘子。  
示例 3：  
输入：n = 1  
输出：1  
示例 4：  
输入：n = 56  
输出：6  
提示：  
1 <= n <= 2*10^9  

# 思路
- ### **bfs+set**
  本题为202次周赛最后一题，基本可以做出来，但是由于时间和空间复杂度比赛时候一直没有达到要求；学习了map和unordered_map以及set和unordered_set的区别，使用map等会使用红黑树，默认使用二叉搜索树来存储有序数据，浪费了空间，并且这里只需要记录是否出现即可，不需要map，只要set即可，使用unordered_set来无需记录，访问时更加快速；从目标n开始向0搜索，使用宽度优先搜索，用队列来记录数据，每一轮进行result++，所以每次必须遍历所有队列的数据，所以使用倒序遍历，i=q.size()-1;i>=0;i--的方式，否则无法遍历完的。100 100

# 代码
- C++ bfs+set
```
class Solution {
public:
    int minDays(int n) {
        unordered_set<int> s;
        int result = 0;
        queue<int> q;
        q.push(n);

        while(!q.empty()){
            for(int i=q.size()-1;i>=0;i--){
                int temp = q.front();
                q.pop();
                if(temp==0) return result;
                
                if(temp%3==0&&s.count(temp/3)==0){
                    q.push(temp/3);
                    s.insert(temp/3);
                }
                if(temp%2==0&&s.count(temp/2)==0){
                    q.push(temp/2);
                    s.insert(temp/2);
                }
                if(s.count(temp-1)==0){
                    q.push(temp-1);
                    s.insert(temp-1);
                }
            }
            result++;
        }
        return result;
    }
};
```