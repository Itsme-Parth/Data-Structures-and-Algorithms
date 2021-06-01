/* Root to leaf path sum  */
class Solution
{
public:
    void hasPathSumUtil(Node *root, int curr_sum, bool &sum, int S)
    {
        if (!root)
            return;
        curr_sum += root->data;
        if (!root->left && !root->right && curr_sum == S)
        {
            sum = true;
            return;
        }
        hasPathSumUtil(root->left, curr_sum, sum, S);
        hasPathSumUtil(root->right, curr_sum, sum, S);
        //curr_sum -= root->data;
    }
    bool hasPathSum(Node *root, int S)
    {
        bool sum = false;
        int curr_sum = 0;
        hasPathSumUtil(root, curr_sum, sum, S);
        return sum;
    }
};