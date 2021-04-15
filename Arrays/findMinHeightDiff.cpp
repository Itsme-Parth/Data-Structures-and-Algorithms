#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        sort(arr, arr + n);
        int res = arr[n-1] - arr[0];
        for(int i = 0; i < n - 1; i++)
        {
            int j = i + 1;
            int high = max((arr[n-1] - k), (arr[i] + k));
            int low = min((arr[0] + k), (arr[j] - k));
            res = min(res, high - low);
        }
        return res;
    }
};
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
} 