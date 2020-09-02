# 题目链接
[leetcode 560](https://leetcode-cn.com/problems/subarray-sum-equals-k/)

# 原文
给定一个整数数组和一个整数 k，你需要找到该数组中和为 k 的连续的子数组的个数。
示例 1 :  
输入:nums = [1,1,1], k = 2
输出: 2 , [1,1] 与 [1,1] 为两种不同的情况。  
说明 :  
数组的长度为 [1, 20,000]。
数组中元素的范围是 [-1000, 1000] ，且整数 k 的范围是 [-1e7, 1e7]。

# 思路
建立**哈希表**，赋初始关键字0的值为1，后面逐个遍历num数组，每遍历一个即累计求和为sum，在哈希表中查找sum-k是否存在，存在的话代表有一连续子序列从sum-k开始到此位结束符合题目要求，更新result+=map[sum-k]（不是+=1是因为到sum-k为止有可能有多个情况）；接着更新实时的sum值，如何已经存在直接+1，否则更新为1。

# 代码
- C++ 哈希
```
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> hash;
        hash[0] = 1;
        int sum = 0,result = 0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(hash.find(sum-k)!=hash.end()){//找到一段目标，更新result
                result+=hash[sum-k];
            }
            if(hash.find(sum)!=hash.end()){
                hash[sum] += 1;
            }
            else{
                hash[sum] = 1;
            }
        }
        return result;
    }
};
```