#include <bits/stdc++.h>
using namespace std;
int consecutiveNumbersSum(int N)
{
    int count = 0;
    for (int k = 2; k < sqrt(2 * N); k++)
    {
        if ((N - (k * (k - 1) / 2)) % k == 0)
            count++;
    }
    return count;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int count = consecutiveNumbersSum(n);
        cout << count << "\n";
    }
}
