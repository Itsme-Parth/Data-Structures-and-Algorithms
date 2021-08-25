class Solution
{
public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int arr[])
    {
        vector<int> dp(n, 1); //ek kitna minimum bna skta
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (arr[j] < arr[i]) //if j element smaller than current i element
                {
                    dp[i] = max(dp[i], dp[j] + 1); //curr ya jo chote element wala hai usme + 1
                }                                  //dp[j] ki updated value mai hi 1 add karenge
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};
