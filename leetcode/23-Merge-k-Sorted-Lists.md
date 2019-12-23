# 题目链接
[leetcode 23](https://leetcode-cn.com/problems/merge-k-sorted-lists/)

# 原文
合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。

示例:
输入:  
[  
  1->4->5,
  1->3->4,
  2->6  
]  
输出: 1->1->2->3->4->4->5->6

# 思路
- ### **暴力求解+递归**
  在21题中已经做过了合并两个排序链表，这回合并k个第一反应就是合并k-1次，每一次都调用mergetwolists函数（函数内进行递归合并），每次排序结果都赋值给Lists[0]（以判断过链表向量长度小于等于1的情况），同时每次都把list[0]和lists[i]进行合并，最后返回lists[0]。15 87
- ### **双层递归-分治**
  首先判断空向量的情况，然后开始分治，即传入首尾地址进行进行合并（即将左侧地址和中间地址进行合并，中间+1和右侧地址进行合并，即逐渐缩短l1和l2的范围，直到最后l1和l2只有一条链表时才真正进行合并），最后返回合并结束的两个链表的真正合并（结束条件：左右指针相遇，这一层递归需要将左右链表合并，返回结果是合并的结果）；合并两个具体链表使用21题中的递归方法即可（可见合并多条时次数固定，但入股合并的两条链表长度相差不大时速度更快）。94 76

# 代码
- C++ 暴力求解+递归
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==1)     return lists[0];
        if(lists.size()==0)     return NULL;
        for(int i=1;i<lists.size();i++){
            lists[0] = mergeTwoLists(lists[0],lists[i]);
        }
        return lists[0];
    }
private:
    ListNode* mergeTwoLists(ListNode* l1,ListNode* l2){
        if(!l1)     return l2;
        if(!l2)     return l1;
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
- C++ 双层递归-分治
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)     return NULL;
        return merge(lists,0,lists.size()-1);
    }
private:
    ListNode* merge(vector<ListNode*>& lists,int left,int right){
        if(left==right) return lists[left];
        ListNode* l1 = merge(lists,left,left+(right-left)/2);
        ListNode* l2 = merge(lists,left+(right-left)/2+1,right);
        return mergeTwoLists(l1,l2);
    }
    ListNode* mergeTwoLists(ListNode* l1,ListNode* l2){
        if(!l1)     return l2;
        if(!l2)     return l1;
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