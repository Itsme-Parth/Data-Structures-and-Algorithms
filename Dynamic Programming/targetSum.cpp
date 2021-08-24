class Solution
{
    int subsetCount(vector<int> &nums, int n, int sum)
    {
        int dp[n + 1][sum + 1];
        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < sum + 1; j++)
            {
                if (i == 0)
                    dp[i][j] = 0;
                if (j == 0)
                    dp[i][j] = 1;
            }
        }
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < sum + 1; j++)
            {
                if (nums[i - 1] <= j)
                {
                    dp[i][j] = dp[i - 1][j - nums[i - 1]] + dp[i - 1][j];
                }
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n][sum];
    }

public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int sum = 0;
        for (auto itr : nums)
        {
            sum += itr;
        }
        if (((sum + target) & 1) == 1)
            return 0; //odd
        int subsetSum = (sum + target) / 2;
        int n = nums.size();
        return subsetCount(nums, n, subsetSum);
    }
};