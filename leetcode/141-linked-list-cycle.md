# 题目链接
[leetcode 141](https://leetcode-cn.com/problems/linked-list-cycle/)

# 原文
给定一个链表，判断链表中是否有环。

为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。 

示例 1：  
输入：head = [3,2,0,-4], pos = 1
输出：true
解释：链表中有一个环，其尾部连接到第二个节点。

示例 2：  
输入：head = [1,2], pos = 0
输出：true
解释：链表中有一个环，其尾部连接到第一个节点。

示例 3：  
输入：head = [1], pos = -1
输出：false
解释：链表中没有环。

# 思路
- ### **链表-双指针**
  使用快慢指针，首先判断当前节点是否为空，不为空再继续后续操作；设置快慢指针，每次快指针移动两个节点，慢指针移动一个节点，移动的前提放在while的条件中--fast的后面两个节点均不为空，移动以后如果快慢节点重合时说明遇到了环，否则会在某个时间退出循环，即没有遇到环。66 100 或者可以先判断有几个节点，小于等于1个节点时候都不可能有环，返回false，否则直接在while里判断下一个节点即可，然后一起向后移，在判断fast的下一个节点，如果有继续移动，最后判断是否重合。
- ### **链表-set**
  使用set来判断是否遇到重复的节点，设置好set容器以后，即开始循环填充，先寻找当前节点是否在容器里，如果存在则遇到环，否则加入到容器中，节点后移，退出循环时说明没有环。

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
    bool hasCycle(ListNode *head) {
        if(!head)   return false;
        ListNode *fast = head,*slow = head;
        while(fast->next&&fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
            if(fast==slow)  return true;
        }
        return false;
    }
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL||head->next==NULL)    return false;
        ListNode *slow = head,*fast = head;
        while(fast){
            slow = slow->next;
            fast = fast->next;
            if(fast)    fast = fast->next;
            if(slow == fast)    break;
        }
        return slow == fast;
    }
};
```
- C++ 链表-set
```
#include <set>
class Solution {
public:
    bool hasCycle(ListNode *head) {
        std::set<ListNode *> node_set;
        while(head){
            if(node_set.find(head) != node_set.end()){
                return true;
            }
            node_set.insert(head);
            head = head->next;
        }
        return false;
    }
};
```