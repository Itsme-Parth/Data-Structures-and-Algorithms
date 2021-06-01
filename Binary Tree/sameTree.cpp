/* Check for identical binary trees */
class Solution
{
public:
    //Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2)
    {
        if (!r1 && !r2) //if both are empty trees
            return true;
        if (!r1 || !r2) //if one is empty and other is not
            return false;
        if (r1->data != r2->data) //if the data is not equal
            return false;
        return (isIdentical(r1->left, r2->left) && isIdentical(r1->right, r2->right)); //following the same for the
                                                                                       // left and right subtrees
    }
};