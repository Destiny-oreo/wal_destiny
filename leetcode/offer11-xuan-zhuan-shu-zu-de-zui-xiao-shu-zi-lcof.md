# 题目链接
[leetcode offer11](https://leetcode-cn.com/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/)

# 原文
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如，数组 [3,4,5,1,2] 为 [1,2,3,4,5] 的一个旋转，该数组的最小值为1。   
示例 1：  
输入：[3,4,5,1,2]  
输出：1  
示例 2：  
输入：[2,2,2,0,1]  
输出：0  

# 思路
- ### **二分查找**
  题目相当于在旋转的递增数组里找到最小的数的下标，使用二分查找，当左下标比右下标小时循环查找，直到两个下标重合时找到最小值；由于计算的mid值总是偏向于左侧，所以更新时考虑left = mid+1,right = mid这一方法，与此对应的是左侧大于右侧和左侧小于右侧，最后多了一种等于的情况，这种情况需要单独考虑，比如3,1,3,3,3和3,3,3,3,1,3这两种情况，使用上述思路怎样都无法完美解决，所以当等于时，无法知道最小值在左侧还是在右侧，于是right--即可或者left++。94 100
- ### **双指针**
  找规律以后发现，第一个变小的数就是最小的元素，所以两边同时检查，当需要右边的比坐标的小时，则小的那个元素就是最小值，如果搜完也没有发现则返回第一个元素。67 100

# 代码
- C++ 二分查找
```
class Solution {
public:
    int minArray(vector<int>& numbers) {
        int left = 0, right = numbers.size()-1;
        while(left<right){
            int mid = left + (right-left)/2;
            if(numbers[mid]<numbers[right]){
                right = mid;
            }
            else if(numbers[mid]>numbers[right]){
                left = mid+1;
            }
            else{
                right--;
            }
        }
        return numbers[left];
    }
};
```
- C++ 双指针
```
class Solution {
public:
    int minArray(vector<int>& numbers) {
        int left = 0,right = numbers.size()-1;
        while(left<right){
            int temp = numbers[left++];
            if(numbers[left]<temp){
                return numbers[left];
            }
            temp = numbers[right--];
            if(numbers[right]>temp){
                return numbers[right+1];
            }
        }
        return numbers[0];
    }
};
```
