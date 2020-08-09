# 题目链接
[leetcode 5484zs](https://leetcode-cn.com/problems/find-kth-bit-in-nth-binary-string/)

# 原文
给你两个正整数 n 和 k，二进制字符串  Sn 的形成规则如下：   
S1 = "0"  
当 i > 1 时，Si = Si-1 + "1" + reverse(invert(Si-1))  
其中 + 表示串联操作，reverse(x) 返回反转 x 后得到的字符串，而 invert(x) 则会翻转 x 中的每一位（0 变为 1，而 1 变为 0）  
例如，符合上述描述的序列的前 4 个字符串依次是：  
S1 = "0"  
S2 = "011"  
S3 = "0111001"    
S4 = "011100110110001"  
请你返回  Sn 的 第 k 位字符 ，题目数据保证 k 一定在 Sn 长度范围以内。  
示例 1：  
输入：n = 3, k = 1  
输出："0"  
解释：S3 为 "0111001"，其第 1 位为 "0" 。  
示例 2：  
输入：n = 4, k = 11  
输出："1"  
解释：S4 为 "011100110110001"，其第 11 位为 "1" 。  
示例 3：  
输入：n = 1, k = 1  
输出："0"  
示例 4：  
输入：n = 2, k = 3  
输出："1"  
提示：   
1 <= n <= 20  
1 <= k <= 2n - 1  

# 思路
- ### **201周赛-字符串-递归**
  周赛时候的做法是找规律，因为觉得不可以使用暴力法求解，所以必须存在规律，没有考虑到使用递归来还原到最原始的状态；思路：任意一个n（除了1），均是由前半部分2^(n-1)-1和1和后半部分2^(n-1)-1一共2^n-1个字符组成，所以判断时计算mid，如果k刚好是mid，直接返回1，然后判断大于mid还是小于mid，小于mid的话相当于n完全是大的，可以递归n-1计算，如果大于mid，需要翻转和反转，先专门写一个翻转函数，然后寻找反转的规律，发现K反转以后是2^n-k的位置，所以继续递归即可。100 100   
  学会了表达2的n次方的写法即1<<n，代表0001向左移动n次，移动1次变成2即2^1,以此类推  
  以及字符串使用删除功能时，可以使用erase(start_index,len)来删除len个字符，大小写字母的ascll相差32。 

# 代码
- C++ 201周赛-字符串-递归
```
class Solution {
public:
    char findKthBit(int n, int k) {
        if(n==1)    return '0';
        int mid = (1<<(n-1));
        if(k==mid)  return '1';
        else if(k<mid)  return findKthBit(n-1,k);
        else    return rev(findKthBit(n-1,(1<<n)-k));
    }
private:
    char rev(char c){
        if(c=='0')  return '1';
        else    return '0';
    }
};
```
