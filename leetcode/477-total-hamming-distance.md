# 题目链接
[leetcode 477](https://leetcode-cn.com/problems/total-hamming-distance/)汉明距离总和

# 原文
两个整数的 [汉明距离](https://baike.baidu.com/item/汉明距离/475174?fr=aladdin) 指的是这两个数字的二进制数对应位不同的数量。

给你一个整数数组 `nums`，请你计算并返回 `nums` 中任意两个数之间汉明距离的总和。

**示例 1：**

```
输入：nums = [4,14,2]
输出：6
解释：在二进制表示中，4 表示为 0100 ，14 表示为 1110 ，2表示为 0010 。（这样表示是为了体现后四位之间关系）
所以答案为：
HammingDistance(4, 14) + HammingDistance(4, 2) + HammingDistance(14, 2) = 2 + 2 + 2 = 6
```

**示例 2：**

```
输入：nums = [4,14,4]
输出：4
```

**提示：**

- `1 <= nums.length <= 105`
- `0 <= nums[i] <= 109`

# 思路
- ### **位运算**
  汉明码需要计算对应位上的二进制数是否相同，涉及汉明码基本都需要位运算& >> <<等；根据输入范围确定最大位数不超过32位，每一位进行遍历，寻找规律发现每一位上的汉明距离总和为0的数量乘以1的数量，所以对于每一位，只要计算所有数字上1的数量即可，使用&1来完成，然后进行>>=1来更新；剪枝通过计算某一位时，所有数字后续全都为0时不需要再进行计算，即此时所有数字右移以后都是00000...，直接退出遍历。21 77

# 代码
- C++ 位运算
```c++
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int result = 0;
        int lens = nums.size();
        for (int i=0;i<32;i++){
            int ones = 0;
            int zeros = 0;
            for(int j=0;j<lens;j++){
                ones += nums[j]&1;
                nums[j] >>= 1;
                zeros += nums[j]==0?1:0;
            }
            result += ones*(lens-ones);
            if(zeros == lens)   break;
        }
        return result;
    }
};
```