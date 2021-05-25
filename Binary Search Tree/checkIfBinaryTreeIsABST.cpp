/* Check if a binary tree is binary search tree or not */
struct Node
{
    int data;
    Node *left;
    Node *right;
};
bool isBSTUtil(Node *root, int minVal, int maxVal)
{
    if (root == NULL)
        return true;
    if (root->data >= minVal && root->data < maxVal && isBSTUtil(root->left, minVal, root->data) &&
        isBSTUtil(root->left, root->data, maxVal))
        return true;
    return false;
}
bool isBinarySearchTree(Node *root)
{
    isBSTUtil(root, INT_MIN, INT_MAX);
}