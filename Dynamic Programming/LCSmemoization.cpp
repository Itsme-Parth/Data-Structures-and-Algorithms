class Solution
{
public:
    //Function to find the length of longest common subsequence in two strings.
    int lcsUtil(int x, int y, string s1, string s2, int *dp[][])
    {
        if (dp[x][y] != -1)
            return dp[x][y];
        if (s1[x - 1] == s2[y - 1])
        {
            return dp[x][y] = 1 + lcsUtil(x - 1, y - 1, s1, s2, dp);
        }
        else
            return dp[x][y] = max(lcsUtil(x - 1, y, s1, s2, dp), lcsUtil(x, y - 1, s1, s2, dp));
    }
    int lcs(int x, int y, string s1, string s2)
    {
        int lcsLength = 0;
        if (x == 0 || y == 0)
            return lcsLength;
        int dp[x + 1][y + 1];
        memset(dp, -1, sizeof(dp));
        return lcsUtil(x, y, s1, s2, dp);
    }
};