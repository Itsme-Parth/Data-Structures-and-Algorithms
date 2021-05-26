/*Construct Binary Search Tree from Preorder Traversal*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int index = 0;
    TreeNode *BSTUtil(vector<int> &preorder, int minVal, int maxVal)
    {
        if (index >= preorder.size() || preorder[index] > maxVal || preorder[index] < minVal)
            return NULL;
        TreeNode *root = new TreeNode(preorder[index++]); //move the index as soon as we create a new node
        root->left = BSTUtil(preorder, minVal, root->val);
        root->right = BSTUtil(preorder, root->val, maxVal);
        return root;
    }
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        return BSTUtil(preorder, INT_MIN, INT_MAX);
    }
};