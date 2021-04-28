#include <bits/stdc++.h>
using namespace std;
int solve(string str)
{
    int cnt0 = 0, cnt1 = 0, ans = -1;
    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == '0')
            cnt0++;
        if(str[i] == '1')
            cnt1++;
        if(cnt0 == cnt1)
        {
            ans++;
            cnt0 = 0, cnt1 = 0;
        }
    }
    return ans;
}
int main()
{
    string str;
    cin>>str;
    cout<<solve(str);
    return 0;
}