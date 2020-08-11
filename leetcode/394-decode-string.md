# 题目链接
[leetcode 394](https://leetcode-cn.com/problems/decode-string/)

# 原文
给定一个经过编码的字符串，返回它解码后的字符串。  
编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。  
你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。  
此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。  
示例 1：  
输入：s = "3[a]2[bc]"  
输出："aaabcbc"  
示例 2：  
输入：s = "3[a2[c]]"  
输出："accaccacc"  
示例 3：  
输入：s = "2[abc]3[cd]ef"  
输出："abcabccdcdcdef"  
示例 4：  
输入：s = "abc3[cd]xyz"  
输出："abccdcdcdxyz"    

# 思路
- ### **状态转换机**
  使用栈来完成状态转换机，由于题目已经保证过输入的合理性，所以只会遇到数字、字母、左括号和右括号四种类型，1.遇到数字需要考虑的问题是首先需要将字符串的多位数字连成一个真正的数字，其次需要将处理完成后的数字在遇到后面对应的]时进行计算，而可能前面一个数字还没有使用就需要存储下一个数字（括号中的括号），所以考虑使用栈来存储每一个数字，使用完再pop，确保每个数字与对应的括号内字符串对齐；2.遇到[时，代表此时刚读完一个数字，可以将处理的数字进行结算，放入栈里，然后初始化num，同时代表开始新的字符串，result字符串需要放入另一个栈中同时result初始化；3.遇到字符时，直接往result上加即可；4.遇到]时最复杂，需要将刚刚存的需要倍加的result字符串进行处理，所以首先需要把倍数取出来即ns，同时数字栈弹出，然后开始倍加，将先前的字符串栈.top()进行倍加ns次result，然后将最后的结果给result，然后栈弹出即可。42 72

# 代码
- C++ 状态转换机
```
class Solution {
public:
    string decodeString(string s) {
        stack<string> strstack;
        stack<int> numstack;
        int num=0;
        string result = "";
        for(int i=0;i<s.size();i++){
            if(s[i]>='0'&&s[i]<='9'){
                num = num*10+s[i]-'0';
            }
            else if(s[i]=='['){
                numstack.push(num);
                num = 0;
                strstack.push(result);
                result = "";
            }
            else if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')){
                result += s[i];
            }
            else if(s[i]==']'){
                int ns = numstack.top();
                numstack.pop();
                for(int i=0;i<ns;i++){
                    strstack.top() += result;
                }
                result = strstack.top();
                strstack.pop();
            }
        }
        return result;
    }
};
```
