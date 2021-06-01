/* Left View of Binary Tree */
vector<int> leftView(Node *root)
{
    vector<int> res;
    if (root == NULL)
        return res;
    queue<Node *> Q;
    bool isFirst = true;
    Q.push(root);
    Q.push(NULL); //Null indicates the start of a new level
    while (!Q.empty())
    {
        Node *temp = Q.front();
        Q.pop();
        if (temp == NULL)
        {
            if (Q.size() == 0)
                return res; //if the queue is empty after null return the vector
            else
            {
                Q.push(NULL);
                isFirst = true; //after a NULL we get the first/leftmost element of the level
            }
        }
        else
        {
            if (isFirst == true)
            {
                res.push_back(temp->data);
                isFirst = false; //setting other elements as false on the same level as false
            }
            if (temp->left)
                Q.push(temp->left);
            if (temp->right)
                Q.push(temp->right);
        }
    }
}

/* METHOD 2 */
void printLeftView(Node *root)
{
    if (!root)
        return;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        // number of nodes at current level
        int n = q.size();

        // Traverse all nodes of current level
        for (int i = 1; i <= n; i++)
        {
            Node *temp = q.front();
            q.pop();

            // Print the left most element
            // at the level
            if (i == 1)
                cout << temp->data << " ";

            // Add left node to queue
            if (temp->left != NULL)
                q.push(temp->left);

            // Add right node to queue
            if (temp->right != NULL)
                q.push(temp->right);
        }
    }
}

/* recursive solution */
class Solution
{
public:
    void recursion(TreeNode *root, int level, vector<int> &res)
    {
        if (root == NULL)
            return;
        if (res.size() > level)
            res.push_back(root->val);
        recursion(root->right, level + 1, res);
        recursion(root->left, level + 1, res);
    }

    vector<int> leftSideView(TreeNode *root)
    {
        vector<int> res;
        recursion(root, 1, res);
        return res;
    }
};