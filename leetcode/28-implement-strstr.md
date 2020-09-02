# 题目链接
[leetcode 28](https://leetcode-cn.com/problems/implement-strstr/)实现 strStr()

# 原文
实现 strStr() 函数。  
给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。  
示例 1:  
输入: haystack = "hello", needle = "ll"  
输出: 2  
示例 2:  
输入: haystack = "aaaaa ", needle = "bba"  
输出: -1  
说明:  
当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。  
对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。  

# 思路
- ### **字符串匹配-RK**
  使用RK算法，利用哈希思想，计算ascll值的和来比较，如果和不相等，直接不进行比较，如果相等，再进行逐个字符比较，全部相等才返回下标；ascll和的更新使用减去当前开头的字符并加上新遍历的字符。87 55
- ### **字符串-交换**
  不申请额外的空间，直接原理反转，需要挨个字符的进行交换，使用库函数（algorithm）swap来交换字符串的两个字符；为了将最后一个单词也和前面进行一样的操作，遍历到n位才停止，处理量条件为遇到空格或者到达末尾，然后从begin到end进行交换，end为空格或结尾前面一个，begin初始化0，后面更新为空格后面一位。91 62

# 代码
- C++ 字符串匹配-RK
```
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n1=haystack.size(),n2=needle.size(),hash1 = 0,hash2 = 0;
        if(n2==0)   return 0;
        if(n1<n2)   return -1;
        for(int i=0;i<n2;i++){
            hash1 += haystack[i]-'A';
            hash2 += needle[i]-'A';
        }
        for(int i=0;i<=n1-n2;i++){
            if(hash1==hash2){
                int j=i;
                for(;j<i+n2;j++){
                    if(haystack[j]!=needle[j-i])  break;
                }
                if(j==i+n2) return i;
            }
            else{
                hash1 = hash1-haystack[i]+'A';
                hash1 = hash1+haystack[i+n2]-'A';
            }
        }
        return -1;
    }
};
```
- C++ 字符串-交换
```
class Solution {
public:
    string reverseWords(string s) {
        int begin = 0,end = 0;
        int n= s.size();
        for(int i=0;i<=n;i++){
            if(i==n||s[i]==' '){
                for(end=i-1;begin<end;begin++,end--){
                    swap(s[begin],s[end]);
                }
                begin = i+1;
            }
        }
        return s;
    }
};
```