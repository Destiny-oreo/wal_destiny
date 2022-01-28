# 算法整理     
696结束105
---------------------------
## 二分
[leetcode 29两数相除](https://leetcode-cn.com/problems/divide-two-integers/)--[笔记](../leetcode/29-divide-two-integers.md)将两数相除，要求不使用乘法、除法和 mod 运算符计算商，需要截去小数部分。（二分思想）
[leetcode 33在有序但旋转过的数组中搜索目标](https://leetcode-cn.com/problems/search-in-rotated-sorted-array/)--[笔记](../leetcode/33-Search-in-Rotated-Sorted-Array.md)假设按照升序排序的数组在预先未知的某个点上进行了旋转，寻找目标数字的下标（改进的二分查找）
[leetcode 34寻找目标值在数组中的开始和结束位置](https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/)--[笔记](../leetcode/34-find-first-and-last-position-of-element-in-sorted-array.md)给定一个按照升序排列的重复整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。（循环边界二分查找）
[leetcode 35在有序数组中找到目标下标或待插入下标](https://leetcode-cn.com/problems/search-in-rotated-sorted-array/)--[笔记](../leetcode/35-search-in-rotated-sorted-array.md)给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
[leetcode 50幂函数x的n次方](https://leetcode-cn.com/problems/powx-n/)--[笔记](../leetcode/50-powx-n.md)实现 pow(x, n) ，即计算 x 的 n 次幂函数。
[leetcode 300最长上升子序列](https://leetcode-cn.com/problems/longest-increasing-subsequence/)--[笔记](../leetcode/300-longest-increasing-subsequence.md)给定一个无序的整数数组，找到其中最长上升子序列的长度。【推导二分左右指针】


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
[leetcode 141判断链表是否有环](https://leetcode-cn.com/problems/linked-list-cycle/)--[笔记](../leetcode/141-linked-list-cycle.md)给定一个链表，判断链表中是否有环。
[leetcode 142判断链表是否有环2](https://leetcode-cn.com/problems/linked-list-cycle-ii/)--[笔记](../leetcode/142-linked-list-cycle-ii.md)给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
[leetcode 167两数之和](https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/)--[笔记](../leetcode/167-two-sum-ii-input-array-is-sorted.md)给定一个已按照升序排列 的有序数组，找到两个数使得它们相加之和等于目标数。
[leetcode 234回文链表](https://leetcode-cn.com/problems/palindrome-linked-list/)--[笔记](../leetcode/234-palindrome-linked-list.md)请判断一个链表是否为回文链表。  
[leetcode 283移动数字零](https://leetcode-cn.com/problems/move-zeroes/)--[笔记](../leetcode/283-move-zeroes.md)给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
[leetcode 287找到重复的数](https://leetcode-cn.com/problems/find-the-duplicate-number/)--[笔记](../leetcode/287-find-the-duplicate-number.md)给定一个包含 n + 1 个整数的数组 nums，其数字都在 1 到 n 之间（包括 1 和 n），可知至少存在一个重复的整数。假设只有一个重复的整数，找出这个重复的数。【推导快慢指针原理】
[leetcode 581最短排序数组长度](https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray/)--[笔记](../leetcode/581-shortest-unsorted-continuous-subarray.md)给定一个整数数组，你需要寻找一个连续的子数组，如果对这个子数组进行升序排序，那么整个数组都会变为升序排序。


## 哈希表
[leetcode 1两数之和](https://leetcode-cn.com/problems/two-sum/)--[笔记](../leetcode/1-Two-Sum.md)从乱序数组中找出和为目标值的那两个整数的下标
[leetcode 13罗马数字转整数 ](https://leetcode-cn.com/problems/roman-to-integer/)--[笔记](../leetcode/13-roman-to-integer.md)将七种字符: I， V， X， L，C，D 和 M组成的罗马数字转为整数
[leetcode 36有效的数独](https://leetcode-cn.com/problems/valid-sudoku/)--[笔记](../leetcode/36-valid-sudoku.md)判断一个 9x9 的数独是否有效，只包含数字 1-9 和字符 '. ' 
[leetcode 49异位词组合](https://leetcode-cn.com/problems/group-anagrams/)--[笔记](../leetcode/49-group-anagrams.md)将字符串数组中字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。 （字符串转向量
[leetcode 347频率前K高的元素](https://leetcode-cn.com/problems/top-k-frequent-elements/)--[笔记](../leetcode/347-top-k-frequent-elements.md)给定一个非空的整数数组，返回其中出现频率前 k 高的元素。
[leetcode 438字母异位词字串起始索引](https://leetcode-cn.com/problems/find-all-anagrams-in-a-string/)--[笔记](../leetcode/438-find-all-anagrams-in-a-string.md)给定一个字符串 s 和一个非空字符串 p，找到 s 中所有是 p 的字母异位词的子串，返回这些子串的起始索引。  
[leetcode 560和为K的连续子数组个数](https://leetcode-cn.com/problems/subarray-sum-equals-k/)--[笔记](../leetcode/560-subarray-sum-equals-k.md)给定一个整数数组和一个整数 k，你需要找到该数组中和为 k 的连续的子数组的个数。


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
[leetcode 130封闭区域](https://leetcode-cn.com/problems/surrounded-regions/)--[笔记](../leetcode/130-surrounded-regions.md)给定一个二维的矩阵，包含 'X' 和 'O'（字母 O），找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。 
[leetcode 133图的深拷贝](https://leetcode-cn.com/problems/clone-graph/)--[笔记](../leetcode/133-clone-graph.md)给你无向连通图中一个节点的引用，请你返回该图的 深拷贝（克隆）。 
[leetcode 200岛屿数量](https://leetcode-cn.com/problems/number-of-islands/)--[笔记](../leetcode/200-number-of-islands.md)给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
[leetcode 216组合总和 III](https://leetcode-cn.com/problems/combination-sum-iii/)--[笔记](../leetcode/216-combination-sum-iii.md)找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。 
[leetcode 226翻转二叉树](https://leetcode-cn.com/problems/invert-binary-tree/)--[笔记](../leetcode/226-invert-binary-tree.md)翻转一棵二叉树。
[leetcode 231二的幂次方](https://leetcode-cn.com/problems/power-of-two/)--[笔记](../leetcode/231-power-of-two.md)给你一个整数 `n`，请你判断该整数是否是 2 的幂次方。如果是，返回 `true` ；否则，返回 `false` 。
[leetcode 236最近的公共祖先](https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/)--[笔记](../leetcode/236-lowest-common-ancestor-of-a-binary-tree.md)给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。 
[leetcode 257二叉树的所有路径](https://leetcode-cn.com/problems/binary-tree-paths/)--[笔记](../leetcode/257-binary-tree-paths.md)给定一个二叉树，返回所有从根节点到叶子节点的路径。 
[leetcode 332有效行程组合](https://leetcode-cn.com/problems/reconstruct-itinerary/)--[笔记](../leetcode/332-reconstruct-itinerary.md)给定一个机票的字符串二维数组 [from, to]，子数组中的两个成员分别表示飞机出发和降落的机场地点，对该行程进行重新规划排序。所有这些机票都属于一个从 JFK（肯尼迪国际机场）出发的先生，所以该行程必须从 JFK 开始。说明:如果存在多种有效的行程，你可以按字符自然排序返回最小的行程组合。例如，行程 ["JFK", "LGA"] 与 ["JFK", "LGB"] 相比就更小，排序更靠前所有的机场都用三个大写字母表示（机场代码）。假定所有机票至少存在一种合理的行程。
[leetcode 337小偷3](https://leetcode-cn.com/problems/house-robber-iii/)--[笔记](../leetcode/337-house-robber-iii.md)在上次打劫完一条街道之后和一圈房屋后，小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为“根”。 除了“根”之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 如果两个直接相连的房子在同一天晚上被打劫，房屋将自动报警。 计算在不触动警报的情况下，小偷一晚能够盗取的最高金额。
[leetcode 491所有的递增子序列](https://leetcode-cn.com/problems/increasing-subsequences/)--[笔记](../leetcode/491-increasing-subsequences.md)给定一个整型数组, 你的任务是找到所有该数组的递增子序列，递增子序列的长度至少是2。   
[leetcode 529扫雷游戏](https://leetcode-cn.com/problems/minesweeper/)--[笔记](../leetcode/529-minesweeper.md)让我们一起来玩扫雷游戏！给定一个代表游戏板的二维字符矩阵。 'M' 代表一个未挖出的地雷，'E' 代表一个未挖出的空方块，'B' 代表没有相邻（上，下，左，右，和所有4个对角线）地雷的已挖出的空白方块，数字（'1' 到 '8'）表示有多少地雷与这块已挖出的方块相邻，'X' 则表示一个已挖出的地雷。  


## BFS+递归-层次遍历
[leetcode 22生成括号？](https://leetcode-cn.com/problems/generate-parentheses/)--[笔记](../leetcode/22-generate-parentheses.md)给出 n 代表生成括号的对数，写出一个函数使其能够生成所有可能的并且有效的括号组合，"((()))"...
[leetcode 78不重复的子集](https://leetcode-cn.com/problems/subsets/)--[笔记](../leetcode/78-subsets.md)给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
[leetcode 104二叉树的最大深度](https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/)--[笔记](../leetcode/104-maximum-depth-of-binary-tree.md)给定一个二叉树，找出其最大深度。——深搜 迭代
[leetcode 111二叉树的最小深度](https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/)--[笔记](../leetcode/111-minimum-depth-of-binary-tree.md)给定一个二叉树，找出其最小深度。
[leetcode 130封闭区域](https://leetcode-cn.com/problems/surrounded-regions/)--[笔记](../leetcode/130-surrounded-regions.md)给定一个二维的矩阵，包含 'X' 和 'O'（字母 O），找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。 
[leetcode 279完全平方数个数最少](https://leetcode-cn.com/problems/perfect-squares/)--[笔记](../leetcode/279-perfect-squares.md)给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。 
[leetcode 529扫雷游戏](https://leetcode-cn.com/problems/minesweeper/)--[笔记](../leetcode/529-minesweeper.md)让我们一起来玩扫雷游戏！给定一个代表游戏板的二维字符矩阵。 'M' 代表一个未挖出的地雷，'E' 代表一个未挖出的空方块，'B' 代表没有相邻（上，下，左，右，和所有4个对角线）地雷的已挖出的空白方块，数字（'1' 到 '8'）表示有多少地雷与这块已挖出的方块相邻，'X' 则表示一个已挖出的地雷。

## 动态规划
[leetcode 53最大和的连续子数组](https://leetcode-cn.com/problems/maximum-subarray)--[笔记](../leetcode/53-maximum-subarray.md)给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
[leetcode 55跳跃游戏](https://leetcode-cn.com/problems/jump-game/)--[笔记](../leetcode/55-jump-game.md)给定一个非负整数数组，最初位于数组的第一个位置。数组中的每个元素代表在该位置可以跳跃的最大长度。判断是否能够到达最后一个位置。
[leetcode 62机器人移动路径数](https://leetcode-cn.com/problems/unique-paths/)--[笔记](../leetcode/62-unique-paths.md)机器人位于一个 m x n 网格的左上角，每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”），问总共有多少条不同的路径？
[leetcode 63机器人移动路径数2](https://leetcode-cn.com/problems/unique-paths-ii/)--[笔记](../leetcode/63-unique-paths-ii.md)同62，现考虑网格中有障碍物。那么从左上角到右下角将有多少条不同的路径？
[leetcode 64最小路径数字和](https://leetcode-cn.com/problems/minimum-path-sum/)--[笔记](../leetcode/64-minimum-path-sum.md)给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小
[leetcode 70爬楼梯](https://leetcode-cn.com/problems/climbing-stairs/)--[笔记](../leetcode/70-climbing-stairs.md)假设你正在爬楼梯。需要 n 阶你才能到达楼顶。每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
[leetcode 96二叉搜索树](https://leetcode-cn.com/problems/unique-binary-search-trees/)--[笔记](../leetcode/96-unique-binary-search-trees.md)给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？
[leetcode 97交错组成字符串](https://leetcode-cn.com/problems/interleaving-string/)--[笔记](../leetcode/97-interleaving-string.md)给定三个字符串 s1, s2, s3, 验证 s3 是否是由 s1 和 s2 交错组成的。 
[leetcode 121买卖股票的最佳时机](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/)--[笔记](../leetcode/121-best-time-to-buy-and-sell-stock.md)给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。最多只允许完成一笔交易（即买入和卖出一支股票），设计一个算法来计算你所能获取的最大利润。
[leetcode 152最大子数组乘积](https://leetcode-cn.com/problems/maximum-product-subarray/)--[笔记](../leetcode/152-maximum-product-subarray.md)给你一个整数数组 nums ，请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。
[leetcode 198房屋偷窃](https://leetcode-cn.com/problems/house-robber/)--[笔记](../leetcode/198-house-robber.md)你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。给定一个代表每个房屋存放金额的非负整数数组，计算你不触动警报装置的情况下，一夜之内能够偷窃到的最高金额
[leetcode 221最大正方形面积](https://leetcode-cn.com/problems/maximal-square/)--[笔记](../leetcode/221-maximal-square.md)在一个由0和1组成的二维矩阵内，找到只包含1的最大正方形，并返回其面积。
[leetcode 279完全平方数个数最少](https://leetcode-cn.com/problems/perfect-squares/)--[笔记](../leetcode/279-perfect-squares.md)给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。 
[leetcode 300最长上升子序列](https://leetcode-cn.com/problems/longest-increasing-subsequence/)--[笔记](../leetcode/300-longest-increasing-subsequence.md)给定一个无序的整数数组，找到其中最长上升子序列的长度。  
[leetcode 309买卖股票最大利益](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/)--[笔记](../leetcode/309-best-time-to-buy-and-sell-stock-with-cooldown.md)给定一个整数数组，其中第 i 个元素代表了第 i 天的股票价格 。​设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。（较难）
[leetcode 322凑总金额的最少硬币个数](https://leetcode-cn.com/problems/coin-change/)--[笔记](../leetcode/322-coin-change.md)给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。   
[leetcode 337小偷3](https://leetcode-cn.com/problems/house-robber-iii/)--[笔记](../leetcode/337-house-robber-iii.md)在上次打劫完一条街道之后和一圈房屋后，小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为“根”。 除了“根”之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 如果两个直接相连的房子在同一天晚上被打劫，房屋将自动报警。 计算在不触动警报的情况下，小偷一晚能够盗取的最高金额。
[leetcode 338计算二进制位1的个数](https://leetcode-cn.com/problems/counting-bits/)--[笔记](../leetcode/338-counting-bits.md)给定一个非负整数 num。对于 0 ≤ i ≤ num 范围中的每个数字 i ，计算其二进制数中的 1 的数目并将它们作为数组返回。  
[leetcode 416分两个相等的子集](https://leetcode-cn.com/problems/partition-equal-subset-sum/)--[笔记](../leetcode/416-partition-equal-subset-sum.md)给定一个只包含正整数的非空数组。是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
[leetcode 486预测赢家](https://leetcode-cn.com/problems/predict-the-winner/)--[笔记](../leetcode/486-predict-the-winner.md)给定一个表示分数的非负整数数组。 玩家 1 从数组任意一端拿取一个分数，随后玩家 2 继续从剩余数组任意一端拿取分数，然后玩家 1 拿，…… 。每次一个玩家只能拿取一个分数，分数被拿取之后不再可取。直到没有剩余分数可取时游戏结束。最终获得分数总和最多的玩家获胜。 
[leetcode 494目标和的个数](https://leetcode-cn.com/problems/target-sum/)--[笔记](../leetcode/494-target-sum.md)给定一个非负整数数组，a1, a2, ..., an, 和一个目标数，S。现在你有两个符号 + 和 -。对于数组中的任意一个整数，你都可以从 + 或 -中选择一个符号添加在前面。返回可以使最终数组和为目标数 S 的所有添加符号的方法数。
[leetcode 647回文字串](https://leetcode-cn.com/problems/palindromic-substrings/)--[笔记](../leetcode/647-Palindromic-Substrings.md)给定一个字符串，你的任务是计算这个字符串中有多少个回文子串，具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被计为是不同的子串。

## 贪心算法
[leetcode 55跳跃游戏](https://leetcode-cn.com/problems/jump-game/)--[笔记](../leetcode/55-jump-game.md)给定一个非负整数数组，最初位于数组的第一个位置。数组中的每个元素代表在该位置可以跳跃的最大长度。判断是否能够到达最后一个位置。
[leetcode 406重建排队队列](https://leetcode-cn.com/problems/queue-reconstruction-by-height/)--[笔记](../leetcode/406-queue-reconstruction-by-height.md)假设有打乱顺序的一群人站成一个队列。 每个人由一个整数对(h, k)表示，其中h是这个人的身高，k是排在这个人前面且身高大于或等于h的人数。 编写一个算法来重建这个队列。   

## 字符串
[leetcode 8字符串转数字](https://leetcode-cn.com/problems/string-to-integer-atoi/)--[笔记](../leetcode/8-string-to-integer-atoi.md)将字符串转数字，省略前面的空格，注意符号，数字后的字符可以省略，但开头若为字符或者超过32位边界则返回0.
[leetcode 14最长公共前缀](https://leetcode-cn.com/problems/longest-common-prefix/)--[笔记](../leetcode/14-longest-common-prefix.md)查找字符串数组中的最长公共前缀子串，不存在返回""
[leetcode 28实现 strStr()](https://leetcode-cn.com/problems/implement-strstr/)--[笔记](../leetcode/28-implement-strstr.md)在haystack字符串中找出needle字符串出现的第一个位置 (从0开始)。如果不存在，则返回-1.
[leetcode 38报数序列](https://leetcode-cn.com/problems/count-and-say/)--[笔记](../leetcode/38-count-and-say.md)报数序列是一个整数序列，按照其中的整数的顺序进行报数，得到下一个数
[leetcode 43字符串相乘](https://leetcode-cn.com/problems/multiply-strings/)--[笔记](../leetcode/43-multiply-strings.md)给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
[leetcode 214最短回文串](https://leetcode-cn.com/problems/shortest-palindrome/)--[笔记](../leetcode/214-shortest-palindrome.md) 给定一个字符串 s，你可以通过在字符串前面添加字符将其转换为回文串。找到并返回可以用这种方式转换的最短回文串。
[leetcode 392判断子序列](https://leetcode-cn.com/problems/is-subsequence/)--[笔记](../leetcode/392-is-subsequence.md)给定字符串 s 和 t ，判断 s 是否为 t 的子序列。字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。（例如，"ace"是"abcde"的一个子序列，而"aec"不是）。    
[leetcode 415字符串计算加法](https://leetcode-cn.com/problems/add-strings/)--[笔记](../leetcode/415-add-strings.md)给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。  
[leetcode 459重复字串构成](https://leetcode-cn.com/problems/repeated-substring-pattern/)--[笔记](../leetcode/459-repeated-substring-pattern.md)给定一个非空的字符串，判断它是否可以由它的一个子串重复多次构成。给定的字符串只含有小写英文字母，并且长度不超过10000。  
[leetcode 557反转字符串中的单词 III](https://leetcode-cn.com/problems/reverse-words-in-a-string-iii/)--[笔记](../leetcode/557-reverse-words-in-a-string-iii.md)给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。   
[leetcode 647回文字串](https://leetcode-cn.com/problems/palindromic-substrings/)--[笔记](../leetcode/647-palindromic-substrings.md)给定一个字符串，你的任务是计算这个字符串中有多少个回文子串，具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被计为是不同的子串。
[leetcode 657回到起点的机器人](https://leetcode-cn.com/problems/robot-return-to-origin/)--[笔记](../leetcode/657-robot-return-to-origin.md)在二维平面上，有一个机器人从原点 (0, 0) 开始。给出它的移动顺序，判断这个机器人在完成移动后是否在 (0, 0) 处结束。
[leetcode 696计数字串](https://leetcode-cn.com/problems/count-binary-substrings/)--[笔记](../leetcode/696-count-binary-substrings.md)给定一个字符串 s，计算具有相同数量0和1的非空(连续)子字符串的数量，并且这些子字符串中的所有0和所有1都是组合在一起的。重复出现的子串要计算它们出现的次数。 

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
[leetcode 226翻转二叉树](https://leetcode-cn.com/problems/invert-binary-tree/)--[笔记](../leetcode/226-invert-binary-tree.md)翻转一棵二叉树。
[leetcode 236最近的公共祖先](https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/)--[笔记](../leetcode/236-lowest-common-ancestor-of-a-binary-tree.md)给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。 
[leetcode 257二叉树的所有路径](https://leetcode-cn.com/problems/binary-tree-paths/)--[笔记](../leetcode/257-binary-tree-paths.md)给定一个二叉树，返回所有从根节点到叶子节点的路径。 
[leetcode 437路径和3](https://leetcode-cn.com/problems/path-sum-iii/)--[笔记](../leetcode/437-path-sum-iii.md)给定一个二叉树，它的每个结点都存放着一个整数值。找出路径和等于给定数值的路径总数  
[leetcode 538二叉搜索树转为累加树](https://leetcode-cn.com/problems/convert-bst-to-greater-tree/)--[笔记](../leetcode/538-convert-bst-to-greater-tree.md)给定一个二叉搜索树（Binary Search Tree），把它转换成为累加树（Greater Tree)，使得每个节点的值是原来的节点值加上所有大于它的节点值之和。  
[leetcode 617合并两个二叉树](https://leetcode-cn.com/problems/merge-two-binary-trees/)--[笔记](../leetcode/617-merge-two-binary-trees.md)给定两个二叉树，想象当你将它们中的一个覆盖到另一个上时，两个二叉树的一些节点便会重叠。你需要将他们合并为一个新的二叉树。合并的规则是如果两个节点重叠，那么将他们的值相加作为节点合并后的新值，否则不为 NULL 的节点将直接作为新二叉树的节点。


## 图
[leetcode 133图的深拷贝](https://leetcode-cn.com/problems/clone-graph/)--[笔记](../leetcode/133-clone-graph.md)给你无向连通图中一个节点的引用，请你返回该图的 深拷贝（克隆）。
[leetcode 207课程选修](https://leetcode-cn.com/problems/course-schedule/)--[笔记](../leetcode/207-course-schedule.md)你这个学期必须选修 numCourse 门课程，记为 0 到 numCourse-1 。  
在选修某些课程之前需要一些先修课程。 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们：[0,1] 给定课程总量以及它们的先决条件，请你判断是否可能完成所有课程的学习？  （指向次数和是否为环


## 位运算
[leetcode 136只出现一次的元素](https://leetcode-cn.com/problems/single-number/)--[笔记](../leetcode/136-single-number.md)给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
[leetcode 201范围内所有数字按位与](https://leetcode-cn.com/problems/bitwise-and-of-numbers-range/)--[笔记](../leetcode/201-bitwise-and-of-numbers-range.md)给定范围 [m, n]，其中 0 <= m <= n <= 2147483647，返回此范围内所有数字的按位与（包含 m, n 两端点）
[leetcode 231二的幂次方](https://leetcode-cn.com/problems/power-of-two/)--[笔记](../leetcode/231-power-of-two.md)给你一个整数 `n`，请你判断该整数是否是 2 的幂次方。如果是，返回 `true` ；否则，返回 `false` 。
[leetcode 338计算二进制位1的个数](https://leetcode-cn.com/problems/counting-bits/)--[笔记](../leetcode/338-counting-bits.md)给定一个非负整数 num。对于 0 ≤ i ≤ num 范围中的每个数字 i ，计算其二进制数中的 1 的数目并将它们作为数组返回。 
[leetcode 461汉明距离](https://leetcode-cn.com/problems/hamming-distance/)--[笔记](../leetcode/461-hamming-distance.md)两个整数之间的汉明距离指的是这两个数字对应二进制位不同的位置的数目。给出两个整数 x 和 y，计算它们之间的汉明距离。    
[leetcode 477汉明距离总和](https://leetcode-cn.com/problems/total-hamming-distance/)--[笔记](../leetcode/477-total-hamming-distance.md)两个整数的汉明距离指的是这两个数字的二进制数对应位不同的数量。给你一个整数数组 `nums`，请你计算并返回 `nums` 中任意两个数之间汉明距离的总和。  

## 栈和队列、堆
[leetcode 20有效的符号](https://leetcode-cn.com/problems/valid-parentheses/)--[笔记](../leetcode/20-valid-parentheses.md)给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
[leetcode 94中序遍历二叉树](https://leetcode-cn.com/problems/binary-tree-inorder-traversal/)--[笔记](../leetcode/94-binary-tree-inorder-traversal.md)给定一个二叉树，返回它的中序 遍历。
[leetcode 98有效的二叉搜索树](https://leetcode-cn.com/problems/validate-binary-search-tree/)--[笔记](../leetcode/98-validate-binary-search-tree.md)给定一个二叉树，判断其是否是一个有效的二叉搜索树。（递归中序 迭代栈）
[leetcode 114展开二叉树为链表](https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/)--[笔记](../leetcode/114-flatten-binary-tree-to-linked-list.md)给定一个二叉树，原地将它展开为链表。
[leetcode 155最小栈](https://leetcode-cn.com/problems/min-stack/)--[笔记](../leetcode/155-min-stack.md)设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。 
[leetcode 215第K个最大的元素](https://leetcode-cn.com/problems/kth-largest-element-in-an-array/)--[笔记](../leetcode/215-kth-largest-element-in-an-array.md)在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。 
[leetcode 394解码字符串](https://leetcode-cn.com/problems/decode-string/)--[笔记](../leetcode/394-decode-string.md)给定一个经过编码的字符串，返回它解码后的字符串。【状态转换机】  


## 链表
[leetcode2两数相加](https://leetcode-cn.com/problems/add-two-numbers/)--[笔记](../leetcode/2-add-two-numbers.md)两个非空的链表逆序存储进行相加
[leetcode 21合并两个有序链表](https://leetcode-cn.com/problems/merge-two-sorted-lists/)--[笔记](../leetcode/21-merge-two-sorted-lists.md)将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
[leetcode 23合并k个有序链表](https://leetcode-cn.com/problems/merge-k-sorted-lists/)--[笔记](../leetcode/23-merge-k-sorted-lists.md)合并 k 个排序链表，返回合并后的排序链表（合并时两条链表长度相差不大时速度更快-分治）
[leetcode 24两两交换节点](https://leetcode-cn.com/problems/swap-nodes-in-pairs/)--[笔记](../leetcode/24-swap-nodes-in-pairs.md)两两交换给定链表其中相邻的节点，并返回交换后的链表。
[leetcode 83删除有序链表中重复节点](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/)--[笔记](../leetcode/83-remove-duplicates-from-sorted-list.md)给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。
[leetcode 86链表排序](https://leetcode-cn.com/problems/partition-list/)--[笔记](../leetcode/86-partition-list.md)给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前，需要保留两个分区中每个节点的相对位置。
[leetcode 109链表转为平衡二叉搜索树](https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree/)--[笔记](../leetcode/109-convert-sorted-list-to-binary-search-tree.md)给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。
[leetcode 141判断链表是否有环](https://leetcode-cn.com/problems/linked-list-cycle/)--[笔记](../leetcode/141-linked-list-cycle.md)给定一个链表，判断链表中是否有环。
[leetcode 142判断链表是否有环2](https://leetcode-cn.com/problems/linked-list-cycle-ii/)--[笔记](../leetcode/142-linked-list-cycle-ii.md)给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
[leetcode 148链表排序](https://leetcode-cn.com/problems/sort-list/)--[笔记](../leetcode/148-sort-list.md)在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。
[leetcode 160两个单链表的相交点](https://leetcode-cn.com/problems/intersection-of-two-linked-lists/)--[笔记](../leetcode/160-intersection-of-two-linked-lists.md)找到两个单链表相交的起始节点
[leetcode 206反转单链表](https://leetcode-cn.com/problems/reverse-linked-list/)--[笔记](../leetcode/206-reverse-linked-list.md)反转一个单链表。
[leetcode 234回文链表](https://leetcode-cn.com/problems/palindrome-linked-list/)--[笔记](../leetcode/234-palindrome-linked-list.md)请判断一个链表是否为回文链表。  

## 其他
### 数学运算
[leetcode7反转整数](https://leetcode-cn.com/problems/reverse-integer/)--[笔记](../leetcode/7-reverse-integer.md)将32位的整数每位上的数字进行反转。反转后整数溢出返回0
[leetcode 43字符串相乘](https://leetcode-cn.com/problems/multiply-strings/)--[笔记](../leetcode/43-multiply-strings.md)给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。 
[leetcode 60第k个排列](https://leetcode-cn.com/problems/permutation-sequence/)--[笔记](../leetcode/60-permutation-sequence.md)给出集合 [1,2,3,…,n]，其所有元素共有 n! 种排列，返回第 k 个排列。  
[leetcode 66加一](https://leetcode-cn.com/problems/plus-one/)--[笔记](../leetcode/66-plus-one.md)给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一（主要考虑进位
[leetcode 169多数的一个元素](https://leetcode-cn.com/problems/majority-element/)--[笔记](../leetcode/169-majority-element.md)给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素
[leetcode 238其余元素的乘积](https://leetcode-cn.com/problems/product-of-array-except-self/)--[笔记](../leetcode/238-product-of-array-except-self.md)给你一个长度为 n 的整数数组 nums，其中 n > 1，返回输出数组 output ，其中 output[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积。

### 分治
[leetcode 23合并k个有序链表](https://leetcode-cn.com/problems/merge-k-sorted-lists/)--[笔记](../leetcode/23-merge-k-sorted-lists.md)合并 k 个排序链表，返回合并后的排序链表（合并时两条链表长度相差不大时速度更快-分治）
[leetcode 109链表转为平衡二叉搜索树](https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree/)--[笔记](../leetcode/109-convert-sorted-list-to-binary-search-tree.md)给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。 
[leetcode 148链表排序](https://leetcode-cn.com/problems/sort-list/)--[笔记](../leetcode/148-sort-list.md)在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。
[leetcode 240二维矩阵中找目标值](https://leetcode-cn.com/problems/search-a-2d-matrix-ii/)--[笔记](../leetcode/240-search-a-2d-matrix-ii.md)编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target。该矩阵具有以下特性：每行的元素从左到右升序排列。每列的元素从上到下升序排列。 


### set
[leetcode 40组合求和2不可重复](https://leetcode-cn.com/problems/combination-sum-ii/)--[笔记](../leetcode/40-combination-sum-ii.md)给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合，每个数字只能使用一次。

### 找规律
[leetcode 48旋转图像](https://leetcode-cn.com/problems/rotate-image/)--[笔记](../leetcode/48-rotate-image.md)给定一个 n × n 的二维矩阵表示一个图像，将图像顺时针旋转 90 度。
[leetcode 56合并重叠区间](https://leetcode-cn.com/problems/merge-intervals/)--[笔记](../leetcode/56-merge-intervals.md)给出一个区间的集合，请合并所有重叠的区间（未排序，需要自定义排序比较器
[leetcode 139单词分割](https://leetcode-cn.com/problems/word-break/)--[笔记](../leetcode/139-word-break.md)哦，不！你不小心把一个长篇文章中的空格、标点都删掉了，并且大写也弄成了小写。像句子"I reset the computer. It still didn’t boot!"已经变成了"iresetthecomputeritstilldidntboot"。在处理标点符号和大小写之前，你得先把它断成词语。当然了，你有一本厚厚的词典dictionary，不过，有些词没在词典里。假设文章用sentence表示，设计一个算法，把文章断开，要求未识别的字符最少，返回未识别的字符数。
[leetcode 343最大乘积](https://leetcode-cn.com/problems/integer-break/)--[笔记](../leetcode/343-integer-break.md)给定一个正整数 n，将其拆分为至少两个正整数的和，并使这些整数的乘积最大化。 返回你可以获得的最大乘积。
[leetcode 448数组中消失的数字](https://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array/)--[笔记](../leetcode/448-find-all-numbers-disappeared-in-an-array.md)给定一个范围在  1 ≤ a[i] ≤ n ( n = 数组大小 ) 的 整型数组，数组中的元素一些出现了两次，另一些只出现一次。找到所有在 [1, n] 范围之间没有出现在数组中的数字。  【两种方法】
[leetcode 621任务日程](https://leetcode-cn.com/problems/task-scheduler/)--[笔记](../leetcode/621-task-scheduler.md)给定一个用字符数组表示的 CPU 需要执行的任务列表。其中包含使用大写的 A - Z 字母表示的26 种不同种类的任务。任务可以以任意顺序执行，并且每个任务都可以在 1 个单位时间内执行完。CPU 在任何一个单位时间内都可以执行一个任务，或者在待命状态。然而，两个相同种类的任务之间必须有长度为 n 的冷却时间，因此至少有连续 n 个单位时间内 CPU 在执行不同的任务，或者在待命状态。你需要计算完成所有任务所需要的最短时间。