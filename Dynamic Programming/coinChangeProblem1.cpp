class Solution
{
public:
    long long int count(int coin[], int n, int sum)
    {
        long long int dp[n + 1][sum + 1];
        for (int i = 0; i < n + 1; i++)
        {
            dp[i][0] = 1;
        }
        for (int j = 0; j < sum + 1; j++)
        {
            dp[0][j] = 0;
        }
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < sum + 1; j++)
            {
                if (coin[i - 1] <= j)
                {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - coin[i - 1]];
                }
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n][sum];
    }
};

// Solution According to Gfg variables:
class Solution
{
public:
    long long int count(int S[], int m, int n)
    {

        //code here.
        long long int dp[m + 1][n + 1];
        for (int i = 0; i < m + 1; i++)
        {
            dp[i][0] = 1;
        }
        for (int j = 1; j < n + 1; j++)
        {
            dp[0][j] = 0;
        }
        for (int i = 1; i < m + 1; i++)
        {
            for (int j = 1; j < n + 1; j++)
            {
                if (S[i - 1] <= j)
                    dp[i][j] = dp[i - 1][j] + dp[i][j - S[i - 1]];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[m][n];
    }
};