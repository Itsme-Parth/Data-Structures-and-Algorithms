class Solution
{
public:
    void connect(Node *root)
    {
        if (!root)
            return NULL;
        queue<Node *> Q;
        Q.push(root);
        Q.push(NULL);
        while (!Q.empty())
        {
            Node *temp = Q.front();
            if (temp->left != NULL)
                Q.push(temp->left);
            if (temp->right != NULL)
                Q.push(temp->right);
            Q.pop();
        }
    }
};