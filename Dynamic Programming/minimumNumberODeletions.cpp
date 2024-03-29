class Solution
{
public:
    int countMin(string str)
    {
        //complete the function here
        string strRev = string(str.rbegin(), str.rend());
        int n = str.length();
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
                if (str[i - 1] == strRev[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        /*now remove the characters that do not contribute to the string for becoming a palindrome*/
        return n - dp[n][n];
    }
};