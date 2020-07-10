# 题目链接
[leetcode 142](https://leetcode-cn.com/problems/linked-list-cycle-ii/)

# 原文
给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。  
说明：不允许修改给定的链表。 

示例 1：  
输入：head = [3,2,0,-4], pos = 1
输出：tail connects to node index 1
解释：链表中有一个环，其尾部连接到第二个节点。
   
示例 2：  
输入：head = [1,2], pos = 0
输出：tail connects to node index 0
解释：链表中有一个环，其尾部连接到第一个节点。

示例 3：   
输入：head = [1], pos = -1
输出：no cycle
解释：链表中没有环。

# 思路
- ### **链表-双指针**
  使用快慢指针，首先和上一题判断是否存在环的方法类似，在重合以后保存相遇的节点，然后退出循环，最后判断，如果有相遇的节点，则有环，没有相遇的节点，直接返回null；有环时，为了找到环的起点，遇到重新设置两个节点，一个在相遇点，一个在起点，一起以相同的速度前进，相遇时即在环的起点。大致推导：2s=2(n-m+p)=(n-m)+p+mk(s为慢节点的路程，n为除去环的链表长度，m为环的长度，p为相遇节点距离环起点的距离，k为正整数，代表多饶了k圈)；或者a+mb+x=2(a+x) => a=mb-x=(m-1)b+(b-x)。100 10

# 代码
- C++ 链表-双指针
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
    ListNode *detectCycle(ListNode *head) {
        //if(!head||!head->next)  return NULL;
        ListNode *fast = head,*slow = head,*meet = NULL;
        while(fast){
            fast = fast->next;
            slow = slow->next;
            if(fast)  fast = fast->next;
            if(fast == slow){
                meet = fast;
                slow = head;
                break;
            }
        }
        if(meet==NULL)  return NULL;
        else{
            while(slow!=meet){
                slow = slow->next;
                meet = meet->next;
            }
            return meet;
        }

    }
};
```