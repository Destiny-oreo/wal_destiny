# 题目链接
[leetcode 92](https://leetcode-cn.com/problems/reverse-linked-list-ii/)

# 原文
反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。

说明:
1 ≤ m ≤ n ≤ 链表长度。

示例:

输入: 1->2->3->4->5->NULL, m = 2, n = 4
输出: 1->4->3->2->5->NULL

# 思路
- ### **链表-多指针**
  翻转部分链表，主要涉及到其中不同情况的连接问题；首先找到起始反转点的前一个节点，保存为prehead，找到此节点使用--m即可，实时保存prehead；接着定义必要的中间节点指针，翻转链表的尾节点需要保存下来和后面的连接，定义为tail，头节点实时更新，需要和prehead连接，翻转过程和找到头节点如下：使用changelength（n-m+1）--来计算，先保存ptr的下一个节点用来更新，然后指向新节点（即newhead，初始化为NULL），更新newhead为当前节点用来下个节点的指向，最后更新ptr为前面保存的下一个节点。最后来解决连接问题，当翻转完成后的节点不为空时，需要连接后部分，否则可以不用连接（翻转过程中尾节点默认指向空），当从第一个节点就翻转时，返回的head不为初始head，而是newhead，即判断prehead是否为空，为空的话，不用连接，返回newhead，不为空的话，连接同时返回head即可（合并以后即判断prehead，如果不为空进行连接，连接时把head赋值给newhead，最后统一返回即可。84 19

# 代码
- C++ 链表-多指针
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int changelen = n-m+1;
        ListNode *ptr = head,*prehead = NULL;
        while(ptr&&--m){
            prehead = ptr;
            ptr = ptr->next;
        }
        ListNode *newhead = NULL,*tail = ptr;
        while(ptr&&changelen--){
            ListNode *temp = ptr->next;
            ptr->next = newhead;
            newhead = ptr;
            ptr = temp;
        }
        if(ptr)
            tail->next = ptr;
        if(prehead){
            prehead->next = newhead;
            newhead = head;
        }
        return newhead;
    }
};
```
