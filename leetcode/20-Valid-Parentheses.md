# 题目链接
[leetcode 20](https://leetcode-cn.com/problems/valid-parentheses/)

# 原文
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。  
左括号必须以正确的顺序闭合。  
注意空字符串可被认为是有效字符串。

示例 1:
输入: "()"
输出: true  
示例 2:
输入: "()[]{}"
输出: true  
示例 3: 
输入: "(]"
输出: false  
示例 4:
输入: "([)]"
输出: false  
示例 5:
输入: "{[]}"
输出: true  

# 思路
- ### **栈-暴力**
  由于括号的特殊位置要求，有着和栈类似的后来先走的特点，所以首先考虑使用栈。最开始先判断字符串的长度，如不是偶数则直接返回false，接着进行遍历，若为三对括号的左半边，则直接push进栈，若是右半边，此时有两种情况都是非法的，第一种是此时栈为空，即前面没有任何括号，第二种是栈不为空，但与之对应的括号不合法；合法时直接将对应的符合pop出来进行下次遍历。最后查看栈是否为空，若为空说明一切都合法，若走完循环但是栈不为空，说明是左半边的括号多出来无法检测，直接返回false。71 94
- ### **栈-总结匹配**
  使用暴力栈求解发现写了很多重复的代码，因为可以弹出的情况只有不为空且栈顶和当前字符匹配的情况，所以专门写一个匹配函数，直接判断，若不匹配push，匹配pop，最后判断栈是否为空。100 77

# 代码
- C++ 栈
```
class Solution {
public:
    bool isValid(string s) {
        if(s.length()%2!=0) return false;
        stack<char> pt;
        for(int i=0;i<s.length();i++){
            switch(s[i]){
                case '(':
                case '[':
                case '{':
                    pt.push(s[i]);
                    break;
                case ')':
                    if(pt.empty()||pt.top()!='('){
                        return false;
                    }
                    pt.pop();
                    break;
                case ']':
                    if(pt.empty()||pt.top()!='['){
                        return false;
                    }
                    pt.pop();
                    break;
                case '}':
                    if(pt.empty()||pt.top()!='{'){
                        return false;
                    }
                    pt.pop();
                    break;
            }
        }
        return pt.empty();
    }
};
```
- C++ 栈-总结匹配
```
class Solution {
public:
    bool isValid(string s) {
        if(s.length()%2!=0) return false;
        stack<char> op;
        for(int i=0;i<s.length();i++){
            if(op.empty()||!match(op.top(),s[i]))   op.push(s[i]);
            else    op.pop();
        }
        return op.empty();
    }
private:
    bool match(char a,char b){
        if((a=='('&&b==')')||(a=='['&&b==']')||(a=='{'&&b=='}'))
            return true;
        return false;
    }
};
```