# 题目链接
[leetcode 739](https://leetcode-cn.com/problems/daily-temperatures/)

# 原文
根据每日 气温 列表，请重新生成一个列表，对应位置的输入是你需要再等待多久温度才会升高超过该日的天数。如果之后都不会升高，请在该位置用 0 来代替。

例如，给定一个列表 temperatures = [73, 74, 75, 71, 69, 72, 76, 73]，你的输出应该是 [1, 1, 4, 2, 1, 1, 0, 0]。

提示：气温 列表长度的范围是 [1, 30000]。每个气温的值的均为华氏度，都是在 [30, 100] 范围内的整数。

# 思路
- ### **动态规划**
  题目为寻找与后面第一个比自己大的数字的距离，所以可以使用动态规划思想（当后一个比较小时可以直接跳到再后面比后一个更大的数字）。由于用到后面的结果，所以由后往前二维遍历，当后面数字比当前大时直接返回距离差，否则：当后一个位置之后没有更大的数字时（即result[i+1]==0)直接返回0，不再搜索，当有时更新下一个位置为j+=result[j]，即确保比后一个数字更大，若还是没有当前位置的数字大则继续找更大的，直至结束。
- ### **栈**
  原理与动态规划一样，即如果后面一个不够大时，找到下一个比后面一个更大的数，省去遍历比后面一个更小的很多值。栈（存放下标）先放入最后一个下标，由后向前遍历，首先循环，如果栈不空并且当前值大于等于栈顶下标的值，弹出栈，直到为空或者栈顶下标的值更加大，所以判断：若为空则没有，赋值0，若不空，赋值栈顶元素的值-当前下标值，最后务必放入当前下标值共下面的循环。

# 代码
- C++ 动态规划
```
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int> result(n,0);
        for(int i=n-2;i>=0;i--){
            for(int j=i+1;j<n;j+=result[j]){
                if(T[i]<T[j]){
                    result[i] = j-i;
                    break;
                }
                else if(result[j]==0){
                    result[i] = 0;
                    break;
                }
            }
        }
        return result;
    }
};
```
- C++ 栈
```
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int> result(n,0);
        stack<int> s;
        s.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(!s.empty()&&T[i]>=T[s.top()]){
                s.pop();
            }
            if(s.empty())   result[i] = 0;
            else    result[i] = s.top()-i;
            s.push(i);
        }
        return result;
    }
};
```