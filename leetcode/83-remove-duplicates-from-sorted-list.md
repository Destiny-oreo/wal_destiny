# 题目链接
[leetcode 83](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/)

# 原文
给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。

示例 1:  
输入: 1->1->2   
输出: 1->2  
示例 2:    
输入: 1->1->2->3->3  
输出: 1->2->3

# 思路
- ### **链表**
  排序链表，所以删除重复的元素只要把前后两个元素的值相比即可，首先判断初始长度，然后备份链表头以后开始遍历，结束条件是到达倒数第二个节点（因为每个节点的操作就是判断后面一个节点是否和当前节点重复），搜索中如果后面一个节点和当前节点重复，跳过后面一个节点即可，如果不重复，更新当前节点到达后面一个节点。100 8

# 代码
- C++ 链表
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL||head->next==NULL)    return head;
        ListNode* temp = head;
        while(temp&&temp->next){//112 11233
            if(temp->next->val!=temp->val)  temp = temp->next;
            else{
                temp->next = temp->next->next;	//delete node;(ListNode *node = temp->next)
            }
        }
        return head;
    }
};
```
