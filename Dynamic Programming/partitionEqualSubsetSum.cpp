class Solution{
public:
    int subsetSum(int n, int arr[], int targetSum)
    {
        int dp[n + 1][targetSum + 1];
        for(int i = 0; i < n + 1; i++)
        {
            dp[i][0] = 1;
        }
        for(int j = 1; j < targetSum + 1; j++)
        {
            dp[0][j] = 0;
        }
        for(int i = 1; i < n + 1; i++)
        {
            for(int j = 1; j < targetSum + 1; j++)
            {
                if(arr[i - 1] <= j)
                {
                    dp[i][j] = max(dp[i - 1][j - arr[i - 1]], dp[i - 1][j]);
                }
                else 
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][targetSum];
    }
    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        for(int i = 0; i < N; i++)
        {
            sum += arr[i];
        }
        if(sum % 2 != 0)//If the sum is odd return false
        {
            return 0;
        }
        else 
        {
            int res = subsetSum(N, arr, sum/2);
            return res;
        }
    }
};