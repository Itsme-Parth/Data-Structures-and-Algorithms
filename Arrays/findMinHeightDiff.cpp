// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        vector<int> vect;
        for(int i = 0; i < n; i++)
        {
            int max = arr[i] + k;
            int min = arr[i] - k;
            if(min >= 0)
                vect.push_back(min);
            vect.push_back(max);
        }
        sort(vect.begin(), vect.end());
        int ans = INT_MAX;
        cout<<endl;
        for(int i = 0; i < vect.size() - n; i++)
        {
            int diff = vect[i + n] - vect[i];
            cout<<diff<<" ";
            if(diff < ans)
                ans = diff;
        }
        return ans;
    }
};

// { Driver Code Starts.
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
}  // } Driver Code Ends