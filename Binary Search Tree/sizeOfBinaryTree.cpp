/*Size of Binary Tree */
void preorder(Node *root, int &count)
{
    if (root == NULL)
        return;
    count++;
    preorder(root->left, count);
    preorder(root->right, count);
}
int getSize(Node *node)
{
    int count;
    preorder(node, count);
    return count;
}