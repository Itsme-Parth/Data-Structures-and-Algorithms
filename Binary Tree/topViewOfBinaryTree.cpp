/* Top View of Binary Tree */
class Solution
{
public:
    //Function to return a list of nodes visible from the top view
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int> res;
        if (!root)
            return res;
        queue<pair<Node *, int>> Q; //making queue of pair containing value of node and the related horizontal distance
        map<int, int> mp;           //map storing horizontalDistance as the key and the topmost element as the value
        Q.push(make_pair(root, 0));
        while (!Q.empty())
        {
            pair<Node *, int> temp = Q.front();
            Q.pop();
            Node *newNode = temp.first;
            int horizontalDistance = temp.second;
            if (mp.find(horizontalDistance) == mp.end()) //if the key doesn't exist
                mp[horizontalDistance] = newNode->data;  //pushing it into the map
            if (newNode->left)
                Q.push(make_pair(newNode->left, horizontalDistance - 1));
            if (newNode->right)
                Q.push(make_pair(newNode->right, horizontalDistance + 1));
        }
        for (auto itr : mp)
            res.push_back(itr.second);
        return res;
    }
};