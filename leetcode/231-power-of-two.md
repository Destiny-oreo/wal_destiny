# 题目链接
[leetcode 231](https://leetcode-cn.com/problems/power-of-two/)

# 原文
给你一个整数 `n`，请你判断该整数是否是 2 的幂次方。如果是，返回 `true` ；否则，返回 `false` 。

如果存在一个整数 `x` 使得 `n == 2x` ，则认为 `n` 是 2 的幂次方。

**示例 1：**

```
输入：n = 1
输出：true
解释：20 = 1
```

**示例 2：**

```
输入：n = 16
输出：true
解释：24 = 16
```

**示例 3：**

```
输入：n = 3
输出：false
```

**示例 4：**

```
输入：n = 4
输出：true
```

**示例 5：**

```
输入：n = 5
输出：false
```

**提示：**

- `-231 <= n <= 231 - 1`

# 思路
- ### **递归**
  判断是否为2的幂需要一直往下除2知道最后，首先想到递归来解决，先判断是否为2的倍数，如果不符合大概率是false，除非是1的情况，所以else里面便是n==1，当是2的倍数时递归判断是否为2的幂，即除以2以后传入递归函数；执行以后显示输入0时报错，发现在取余时需要首先判断是否大于0。100 77

- ### **位运算**

  更加快速的运算是采用位运算，寻找规律可以发现，当该数是2的幂时，换成二进制以后只有一位是1其余均是0，所以从这一点下手，当确保是正数以后，可以利用&运算，本身与-1相与以后将全是0。100 43

# 代码
- C++ 递归
```c++
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n>0&&n%2==0){
            return isPowerOfTwo(n/2);
        }
        else    return n==1;
    }
};
```

- C++ 位运算

```C++
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0)    return false;
        if((n&n-1)==0)    return true;
        else    return false;
    }
};
```

