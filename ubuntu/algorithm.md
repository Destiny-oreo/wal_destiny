### 小抄

### 开篇

- 动态规划解题框架

  > 1. 一般形式：求最值，核心问题：穷举
  > 2. 三要素：重叠子问题、最优子结构、状态转移方程
  > 3. 明确状态->定义dp数组的含义->明确选择->明确base case

- 回溯算法详解

  > 1. 决策树遍历过程->回溯问题
  >
  > 2. 3个问题：路径、选择列表、结束条件
  >
  > 3. 框架
  >
  >    ```python
  >    result = []
  >    def backtrack(路径，选择列表):
  >        if 满足结束条件:
  >            result.add(路径)
  >            return
  >        for 选择 in 选择列表 :
  >            做选择
  >            backtrack(路径，选择列表)
  >            撤销选择
  >    ```
  
- BFS算法解题框架

  > 1. 框架
  >
  >    ```java
  >    int BFS(Node start,Node target){
  >    	Queue<Node> q;
  >        Set<Node> visited;
  >        q.offer(start);
  >        visited.add(start);
  >        int step = 0;
  >        while(q not empty){
  >            int sz = q.size();
  >            for(int i=0;i<sz;i++){
  >                Node cur = q.poll();
  >                if(cur is target){
  >                    return step;
  >                }
  >                for(Node x:cur.adj()){
  >                    if(x not in visited){
  >                        q.offer(x);
  >                        visited.add(x);
  >                    }
  >                }
  >            }
  >        	step++;
  >        }
  >    }
  >    ```
  >
  > 2. 双向BFS优化
  >
  >    ```
  >    传统BFS框架是从起点开始向四周扩散，遇到终点时停止，双向BFS从起点和终点同时开始扩散，当两边有交集时停止（前提：必须知道终点在哪）
  >    不需要使用队列，而是使用HashSet方便快速判断两个集合是否有交集
  >    无论传统BFS还是双向BFS，无论做不做优化，时间复杂度都是一样的。
  >    ```
  
- 二分搜索框架

  > 1. 框架
  >
  >    ```c++
  >    int binarySearch(int[] nums,int target){
  >        int left=0,right=...;
  >        while(){
  >            int mid = left+(right-left)/2;
  >            if(nums[mid]==target){
  >                ...
  >            }
  >            else if(nums[mid]<target){
  >                left = mid+1;
  >                ...
  >            }
  >            else if(nums[mid]>target){
  >                right = mid-1;
  >                ...
  >            }
  >        }
  >        return ...;
  >    }
  >    ```
  >
  > 2. 注意
  >
  >    1. 注意搜索区间和while的终止条件
  >    2. 注意左闭右开还是左右都闭的所搜区间

- 滑动窗口算法题

  > 1. 逻辑框架
  >
  >    ```C++
  >    int left =0, right = 0;
  >    while(right < s.szie()){
  >        windows,add(s[right]);
  >        right++;
  >        while(windows needs shrink){
  >            windows.remove(s[left]);
  >            left++;
  >        }
  >    }
  >    ```

- 股票买卖问题

  > 1. 诡异高效解法
  >
  >    ```c++
  >    int maxProfit(vector<int>& prices){
  >        if(prices.empty())	return 0;
  >        int s1=-prices[0],s2=INT_MIN,s3=INT_MIN,s4=INT_MIN;
  >        fo r(int i=1;i<prices.size();i++){
  >            s1=max(s1,-prices[i]);
  >            s2=max(s2,s1+prices[i]);
  >            s3=max(s3,s2-prices[i]);
  >            s4=max(s4,s3+prices[i]);
  >        }
  >        return max(0,s4);
  >    }
  >    ```
  >
  >    

### 动态规划系列

- 前言

  > 1. 一般流程三步：暴力的递归解法、带备忘录的递归解法、迭代的动态规划解法
  > 2. 找到状态和选择、明确dp数组函数的定义、寻找状态之间的关系



### 数据结构系列



### 常用数据结构

- C++ STL

  > 1. 维持顺序的容器
  >    1. vector 动态数组，O1随机读取，尾部增删的复杂度O1
  >    2. list 双向链表 很少使用
  >    3. deque 双端队列 很强大 O1随机读取和O1头部增删尾部增删
  >    4. array 固定大小的数组 刷题很少用
  >    5. forward_list 单向链表 刷题很少用
  > 2. Container Adaptors 基于其他容器实现的数据结构
  >    1. stack LIFO 基于deque实现，常用语深度优先搜索、字符串匹配以及单调栈问题
  >    2. queue FIFO 基于deque实现，常用语广度优先搜索
  >    3. priority_queue 最大值先出的数据结构 基于vector实现堆结构 可以再Onlogn时间排序数组，Ologn时间插入任意值 O1时间获得最大值 Ologn时间 删除最大值 常用于维护数据结构并快速获取最大最小值
  > 3. Associative Containers 实现排好序的数据结构
  >    1. set 有序集合 元素不可重复 底层红黑树实现即特殊的二叉查找树BST 
  >    2. multiset 支持重复元素的set
  >    3. map 有序映射或有序表 set的基础上加上映射关系 对每个key存一个value
  >    4. multimap 支持重复元素的map
  > 4. Unordered Associative Containers：对每个 Associative Containers 实现了哈希版本。
  >    1. unordered_set：哈希集合，可以在 O(1) 的时间快速插入、查找、删除元素，常用于快
  >       速的查询一个元素是否在这个容器内。
  >    2.  unordered_multiset：支持重复元素的 unordered_set。
  >    3.  unordered_map：哈希映射或哈希表，在 unordered_set 的基础上加上映射关系，可以对每一个元素 key 存一个值 value。在某些情况下，如果 key 的范围已知且较小，我们也可以用 vector 代替 unordered_map，用位置表示 key，用每个位置的值表示 value。
  >    4.  unordered_multimap：支持重复元素的 unordered_map。



## 高频题分类

### 排序类

- 基础知识

  > 快速排序、归并排序
  >
  > 需要能讲明白代码中每一行的目的。快速排序时间复杂度平均状态下 O（NlogN），空间复杂度 O（1），归并排序最坏情况下时间复杂度 O（NlogN），空间复杂度 O（N）
  >
  > 

- 题目

  > - Leetcode 148. Sort List
  > - Leetcode 56. Merge Intervals
  > - Leetcode 27. Remove elements
  >
  > ---
  >
  > - Leetcode 179. Largest Number
  > - Leetcode 75. Sort Colors
  > - Leetcode 215. Kth Largest Element
  > - Leetcode 4. Median of Two Sorted Arrays

  

### 链表类

- 基础知识

  > 链表如何实现，如何遍历链表。链表可以保证头部尾部插入删除操作都是 O（1），查找任意元素位置 O（N）

- 题目

  > - ~~Leetcode 206. Reverse Linked List~~
  > - ~~Leetcode 876. Middle of the Linked List~~
  >
  > ---
  >
  > - ~~Leetcode 160. Intersection of Two Linked Lists~~
  > - ~~Leetcode 141. Linked List Cycle (Linked List Cycle II)~~
  > - ~~Leetcode 92. Reverse Linked List II~~
  > - ~~Leetcode 328. Odd Even Linked List~~

### 堆、栈、队列、哈希表

- 基础知识

  > 各个数据结构的基本原理，增删查改复杂度。

- Queue题目

  > - ~~Leetcode 225. Implement Stack using Queues~~
  > - `~~Leetcode 346. Moving Average from Data Stream~~`
  > - `~~Leetcode 281. Zigzag Iterator~~`
  > - `~~Leetcode 1429. First Unique Number~~`
  > - ~~Leetcode 54. Spiral Matrix~~
  > - `~~Leetcode 362. Design Hit Counter~~`

- Stack题目

  > - ~~Leetcode 155. Min Stack (follow up Leetcode 716 Max Stack)~~
  > - ~~Leetcode 232. Implement Queue using Stacks~~
  > - ~~Leetcode 150. Evaluate Reverse Polish Notation~~
  > - ~~Leetcode 224. Basic Calculator II (I, II, III, IV)~~
  > - ~~Leetcode 20. Valid Parentheses~~
  > - ~~Leetcode 1472. Design Browser History~~
  > - Leetcode 1209. Remove All Adjacent Duplicates in String II
  > - Leetcode 1249. Minimum Remove to Make Valid Parentheses
  > - Leetcode 735. Asteroid Collision

- Hashmap/Hashset

  > - Leetcode 1. Two Sum
  > - Leetcode 146. LRU Cache (Python 中可以使用 OrderedDict 来代替)
  > - Leetcode 128. Longest Consecutive Sequence
  > - Leetcode 73. Set Matrix Zeroes
  > - Leetcode 380. Insert Delete GetRandom O(1)
  > - Leetcode 49. Group Anagrams
  > - Leetcode 350. Intersection of Two Arrays II
  > - Leetcode 299. Bulls and Cows
  > - Leetcode 348 Design Tic-Tac-Toe

- Heap/Priority Queue

  > - Leetcode 973. K Closest Points
  > - Leetcode 347. Top k Largest Elements
  > - Leetcode 23. Merge K Sorted Lists
  > - Leetcode 264. Ugly Number II
  > - Leetcode 1086. High Five
  > - Leetcode 88. Merge Sorted Arrays
  > - Leetcode 692. Top K Frequent Words
  > - Leetcode 378. Kth Smallest Element in a Sorted Matrix
  > - Leetcode 295. Find Median from Data Stream （标准解法是双 heap，但是 SortedDict 会非常容易）
  > - Leetcode 767. Reorganize String
  > - Leetcode 1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit (这个题用单调双端队列、TreeMap、双 heap 都可以)
  > - Leetcode 895. Maximum Frequency Stack

### 二分法

- 基础

  > 二分法是用来解法基本模板，时间复杂度 logN；常见的二分法题目可以分为两大类，显式与隐式，即是否能从字面上一眼看出二分法的特点：要查找的数据是否可以分为两部分，前半部分为 X，后半部分为 O

- 显式二分法

  > - Leetcode 34. Find First and Last Position of Element in Sorted Array
  > - Leetcode 33. Search in Rotated Sorted Array
  > - Leetcode 1095. Find in Mountain Array
  > - Leetcode 162. Find Peak Element
  > - Leetcode 278. First Bad Version
  > - Leetcode 74. Search a 2D Matrix
  > - Leetcode 240. Search a 2D Matrix II

- 隐式二分法

  > - Leetcode 69. Sqrt(x)
  > - Leetcode 540. Single Element in a Sorted Array
  > - Leetcode 644. Maximum Average Subarray II
  > - Leetcode 528. Random Pick with Weight
  > - Leetcode 1300. Sum of Mutated Array Closest to Target
  > - Leetcode 1060. Missing Element in Sorted Array
  > - Leetcode 1062. Longest Repeating Substring
  > - Leetcode 1891. Cutting Ribbons

### 双指针

- 基础知识

  > 常见双指针算法分为三类，同向（即两个指针都相同一个方向移动），背向（两个指针从相同或者相邻的位置出发，背向移动直到其中一根指针到达边界为止），相向（两个指针从两边出发一起向中间移动直到两个指针相遇）

- 背向双指针(回文串)

  > - Leetcode 409. Longest Palindrome
  > - Leetcode 125. Valid Palindrome
  > - Leetcode 5. Longest Palindromic Substring

- 相向双指针

  > - Leetcode 1. Two Sum (这里使用的是先排序的双指针算法，不同于 hashmap 做法)
  > - Leetcode 167. Two Sum II - Input array is sorted
  > - Leetcode 15. 3Sum
  > - Leetcode 16. 3Sum Closest
  > - Leetcode 18. 4Sum
  > - Leetcode 454. 4Sum II
  > - Leetcode 277. Find the Celebrity
  > - Leetcode 11. Container With Most Water

- 同向双指针

  > - Leetcode 283. Move Zeroes
  > - Leetcode 26. Remove Duplicate Numbers in Array
  > - Leetcode 395. Longest Substring with At Least K Repeating Characters
  > - Leetcode 340. Longest Substring with At Most K Distinct Characters
  > - Leetcode 424. Longest Repeating Character Replacement
  > - Leetcode 76. Minimum Window Substring
  > - Leetcode 3. Longest Substring Without Repeating Characters
  > - Leetcode 1004 Max Consecutive Ones III

### 宽度优先搜索

- 基础知识

  > 1. 常见的 BFS 用来解决什么问题？(1) 简单图（有向无向皆可）的最短路径长度，注意是长度而不是具体的路径（2）拓扑排序 （3） 遍历一个图（或者树）
  > 2. BFS 基本模板（需要记录层数或者不需要记录层数）
  > 3. 多数情况下时间复杂度空间复杂度都是 O（N+M），N 为节点个数，M 为边的个数
  > 4. 基于树的 BFS：不需要专门一个 set 来记录访问过的节点


- 基于树的 BFS：不需要专门一个 set 来记录访问过的节点

  > - Leetcode 102 Binary Tree Level Order Traversal
  > - Leetcode 103 Binary Tree Zigzag Level Order Traversal
  > - Leetcode 297 Serialize and Deserialize Binary Tree （很好的 BFS 和双指针结合的题）
  > - Leetcode 314 Binary Tree Vertical Order Traversal

- 基于图的 BFS：（一般需要一个 set 来记录访问过的节点）

  > - Leetcode 200. Number of Islands
  > - Leetcode 133. Clone Graph
  > - Leetcode 127. Word Ladder
  > - Leetcode 490. The Maze
  > - Leetcode 323. Connected Component in Undirected Graph
  > - Leetcode 130. Surrounded Regions
  > - Leetcode 752. Open the Lock
  > - Leetcode 815. Bus Routes
  > - Leetcode 1091. Shortest Path in Binary Matrix
  > - Leetcode 542. 01 Matrix
  > - Leetcode 1293. Shortest Path in a Grid with Obstacles Elimination

- 拓扑排序

  > - Leetcode 207 Course Schedule （I, II）
  > - Leetcode 444 Sequence Reconstruction
  > - Leetcode 269 Alien Dictionary

### 深度优先搜索（DFS）

- 基础知识

  > - 常见的 DFS 用来解决什么问题？(1) 图中（有向无向皆可）的符合某种特征（比如最长）的路径以及长度（2）排列组合（3） 遍历一个图（或者树）（4）找出图或者树中符合题目要求的全部方案
  > - DFS 基本模板（需要记录路径，不需要返回值 and 不需要记录路径，但需要记录某些特征的返回值）
  > - 除了遍历之外多数情况下时间复杂度是指数级别，一般是 O(方案数 × 找到每个方案的时间复杂度)
  > - 递归题目都可以用非递归迭代的方法写，但一般实现起来非常麻烦

- 基于树的 DFS：需要记住递归写前序中序后序遍历二叉树的模板

  > - Leetcode 543 Diameter of Binary Tree
  > - Leetcode 226 Invert Binary Tree
  > - Leetcode 101 Symmetric Tree
  > - Leetcode 951 Flip Equivalent Binary Trees
  > - Leetcode 124 Binary Tree Maximum Path Sum
  > - Leetcode 236 Lowest Common Ancestor of a Binary Tree (相似题：235、1650)
  > - Leetcode 105 Construct Binary Tree from Preorder and Inorder Traversal
  > - Leetcode 104 Maximum Depth of Binary Tree
  > - Leetcode 987 Vertical Order Traversal of a Binary Tree
  > - Leetcode 1485 Clone Binary Tree With Random Pointer
  > - Leetcode 572 Subtree of Another Tree
  > - Leetcode 863 All Nodes Distance K in Binary Tree
  > - Leetcode 1110 Delete Nodes And Return Forest

- 二叉搜索树（BST）

  > BST 特征：中序遍历为单调递增的二叉树，换句话说，根节点的值比左子树任意节点值都大，比右子树任意节点值都小，增删查改均为 O（h）复杂度，h 为树的高度；注意不是所有的 BST 题目都需要递归，有的题目只需要 while 循环即可
  >
  > - Leetcode 230 Kth Smallest element in a BST
  > - Leetcode 98 Validate Binary Search Tree
  > - Leetcode 270 Cloest Binary Search Tree Value
  > - Leetcode 235 Lowest Common Ancestor of a Binary Search Tree
  > - Leetcode 669 Trim a Binary Search Tree
  > - Leetcode 700 Search in a Binary Search Tree
  > - Leetcode 108 Convert Sorted Array to Binary Search Tree
  > - Leetcode 333 Largest BST Subtree (与 98 类似)
  > - Leetcode 285 Inorder Successor in BST (I, II)


- 基于图的 DFS

  > 和 BFS 一样一般需要一个 set 来记录访问过的节点，避免重复访问造成死循环; Word XXX 系列面试中非常常见，例如 word break，word ladder，word pattern，word search。
  >
  > - Leetcode 341 Flatten Nested List Iterator (339 364)
  > - Leetcode 394 Decode String
  > - Leetcode 51 N-Queens (I II 基本相同)
  > - Leetcode 291 Word Pattern II (I 为简单的 Hashmap 题)
  > - Leetcode 126 Word Ladder II （I 为 BFS 题目）
  > - Leetcode 93 Restore IP Addresses
  > - Leetcode 22 Generate Parentheses
  > - Leetcode 586 Score of Parentheses
  > - Leetcode 301 Remove Invalid Parentheses
  > - Leetcode 37 Sodoku Solver
  > - Leetcode 212 Word Search II （I, II）
  > - Leetcode 1087 Brace Expansion
  > - Leetcode 399 Evaluate Division
  > - Leetcode 1274 Number of Ships in a Rectangle
  > - Leetcode 1376 Time Needed to Inform All Employees
  > - Leetcode 694 Number of Distinct Islands
  > - Leetcode 131 Palindrome Partitioning

- 基于排列组合的 DFS: 其实与图类 DFS 方法一致，但是排列组合的特征更明显

  > - Leetcode 17 Letter Combinations of a Phone Number
  > - Leetcode 39 Combination Sum（I, II, III 相似， IV 为动态规划题目）
  > - Leetcode 78 Subsets （I, II 重点在于如何去重）
  > - Leetcode 46 Permutation (I, II 重点在于如何去重)
  > - Leetcode 77 Combinations (I, II 重点在于如何去重)
  > - Leetcode 698 Partition to K Equal Sum Subsets
  > - Leetcode 526 Beautiful Arrangement (similar to 46)

- 记忆化搜索（DFS + Memoization Search）

  > 算是动态规划的一种，递归每次返回时同时记录下已访问过的节点特征，避免重复访问同一个节点，可以有效的把指数级别的 DFS 时间复杂度降为多项式级别; 注意这一类的 DFS 必须在最后有返回值，不可以用排列组合类型的 DFS 方法写; for 循环的 dp 题目都可以用记忆化搜索的方式写，但是不是所有的记忆化搜索题目都可以用 for 循环的 dp 方式写。
  >
  > - Leetcode 139 Word Break II
  > - Leetcode 72 Edit Distance
  > - Leetcode 377 Combination Sum IV
  > - Leetcode 1235 [Maximum Profit in Job Scheduling](https://leetcode.com/explore/item/3950)
  > - Leetcode 1335 Minimum Difficulty of a Job Schedule
  > - Leetcode 1216 Valid Palindrome III
  > - Leetcode 97 Interleaving String
  > - Leetcode 472 Concatenated Words
  > - Leetcode 403 Frog Jump
  > - Leetcode 329 Longest Increasing Path in a Matrix

### 前缀和

- 基础知识

  > 前缀和本质上是在一个 list 当中，用 O（N）的时间提前算好从第 0 个数字到第 i 个数字之和，在后续使用中可以在 O（1）时间内计算出第 i 到第 j 个数字之和，一般很少单独作为一道题出现，而是很多题目中的用到的一个小技巧

- 题目

  > - Leetcode 53 Maximum Subarray
  > - Leetcode 1423 Maximum Points You Can Obtain from Cards
  > - Leetcode 1031 Maximum Sum of Two Non-Overlapping Subarrays
  > - Leetcode 523 Continuous Subarray Sum
  > - Leetcode 304 Range Sum Query 2D - Immutable
