# 二叉树的定义
- ### [树](https://www.jianshu.com/p/bf73c8d50dc2)
  树是n（n>=-0）个节点的有限集，且这些节点满足如下关系：  
 （1）有且仅有一个节点没有父结点，该节点称为树的根。  
 （2）除根外，其余的每个节点都有且仅有一个父结点。  
 （3）树中的每一个节点都构成一个以它为根的树。
- ### 二叉树(Binary Tree)
  - 每个节点最多有两个孩子（子树），这两个子树有左右之分，次序不可颠倒
  - 1）在二叉树的第i层上最多有2i-1 个节点 。（i>=1）  
    2）二叉树中如果深度为k,那么最多有2k-1个节点。(k>=1）  
    3）n0=n2+1 n0表示度数为0的节点数，n2表示度数为2的节点数。  
    4）在完全二叉树中，具有n个节点的完全二叉树的深度为[log2n]+1，其中[log2n]是向下取整。  
    5）若对含 n 个结点的完全二叉树从上到下且从左至右进行 1 至 n 的编号，则对完全二叉树中任意一个编号为 i 的结点有如下特性：

       (1) 若 i=1，则该结点是二叉树的根，无双亲, 否则，编号为 [i/2] 的结点为其双亲结点;  
       (2) 若 2i>n，则该结点无左孩子， 否则，编号为 2i 的结点为其左孩子结点；  
       (3) 若 2i+1>n，则该结点无右孩子结点， 否则，编号为2i+1 的结点为其右孩子结点。 
  - **满二叉树(Full Binary Tree)**： 在一棵二叉树中。如果所有分支结点都存在左子树和右子树，并且所有叶子都在同一层上，这样的二叉树称为满二叉树。
  - **完全二叉树(Complete Binary Tree)**：对一颗具有n个结点的二叉树按层编号，如果编号为i(1<=i<=n)的结点与同样深度的满二叉树中编号为i的结点在二叉树中位置完全相同，则这棵二叉树称为完全二叉树。
  - 定义： 
```
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
```
- ### 注意事项
  1. 先序遍历除了递归可以使用队列来实现，记录每一层数量即可（队列大小）；
  2. 中序遍历除了递归可以使用栈来实现，只要节点不为空一直push进栈中；
  3. 后序遍历除了递归也可以使用栈，与中序的区别时节点为空以后还要继续判断右子树是否为空；

# 经典题目
[leetcode 94 给定一个二叉树，返回它的中序 遍历](E:/English/GitHub_test/wal_destiny/leetcode/94-binary-tree-inorder-traversal.md)
[leetcode 96 n 为节点组成的二叉搜索树有多少种](E:/English/GitHub_test/wal_destiny/leetcode/96-unique-binary-search-trees.md)
[leetcode 98 判断其是否是一个有效的二叉搜索树](E:/English/GitHub_test/wal_destiny/leetcode/98-validate-binary-search-tree.md)
[leetcode 101 检查它是否是镜像对称的](E:/English/GitHub_test/wal_destiny/leetcode/101-symmetric-tree.md)
[leetcode 102 返回其按层次遍历的节点值](E:/English/GitHub_test/wal_destiny/leetcode/102-binary-tree-level-order-traversal.md)
[leetcode 104 给定一个二叉树，找出其最大深度](E:/English/GitHub_test/wal_destiny/leetcode/104-maximum-depth-of-binary-tree.md)
[leetcode 105 根据一棵树的前序遍历与中序遍历构造二叉树](E:/English/GitHub_test/wal_destiny/leetcode/105-construct-binary-tree-from-preorder-and-inorder-traversal.md)

[leetcode 114 给定一个二叉树，原地将它展开为链表](E:/English/GitHub_test/wal_destiny/leetcode/114-flatten-binary-tree-to-linked-list.md)

[leetcode 617 合并两个给定二叉树各对应节点上的值](E:/English/GitHub_test/wal_destiny/leetcode/617-Merge-Two-Binary-Trees.md)


C++性能优化指南:  E:\软件学习资料\VS学习资料\图像处理书籍\C++性能优化指南(中英文版高清)



# 搜索算法
- ### 深度优先搜索DFS
  对一个分支进行深层遍历,属于图算法的一种，英文缩写为DFS即Depth First Search.其过程简要来说是对每一个可能的分支路径深入到不能再深入为止，而且每个节点只能访问一次；
```
void DFS(Node* Root)
{
    cout<<Root->Value<<" ";

    if (Root->Left!=NULL)
        DFS(Root->Left);

    if (Root->Right!=NULL)
        DFS(Root->Right);
    return;
}
```
- ### 广度优先搜索BFS
  一层一层搜索,宽度优先搜索算法（又称广度优先搜索）是最简便的图的搜索算法之一，这一算法也是很多重要的图的算法的原型。Dijkstra单源最短路径算法和Prim最小生成树算法都采用了和宽度优先搜索类似的思想。其别名又叫BFS，属于一种盲目搜寻法，目的是系统地展开并检查图中的所有节点，以找寻结果。换句话说，它并不考虑结果的可能位置，彻底地搜索整张图，直到找到结果为止。
```
void BFS(Node *Root)
{
    queue<Node*> Q;
    Node * node ;
    Q.push(Root);
    while(!Q.empty())
    {

        node = Q.front();
        cout<<node->Value<<" ";
        if (node->Left!=NULL)
        {
            Q.push(node->Left);
        }
        if (node->Right!=NULL)
        {
            Q.push(node->Right);
        }
        Q.pop();
    }
    cout<<endl;
}
```
- ### 二叉搜索树
# 遍历算法
- **前序遍历**  
  从二叉树的根结点出发，当第一次到达结点时就输出结点数据，按照先向左在向右的方向访问。
```
/*二叉树的前序遍历递归算法*/
void PreOrderTraverse(BiTree T)
{
    if(T==NULL)
    	return;
    printf("%c", T->data);  /*显示结点数据，可以更改为其他对结点操作*/
    PreOrderTraverse(T->lchild);    /*再先序遍历左子树*/
    PreOrderTraverse(T->rchild);    /*最后先序遍历右子树*/
}
```
- **中序遍历**  
  从二叉树的根结点出发，当第二次到达结点时就输出结点数据，按照先向左在向右的方向访问。
```
/*二叉树的中序遍历递归算法*/
void InOrderTraverse(BiTree T)
{
    if(T==NULL)
    	return;
    InOrderTraverse(T->lchild); /*中序遍历左子树*/
    printf("%c", T->data);  /*显示结点数据，可以更改为其他对结点操作*/
    InOrderTraverse(T->rchild); /*最后中序遍历右子树*/
}
```
- **后序遍历**  
  从二叉树的根结点出发，当第三次到达结点时就输出结点数据，按照先向左在向右的方向访问。
```
/*二叉树的后序遍历递归算法*/
void PostOrderTraverse(BiTree T)
{
    if(T==NULL)
    return;
    PostOrderTraverse(T->lchild);   /*先后序遍历左子树*/
    PostOrderTraverse(T->rchild);   /*再后续遍历右子树*/
    printf("%c", T->data);  /*显示结点数据，可以更改为其他对结点操作*/
}
```


