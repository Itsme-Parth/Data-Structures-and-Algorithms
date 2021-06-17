#include <bits/stdc++.h>
using namespace std;
void print(int n)
{
    if (n == 1)
    {
        cout << n << " ";
        return;
    }
    cout << n << " ";
    print(n - 1); //for example if n = 7 we expect this hypothesis to bring us 6 5 4 3 2 1
}
int main()
{
    int n;
    cin >> n;
    print(n);
    return 0;
}