class Solution
{
public:
    int cutRod(int price[], int n)
    {
        int lengthArr[n];
        for (int i = 0; i < n; i++)
            lengthArr[i] = i + 1; //making length array

        int l = lengthArr.size(); //to avoid confusion

        int dp[l + 1]; //dp

        //initialisation
        for (int i = 0; i < l + 1; i++)
            for (int j = 0; j < n; j++)
                if (lengthArr[j] <= i)
                    dp[i] = max(dp[i], price[j] + dp[i - lengthArr[j]]);

        return dp[l];
    }
};