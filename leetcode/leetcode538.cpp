/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        if(!root)    return NULL;
        convertBST(root->right);    //递归 假设右子树此时建立完成
        root->val+=sums;            //中序遍历自己 更新节点
        sums = root->val;           //记录总和
        convertBST(root->left);
        return root;
    }
private:
    int sums = 0;
};