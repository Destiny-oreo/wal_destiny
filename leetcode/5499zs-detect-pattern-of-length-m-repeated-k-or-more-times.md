# 题目链接
[leetcode 5499zs](https://leetcode-cn.com/problems/detect-pattern-of-length-m-repeated-k-or-more-times/)  重复至少 K 次且长度为 M 的模式

# 原文
给你一个正整数数组 arr，请你找出一个长度为 m 且在数组中至少重复 k 次的模式。  
模式 是由一个或多个值组成的子数组（连续的子序列），连续 重复多次但 不重叠 。 模式由其长度和重复次数定义。  
如果数组中存在至少重复 k 次且长度为 m 的模式，则返回 true ，否则返回  false 。  
示例 1：  
输入：arr = [1,2,4,4,4,4], m = 1, k = 3  
输出：true  
解释：模式 (4) 的长度为 1 ，且连续重复 4 次。注意，模式可以重复 k 次或更多次，但不能少于 k 次。  
示例 2：  
输入：arr = [1,2,1,2,1,1,1,3], m = 2, k = 2  
输出：true  
解释：模式 (1,2) 长度为 2 ，且连续重复 2 次。另一个符合题意的模式是 (2,1) ，同样重复 2 次。  
示例 3：  
输入：arr = [1,2,1,2,1,3], m = 2, k = 3  
输出：false  
解释：模式 (1,2) 长度为 2 ，但是只连续重复 2 次。不存在长度为 2 且至少重复 3 次的模式。  
示例 4：   
输入：arr = [1,2,3,1,2],  m = 2, k = 2    
输出：false  
解释：模式 (1,2) 出现 2 次但并不连续，所以不能算作连续重复 2 次。  
示例 5：  
输入：arr = [2,2,2,2], m = 2, k = 3  
输出：false   
解释：长度为 2 的模式只有 (2,2) ，但是只连续重复 2 次。注意，不能计算重叠的重复次数。  
提示：  
2 <= arr.length <= 100  
1 <= arr[i] <= 100  
1 <= m <= 100  
2 <= k <= 100  

# 思路
- ### **204周赛-向量**
  没有注意到题目中写的是连续重复，所以理解成了哈希表；连续重复的话使用暴力法就可以解决，从一开始到最后可以遍历的位置，判断m*k个字符是否符合即可。100 100   

# 代码
- C++ 204周赛-向量
```
class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        int n=arr.size();
        if(n<m*k)   return false;
        int j;
        for(int i=0;i<=n-m*k;i++){
            for(j=i+m;j<i+m*k;j++){
                if(arr[j]!=arr[j-m])    break;
            }
            if(j==i+m*k)    return true;
        }
        return false;
    }
};
```