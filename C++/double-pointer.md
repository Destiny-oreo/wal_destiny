# 使用双指针  
- 常用于**数组**题目
- 题目中如有`Do not allocate extra space for another array,you must do this by modifying` ` the input array in-place with O(1) extra memory.`
这对于常规的采用循环甚至双循环的方法来说**空间开销**就很大，而且题设要求不能开辟更多的空间，只能再原来的内存空间进行修改。因此，双指针法（双下标法）的用处就体现出来了。
- 算法的**思路**如下：  
初始化两个指针，一个指向数组的第一个元素（或首位置），另外一个指向数组的最后一个元素（数组末尾的位置），在两个指针相遇之前，指针1只能向前移动，指针2 只能向后移动。比较当前两个指针所指元素和与给定数字的大小，如果和较大，指针2向后移动，如果和较小，指针1向前移动。最终的结果是找到两个满足条件的数或者不存在这样的两个数字。


# 经典题目
[leetcode 5 找到字符串s中最长的回文子串](E:/English/GitHub_test/wal_destiny/leetcode/5-Longest-Palindromic-Substring.md)  
[leetcode 11 在数组中找出其中的两条线使得它们与 x 轴共同构成的容器可以容纳最多的水](E:/English/GitHub_test/wal_destiny/leetcode/11-Container-With-Most-Water.md)  
[leetcode 15 判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0](E:/English/GitHub_test/wal_destiny/leetcode/15-3Sum.md)  
[leetcode 19 删除链表的倒数第 n 个节点](E:/English/GitHub_test/wal_destiny/leetcode/19-Remove-Nth-Node-From-End-of-List.md)    
[leetcode 26 给定一个排序数组并在原地删除重复出现的元素](E:/English/GitHub_test/wal_destiny/leetcode/26-Remove-Duplicates-from-Sorted-Array.md)   
[leetcode 31 将给定数字序列重新排列成字典序中下一个更大的排列](E:/English/GitHub_test/wal_destiny/leetcode/31-Next-Permutation.md)  
[leetcode 75 原地排序少种类的数组](E:/English/GitHub_test/wal_destiny/leetcode/75-sort-colors.md)  
[leetcode 86 对链表进行特定值前后的分隔](E:/English/GitHub_test/wal_destiny/leetcode/86-partition-list.md)
[leetcode 88 将两个有序整数数组合并](E:/English/GitHub_test/wal_destiny/leetcode/88-merge-sorted-array.md)
[leetcode 92 反转从位置 m 到 n 的链表](E:/English/GitHub_test/wal_destiny/leetcode/92-reverse-linked-list-ii.md)

[leetcode 21 将两个有序链表合并为一个新的有序链表](E:/English/GitHub_test/wal_destiny/leetcode/21-Merge-Two-Sorted-Lists.md)

[leetcode 581 寻找一个连续的子数组排序，使整个数组都会变为升序排序](E:/English/GitHub_test/wal_destiny/leetcode/581-Shortest-Unsorted-Continuous-Subarray.md)








# 递归
[leetcode 21 将两个有序链表合并为一个新的有序链表](E:/English/GitHub_test/wal_destiny/leetcode/21-Merge-Two-Sorted-Lists.md)   
[leetcode 22 生成所有可能的并且有效的括号组合](E:/English/GitHub_test/wal_destiny/leetcode/22-Generate-Parentheses.md)   
[leetcode 33 在旋转的升序排列数组中寻找目标值](E:/English/GitHub_test/wal_destiny/leetcode/33-Search-in-Rotated-Sorted-Array.md)   
[leetcode 34 在数组中找出给定目标值在数组中的开始位置和结束位置](E:/English/GitHub_test/wal_destiny/leetcode/34-find-first-and-last-position-of-element-in-sorted-array.md)   
[leetcode 35 在排序数组中寻找目标值的索引或者需要插入的位置](E:/English/GitHub_test/wal_destiny/leetcode/35-Search-Insert-Position.md)   
[leetcode 38 按照给定整数的顺序进行报数](E:/English/GitHub_test/wal_destiny/leetcode/38-count-and-say.md)   
[leetcode 39 找出数组中所有可以使数字和为目标的组合——可重复](E:/English/GitHub_test/wal_destiny/leetcode/39-combination-sum.md)   
[leetcode 40 找出数组中所有可以使数字和为目标的组合——不可重复](E:/English/GitHub_test/wal_destiny/leetcode/40-combination-sum-ii.md) 
[leetcode 46 返回其所有可能的全排列](E:/English/GitHub_test/wal_destiny/leetcode/46-permutations.md)   
[leetcode 78 返回该数组所有可能的子集](E:/English/GitHub_test/wal_destiny/leetcode/78-subsets.md)   
[leetcode 79 二维网格中寻找给定的一个单词](E:/English/GitHub_test/wal_destiny/leetcode/79-word-search.md)   
[leetcode 90 返回包含重复元素的整数数组所有可能的子集](E:/English/GitHub_test/wal_destiny/leetcode/90-subsets-ii.md)   

[leetcode 21 将两个有序链表合并为一个新的有序链表](E:/English/GitHub_test/wal_destiny/leetcode/21-Merge-Two-Sorted-Lists.md)   
 

# 动态规划
[leetcode 53 找到一个具有最大和的连续子数组](E:/English/GitHub_test/wal_destiny/leetcode/53-maximum-subarray.md)   
[leetcode 55 判断根据数组中的数据能否到达最后一个位置](E:/English/GitHub_test/wal_destiny/leetcode/55-jump-game.md) 
[leetcode 62 在mxn网格到达右下角的途径数量](E:/English/GitHub_test/wal_destiny/leetcode/62-unique-paths.md)   
[leetcode 64 在mxn网格到达右下角的最小和的途径](E:/English/GitHub_test/wal_destiny/leetcode/64-minimum-path-sum.md) 
[leetcode 70 多少种不同的方法可以爬到楼顶](E:/English/GitHub_test/wal_destiny/leetcode/70-climbing-stairs.md)   
[leetcode 121 给定数组中股票价格买入卖出的最大利润](E:/English/GitHub_test/wal_destiny/leetcode/121-best-time-to-buy-and-sell-stock.md) 
[leetcode 647 计算这个字符串中有多少个回文子串](E:/English/GitHub_test/wal_destiny/leetcode/647-Palindromic-Substrings.md)
[leetcode 739 需要再等待多久温度才会升高超过该日的天数](E:/English/GitHub_test/wal_destiny/leetcode/739-Daily-Temperatures.md)






