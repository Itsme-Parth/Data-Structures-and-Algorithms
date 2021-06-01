/* The function should print all the paths from root
 to leaf nodes of the binary tree */
void pathsUtil(Node *root, vector<int> &curr_path, vector<vector<int>> &res)
{
    if (!root)
        return;
    curr_path.push_back(root->data); //pushing the data into the current path as soon as we see a new node
    if (!root->left && !root->right) // if it is a leaf node we push the data into the result vector
        res.push_back(curr_path);
    pathsUtil(root->left, curr_path, res);
    pathsUtil(root->right, curr_path, res);
    curr_path.pop_back(); //we pop back the current value entered to return to the previous state
}
vector<vector<int>> Paths(Node *root)
{
    vector<vector<int>> res;
    vector<int> curr_path;
    pathsUtil(root, curr_path, res);
    return res;
}