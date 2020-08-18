# 题目链接
[leetcode 448](https://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array/)

# 原文
给定一个范围在  1 ≤ a[i] ≤ n ( n = 数组大小 ) 的 整型数组，数组中的元素一些出现了两次，另一些只出现一次。  
找到所有在 [1, n] 范围之间没有出现在数组中的数字。  
您能在不使用额外空间且时间复杂度为O(n)的情况下完成这个任务吗? 你可以假定返回的数组不算在额外空间内。  
示例:  
输入:  
[4,3,2,7,8,2,3,1]  
输出:  
[5,6]  

# 思路
- ### **数组**
  要求使用O1的空间复杂度，所以使用哈希表不是最好的选择（首先哈希表记录每个数字是否出现，然后遍历n，在哈希表中没有出现的放入结果中，空间复杂度On）；由于空间复杂度的限制，所以考虑找到数组坐标和数组值的联系，由于坐标是0到n-1，数组值是1-n，所以发现可以根据坐标跳到对应的数组值，存在的数组值将对应坐标的值做标记，最后没有被做标记的值的下标即为没有出现的值；对于标记，不能和当前值相同，但也不能覆盖当前的信息值，所以使用负数概念，既可以做标记，也可以在再次遍历到该值时，继续通过绝对值来访问此位置出现的数字。68 23

# 代码
- C++ 数组
```
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result;
        for(int i=0;i<nums.size();i++){
            nums[abs(nums[i])-1] = -abs(nums[abs(nums[i])-1]);
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0)   result.push_back(i+1);
        }
        return result;
    }
};
```