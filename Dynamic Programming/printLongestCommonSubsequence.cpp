class Solution
{
public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        int dp[x + 1][y + 1];
        for (int i = 0; i < x + 1; i++)
        {
            for (int j = 0; j < y + 1; j++)
            {
                if (i == 0 || j == 0)
                {
                    dp[i][j] = 0;
                }
            }
        }
        for (int i = 1; i < x + 1; i++)
        {
            for (int j = 1; j < y + 1; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        //Main solution ahead
        int i = x, int y = j, string str = "";
        while (i > 0 && j > 0)
        {
            if (s1[i - 1] == s2 = [j - 1]) //if the characters are equal push the char in the string
            {
                str.push_back(s2[i - 1]);
                i--, j--;
            }
            else
            {
                if (dp[i - 1][j] > dp[i][j - 1]) //we move towards the max value in the dp array
                {
                    i--;
                }
                else
                    j--;
            }
            return reverse(str.begin(), str.end());
        }
    }
};