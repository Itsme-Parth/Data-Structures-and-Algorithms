/*Vertical Order Traversal of a Binary Tree*/
class Solution
{
public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        vector<int> res;
        if (root == NULL)
            return res;
        map<int, vector<int>> mp;
        queue<pair<Node *, int>> Q;
        Q.push(make_pair(root, 0)); //pushing the first pair into the queue with root and 0
        while (!Q.empty())
        {
            pair<Node *, int> newRoot = Q.front();
            Node *temp = newRoot.first;              //creating new TreeNode
            int horizontalDistance = newRoot.second; //Storing value into horizontalDistance
            mp[horizontalDistance].push_back(temp->data);
            if (temp->left) //if temp has a left node then pushing value in the queue and decreasing distance by 1
                Q.push(make_pair(root->left, horizontalDistance - 1));
            if (temp->right) //if temp has a right node then pushing value in the queue and increasing distance by 1
                Q.push(make_pair(root->right, horizontalDistance + 1));
            Q.pop();
        }
        for (auto itr : mp)
        {
            for (auto it : itr.second)
            {
                res.push_back(it);
            }
        }
        return res;
    }
};