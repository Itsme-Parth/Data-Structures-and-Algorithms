/* Given the root of a binary tree, invert the tree, and return its root */
class Solution
{
public:
    void invert(TreeNode *root)
    {
        if (!root)
            return;
        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;
        invert(root->left);
        invert(root->right);
    }
    TreeNode *invertTree(TreeNode *root)
    {
        if (!root)
            return NULL;
        invert(root);
        return root;
    }
};