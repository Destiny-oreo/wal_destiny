# 题目链接
[leetcode 647](https://leetcode-cn.com/problems/palindromic-substrings/)

# 原文
给定一个字符串，你的任务是计算这个字符串中有多少个回文子串。

具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被计为是不同的子串。

示例 1:

输入: "abc"
输出: 3
解释: 三个回文子串: "a", "b", "c".
示例 2:

输入: "aaa"
输出: 6
说明: 6个回文子串: "a", "a", "a", "aa", "aa", "aaa".
注意:

输入的字符串长度不会超过1000。

# 思路
- ### **单双数遍历**
  私有变量设置result为0，逐个遍历string对象，每到一个位置以此为中心寻找回文数量，寻找时分为单双中心进行，分别向两侧扩散（设置好边界检测），如果相同result++的同时继续两侧扩散。
- ### **动态规划**
  设置二维bool数组dp初始化false，dp[i][j]代表字符串i到j未知是否是回文，所以j必须大于等于i，所以循环的第二维需要从j=i开始；由于动态规划需要找到和之前判断的关系，所以这里找到的关系就是如果当前s[i]和s[j]相等且i+1到j-1也是回文的话当前位置就也是回文（设置的边界条件是j-i大于等于2，当差值是0 1 2时，当前位置相等便可以不用再判断），大于此时也可以放心的使用i+1和j-1而不用担心越界问题；由于需要向中心搜索，即二维数组需要向下一层右侧一格寻找，所以遍历时需要从右下角开始，最终判断左上角时右下角可以作为参考，实现动态规划。

# 代码
- C++ 单双数遍历
```
class Solution {
public:
    int countSubstrings(string s) {
        for(int i=0;i<s.length();i++){
            func(s,i,i);
            func(s,i,i+1);
        }
        return result;
    }
private:
    int result = 0;
    void func(string& s,int begin,int end){
        while(begin>=0&&end<s.length()&&s[begin]==s[end]){
            result++;
            begin--;
            end++;
        }
    }
};
```
- C++ 动态规划
```
class Solution {
public:
    int countSubstrings(string s) {
        int n =s.length(),result = 0;
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(s[i]==s[j]&&(j-i<=2||dp[i+1][j-1])){
                    dp[i][j] = true;
                    result++;
                }
            }
        }
        return result;
    }
};
```