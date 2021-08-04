class Solution
{
public:
    int cutRod(int price[], int n)
    {
        int len = n; //len represents the numbers of cut options available in this question len = n
        int lengthy[len];
        for (int i = 0; i < len; i++) //creating a lengthy array which holds the size of every cut possible i.e 1 - n
        {
            lengthy[i] = i + 1;
        }
        int dp[len + 1][n + 1]; //creating dp array
        for (int i = 0; i < len + 1; i++)
        {
            dp[i][0] = 0;
        }
        for (int j = 0; j < n + 1; j++)
        {
            dp[0][j] = 0;
        }
        for (int i = 1; i < len + 1; i++) //traverse in rows/i represents the size of the cut
        {
            for (int j = 1; j < n + 1; j++) //traverse in cols/j represents the length of the rod
            {
                if (lengthy[i - 1] <= j)
                {
                    int price1 = price[i - 1] + dp[i][j - lengthy[i - 1]]; //dp[i] and not [i-1] as we can process again and again
                    int price2 = dp[i - 1][j];
                    dp[i][j] = max(price1, price2);
                }
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[len][n];
    }