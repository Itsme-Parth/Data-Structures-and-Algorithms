class Solution
{
public:
    int solve(int arr[], int i, int j)
    {
        if (i >= j)
        {
            return 0;
        }
        int ans = INT_MAX;
        for (int k = i; k < j; k++)
        {
            int tempRes = solve(arr, i, k) + solve(arr, k + 1, j) + arr[i - 1] * arr[j] * arr[k];
            ans = min(tempRes, ans);
        }
        return ans;
    }
    int matrixMultiplication(int N, int arr[])
    {
        int i = 1, j = N - 1;
        return solve(arr, i, j);
    }
};