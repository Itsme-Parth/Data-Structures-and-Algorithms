#include <bits/stdc++.h>
using namespace std;
int factorial(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    return n * factorial(n - 1); //if n = 7 here factorial(n - 1) is the hypothesis and returns 6!
}
int main()
{
    int n;
    cin >> n;
    int k = factorial(n);
    cout << k;
    return 0;
}