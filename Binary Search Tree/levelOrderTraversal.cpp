#include <bits/stdc++.h>
using namespace std;

struct Node
{
    char data;
    Node *left;
    Node *right;
};

// Function to print Nodes in a binary tree in Level order
void LevelOrder(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> Q;
    Q.push(root);
    //While there is atleast one node in the queue
    while (!Q.empty())
    {
        Node *curr = Q.front();
        cout << curr->data << " ";
        if (curr->left != NULL)
            Q.push(curr->left);
        if (curr->right != NULL)
            Q.push(curr->right);
        Q.pop(); //removing the element at front
    }
}

Node *Insert(Node *root, char data)
{
    if (root == NULL)
    {
        root = new Node();
        root->data = data;
        root->left = root->right = NULL;
    }
    else if (data <= root->data)
        root->left = Insert(root->left, data);
    else
        root->right = Insert(root->right, data);
    return root;
}

int main()
{
    /*Code To Test the logic
	  Creating an example tree
	            M
			   / \
			  B   Q
			 / \   \
			A   C   Z
    */
    Node *root = NULL;
    root = Insert(root, 'M');
    root = Insert(root, 'B');
    root = Insert(root, 'Q');
    root = Insert(root, 'Z');
    root = Insert(root, 'A');
    root = Insert(root, 'C');
    //Print Nodes in Level Order.
    LevelOrder(root);
}
