# 题目链接
[leetcode 109](https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree/)

# 原文
给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。  
本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。  
示例:  
给定的有序链表： [-10, -3, 0, 5, 9],  
一个可能的答案是：[0, -3, 9, -10, null, 5], 它可以表示下面这个高度平衡二叉搜索树：  
      0  
     / \    
   -3   9  
   /   /  
 -10  5  

# 思路
- ### **深搜-分治-快慢指针**
  由于是升序的链表，所以需要找到每次链表的中点作为树节点的根节点，所以使用快慢指针；找到根节点以后左节点连接左边链表（左边链表结尾一定记得给null），有边子树连接右边链表，使用的分治的思想；对于结束条件，null的话直接返回，尾结点的话直接返回一个树节点指针，创建方法即new TreeNode(val)。99 100

# 代码
- C++ 深搜-分治-快慢指针
```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head)   return nullptr;
        if(!head->next) return new TreeNode(head->val);
        ListNode* pre = head;
        ListNode* slow = pre->next;
        ListNode* fast = slow->next;
        while(fast&&fast->next){
            pre = pre->next;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = nullptr;
        TreeNode *root = new TreeNode(slow->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);
        return root;
    }
};
```