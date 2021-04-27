#include <bits/stdc++.h>
using namespace std;
void permute(string str, int l, int r)
{
    if (l == r)
        cout << str << " ";
    else
    {
        for (int i = l; i < r; i++)
        {
            swap(str[l], str[i]);
            permute(str, i, r);
            swap(str[l], str[i]);
        }
    }
}
int main()
{
    string str;
    cin >> str;
    permute(str, 0, str.size());
    return 0;
}