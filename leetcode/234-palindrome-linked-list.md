# 题目链接
[leetcode 234](https://leetcode-cn.com/problems/palindrome-linked-list/)

# 原文
请判断一个链表是否为回文链表。  
示例 1:  
输入: 1->2  
输出: false  
示例 2:  
输入: 1->2->2->1  
输出: true  
进阶：  
你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？

# 思路
- ### **链表-反转 双指针**
  判断是否为回文链表需要一个正方向遍历一个反方向遍历，对于链表无法反方向遍历，所以考虑先反转后半部分，然后再遍历对比；首先找到后半部分，使用双指针找到需要反转的部分，然后设置好pre指针记录前一个节点，然后开始反转，最后使用head和反转后的pre头节点进行一一对比即可。45 54

# 代码
- C++ 链表-反转 双指针
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
    bool isPalindrome(ListNode* head) {
        if(!head)   return true;
        ListNode *fast = head,*slow = head,*pre = NULL;
        while(fast&&fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        while(slow){
            ListNode *temp = slow->next;
            slow->next = pre;
            pre = slow;
            slow = temp;
        }
        while(head&&pre){
            if(head->val!=pre->val) return false;
            head = head->next;
            pre = pre->next;
        }
        return true;

    }
};
```
