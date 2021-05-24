//Finding min element using iteration
int findMin(BstNode *root)
{
    if (root == NULL)
    {
        cout << "The tree is empty";
        return -1;
    }
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root->data;
}
//Finding max element using iteration
int findMax(BstNode *root)
{
    if (root == NULL)
    {
        cout << "The tree is empty";
        return -1;
    }
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root->data;
}
//Finding min element using recursion
int recurFindMin(BstNode *root)
{
    if (root == NULL) //if the tree is empty
    {
        cout << "The tree is empty";
        return -1;
    }
    else if (root->left == NULL) //base condition to find min value
        return root->data;
    return recurFindMin(root->left);
}
//Finding max element using recursion
int recurFindMax(BstNode *root)
{
    if (root == NULL) //if the tree is empty
    {
        cout << "The tree is empty";
        return -1;
    }
    else if (root->right == NULL) //base condition to find max value
        return root->data;
    return recurFindMin(root->right);
}