/*Convert Sorted Array to Binary Search Tree
   https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/ */
class Solution
{
public:
    TreeNode *sortedArrayToBSTUtil(vector<int> &nums, int minVal, int maxVal)
    {
        //for leaf node
        if (minVal > maxVal)
            return NULL;
        int mid = minVal + (maxVal - minVal) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBSTUtil(nums, minVal, mid - 1);
        root->right = sortedArrayToBSTUtil(nums, mid + 1, maxVal);
        return root;
    }
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        if (nums.empty())
            return NULL;
        return sortedArrayToBSTUtil(nums, 0, nums.size());
    }
};