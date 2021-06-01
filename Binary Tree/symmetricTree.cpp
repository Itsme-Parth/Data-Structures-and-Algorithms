/* Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center). */
class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (!p && !q)
            return true;
        if (!p || !q)
            return false;
        if (p->val != q->val)
            return false;
        return (isSameTree(p->left, q->right) && isSameTree(p->right, q->left));
    }
    bool isSymmetric(TreeNode *root)
    {
        if (root == NULL)
            return true;
        return isSameTree(root->left, root->right);
    }
};