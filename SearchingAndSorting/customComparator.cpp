#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if(a.second != b.second)
        return a.second < b.second;
    return a.first < b.first;
}
//keep in mind, jis order mai chahiye vahi return karo!!
int main()
{
    int n;
    cin>>n;
    vector<pair<int, int>> vect(n);
    for(int i = 0; i < n; i++)
    {
        cin>>vect[i].first>>vect[i].second;
    }
    sort(vect.begin(), vect.end(), cmp);
    for(int i = 0; i < n; i++)
    {
        cout<<vect[i].first<<" "<<vect[i].second<<endl;
    }
    return 0;
}