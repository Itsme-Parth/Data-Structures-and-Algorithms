/* Check for Balanced Tree */
int height(Node *root, bool &balanced)
{
    if (!root)
        return 0;
    int leftHeight = height(root->left, balanced);
    int rightHeight = height(root->right, balanced);
    if (abs(leftHeight - rightHeight) > 1)
        balanced = false;
    return max(leftHeight, rightHeight) + 1;
}
bool isBalanced(Node *root)
{
    bool balanced = true;
    int heightOfTree = height(root, balanced);
    return balanced;
}

/*better time complexity approach */
/* this solution calculates height multiple times */
class Solution
{
public:
    int height(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        return max(height(root->left), height(root->right)) + 1;
    }
    bool isBalanced(TreeNode *root)
    {
        if (root == NULL)
            return true;
        return abs(height(root->left) - height(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
};