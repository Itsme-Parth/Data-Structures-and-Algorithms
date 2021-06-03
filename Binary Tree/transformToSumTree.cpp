class Solution
{
public:
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    int sumTree(Node *root)
    {
        if (!root)
            return 0;
        int leftSum = sumTree(root->left);
        int rightSum = sumTree(root->right);
        int value = root->data + leftSum + rightSum; //calculation value before changing the root -> data
        root->data = leftSum + rightSum;             //updating the value later after storing it in value
        return value;                                //returning value which would change the data of the node
    }
    void toSumTree(Node *node)
    {
        if (!root)
            return;
        sumTree(node);
        return;
    }
};