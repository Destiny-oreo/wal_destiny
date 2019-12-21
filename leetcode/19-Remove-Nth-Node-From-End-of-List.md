# 题目链接
[leetcode 19](https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/)

# 原文
给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

示例：

给定一个链表: 1->2->3->4->5, 和 n = 2.

当删除了倒数第二个节点后，链表变为 1->2->3->5.
说明：

给定的 n 保证是有效的。

进阶：

你能尝试使用一趟扫描实现吗？

# 思路
- ### **快慢双指针**
  一趟扫描，所以考虑使用双指针，要求定位在链表倒数第n个，且不知道一共多少个节点，所以设置快慢两个指针，两指针相差n个节点（即快节点先走n个），此时判断特殊情况即需要去除的是头节点，这种情况下快指针已经走到了最后的空节点，直接返回`head->next`，若不是这种特殊情况，则把快节点走到最后一位，此时慢节点刚好听到要删除的节点前，删除即可。62 91 
- ### **暴力扫描两次**
  两趟扫描，第一趟计算总长度，然后计算要删除的是第几个，若为0则返回`head->next`，若不是则扫描至特定位置进行删除即可。

# 代码
- C++ 快慢双指针
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast = head,*slow = head;
        while(n--){//1 2 3 4 5 6    2    fast->3 slow ->1
            fast = fast->next;
        }
        if(!fast)   return head->next;
        while(fast->next){//fast->6  slow->4 
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;    //1 2 3 4   4  fast->null    3 fast->4
    }
};
```
- C++ 暴力扫描两次
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int total_len = 0;
        ListNode* temp = head;
        while(temp){
            temp = temp->next;
            total_len++;
        }
        int num = total_len-n;
        temp = head;
        if(num==0)  return head->next;
        else{
            num--;
            while(num--&&temp){
                temp = temp->next;
            }
            ListNode* next = temp->next;
            temp->next = next->next;
        }
        return head;
    }
};
```