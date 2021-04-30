#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        int *ans = new int[2];
        vector<bool> temp(n + 1, false);
        for(int i = 0; i < n; i++)
        {
            if(temp[arr[i]] == false)
                temp[arr[i]] = true;
            else if(temp[arr[i]] == true)
            {
                ans[0] = arr[i];
            }
        }
        for(int i = 1; i <= n; i++)
        {
            if(temp[i] == false)
                ans[1] = i;
        }
        return ans;
    }
};
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}