#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    void sort012(int arr[], int n)
    {
        int left = 0, right = n - 1, i = 0; 
        while(i <= right)
        {
            if(arr[i] == 0)
            {
                swap(arr[i], arr[left]);
                left++;
                i++;
            }
            else if(arr[i] == 2)
            {
                swap(arr[i], arr[right]);
                right--;
            }
            else 
                i++;
        }
    }
};
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}