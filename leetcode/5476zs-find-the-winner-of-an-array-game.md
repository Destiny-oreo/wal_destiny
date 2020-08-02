# 题目链接
[leetcode 5476zs](https://leetcode-cn.com/problems/find-the-winner-of-an-array-game/)

# 原文
给你一个由 不同 整数组成的整数数组 arr 和一个整数 k 。  
每回合游戏都在数组的前两个元素（即 arr[0] 和 arr[1] ）之间进行。比较 arr[0] 与 arr[1] 的大小，较大的整数将会取得这一回合的胜利并保留在位置 0 ，较小的整数移至数组的末尾。当一个整数赢得 k 个连续回合时，游戏结束，该整数就是比赛的 赢家 。
返回赢得比赛的整数。  
题目数据 保证 游戏存在赢家。  
示例 1：  
输入：arr = [2,1,3,5,4,6,7], k = 2  
输出：5  
解释：一起看一下本场游戏每回合的情况：  
因此将进行 4 回合比赛，其中 5 是赢家，因为它连胜 2 回合。  
示例 2：  
输入：arr = [3,2,1], k = 10  
输出：3  
解释：3 将会在前 10 个回合中连续获胜。  
示例 3：  
输入：arr = [1,9,8,2,3,7,6,4,5], k = 7  
输出：9  
示例 4：  
输入：arr = [1,11,22,33,44,55,66,77,88,99], k = 1000000000  
输出：99  
提示：  
2 <= arr.length <= 10^5  
1 <= arr[i] <= 10^6  
arr 所含的整数 各不相同 。  
1 <= k <= 10^9  

# 思路
- ### **200周赛-数组-暴力**
  真实的数组不向题目中那样可以循环，所以找到规律以后发现就是要求该位连续比后面k-1个数都要打（第0位时后面k个数），所以只要暴力求解；对于特殊情况即k大于等于数组长度时，代表存在一个最大的数循环pk掉数组其他元素，所以返回最大的数即可。

# 代码
- C++ 数组-暴力
```
class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int temp = 0;
        if(k>=arr.size()){
            int maxs = arr[0];
            for(int i=1;i<arr.size();i++){
                maxs = max(maxs,arr[i]);
            }
            return maxs;
        }
        for(int i=0;i<arr.size();i++){
            if(i==0){
                int j=i+1;

                while(arr[0]>arr[j++]){
 
                    temp++;
                    if(temp==k) return arr[0];
                    if(j>=arr.size())   j=i+1;
                }
            }
            else{
                int j = i+1;

                temp = 1;
                if(temp == k)   return arr[i];
                if(j>=arr.size())   j=0;
                while(arr[i]>arr[j++]){
                    temp++;
                    if(temp==k) return arr[i];
                    if(j>=arr.size())   j=0;
                    if(j==i)    j++;
                }
            }
        }
        return 0;
    }
};
```
