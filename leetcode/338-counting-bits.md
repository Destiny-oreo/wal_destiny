# 题目链接
[leetcode 338](https://leetcode-cn.com/problems/counting-bits/)

# 原文
给定一个非负整数 num。对于 0 ≤ i ≤ num 范围中的每个数字 i ，计算其二进制数中的 1 的数目并将它们作为数组返回。  
示例 1:  
输入: 2  
输出: [0,1,1]  
示例 2:  
输入: 5  
输出: [0,1,1,2,1,2]  
进阶:  
给出时间复杂度为O(n*sizeof(integer))的解答非常容易。但你可以在线性时间O(n)内用一趟扫描做到吗？  
要求算法的空间复杂度为O(n)。  
你能进一步完善解法吗？要求在C++或任何其他语言中不使用任何内置函数（如 C++ 中的 __builtin_popcount）来执行此操作。  

# 思路
- ### **动态规划-位运算**
  位运算基本设计到| & >>等运算方法，此题有两种较好的解法，第一种最常见：任何一个数的1的个数可以循环将此数与1进行与运算然后将数右移一位，继续进行与运算即可取出所有的1进行相加，所以可以使用动态规划思想，从1开始往目标数字运算，每一个数的运算规则是先右移一位，找到dp[i>>1]的结果，然后两者的区别在于移走的一位是0还是1，所以后面加上(i&1)即可； 70 71
  第二种，使用与前面一位相与，一定会少一个该数最右边的1，且结果是比当前数小的，所以可以使用dp来记录，同时最后固定加上1个1。

# 代码
- C++ 动态规划-位运算
```
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result(num+1,0);
        for(int i=1;i<=num;i++){
            result[i] = result[i>>1]+(i&1);
        }
        return result;
    }
};
```
```
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result(num+1,0);
        for(int i=1;i<=num;i++){
            result[i] = result[i&i-1]+1;
        }
        return result;
    }
};
```