#include <bits/stdc++.h>
using namespace std;
struct BstNode
{
    int data;
    BstNode *left;
    BstNode *right;
};
BstNode *getNewNode(int data)
{
    BstNode *newNode = new BstNode();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
BstNode *BstInsertNode(BstNode *root, int data)
{
    if (root == NULL)
    {
        root = getNewNode(data);
    }
    else if (data <= root->data)
        root->left = BstInsertNode(root->left, data);
    else
        root->right = BstInsertNode(root->right, data);
    return root;
}
//Finding height of the binary tree using recursion
int findHeight(BstNode *root)
{
    if (root == NULL)
        return -1;

    return max(findHeight(root->left), findHeight(root->right)) + 1;
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
    cout << findHeight(root);
    return 0;
}