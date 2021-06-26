/* Using Dynamic Programming */
bool isSubsetSum(int arr[], int n, int sum)
{
    bool dp[n + 1][sum + 1];
    for (int i = 0; i < n + 1; i++) //here i represents the size of the array
    {
        for (int j = 0; j < sum + 1; j++) // here j represents the targetted sum
        {
            if (j == 0)
            {
                dp[i][j] = false;
            }
            if (i == 0)
            {
                dp[i][j] = true;
            }
        }
    }
    for (int i = 1; i < n + 1; i++) //why not starting i with 0?
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (arr[i - 1] <= j) //The element is smaller than the targetted sum hence we have an option to include it or not
            {
                dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
            }
            else //The element is greater than the targetted sum hence we won't include it in our subset
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][sum];
}