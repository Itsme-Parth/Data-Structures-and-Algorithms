/* Balance a Binary Search Tree
https://leetcode.com/problems/balance-a-binary-search-tree/ */
class Solution
{
public:
    //function to get inorder traversal
    void inorder(TreeNode *root, vector<int> &nums)
    {
        if (root == NULL)
            return;
        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }
    TreeNode *inorderToBST(vector<int> nums, int minVal, int maxVal)
    {
        //for leaf node
        if (minVal > maxVal)
            return NULL;
        int mid = minVal + (maxVal - minVal) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = inorderToBST(nums, minVal, mid - 1);
        root->right = inorderToBST(nums, mid + 1, maxVal);
        return root;
    }
    TreeNode *balanceBST(TreeNode *root)
    {
        vector<int> nums;
        inorder(root, nums);
        return inorderToBST(nums, 0, nums.size());
    }
};