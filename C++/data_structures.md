## 绪论  

**结构**：  
- 逻辑结构  
线性结构、树形结构、图结构、集合结构。  
- 存储结构  
顺序存储结构、链式存储结构
- 数据运算  
搜素运算、插入运算、删除运算、更新运算。

**时间复杂度**：  
- 程序运行从开始到结束所需的时间（事后统计法、**事前估算法**）——大O记号：渐进时间复杂度，表示运行时间的上限。 
  
**空间复杂度**：对应的程序从运行开始到结束所需的存储量（固定部分、可变部分）  

## 线性表 


## [并查集](https://www.jianshu.com/p/fc17847b0a31)

## [字符串匹配算法]
- BF算法：（BruteForce暴力算法）O(m*n)；
- RK算法：(Rabin-Karp)使用哈希值来比较字符子串，时间复杂度O(n)，缺点是可能产生哈希冲突的现象，如果出现冲突的次数比较多，就和BF算法一样了；
- [BM算法](https://blog.csdn.net/qq_21201267/article/details/92799488)：（Boyer-Moore）使用坏字符和好后缀来完成suffix，prefix等，从模式串的右边逆序遍历，计算最大滑动位数；
- KMP算法：（Knuth-Morria-Pratt）O(m+n)
```
class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        vector<int> fail(n, -1);
        for (int i = 1; i < n; ++i) {
            int j = fail[i - 1];
            while (j != -1 && s[j + 1] != s[i]) {
                j = fail[j];
            }
            if (s[j + 1] == s[i]) {
                fail[i] = j + 1;
            }
        }
        int best = -1;
        for (int i = n - 1; i >= 0; --i) {
            while (best != -1 && s[best + 1] != s[i]) {
                best = fail[best];
            }
            if (s[best + 1] == s[i]) {
                ++best;
            }
        }
        string add = (best == n - 1 ? "" : s.substr(best + 1, n));
        reverse(add.begin(), add.end());
        return add + s;
    }
};

```


## 笔记
- [int 最大值最小值](https://blog.csdn.net/jyy208/article/details/7479113)int类型为4字节32比特，最大值：正数时最高位为0，所以最大值即为0111 1111:1111为2^31-1;最小值：负数的二进制用补码表示，首先-(2^31-1)为1000 0000:0001，所以-2^31二进制为1000:0000
- [回文算法](https://leetcode-cn.com/problems/shortest-palindrome/solution/zui-duan-hui-wen-chuan-by-leetcode-solution/)使用正反序的ascll码进行对比（还有KMP算法）
- 字符串反转函数 reverse(str.begin(),str.end())
