#include <bits/stdc++.h>
using namespace std;

int cmp(pair<int,  int> a, pair<int, int> b)
{
    if(a.first != b.first)
        return a.first > b.first;//decreasing order
    return a.second < b.second;//increasing order
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