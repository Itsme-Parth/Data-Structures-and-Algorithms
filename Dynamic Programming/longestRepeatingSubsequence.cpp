class Solution
{
public:
    int LongestRepeatingSubsequence(string str)
    {
        int n = str.length();
        string strCopy = str; //our second string is the same string
        int dp[n + 1][n + 1];
        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < n + 1; j++)
            {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
            }
        }
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < n + 1; j++)
            {
                if (str[i - 1] == strCopy[j - 1] && i != j) /*if the character is occurring at the same place in the second string, means it's not reapeating*/
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n][n];
    }
};