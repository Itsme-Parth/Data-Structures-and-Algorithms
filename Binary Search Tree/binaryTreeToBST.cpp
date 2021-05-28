#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

void printInorder(struct Node *node)
{
    if (node == NULL)
        return;

    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}

// Function to Build Tree
Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    return root;
}
/* The Node structure is
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; 
*/

class Solution
{
public:
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    void retreive(Node *root, vector<int> &storeVal)
    {
        if (root == NULL)
            return;
        retreive(root->left, storeVal);
        storeVal.push_back(root->data);
        retreive(root->left, storeVal);
    }
    void constructBST(Node *root, vector<int> &storeVal, int &index)
    {
        if (root == NULL)
            return;
        constructBST(root->left, storeVal, index);
        root->data = storeVal[index++];
        constructBST(root->left, storeVal, index);
    }
    Node *binaryTreeToBST(Node *root)
    {
        vector<int> storeVal;
        int index = 0;
        retreive(root, storeVal);
        sort(storeVal.begin(), storeVal.end());
        constructBST(root, storeVal, index);
        return root;
    }
};

int main()
{
    int t;
    scanf("%d\n", &t);
    while (t--)
    {
        string s;
        getline(cin, s);
        Node *root = buildTree(s);
        Solution obj;
        Node *res = obj.binaryTreeToBST(root);
        printInorder(res);
        cout << endl;
    }
    return 0;
}