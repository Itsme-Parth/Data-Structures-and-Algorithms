class Solution
{

public:
    int minOperations(string str1, string str2)
    {
        int n = str1.length();
        int m = str2.length();
        int dp[n + 1][m + 1];
        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < m + 1; j++)
            {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
            }
        }
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < m + 1; j++)
            {
                if (str1[i - 1] == str2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        /* We have to convert X--->Y
        also since we have to convert completely then order matters.
        So, delete from X which Y doesn't have
        and insert into X from Y which X doesn't have
        */
        int deletions = n * length of str1 * / -dp[n][m];
        int insertions = m /*length of str2*/ - dp[n][m];
        return insertions + deletions;
    }
};