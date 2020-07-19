# 题目链接
[leetcode 160](https://leetcode-cn.com/problems/intersection-of-two-linked-lists/)

# 原文
编写一个程序，找到两个单链表相交的起始节点。  
如下面的两个链表：  
在节点 c1 开始相交。  
示例 1：  
输入：intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3  
输出：Reference of the node with value = 8  
输入解释：相交节点的值为 8 （注意，如果两个链表相交则不能为 0）。从各自的表头开始算起，链表 A 为 [4,1,8,4,5]，链表 B 为 [5,0,1,8,4,5]。在 A 中，相交节点前有 2 个节点；在 B 中，相交节点前有 3 个节点。  
示例 2：  
输入：intersectVal = 2, listA = [0,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1  
输出：Reference of the node with value = 2  
输入解释：相交节点的值为 2 （注意，如果两个链表相交则不能为 0）。从各自的表头开始算起，链表 A 为 [0,9,1,2,4]，链表 B 为 [3,2,4]。在 A 中，相交节点前有 3 个节点；在 B 中，相交节点前有 1 个节点。  
示例 3：  
输入：intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2  
输出：null  
输入解释：从各自的表头开始算起，链表 A 为 [2,6,4]，链表 B 为 [1,5]。由于这两个链表不相交，所以 intersectVal 必须为 0，而 skipA 和 skipB 可以是任意值。  
解释：这两个链表不相交，因此返回 null。  
注意：  
如果两个链表没有交点，返回 null.  
在返回结果后，两个链表仍须保持原有的结构。  
可假定整个链表结构中没有循环。  
程序尽量满足 O(n) 时间复杂度，且仅用 O(1) 内存。  

# 思路
- ### **链表**
  找到两个没有环的链表的起始相交点，由于相交以后一直是重复的，所以后面部分都是一样的，由此往前推即可，所以需要首先找到两个链表的长度，然后将长的链表的头节点移动到和短的链表开头相对的位置，从而让他们结尾对齐，此时只要两个链表一起往后移动同时比较即可。92 100

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0,lenB = 0;
        ListNode *_ha = headA,*_hb = headB;
        while(_ha){
            lenA += 1;
            _ha = _ha->next;
        }
        while(_hb){
            lenB += 1;
            _hb = _hb->next;
        }
        if(lenA>lenB){
            while(lenA--!=lenB)   headA = headA->next;
        }
        else{
            while(lenA!=lenB--) headB = headB->next;
        }
        while(headA&&headB){
            if(headA==headB)    return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};
```
