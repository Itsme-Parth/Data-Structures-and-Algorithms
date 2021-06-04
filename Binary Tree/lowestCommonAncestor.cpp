/*
Find the lowest common ancestor of two given nodes
                CASE - 1
            n1 = 2 , n2 =  2
                  1
                   \  
                    2    
               CASE - 2
            n1 = 2 , n2 =  2
                  1
                /  
               2    
                CASE - 3
            n1 = 2 , n2 =  3
                  1
                /  \
               2    3
               CASE - 4
            n1 = 3 , n2 = 4
                    5
                   /
                  2
                /  \
               3    4
                CASE - 5
            n1 = 3 , n2 = 4
                    5
                     \
                      2
                     / \
                    3   4
*/
class Solution
{
public:
    //Function to return the lowest common ancestor in a Binary Tree.
    Node *lca(Node *root, int n1, int n2)
    {
        if (!root)
            return NULL; //case 0, if the tree is empty
        if (root->data == n1 || root->data == n2)
            return root; //case 1, 2
        Node *left = lca(root->left, n1, n2);
        Node *right = lca(root->right, n1, n2);
        if (left && right)
            return root; //case 3
        if (left)
            return left; //case 4
        if (right)
            return right; //case 5
        return NULL;
    }
};