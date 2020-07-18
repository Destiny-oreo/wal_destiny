# 题目链接
[leetcode 148](https://leetcode-cn.com/problems/sort-list/)

# 原文
在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。  
示例 1:  
输入: 4->2->1->3  
输出: 1->2->3->4  
示例 2:  
输入: -1->5->3->4->0  
输出: -1->0->3->4->5

# 思路
- ### **归并排序**
  对于链表排序，无法使用一般的选择排序，重复重连会十分耗时间，一般使用归并排序，将链表分为有限个对半链表，直到分到最后链表只剩一个，然后开始排序；对于分开的过程可以使用快慢指针，循环结束条件为fast或者fast的下一节点为空，为了记录前半段的结尾，需要额外申请一个pre指针记录slow的前一节点，fast节点停止时到达链表结尾，slow节点到达的是第二段的开头，分开以后以pre后面置空结束，最后返回合并好的链表即可；对于合并：首先判断是否需要合并，即两边有可能为空链表的情况，直接返回另一半的链表，如果不空，则开始排序开头，那边小返回那边的链表开头，同时把另一条链表的开头放的小节点的后面，再后面的节点连上重新merge的结果。46 13
- ### **merge**
  重新使用循环来实现merge函数，此时需要设立一个专门的头节点才可以全部连接起来（先新建节点，然后使用指针指向节点），当两个链表都有节点时进行比较并移动，当一个链表为空时退出，然后完全连接不空的链表即可。

# 代码
- C++ 归并排序
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
    ListNode* sortList(ListNode* head) {
        if(!head||!head->next)  return head;
        ListNode *slow = head,*fast = head,*pre = head;
        while(fast&&fast->next){
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = NULL;
        return merge(sortList(head),sortList(slow));
    }
private:
    ListNode* merge(ListNode* left,ListNode* right){
        if(!left)   return right;
        else if(!right) return left;
        if(left->val<right->val){
            left->next = merge(left->next,right);
            return left;
        }
        else{
            right->next = merge(left,right->next);
            return right;
        }
    }
};
```
- C++ merge
```
    ListNode* merge(ListNode* left,ListNode* right){
        ListNode temp(0);
        ListNode* cur = &temp;
        while(left&&right){
            if(left->val<right->val){
                cur->next = left;
                left = left->next;
            }
            else{
                cur->next = right;
                right = right->next;
            }
            cur = cur->next;
        }
        if(left)    cur->next = left;
        if(right)   cur->next = right;
        return temp.next;
    }
```