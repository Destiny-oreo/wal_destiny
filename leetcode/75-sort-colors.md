# 题目链接
[leetcode 75](https://leetcode-cn.com/problems/sort-colors/)

# 原文
给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。

此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。

注意:  
不能使用代码库中的排序函数来解决这道题。

示例:  
输入: [2,0,2,1,1,0]  
输出: [0,0,1,1,2,2]  
进阶：

一个直观的解决方案是使用计数排序的两趟扫描算法。
首先，迭代计算出0、1 和 2 元素的个数，然后按照0、1、2的排序，重写当前数组。
你能想出一个仅使用常数空间的一趟扫描算法吗？

# 思路
- ### **计数排序**
  由于目标数组只有三种颜色，且总的目的是把乱序的颜色分布变成有序的，所以适合使用计数排序（当颜色种类多的时候，即需要统计的种类变多时，计数排序所需要的空间复杂度也会变大），一开始需要将颜色计数，遍历一遍nums数组即可，将对应的颜色在colors里++，然后设置初始index=0，再次遍历nums数组，先判断colors[index]是否为0，如果不为0则进行填充，填充数就是index，如果为0，说明当前颜色已经被填充完毕，则index++进行到下一颜色，同时i--以免忘记填充此位。88 5
- ### **三指针**
  一趟扫描算法需要用到双指针，左右指针先设置好，然后开始循环扫描（循环结束条件为左指针超过右指针，当相遇时可能还需要调整，因为右指针指向的位置是指此位以右都是2，此位是待处理，左指针指向的位置也是待处理），循环内判断此位的颜色，如果是1不处理（因为有可能没有0，所以1不需要往后移），当遇到0时再和最前面的1交换，此时有专门的index指向最前面的1，交换以后index++来更新位置，同时left指针换过来的肯定是1，所以此位也不需要处理，left++，如果遇到2则和最后一位right交换，交换以后right--来更新，同时left交换过来的不知道是什么东西，所以还需要再次处理，left不进行更新。100 5

# 代码
- C++ 计数排序
```
class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> colors(3,0);
        for(int i=0;i<nums.size();i++){
            colors[nums[i]]++;
        }
        int index = 0;
        for(int i=0;i<nums.size();i++){
            if(colors[index]!=0){
                nums[i] = index;
                colors[index]--;
            }
            else{
                index++;
                i--;
            }
        }
    }
};
```
- C++ 三指针
```
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0,right = nums.size()-1,idnex=0;
        while(left<=right){
            if(nums[left]==1)   left++;
            else if(nums[left]==0)  swap(nums,idnex++,left++);
            else    swap(nums,left,right--);
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