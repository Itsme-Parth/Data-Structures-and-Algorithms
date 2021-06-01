/* Check if subtree  */
class Solution
{
public:
    //Function to check identical trees
    bool isIdentical(Node *r1, Node *r2)
    {
        if (!r1 && !r2)
            return true;
        if (!r1 || !r2)
            return false;
        if (r1->data != r2->data)
            return false;
        return (isIdentical(r1->left, r2->left) && isIdentical(r1->right, r2->right));
    }
    //Function to check if S is a subtree of tree T.
    bool isSubTree(Node *T, Node *S)
    {
        //base conditions
        if (!T && !S)
            return true;
        if (!T || !S)
            return false;
        queue<Node *> Q;
        Q.push(T);
        while (!Q.empty())
        {
            Node *temp = Q.front();
            Q.pop();
            if (temp->data == S->data) // if we have found a node with same value as the root node of S
            {
                if (isIdentical(temp, S)) //then check if the two trees are identical or not
                    return true;
            }
            if (temp->left)
                Q.push(temp->left);
            if (temp->right)
                Q.push(temp->right);
        }
        return false; //if the queue is empty and still we haven't found the subtree then return false
    }
};