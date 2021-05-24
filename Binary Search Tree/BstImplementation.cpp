#include <bits/stdc++.h>
using namespace std;
struct BstNode
{
    int data;
    BstNode *left;
    BstNode *right;
};
//setting values to the new node
BstNode *getNewNode(int data)
{
    BstNode *newNode = new BstNode();
    newNode->data = data;
    newNode->right = newNode->right = NULL;
    return newNode;
}
//inserting values in the tree
BstNode *BstInsertNode(BstNode *root, int data)
{
    if (root == NULL)
    {
        root = getNewNode(data);
    }
    else if (data <= root->data)
    {
        root->left = BstInsertNode(root->left, data);
    }
    else
    {
        root->right = BstInsertNode(root->right, data);
    }
    return root;
}
//searching a value in the tree
bool search(BstNode *root, int data)
{
    if (root == NULL)
        return false;
    else if (root->data == data)
        return true;
    else if (data <= root->data)
        return search(root->left, data);
    else
        return search(root->right, data);
}
int main()
{
    BstNode *root = NULL;
    root = BstInsertNode(root, 5);
    root = BstInsertNode(root, 15);
    root = BstInsertNode(root, 2);
    root = BstInsertNode(root, 25);
    root = BstInsertNode(root, 6);
    root = BstInsertNode(root, 11);
    root = BstInsertNode(root, 40);
    root = BstInsertNode(root, 50);
    cout << search(root, 25) << "\n";
    cout << search(root, 256) << "\n";
    cout << search(root, 5) << "\n";
    // cout << findMin(root) << "\n";
    // cout << findMax(root) << "\n";
    return 0;
}