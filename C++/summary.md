# 算法整理     
114结束
---------------------------
## 二分
[leetcode 29两数相除](https://leetcode-cn.com/problems/divide-two-integers/)--[笔记](../leetcode/29-divide-two-integers.md)将两数相除，要求不使用乘法、除法和 mod 运算符计算商，需要截去小数部分。（二分思想）
[leetcode 33在有序但旋转过的数组中搜索目标](https://leetcode-cn.com/problems/search-in-rotated-sorted-array/)--[笔记](../leetcode/33-search-in-rotated-sorted-array.md)假设按照升序排序的数组在预先未知的某个点上进行了旋转，寻找目标数字的下标（改进的二分查找）
[leetcode 34寻找目标值在数组中的开始和结束位置](https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/)--[笔记](../leetcode/34-find-first-and-last-position-of-element-in-sorted-array.md)给定一个按照升序排列的重复整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。（循环边界二分查找）
[leetcode 35在有序数组中找到目标下标或待插入下标](https://leetcode-cn.com/problems/search-in-rotated-sorted-array/)--[笔记](../leetcode/35-search-in-rotated-sorted-array.md)给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
[leetcode 50幂函数x的n次方](https://leetcode-cn.com/problems/powx-n/)--[笔记](../leetcode/50-powx-n.md)实现 pow(x, n) ，即计算 x 的 n 次幂函数。

## 双指针
[leetcode 3无重复字符的最长子串](https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/)--[笔记](../leetcode/3-longest-substring-without-repeating-characters.md)找出字符串中不含有重复字符的最长子串的长度
[leetcode 5最长回文子串](https://leetcode-cn.com/problems/longest-palindromic-substring/)--[笔记](../leetcode/5-longest-palindromic-substring.md)返回给定字符串中最长的回文子字符串
[leetcode 11盛最多水的容器](https://leetcode-cn.com/problems/container-with-most-water/)--[笔记](../leetcode/11-container-with-most-water.md)数组中每个数代表一条垂线，求出容器能够容纳水的最大值
[leetcode 15三数之和](https://leetcode-cn.com/problems/3sum/)--[笔记](../leetcode/15-3sum.md)在给定乱序数组中找出三个元素使之和为0
[leetcode 19删除链表倒数第n个节点](https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/)--[笔记](../leetcode/19-remove-nth-node-from-end-of-list.md)给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点
[leetcode 26删除数组中重复节点](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/)--[笔记](../leetcode/26-remove-duplicates-from-sorted-array.md)在排序数组中原地删除重复出现的元素，返回新长度并不考虑超出新长度后的元素
[leetcode 31下一个排列](https://leetcode-cn.com/problems/next-permutation/)--[笔记](../leetcode/31-next-permutation.md)实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。
[leetcode 75三颜色排序](https://leetcode-cn.com/problems/sort-colors/)--[笔记](../leetcode/75-sort-colors.md)给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。（三指针、计数排序
[leetcode 86链表排序](https://leetcode-cn.com/problems/partition-list/)--[笔记](../leetcode/86-partition-list.md)给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前，需要保留两个分区中每个节点的相对位置。
[leetcode 88合并排序数组](https://leetcode-cn.com/problems/merge-sorted-array/)--[笔记](../leetcode/88-merge-sorted-array.md)给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。 
[leetcode 92反转部分排序链表2](https://leetcode-cn.com/problems/reverse-linked-list-ii/)--[笔记](../leetcode/92-reverse-linked-list-ii.md)反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。


## 哈希表
[leetcode 1两数之和](https://leetcode-cn.com/problems/two-sum/)--[笔记](../leetcode/1-Two-Sum.md)从乱序数组中找出和为目标值的那两个整数的下标
[leetcode 13罗马数字转整数 ](https://leetcode-cn.com/problems/roman-to-integer/)--[笔记](../leetcode/13-roman-to-integer.md)将七种字符: I， V， X， L，C，D 和 M组成的罗马数字转为整数
[leetcode 36有效的数独](https://leetcode-cn.com/problems/valid-sudoku/)--[笔记](../leetcode/36-valid-sudoku.md)判断一个 9x9 的数独是否有效，只包含数字 1-9 和字符 '. ' 
[leetcode 49异位词组合](https://leetcode-cn.com/problems/group-anagrams/)--[笔记](../leetcode/49-group-anagrams.md)将字符串数组中字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。 （字符串转向量

## dfs+回溯-递归
[leetcode 17电话按键数字转字符串](https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/)--[笔记](../leetcode/17-letter-combinations-of-a-phone-number.md)将给定只包含2-9的字符串转为所有能表示的字母组合字符串，映射关系与电话按键相同
[leetcode 39组合求和 可重复](https://leetcode-cn.com/problems/combination-sum/)--[笔记](../leetcode/39-combination-sum.md)给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合，可被重复选取。（无重复元素
[leetcode 40组合求和2不可重复](https://leetcode-cn.com/problems/combination-sum-ii/)--[笔记](../leetcode/40-combination-sum-ii.md)给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合，每个数字只能使用一次。（有重复元素-set或者算法去重
[leetcode 46全排列](https://leetcode-cn.com/problems/permutations/)--[笔记](../leetcode/46-permutations.md)给定一个没有重复数字的序列，返回其所有可能的全排列。
[leetcode 78不重复的子集](https://leetcode-cn.com/problems/subsets/)--[笔记](../leetcode/78-subsets.md)给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
[leetcode 79单词寻找](https://leetcode-cn.com/problems/word-search/)--[笔记](../leetcode/79-word-search.md)给定一个二维网格和一个单词，找出该单词是否存在于网格中，同一个单元格内的字母不允许被重复使用。
[leetcode 90子串集2](https://leetcode-cn.com/problems/subsets-ii/)--[笔记](../leetcode/90-subsets-ii.md)给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）（除了set查重，可以尝试visited来判断-待尝试
[leetcode 94中序遍历二叉树](https://leetcode-cn.com/problems/binary-tree-inorder-traversal/)--[笔记](../leetcode/94-binary-tree-inorder-traversal.md)给定一个二叉树，返回它的中序 遍历。
[leetcode 98有效的二叉搜索树](https://leetcode-cn.com/problems/validate-binary-search-tree/)--[笔记](../leetcode/98-validate-binary-search-tree.md)给定一个二叉树，判断其是否是一个有效的二叉搜索树。（递归中序 迭代栈）
[leetcode 104二叉树的最大深度](https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/)--[笔记](../leetcode/104-maximum-depth-of-binary-tree.md)给定一个二叉树，找出其最大深度。——深搜 迭代
[leetcode 105前序+中序构造二叉树](https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)--[笔记](../leetcode/105-construct-binary-tree-from-preorder-and-inorder-traversal.md)根据一棵树的前序遍历与中序遍历构造二叉树（无重复元素）
[leetcode 110平衡二叉树](https://leetcode-cn.com/problems/balanced-binary-tree/)--[笔记](../leetcode/110-balanced-binary-tree.md)给定一个二叉树，判断它是否是高度平衡的二叉树。（待优化）
[leetcode 111二叉树的最小深度](https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/)--[笔记](../leetcode/111-minimum-depth-of-binary-tree.md)给定一个二叉树，找出其最小深度。
[leetcode 112目标和子路径](https://leetcode-cn.com/problems/path-sum/submissions/)--[笔记](../leetcode/112-submissions.md)给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。
[leetcode 114展开二叉树为链表](https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/)--[笔记](../leetcode/114-flatten-binary-tree-to-linked-list.md)给定一个二叉树，原地将它展开为链表。



## BFS+递归-层次遍历
[leetcode 22生成括号？](https://leetcode-cn.com/problems/generate-parentheses/)--[笔记](../leetcode/22-generate-parentheses.md)给出 n 代表生成括号的对数，写出一个函数使其能够生成所有可能的并且有效的括号组合，"((()))"...
[leetcode 78不重复的子集](https://leetcode-cn.com/problems/subsets/)--[笔记](../leetcode/78-subsets.md)给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
[leetcode 104二叉树的最大深度](https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/)--[笔记](../leetcode/104-maximum-depth-of-binary-tree.md)给定一个二叉树，找出其最大深度。——深搜 迭代
[leetcode 111二叉树的最小深度](https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/)--[笔记](../leetcode/111-minimum-depth-of-binary-tree.md)给定一个二叉树，找出其最小深度。


## 动态规划
[leetcode 53最大和的连续子数组](https://leetcode-cn.com/problems/maximum-subarray)--[笔记](../leetcode/53-maximum-subarray.md)给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
[leetcode 55跳跃游戏](https://leetcode-cn.com/problems/jump-game/)--[笔记](../leetcode/55-jump-game.md)给定一个非负整数数组，最初位于数组的第一个位置。数组中的每个元素代表在该位置可以跳跃的最大长度。判断是否能够到达最后一个位置。
[leetcode 62机器人移动路径数](https://leetcode-cn.com/problems/unique-paths/)--[笔记](../leetcode/62-unique-paths.md)机器人位于一个 m x n 网格的左上角，每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”），问总共有多少条不同的路径？
[leetcode 63机器人移动路径数2](https://leetcode-cn.com/problems/unique-paths-ii/)--[笔记](../leetcode/63-unique-paths-ii.md)同62，现考虑网格中有障碍物。那么从左上角到右下角将有多少条不同的路径？
[leetcode 64最小路径数字和](https://leetcode-cn.com/problems/minimum-path-sum/)--[笔记](../leetcode/64-minimum-path-sum.md)给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小
[leetcode 70爬楼梯](https://leetcode-cn.com/problems/climbing-stairs/)--[笔记](../leetcode/70-climbing-stairs.md)假设你正在爬楼梯。需要 n 阶你才能到达楼顶。每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
[leetcode 96二叉搜索树](https://leetcode-cn.com/problems/unique-binary-search-trees/)--[笔记](../leetcode/96-unique-binary-search-trees.md)给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？
[leetcode 97交错组成字符串](https://leetcode-cn.com/problems/interleaving-string/)--[笔记](../leetcode/97-interleaving-string.md)给定三个字符串 s1, s2, s3, 验证 s3 是否是由 s1 和 s2 交错组成的。 

## 贪心算法
[leetcode 55跳跃游戏](https://leetcode-cn.com/problems/jump-game/)--[笔记](../leetcode/55-jump-game.md)给定一个非负整数数组，最初位于数组的第一个位置。数组中的每个元素代表在该位置可以跳跃的最大长度。判断是否能够到达最后一个位置。

## 字符串
[leetcode 8字符串转数字](https://leetcode-cn.com/problems/string-to-integer-atoi/)--[笔记](../leetcode/8-string-to-integer-atoi.md)将字符串转数字，省略前面的空格，注意符号，数字后的字符可以省略，但开头若为字符或者超过32位边界则返回0.
[leetcode 14最长公共前缀](https://leetcode-cn.com/problems/longest-common-prefix/)--[笔记](../leetcode/14-longest-common-prefix.md)查找字符串数组中的最长公共前缀子串，不存在返回""
[leetcode 28实现 strStr()](https://leetcode-cn.com/problems/implement-strstr/)--[笔记](../leetcode/28-implement-strstr.md)在haystack字符串中找出needle字符串出现的第一个位置 (从0开始)。如果不存在，则返回-1.
[leetcode 38报数序列](https://leetcode-cn.com/problems/count-and-say/)--[笔记](../leetcode/38-count-and-say.md)报数序列是一个整数序列，按照其中的整数的顺序进行报数，得到下一个数
[leetcode 43字符串相乘](https://leetcode-cn.com/problems/multiply-strings/)--[笔记](../leetcode/43-multiply-strings.md)给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
 

## 二叉树
[leetcode 94中序遍历二叉树](https://leetcode-cn.com/problems/binary-tree-inorder-traversal/)--[笔记](../leetcode/94-binary-tree-inorder-traversal.md)给定一个二叉树，返回它的中序 遍历。
[leetcode 95独特的二叉搜索树2](https://leetcode-cn.com/problems/unique-binary-search-trees-ii/)--[笔记](../leetcode/95-unique-binary-search-trees-ii.md)给定一个整数 n，生成所有由 1 ... n 为节点所组成的 二叉搜索树 。
[leetcode 96二叉搜索树](https://leetcode-cn.com/problems/unique-binary-search-trees/)--[笔记](../leetcode/96-unique-binary-search-trees.md)给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？
[leetcode 98有效的二叉搜索树](https://leetcode-cn.com/problems/validate-binary-search-tree/)--[笔记](../leetcode/98-validate-binary-search-tree.md)给定一个二叉树，判断其是否是一个有效的二叉搜索树。（递归中序 迭代栈）
[leetcode 100相同的二叉树](https://leetcode-cn.com/problems/same-tree/)--[笔记](../leetcode/100-same-tree.md)给定两个二叉树，编写一个函数来检验它们是否相同。 
[leetcode 101对称的二叉树](https://leetcode-cn.com/problems/symmetric-tree/)--[笔记](../leetcode/101-symmetric-tree.md)给定一个二叉树，检查它是否是镜像对称的。
[leetcode 102层次遍历所有节点](https://leetcode-cn.com/problems/binary-tree-level-order-traversal/)--[笔记](../leetcode/102-binary-tree-level-order-traversal.md)给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。
[leetcode 104二叉树的最大深度](https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/)--[笔记](../leetcode/104-maximum-depth-of-binary-tree.md)给定一个二叉树找出最大深度——深搜 迭代
[leetcode 105前序+中序构造二叉树](https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)--[笔记](../leetcode/105-construct-binary-tree-from-preorder-and-inorder-traversal.md)根据一棵树的前序遍历与中序遍历构造二叉树（无重复元素）
[leetcode 107二叉树的层次遍历 II](https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/)--[笔记](../leetcode/107-binary-tree-level-order-traversal-ii.md)给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历） 
[leetcode 109链表转为平衡二叉搜索树](https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree/)--[笔记](../leetcode/109-convert-sorted-list-to-binary-search-tree.md)给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。
[leetcode 110平衡二叉树](https://leetcode-cn.com/problems/balanced-binary-tree/)--[笔记](../leetcode/110-balanced-binary-tree.md)给定一个二叉树，判断它是否是高度平衡的二叉树。（待优化）
[leetcode 111二叉树的最小深度](https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/)--[笔记](../leetcode/111-minimum-depth-of-binary-tree.md)给定一个二叉树，找出其最小深度。
[leetcode 112目标和子路径](https://leetcode-cn.com/problems/path-sum/submissions/)--[笔记](../leetcode/112-submissions.md)给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。
[leetcode 114展开二叉树为链表](https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/)--[笔记](../leetcode/114-flatten-binary-tree-to-linked-list.md)给定一个二叉树，原地将它展开为链表。



## 位运算


## 栈和队列
[leetcode 20有效的符号](https://leetcode-cn.com/problems/valid-parentheses/)--[笔记](../leetcode/20-valid-parentheses.md)给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
[leetcode 94中序遍历二叉树](https://leetcode-cn.com/problems/binary-tree-inorder-traversal/)--[笔记](../leetcode/94-binary-tree-inorder-traversal.md)给定一个二叉树，返回它的中序 遍历。
[leetcode 98有效的二叉搜索树](https://leetcode-cn.com/problems/validate-binary-search-tree/)--[笔记](../leetcode/98-validate-binary-search-tree.md)给定一个二叉树，判断其是否是一个有效的二叉搜索树。（递归中序 迭代栈）
[leetcode 114展开二叉树为链表](https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/)--[笔记](../leetcode/114-flatten-binary-tree-to-linked-list.md)给定一个二叉树，原地将它展开为链表。

## 链表
[leetcode2两数相加](https://leetcode-cn.com/problems/add-two-numbers/)--[笔记](../leetcode/2-add-two-numbers.md)两个非空的链表逆序存储进行相加
[leetcode 21合并两个有序链表](https://leetcode-cn.com/problems/merge-two-sorted-lists/)--[笔记](../leetcode/21-merge-two-sorted-lists.md)将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
[leetcode 23合并k个有序链表](https://leetcode-cn.com/problems/merge-k-sorted-lists/)--[笔记](../leetcode/23-merge-k-sorted-lists.md)合并 k 个排序链表，返回合并后的排序链表（合并时两条链表长度相差不大时速度更快-分治）
[leetcode 24两两交换节点](https://leetcode-cn.com/problems/swap-nodes-in-pairs/)--[笔记](../leetcode/24-swap-nodes-in-pairs.md)两两交换给定链表其中相邻的节点，并返回交换后的链表。
[leetcode 83删除有序链表中重复节点](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/)--[笔记](../leetcode/83-remove-duplicates-from-sorted-list.md)给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。
[leetcode 86链表排序](https://leetcode-cn.com/problems/partition-list/)--[笔记](../leetcode/86-partition-list.md)给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前，需要保留两个分区中每个节点的相对位置。
[leetcode 109链表转为平衡二叉搜索树](https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree/)--[笔记](../leetcode/109-convert-sorted-list-to-binary-search-tree.md)给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。


## 其他
### 数学运算
[leetcode7反转整数](https://leetcode-cn.com/problems/reverse-integer/)--[笔记](../leetcode/7-reverse-integer.md)将32位的整数每位上的数字进行反转。反转后整数溢出返回0
[leetcode 43字符串相乘](https://leetcode-cn.com/problems/multiply-strings/)--[笔记](../leetcode/43-multiply-strings.md)给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。 
[leetcode 60第k个排列](https://leetcode-cn.com/problems/permutation-sequence/)--[笔记](../leetcode/60-permutation-sequence.md)给出集合 [1,2,3,…,n]，其所有元素共有 n! 种排列，返回第 k 个排列。  
[leetcode 66加一](https://leetcode-cn.com/problems/plus-one/)--[笔记](../leetcode/66-plus-one.md)给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一（主要考虑进位



### 分治
[leetcode 23合并k个有序链表](https://leetcode-cn.com/problems/merge-k-sorted-lists/)--[笔记](../leetcode/23-merge-k-sorted-lists.md)合并 k 个排序链表，返回合并后的排序链表（合并时两条链表长度相差不大时速度更快-分治）
[leetcode 109链表转为平衡二叉搜索树](https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree/)--[笔记](../leetcode/109-convert-sorted-list-to-binary-search-tree.md)给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。 


### set
[leetcode 40组合求和2不可重复](https://leetcode-cn.com/problems/combination-sum-ii/)--[笔记](../leetcode/40-combination-sum-ii.md)给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合，每个数字只能使用一次。

### 找规律
[leetcode 48旋转图像](https://leetcode-cn.com/problems/rotate-image/)--[笔记](../leetcode/48-rotate-image.md)给定一个 n × n 的二维矩阵表示一个图像，将图像顺时针旋转 90 度。
[leetcode 56合并重叠区间](https://leetcode-cn.com/problems/merge-intervals/)--[笔记](../leetcode/56-merge-intervals.md)给出一个区间的集合，请合并所有重叠的区间（未排序，需要自定义排序比较器



