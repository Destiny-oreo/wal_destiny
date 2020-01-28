# 题目链接
[leetcode 86](https://leetcode-cn.com/problems/partition-list/)

# 原文
给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。

你应当保留两个分区中每个节点的初始相对位置。

示例:

输入: head = 1->4->3->2->5->2, x = 3
输出: 1->2->2->4->3->5

# 思路
- ### **链表 双指针**
  将非定的链表按照特定值x进行重新组成链表，直接在原链表上使用双指针很难原理交换（因为要考虑前后节点的重连接），所以重新定义新的两个指针用来存放小的部分和大于等于的部分，最后再把两部分链表进行连接。遍历head指针，当当前节点不为空时说明还要重连接工作，进行判断，如果小于特定值，lessptr指针操作，否则moreptr指针操作（所有指针连接完毕以后必须进行后移），最后两部分相连有三种情况：1是两段链表都有节点，less头节点的next是返回指针，lessptr使最后一个，需要指向more的next，moreptr是最后一个节点，需要指向空节点代表结束；2是less为空，lessptr的next指向more的第一个有效指针，返回less的next也就是more的第一个有效指针，最后记得结尾即可，3是more为空，同2。98 5

# 代码
- C++ 链表 双指针
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
    ListNode* partition(ListNode* head, int x) {
        ListNode less(0),more(0);
        ListNode *lessptr = &less;
        ListNode *moreptr = &more;
        while(head){
            if(head->val<x){
                lessptr->next = head;
                lessptr = lessptr->next;
            }
            else{
                moreptr->next = head;
                moreptr = moreptr->next;
            }
            head = head->next;
        }
        lessptr->next = more.next;
        moreptr->next = NULL;
        return less.next;
    }
};
```
