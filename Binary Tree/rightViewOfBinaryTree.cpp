/* Right View of Binary Tree */
class Solution
{
public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
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
                if (temp->right)
                    Q.push(temp->right);
                if (temp->left)
                    Q.push(temp->left);
            }
        }
    }
};

/* recursive solution */
class Solution
{
public:
    void recursion(TreeNode *root, int level, vector<int> &res)
    {
        if (root == NULL)
            return;
        if (res.size() < level)
            res.push_back(root->val);
        recursion(root->right, level + 1, res);
        recursion(root->left, level + 1, res);
    }

    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> res;
        recursion(root, 1, res);
        return res;
    }
};