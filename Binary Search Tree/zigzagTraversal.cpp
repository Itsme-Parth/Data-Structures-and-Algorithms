/*
Given a Binary Tree. Find the Zig-Zag Level Order Traversal of the Binary Tree.

 

Example 1:

Input:
        3
      /   \
     2     1
Output:
3 1 2
Example 2:

Input:
           7
        /     \
       9       7
     /  \     /   
    8    8   6     
   /  \
  10   9 
Output:
7 7 9 8 8 6 9 10 
 

Your Task:
You don't need to read input or print anything. Your task is to complete the function zigZagTraversal() which takes the root node of the Binary Tree as its input and returns a list containing the node values as they appear in the Zig-Zag Level-Order Traversal of the Tree.

 

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

 

Constraints:
1 <= N <= 104
*/
//Function to store the zig zag order traversal of tree in a list.
vector<int> zigZagTraversal(Node *root)
{
    vector<int> res;
    if (root == NULL)
        return res;
    stack<Node *> s1, s2;
    s1.push(root);
    while (!s1.empty() || !s2.empty())
    {
        Node *temp;
        while (!s1.empty())
        {
            temp = s1.top();
            res.push_back(temp->data);
            if (temp->right != NULL)
                s2.push(temp->right);
            if (temp->left != NULL)
                s2.push(temp->left);
            s1.pop();
        }
        while (!s2.empty())
        {
            temp = s2.top();
            res.push_back(temp->data);
            if (temp->left != NULL)
                s1.push(temp->left);
            if (temp->right != NULL)
                s1.push(temp->right);
            s2.pop();
        }
    }
    return res;
}