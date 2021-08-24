class Solution
{

public:
    int minCoins(int coins[], int M, int V)
    {
        // Your code goes here
        int dp[M + 1][V + 1];
        for (int i = 1; i < M + 1; i++)
        {
            dp[i][0] = 0;
        }
        for (int j = 0; j < V + 1; j++)
        {
            dp[0][j] = INT_MAX - 1;
        }
        for (int i = 1; i < M + 1; i++)
        {
            for (int j = 1; j < V + 1; j++)
            {
                if (coins[i - 1] <= j)
                    dp[i][j] = min(dp[i][j - coins[i - 1]] + 1, dp[i - 1][j]); //+1 is added to min number of coins
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[M][V] == INT_MAX - 1 ? -1 : dp[M][V];
    }
};