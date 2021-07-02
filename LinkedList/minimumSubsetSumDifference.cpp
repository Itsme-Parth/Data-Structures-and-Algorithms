/* Minimum sum partition */
class Solution
{

public:
    int minDifference(int arr[], int n)
    {
        int range = 0;
        for (int i = 0; i < n; i++)
        {
            range += arr[i];
        }
        bool dp[n + 1][range + 1];
        for (int i = 0; i < n + 1; i++)
        {
            dp[i][0] = true;
        }
        for (int i = 1; i < range + 1; i++)
        {
            dp[0][i] = false;
        }
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < range + 1; j++)
            {
                if (arr[i - 1] <= j)
                {
                    dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
                }
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        vector<int> possibleSum;
        for (int j = 0; j <= ceil(range / 2); j++)
        {
            if (dp[n][j] == true)
                possibleSum.push_back(j);
        }
        int minDiff = INT_MAX;
        for (int i = 0; i < possibleSum.size(); i++)
        {
            minDiff = min(minDiff, range - 2 * possibleSum[i]);
        }
        return minDiff;
    }
};