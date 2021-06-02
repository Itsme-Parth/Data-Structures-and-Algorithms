class Solution
{
public:
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    int sumTree(Node *root)
    {
        if (!root)
            return 0;
        if (!root->left && !root->right)
            return
    }
    void toSumTree(Node *node)
    {
        if (!root)
            return;
        sumTree(node);
        return;
    }
};