class Solution
{
public:
    int dp[101][101]; //kkey trick for memoisation is to add dp as global variable
    int solve(int arr[], int i, int j)
    {
        if (i >= j)
        {
            return 0;
        }
        if (dp[i][j] != -1)
            return dp[i][j];

        int res = INT_MAX;

        for (int k = i; k < j; k++)
        {
            int tempRes = solve(arr, i, k) + solve(arr, k + 1, j) + arr[i - 1] * arr[j] * arr[k];
            res = min(tempRes, res);
        }

        dp[i][j] = res;

        return res;
    }
    int matrixMultiplication(int N, int arr[])
    {
        //int dp[N][N];
        memset(dp, -1, sizeof(dp)); //setting in the value to -1
        int i = 1, j = N - 1;
        return solve(arr, i, j);
    }
};