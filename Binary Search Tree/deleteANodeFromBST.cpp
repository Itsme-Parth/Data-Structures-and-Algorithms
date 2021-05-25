/*Delete a node from Binary Search Tree */
struct Node *
{
    int data;
    Node *left;
    Node *right;
};

Node *deleteNode(Node *root, int data)
{
    if (root == NULL)
        return NULL;
    else if (root->data <= data)
        root->left = deleteNode(root->left, data);
    else if (root->data > data)
        root->right = deleteNode(root->right, data); //setting up the new links as returned by root in the end
    else                                             // you've found the number
    {
        if (root->right == NULL && root->left == NULL) //case of no child / leaf node
        {
            delete root;
            root = NULL;
        }
        else if (root->left == NULL) //case of 1 child
        {
            Node *temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root;
            root = root->left;
            delete temp;
        }
        else //case of two children
        {
            Node *temp = findMin(root->right); //findMin is the function to find minimum
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}