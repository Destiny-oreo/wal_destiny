# 题目链接
[leetcode 38](https://leetcode-cn.com/problems/count-and-say/)

# 原文
报数序列是一个整数序列，按照其中的整数的顺序进行报数，得到下一个数。其前五项如下：

1.    1
2.     11
3.     21
4.     1211
5.     111221

1 被读作  "one 1"  ("一个一") , 即 11。
11 被读作 "two 1s" ("两个一"）, 即 21。
21 被读作 "one 2",  "one 1" （"一个二" ,  "一个一") , 即 1211。

给定一个正整数 n（1 ≤ n ≤ 30），输出报数序列的第 n 项。

注意：整数顺序将表示为一个字符串。

示例 1:

输入: 1
输出: "1"
示例 2:

输入: 4
输出: "1211"

# 思路
- ### **递归字符串**
  每一层的数字都和上一层的结果有关联（除了n为1的情况），所以优先考虑使用递归解决。结束条件即为n为1时，直接返回字符串1，本层应该返回本层对应所读取的上一层的结果，最后即为本层应该做的操作，遍历上一层结果的字符串，如果当前字符串为最后一位或者于后面一位不相同（代表当前字符处为断点处，需要进行读取），将num++后进行读取（结果字符串先加进数量num再加进当前字符），如果不是说明后面还有相同的字符，当前位置不能读取，直接++即可。100 43
- ### **循环字符串**
  递归代码比较简便，但效果大多数没有循环的效率高，所以又考虑使用循环来解决此题。首先定义两个字符串，与递归的last和result相同，一个是上一层的结果，一个是此层的结果，最后定义一个num计数，对每一层循环，首先将结果备份给last，再讲result清空，再进行与递归相同的遍历即可，即先对num++，再判断此字符是否可以进行读取操作（见递归）。100 95

# 代码
- C++ 递归字符串
```
class Solution {
public:
    string countAndSay(int n) {
        if(n==1)    return "1";
        string result,last = countAndSay(n-1);
        int num = 0;
        for(int i=0;i<last.length();i++){
            if(i==last.length()-1||last[i]!=last[i+1]){
                num++;
                result+=num+'0';
                result+=last[i];
                num=0;
            }
            else{
                num++;
            }
        }
        return result;
    }
};
```
- C++ 循环字符串
```
class Solution {
public:
    string countAndSay(int n) {
        string last,result = "1";
        int num = 0;
        for(int i=2;i<=n;i++){
            last = result;
            result = "";
            num=0;
            for(int j=0;j<last.length();j++){
                num++;
                if(j==last.length()-1||last[j]!=last[j+1]){
                    result+=num+'0';
                    result+=last[j];
                    num = 0;
                }
            }
        }
        return result;
    }
};
```