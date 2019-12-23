# 题目链接
[leetcode 24](https://leetcode-cn.com/problems/swap-nodes-in-pairs/)

# 原文
给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。  
示例:

给定 1->2->3->4, 你应该返回 2->1->4->3.

# 思路
- ### **递归**
  两两合并，使用递归，三要素：结束条件：当链表只剩一个元素或者不剩元素时直接返回head指针；这一层应该完成什么：交换此节点和下个节点（目标有三个节点 当前节点 下个节点 下下个节点，先保存下个节点为next，否则一旦断开连接将丢失下下个节点，然后可以断开当前节点，当前节点指向下下个节点，下下个节点使用递归返回值节课，最后将下个节点指向当前节点），最后返回什么：返回新的头节点即next指针。87 98
- ### **循环遍历**
  循环解决，先考虑特殊情况，即空节点和单节点时，单独解决，然后设置两个指针，先交换好前面两个节点，并保存好头节点以及pre节点（连接用），然后设置next指针指向后面需要交换的第一个节点，while循环（条件为当前节点和下一个节点都不为空节点），然后先保存下个节点，同时连接好pre和下个节点，断开当前节点指向下下个节点，下个节点指向当前节点，交换完成，然后更新指针位置，即pre更新到当前节点，next更新到pre->next。87 97

# 代码
- C++ 递归
```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head||!head->next)  return head;
        ListNode* next = head->next;
        head->next = swapPairs(next->next);
        next->next = head;
        return next;
    }
};
```
- C++ 循环遍历
```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head||!head->next)      return head;
        ListNode* next = head->next;
        ListNode* pre = head;
        pre->next = next->next;
        next->next = pre;
        head = next;
        pre = next->next;next = pre->next;
        while(next&&next->next){
            ListNode* temp = next->next;//保存
            pre->next = temp;//连接
            next->next = temp->next;
            temp->next = next;
            pre =  next;
            next = pre->next;            
        }
        return head;
    }
};
```