/*Diagonal Traversal of Binary Tree */
void diagonalUtil(Node *root, map<int, vector<int>> &mp, int distance)
{
    if (root == NULL)
        return;
    mp[distance].push_back(root->data);
    diagonalUtil(root->left, mp, distance + 1);
    diagonalUtil(root->right, mp, distance);
}
vector<int> diagonal(Node *root)
{
    vector<int> res;
    if (root == NULL)
        return res;
    map<int, vector<int>> mp;
    int distance = 0;
    diagonalUtil(root, mp, distance);
    for (auto itr : mp)
    {
        for (auto it : itr.second)
            res.push_back(it);
    }
    return res;
}