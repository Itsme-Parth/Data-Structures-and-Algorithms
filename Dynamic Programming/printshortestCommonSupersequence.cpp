class Solution
{
public:
    string shortestCommonSupersequence(string str1, string str2)
    {
        int n = str1.length(), m = str2.length();
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
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        int i = n, j = m;
        string res = "";
        while (i > 0 && j > 0)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                res.push_back(str1[i - 1]);
                i--, j--;
            }
            else
            {
                if (dp[i][j - 1] > dp[i - 1][j])
                {
                    res.push_back(str2[j - 1]);
                    j--;
                }
                else if (dp[i - 1][j] > dp[i][j - 1])
                {
                    res.push_back(str1[i - 1]);
                    i--;
                }
            }
        }
        while (i > 0)
        {
            res.push_back(str1[i - 1]);
            i--;
        }
        while (j > 0)
        {
            res.push_back(str2[j - 1]);
            j--;
        }
        // reverse(res.begin(), res.end());
        return res;
    }
};

/* Optimized algorithm to calculate the dp instead of using the LCS approach

Let X[0..m-1] and Y[0..n-1] be two strings and m and be respective 
lengths.

if (m == 0) return n;
if (n == 0) return m;

// If last characters are same, then add 1 to result and
// recur for X[]
if (X[m-1] == Y[n-1]) 
    return 1 + SCS(X, Y, m-1, n-1);

// Else find shortest of following two
//  a) Remove last character from X and recur
//  b) Remove last character from Y and recur
else return 1 + min( SCS(X, Y, m-1, n), SCS(X, Y, m, n-1) );

*/