# 题目链接
[leetcode 31](https://leetcode-cn.com/problems/next-permutation/)

# 原文
实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。

如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。

必须原地修改，只允许使用额外常数空间。

以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

# 思路
- ### **双指针**
  寻找下一个更大的排序，最小的排列是递增的，最大的排列是递减的，通过找规律发现从右边开始搜索，第一个递增的数字便是需要改变的点，如果这个点小于0说明整个排列就是最大的，直接进行翻转，如果大于等于0，说明需要在中间进行处理再翻转：首先将递增的这个点和后面序列中比此位大的数中的最小值交换，即从此位开始把新的排列开头放置完毕，再将此位以后的序列进行翻转逆序（如果前面的点小于0直接执行此步）。其中涉及到重复的位时，在找递增的点时就需要把等于的情况和小于的情况考虑在一起，同时在寻找比翻转点大的最小数时，也会涉及到重复的数，必须当完全大于时再考虑寻找最小的数。62 91

# 代码
- C++ 双指针
```
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size()<=1)  return;
        int index = nums.size()-2;
        while(index>=0&&nums[index]>=nums[index+1])   index--;
        if(index>=0){
            int right = nums.size()-1;
            while(right>index&&nums[right]<=nums[index]) right--;
            swap(nums,index,right);
        }
        reverse(nums,index+1);
    }
private:
    void swap(vector<int>& nums,int i,int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    void reverse(vector<int>& nums,int begin){
        int end = nums.size()-1;
        while(begin<end){
            swap(nums,begin++,end--);
        }
    }
};
```