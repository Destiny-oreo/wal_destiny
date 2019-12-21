# 题目链接
[leetcode 5](https://leetcode-cn.com/problems/longest-palindromic-substring/)

# 原文
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：

输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。
示例 2：

输入: "cbbd"
输出: "bb"

# 思路
- ### **中心扩展法**--->较优
  需要返回回文子串，为了节省空间复杂度，可以只是用子串的头尾下标来表示子串，最后再用下标把子串取出来即可，中间不需要一次次取出。使用中心法遍历每个元素（此时不分奇偶数，偶数的中心不过是被扩展过的奇数中心而已），首先判断中心是否可以扩展，即`while(high+1<s.length()&&s[low]==s[high+1]`，找到最后一位和中心相同的元素即为扩展结束（此时为了节省时间复杂度，使用被扩展的中心的最后一位作为下一次遍历的起点，节省了中间重新遍历中心的时间），接着从扩展中心的左右端点开始判断是否是回文子串，直到不再符合回文要求，此时high和low就是回文的左右端点，再判断这两个端点长度是否超过结果端点的长度，进行选择性更新。
- ### **暴力法**  
  思路同上，都采用下标代表回文子串（曾尝试使用**字符串记录回文子串**，但复杂度太高，舍弃），暴力法即分回文长度的奇偶数，分别进行判断，是正常判断的时间复杂度的两倍左右，传入两位（奇数时两位均为中心位，偶数时为中间的两位），判断范围以及是否相等，最后返回回文两头的外围一位，最后再判断长度。
- ### **动态规划**
  见[leetcode 647](https://leetcode-cn.com/problems/palindromic-substrings/submissions/)

# 代码
- C++ 中心扩展法
```
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length()<=1)   return s;
        int range[2] = {0,0};
        for(int i=0;i<s.length();i++){
            i = find_ind(s,i,range);
        }
        return s.substr(range[0],range[1]-range[0]+1);
    }
private:
    int find_ind(string s,int left,int range[]){
        int right = left;
        while(right+1<s.length()&&s[right+1]==s[left])  right++;
        int temp = right;
        while(left-1>=0&&right+1<s.length()&&s[left-1]==s[right+1]){
            left--;
            right++;
        }
        if(range[1]-range[0]<right-left){
            range[0] = left;
            range[1] = right;
        }
        return temp;
    }
};
```
- C++ 暴力法
```
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length()<=1)   return s;
        int range[2] = {0,0};
        for(int i=0;i<s.length()-1;i++){
            func(s,i,i,range);
            func(s,i,i+1,range);
        }
        return s.substr(range[0],range[1]-range[0]+1);
    }
private:
    void func(string s,int i,int j,int range[]){
        while(i>=0&&j<=s.length()-1&&s[i]==s[j]){
            i--;
            j++;
        }
        i++;j--;
        if(j-i>range[1]-range[0]){
            range[0] = i;
            range[1] = j;
        }
    }
};
```