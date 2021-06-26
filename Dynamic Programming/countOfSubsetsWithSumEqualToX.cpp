/* Using Dynamic Programming */
int CountOfSubsetsWithSumEqualToGivenSu(int arr[], int n, int sum)
{
    int dp[n + 1][sum + 1];
    for (int i = 0; i < n + 1; i++)
    {
        dp[i][0] = 1;
    }
    for (int j = 1; j < sum + 1; j++)
    {
        dp[0][j] = 0;
    }
    //now again if current element's value is less than the current sum
    //decide to include it or not
    //else don't include it
    for (int i = 1; i < n + 1; i++) //why not starting i with 0?
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (arr[i - 1] <= j) //The element is smaller than the targetted sum hence we have an option to include it or not
            {
                dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i - 1][j]; //Adding both cases
            }
            else //The element is greater than the targetted sum hence we won't include it in our subset
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][sum];
}