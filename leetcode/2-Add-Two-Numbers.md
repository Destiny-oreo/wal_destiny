# 题目链接
[leetcode 2](https://leetcode-cn.com/problems/add-two-numbers/)

# 原文
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807

# 思路
- ### **链表**
  从低到高计算链表各位的和，关键点在于进位的处理，尝试用递归，发现判断结束时的点太多，开始使用循环，因为new返回的是一个指针，所以必须用ListNode* 来接收。初始定义节点指针并初始化进位为0，开始循环（只有两个节点都为空且进位为0时才退出循环），先计算当前节点的和（包括进位），计算时需要计算节点是否为空，为空时赋值为0，利用完进位值便需要更新，同时用计算的节点值new新的链表节点并做好连接工作，更新指针；最后在更新节点指针时要再次单独判断是否为空，已经为空时不需再更新直接进入下层循环。

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode head(0),*ptr = &head;
        int carry = 0;
        while(l1||l2||carry){
            int num1 = l1==NULL?0:l1->val;
            int num2 = l2==NULL?0:l2->val;
            int result = num1+num2+carry;
            ListNode* temp = new ListNode(result%10);
            ptr->next = temp;
            ptr = ptr->next;
            carry = result/10;
            if(l1)  l1 = l1->next;
            if(l2)  l2 = l2->next;
        }
        return head.next;
    }
};
```