# 题目链接
[leetcode 155](https://leetcode-cn.com/problems/min-stack/)

# 原文
设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。  
push(x) —— 将元素 x 推入栈中。  
pop() —— 删除栈顶的元素。  
top() —— 获取栈顶元素。   
getMin() —— 检索栈中的最小元素。  
 
示例:  
输入：
["MinStack","push","push","push","getMin","pop","top","getMin"]  
[[],[-2],[0],[-3],[],[],[],[]]  
输出：  
[null,null,null,null,-3,null,0,-2]  
解释：  
MinStack minStack = new MinStack();  
minStack.push(-2);  
minStack.push(0);  
minStack.push(-3);  
minStack.getMin();   --> 返回 -3.  
minStack.pop();  
minStack.top();      --> 返回 0.  
minStack.getMin();   --> 返回 -2.  
提示：  
pop、top 和 getMin 操作总是在 非空栈 上调用。

# 思路
- ### **栈-设计**
  设计完成一个实时更新最小元素的栈，设计时由于栈顶元素会弹出，所以最小值有可能也被弹出，所以需要记录第二小的、第三小的等等，即需要将最小值与栈对应，每一个位置都有对应的最小值，所以建立栈时需要建立两个栈，push时元素栈正常工作，最小值栈需要先判断是否为空，空时直接push，否则和栈顶比较以后放入较小的一个，pop时两个正常工作即可，后面返回最小值时直接返回栈顶即可，因为已经实现实时更新的功能。53 100

# 代码
- C++ 栈-设计
```
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        s.push(x);
        if(mins.empty())    mins.push(x);
        else    mins.push(min(mins.top(),x));
    }
    void pop() {
        s.pop();
        mins.pop();   
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return mins.top();
    }
private:
    std::stack<int> mins,s;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
```
