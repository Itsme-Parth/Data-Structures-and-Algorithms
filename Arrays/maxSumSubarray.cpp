#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int maxSubarraySum(int arr[], int n){
        int meh = 0, msf = INT_MIN;
        for(int i = 0; i < n; i++)
        {
            meh += arr[i];
            if(meh < arr[i])
                meh = arr[i];
            if(msf < meh)
                msf = meh;
        }
        return msf;
    }
};
int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}