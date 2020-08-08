# 题目链接
[leetcode 283](https://leetcode-cn.com/problems/move-zeroes/)

# 原文
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。  
示例:  
输入: [0,1,0,3,12]  
输出: [1,3,12,0,0]  
说明:  
必须在原数组上操作，不能拷贝额外的数组。  
尽量减少操作次数。

# 思路
- ### **双指针**
  根据题目意思，此题适合使用双指针来达到在原数组上操作的要求；使用了三种代码：  
  第一种：左右指针，左指针不遇到0时一起+1，左指针遇到0时，判断右指针，右指针如果也为0，右指针++，继续循环（循环结束条件为右指针越界），当右指针不为0时，左右指针数字交换再++，达到将左边的0改成后面最近的一个非0数。53 20  
  第二种：temp指针代表左边不为0的坐标，遍历向量，遇到非0的数就赋值给temp++，使temp全程记录了所有的非0数，最后退出循环后再将temp及以后的位置全部赋0.  
  第三种：类似于第二种，temp指针记录非0的最新下标，遍历向量的指针遇到非0时开始操作，首先判断非0的坐标是否和temp一致（即是否temp下标已经是非0的数，是的话直接一起++，不需要交换），不是的话说明temp位置是个0，交换数值以后一起++。

# 代码
- C++ 双指针
```
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0,right = 1;
        while(right<nums.size()){
            if(nums[left]==0){
                if(nums[right]==0)  right++;
                else{
                    swap(nums,left++,right++);
                }
            }
            else {
                left++;right++;
            }
        }
    }
private:
    void swap(vector<int>& nums,int i,int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
};
```
```
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0,temp = 0;
        for(i=0;i<nums.size();i++){
            if(nums[i]!=0){
                nums[temp++] = nums[i];
            }
        }
        while(temp<nums.size()){
            nums[temp++] = 0;
        }
    }
};
```
```
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int temp = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                if(i!=temp){
                    nums[temp++] = nums[i];
                    nums[i] = 0;
                }
                else{
                    temp++;
                }
            }
        }
    }
};
```