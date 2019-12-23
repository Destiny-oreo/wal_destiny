# [链表](https://blog.csdn.net/Kevin_zhai/article/details/50494020)
- **定义**：链表是一种常见的数据结构，它是一种物理存储单元上非连续、非顺序的存储结构，数据元素的逻辑顺序是通过链表中的指针链接次序实现的。链表由一系列结点（链表中每一个元素称为结点）组成，结点可以在运行时动态生成。每个结点包括两个部分：一个是存储数据元素的数据域，另一个是存储下一个结点地址的指针域。
```
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
```
- **优势**：和数组相比，当进行插入和删除操作时，链表操作的时间复杂度仅为O(1)。另外，因为链表在内存中不是连续存储的，所以可以充分利用内存中的碎片空间。除此之外，链表还是很多算法的基础，最常见的哈希表就是基于链表来实现的。
# 经典题目
[leetcode 2 将逆序链表表示的两个数相加，返回一个新的链表来表示它们的和](E:/English/GitHub_test/wal_destiny/leetcode/2-Add-Two-Numbers.md)  
[leetcode 19 删除链表的倒数第 n 个节点](E:/English/GitHub_test/wal_destiny/leetcode/19-Remove-Nth-Node-From-End-of-List.md)  
[leetcode 21 将两个有序链表合并为一个新的有序链表](E:/English/GitHub_test/wal_destiny/leetcode/21-Merge-Two-Sorted-Lists.md)   
[leetcode 23 将k个有序链表合并为一个新的有序链表](E:/English/GitHub_test/wal_destiny/leetcode/23-Merge-k-Sorted-Lists.md)   
[leetcode 24 两两交换给定链表其中相邻的节点](E:/English/GitHub_test/wal_destiny/leetcode/24-Swap-Nodes-in-Pairs.md)   

# [常见算法](https://blog.csdn.net/qq_18150255/article/details/88636821https://blog.csdn.net/qq_18150255/article/details/88636821)
- ## 链表反转
  逆序的思路：首先声明一个空指针node指向一个空节点，然后将原链表中的节点1指向node，接着声明一个临时根节点root用来保存链表的表头，循环操作，直到root为空指针。  
示例程序如下：
```
ListNode *reverse(ListNode *root)
{
    ListNode *node = nullptr;
    while(root){
        ListNode *next = root->next;	//保存表头的位置
        //由于逆序，因此此时原表头的下一个节点为空节点 ，下一个node为原表头
        root->next = node;				
        node = root;					//保存此时的根节点，准备下一次连接
        root = next;					//重置新的表头
    }
    return node; 
}

```
- ## 链表去重
  - 有序链表去重：  
  **算法思路**：首先明确判断的条件：相同的元素是相邻的，即cur->val == cur->next->val，找到这个元素后，先将该元素（cur->next）的后继节点连接到一个临时节点保存起来，然后删除cur->next，此时cur->next为空，最后将临时节点连接到当前cur的后继。此处不能直接将cur->next的后继节点赋值给cur->next，也不能首先删除cur->next，一定要缓存cur->next。  
	```
	//code:
	void removeDuplicates(ListNode *head) {
	    if (head == nullptr) return;		//若是空指针，则直接跳出
	    for (ListNode *cur=head; cur->next; )    //拷贝head到cur，判断cur->next是否为空，为空就跳出循环；
	        if (cur->val == cur->next->val) {    //比较条件
	            ListNode *next = cur->next->next;    //临时缓存cur->next的后继节点
	            delete  cur->next;        //删除重复的节点，释放内存
	            cur->next = next;        //将cur->next的后继节点连接到cur的后继
	        } else 
	        { 
	            cur = cur->next;    //比较下一个节点
	        }
	}
	
	```
  - 无需链表去重:  
  **算法思路**：首先明确判断的条件：寻找后续的节点中的元素与当前节点是否相同，寻找到相同的元素后删除节点，继续寻找剩下的元素中是否有相同的元素。
	```
	//code2:时间复杂度O(N),空间复杂度O(N)
	void removeRep1(ListNode *head){
	        if(head==nullptr){
	            return;
	        }
	        set<int> val_set;    //利用容器find的功能
	        ListNode *pre = head;    //声明前一个节点
	        ListNode *cur = head->next;    //声明当前比较的节点
	        val_set.insert(pre->val);    //头结点加到容器列表中
	        while(cur != nullptr)
	        {
	            //判断容器中是否已存在cur->val，不存在，就将该元素添加到容器中
	            if(val_set.find(cur->val) == val_set.end())
	            {
	                val_set.insert(cur->val);
	                pre = cur;     //更新上一个节点
	            }
	            else
	            {
	                pre->next = cur->next;    //删除重复节点
	                delete cur;               //删除重复的节点的内存
	                cur = pre;                //将链表重新连接起来
	            }
	            cur = cur->next;              //再以下一个节点作为参考点
	        }           
	    }
	```
- ## 链表合并
  算法思路：在程序中使用dummy节点来缓存节点，其作用是保存新的链表，头节点的值可任意设置，最后返回dummy.next即可。
```
//code:
ListNode *shuffleMerge(ListNode *a, ListNode *b) {
    ListNode dummy(0), *tail = &dummy;
    while (a && b) {
        tail->next = a;        //初始时tail->next为空，以后的循环中令上一轮中的节点b指向下一个a
        tail = a;              //更新tail的地址，以便下一次的拼接
        a = a->next;           //处理a的下一个节点
        tail->next = b;        //上一轮中的节点a指向下一个b
        tail = b;              //更新tail的地址，以便下一次的拼接
        b = b->next;           //处理b的下一个节点
    }
    tail->next = (a ? a : b);    //若a和b不是等长的，将剩余部分拼接到tail的末尾
    return dummy.next;           //返回拼接好的节点的头结点
}

```  
- ## 链表顺序插入
  - 直接法：遍历整个链表，找到newNode合适的位置插入
	```
	//code:
	void sortinsert(ListNode **root, ListNode *newNode) {
	     if (*root ==  nullptr || (*root)->val >= newNode->val) {
	         newNode->next = *root;
	         *root = newNode;       //更新链表root   
	     }
	     else
	     {
	         ListNode *cur = *root;
	         //如果节点cur不为空，而且下一个节点的值小于newNode的值，则移动cur的位置
	         while(cur->next != nullptr && cur->next->val < newNode->val)
	         {
	            cur = cur->next;
	         }
	         //否则，将新节点插入当前位置
	         newNode->next = cur->next;
	         cur->next = newNode;       
	     }
	     
	 }
	```
  - 引用法:和引用类似的思路，不过不再是cur的移动，而是指针的移动  
```
//code:
 void sortinsert(ListNode **root, ListNode *newNode) {
     ListNode **cur = root;//拷贝更节点
     //如果节点*cur不为空，而且下一个节点的值小于newNode的值，则移动*cur的位置
     while(*cur != nullptr && (*cur)->val < newNode->val){
        cur = &((*cur)->next);       
     }
    //否则，将新节点插入当前位置
    newNode->next = *cur;
    *cur = newNode;     
 }
```
- ## 链表排序
  根据上述的顺序插入，链表的排序问题关键在于如何插入元素。  
算法思路：声明一个空链表ListNode *newroot = nullptr，然后遍历整个链表，再用上一节提到的顺序插入函数，将每一个节点用sortinsert到newroot  
```
void insertSort(ListNode **head) {
    ListNode *newHead = nullptr;        //声明空节点
    ListNode *curr = *head, *next;      //声明一个cur和一个临时节点
    //若当前节点不为空
    while (curr) {      
        next = curr->next;              //缓存后续的节点    
        sortinsert2(&newHead, curr);    //处理当前的节点
        curr = next;                    //更新当前节点，准备处理下一个节点
    }
    *head = newHead;                    //更新链表
}
```