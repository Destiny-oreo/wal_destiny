# 题目链接
[leetcode 88](https://leetcode-cn.com/problems/merge-sorted-array/)

# 原文
给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。  
说明:  
初始化 nums1 和 nums2 的元素数量分别为 m 和 n。  
你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。  
示例:  
输入:  
nums1 = [1,2,3,0,0,0], m = 3  
nums2 = [2,5,6],       n = 3

输出: [1,2,2,3,5,6]

# 思路
- ### **链表 双指针**
  虽然给定了两个数组，但是需要将数组2插入到数组1中（已经提前预留了足够空间），即原地改变数组1的排列，所以考虑使用双指针（三指针）。因为数组1中原来的有效节点不能被覆盖，所以考虑从后向前进行填充（由于原数组已经是有序的，所以无论如何排列，都不会覆盖前面的小数值的节点）。首先定义好从后向前的指针，再while循环此指针，只要≥0就继续循环，循环中，先判断边界情况，即到达第一位时，如果不特殊处理，当一个数组的第一位处理过以后会减减变成负数，下次把次指针带入会越界；所以判断如果第二个数组处理完以后，此时已经不用考虑剩下的（因为已经没有可以与之相比较的），如果第一个数组处理完以后直接将第二个数组的各个数逐个添加至1中；如果不是特殊情况，就正常比较数组1和2的数值大小，大的放到index指针下。100 9

# 代码
- C++ 链表 双指针
```
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int idnex = m+n-1;
        m--;n--;
        while(idnex>=0){
            if(n<0) return;
            // else if(m<0){
            //     nums1[idnex--] = nums2[n--];
            //     continue;
            // }
            else if(m<0||nums1[m]<nums2[n]){
                nums1[idnex--] = nums2[n--];
            }
            else{
                nums1[idnex--] = nums1[m--];
            }
        }
    }
};
```
