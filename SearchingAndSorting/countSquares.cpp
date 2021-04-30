#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int countSquares(int N) {
       return sqrt(N-1);
    }
};
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.countSquares(N) << endl;
    }
    return 0;
}  