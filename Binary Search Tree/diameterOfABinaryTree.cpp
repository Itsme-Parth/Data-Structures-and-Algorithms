/* Diameter of Binary Tree */
class Solution
{
public:
    //Function to return the diameter of a Binary Tree.
    int height(Node *root, int &diameter)
    {
        if (!root)
            return 0;
        int leftHeight = height(root->left, diameter);
        int rightHeight = height(root->right, diameter);
        diameter = max(diameter, leftHeight + rightHeight + 1);
        return max(leftHeight, rightHeight) + 1;
    }
    int diameter(Node *root)
    {
        int diameter = 0;
        int heightOfTree = height(root, diameter);
        return diameter;
    }
};