# 题目链接
[leetcode 557](https://leetcode-cn.com/problems/reverse-words-in-a-string-iii/)反转字符串中的单词 III

# 原文
给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。  
示例：   
输入："Let's take LeetCode contest"  
输出："s'teL ekat edoCteeL tsetnoc"  
提示：  
在字符串中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格。  

# 思路
- ### **字符串-反转**
  写的没有算法的代码，就是分类讨论而已，主要使用字符串的reverse函数。9 6
- ### **字符串-交换**
  不申请额外的空间，直接原理反转，需要挨个字符的进行交换，使用库函数（algorithm）swap来交换字符串的两个字符；为了将最后一个单词也和前面进行一样的操作，遍历到n位才停止，处理量条件为遇到空格或者到达末尾，然后从begin到end进行交换，end为空格或结尾前面一个，begin初始化0，后面更新为空格后面一位。91 62

# 代码
- C++ 字符串-反转
```
class Solution {
public:
    string reverseWords(string s) {
        string result = "",item = "";
        int n = s.size();
        for(int i=0;i<n;i++){
            if(s[i]==' '){
                reverse(item.begin(),item.end());
                result = result+item+' ';
                item = "";
            }
            else if(i==n-1){
                item += s[i];
                reverse(item.begin(),item.end());
                result+=item;
            }
            else    item += s[i];
        }
        return result;
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