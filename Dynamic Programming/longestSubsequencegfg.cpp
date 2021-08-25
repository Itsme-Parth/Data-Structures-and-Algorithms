class Solution
{
public:
    int longestSubsequence(int n, int arr[])
    {
        vector<int> dp(n, 1);
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (abs(arr[i] - arr[j]) == 1) //as value matter nahi karti unka diff bus 1 hona chahiye
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};