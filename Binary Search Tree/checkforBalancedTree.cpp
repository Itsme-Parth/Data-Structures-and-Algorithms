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