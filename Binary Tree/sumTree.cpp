// Should return true if tree is Sum Tree, else false
class Solution
{
public:
    int isSumTreeUtil(Node *root, bool &sumTree)
    {
        if (!root)
            return 0;
        if (!root->left && !root->right) //if it is a leaf node
            return root->data;
        int leftSum = isSumTreeUtil(root->left, sumTree);
        int rightSum = isSumTreeUtil(root->right, sumTree);
        if (root->data != leftSum + rightSum)
            sumTree = false;
        return root->data + leftSum + rightSum;
    }
    bool isSumTree(Node *root)
    {
        bool sumTree = true;
        isSumTreeUtil(root, sumTree);
        return sumTree;
    }
};