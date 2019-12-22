# 题目链接
[leetcode 21](https://leetcode-cn.com/problems/merge-two-sorted-lists/)

# 原文
将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

示例：
输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4

# 思路
- ### **链表-循环**
  由于是排序好的链表，所以当两个链表都不为空时判断两个节点值得大小，小的优先放到结果链表，大的和小链表后面的比较，直到一个链表为空；最后将不空的链表接在最后即可。9 85
- ### **递归**
  使用循环发现过于繁琐，可以考虑使用递归实现，递归三要素，第一为结束条件，即有任何一个指针为空时直接返回另外一个节点，第二为本层递归需要做什么，即比较两个节点的值得大小（已经判断过，此时两个节点均不为空），找到小的已经把小的作为头节点，后面连接的是次小的节点，运用递归寻找次小的节点指针，第三为需要返回什么，即第二步中已经找到的最小值得节点。94 79

# 代码
- C++ 链表-循环
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode temp(0);
        ListNode* head =&temp;
        while(l1&&l2){
            if(l1->val<l2->val) {
                head->next = l1;
                l1 = l1->next;
            }
            else{
                head->next = l2;
                l2 = l2->next;
            }
            head = head->next;
        }
        head->next = (l1?l1:l2);
        return temp.next;
    }
};
```
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        if(l1->val<l2->val){
            l1->next = mergeTwoLists(l1->next,l2);
            return l1;
        }
        else{
            l2->next = mergeTwoLists(l1,l2->next);
            return l2;
        }
    }
};
```