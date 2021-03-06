# 题目链接
[leetcode 55](https://leetcode-cn.com/problems/jump-game/)

# 原文
给定一个非负整数数组，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

判断你是否能够到达最后一个位置。

示例 1:

输入: [2,3,1,1,4]  
输出: true  
解释: 我们可以先跳 1 步，从位置 0 到达 位置 1, 然后再从位置 1 跳 3 步到达最后一个位置。  
示例 2:

输入: [3,2,1,0,4]  
输出: false  
解释: 无论怎样，你总会到达索引为 3 的位置。但该位置的最大跳跃长度是 0 ， 所以你永远不可能到达最后一个位置。
  
# 思路
- ### **贪心算法**
  能否到达最后一个位置，并不用计算需要多少步，所以先考虑贪心算法，只要最后能够到达最后一个位置即可；首先将原数组进行预处理，每一个位置的值加上下标值，代表每一个位置可以到达的最远位置（原始数组每个位置代表每个位置可以往后跳跃的距离），然后开始循环跳跃，首先设置初始下标位置和可以跳跃的最远距离，循环结束标志为已经到达数组的最后一个位置或者下标已经跳跃到最远距离（可能未达到最后一个位置），对于每个位置，查看当前位置能够取得最远距离，如果超过最远距离，则实时更新最远距离，同时每一次都要将下标往后更新一位；最后退出循环时只有两种可能，第一是已经到达最后一个位置，则返回true，第二是下标已经到达最远距离，无法再往后跳跃，如果没有达到最后一个位置返回false。74 71
- ### **动态规划**
  使用动态规划，可以从前可以从后，此处考虑从后往前的动态规划：从倒数第二个位置开始搜素，初始化n=1（代表此位置需要达到的跳跃要求），如果此位置的跳跃能力大于等于n说明此位置达到要求，将n再次赋值为1（代表截断后面的数组，前面的数组只要能够到达此位置便一定能够到达最后一位），如果不能，说明此位置也达不到跳跃的要求，将n++（计算实时位置到达截断位置的距离，直到有一个位置达到跳跃要求，否则n会越来越大），到第一个位置时，首先同样进行计算，是否达到跳跃要求，达到的话n=1,达不到的话前功尽弃，n++，此时进行判断，如果到达第一个位置且达不到跳跃要求，返回false，最后退出循环时返回true。74 73  

# 代码
- C++ 贪心算法
```
class Solution {
public:
    bool canJump(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            nums[i] = i+nums[i];
        }
        int k=0,max_index = nums[0];
        while(k<nums.size()&&k<=max_index){
            if(nums[k]>max_index)   max_index = nums[k];
            k++;
        }
        if(k==nums.size())  return true;
        return false;
    }
};
```
- C++ 动态规划
```
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=1;
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]>=n)  n=1;
            else    n++;
            if(i==0&&n!=1)   return false;
        }
        return true;
    }
};
```