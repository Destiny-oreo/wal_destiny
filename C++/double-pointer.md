# 使用双指针  
- 常用于**数组**题目
- 题目中如有`Do not allocate extra space for another array,you must do this by modifying` ` the input array in-place with O(1) extra memory.`
这对于常规的采用循环甚至双循环的方法来说**空间开销**就很大，而且题设要求不能开辟更多的空间，只能再原来的内存空间进行修改。因此，双指针法（双下标法）的用处就体现出来了。
- 算法的**思路**如下：  
初始化两个指针，一个指向数组的第一个元素（或首位置），另外一个指向数组的最后一个元素（数组末尾的位置），在两个指针相遇之前，指针1只能向前移动，指针2 只能向后移动。比较当前两个指针所指元素和与给定数字的大小，如果和较大，指针2向后移动，如果和较小，指针1向前移动。最终的结果是找到两个满足条件的数或者不存在这样的两个数字。


# 经典题目
[leetcode 581 寻找一个连续的子数组排序，使整个数组都会变为升序排序](E:/English/GitHub_test/wal_destiny/leetcode/581-Shortest-Unsorted-Continuous-Subarray.md)
