#include <bits/stdc++.h>
using namespace std;
int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<int> LA, LB;
        int N = A.size();
        unordered_map<int, int> count;
        for (int i = 0; i < N * N; ++i)
            if (A[i / N][i % N] == 1)
                LA.push_back(i / N * 100 + i % N);
        for (int i = 0; i < N * N; ++i)
            if (B[i / N][i % N] == 1)
                LB.push_back(i / N * 100 + i % N);
        for (int i : LA) for (int j : LB) count[i - j]++;
        int res = 0;
        for (auto it : count) res = max(res, it.second);
        return res;
    }
int main()
{
    int n;
    cin>>n;
    vector<vector<int>> arr1( n , vector<int> (n, 0));
    for(int i = 0; i < n; i++)
    {
      for(int j = 0; j < n; j++)
      {
        cin>>arr1[i][j];
      }
    }
    vector<vector<int>> arr2( n , vector<int> (n, 0));
    for(int i = 0; i < n; i++)
    {
      for(int j = 0; j < n; j++)
      {
        cin>>arr2[i][j];
      }
    }
    int ans = largestOverlap(arr1, arr2);
    cout<<ans;
  return 0;
}