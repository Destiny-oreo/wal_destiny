# 题目链接
[leetcode 206](https://leetcode-cn.com/problems/reverse-linked-list/)

# 原文
反转一个单链表。  
示例:  
输入: 1->2->3->4->5->NULL  
输出: 5->4->3->2->1->NULL  
进阶:  
你可以迭代或递归地反转链表。你能否用两种方法解决这道题？

# 思路
- ### **链表-迭代**
  反转一个链表，只要一个节点一个节点的反转就可以，当当前节点存在时，就可以把当前节点反转，反转方法是记录下一个节点，然后当前节点指向前面一个节点，更新前面一个节点，更新当前节点为下一个节点。72 100 （递归：调用递归函数时深层次反转，为了返回真正的头节点，只有到最后一层时才返回真正的节点指针，其他时候一直重复调用递归函数即可。72 100）

# 代码
- C++ 链表-迭代
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
    ListNode* reverseList(ListNode* head) {
        if(!head||!head->next)   return head;
        ListNode* pre = NULL;
        while(head->next){
            ListNode *temp = head->next;
            head->next = pre;
            pre = head;
            head = temp;
        }
        head->next = pre;
        return head;
    }
};
```
- C++ 链表-递归
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
    ListNode* reverseList(ListNode* head) {
        return reverse(NULL,head);
    }
private:
    ListNode* reverse(ListNode* pre,ListNode* cur){
        if(cur == NULL) return pre;
        ListNode *temp = cur->next;
        cur->next = pre;
        // if(temp == NULL)    return cur;
        return reverse(cur,temp);
    }
};
```