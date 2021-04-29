#include <bits/stdc++.h>
using namespace std;
int binSearch(int arr[], int n, int num)
{
    int start = 0, end = n - 1;
    while(start <= end)
    {
        int mid = start + (end - start)/2;
        if(arr[mid] == num)
            return mid;
        else if(arr[mid] > num)
            end = mid - 1;
        else 
            start = mid + 1;
    }
    return -1;
}
int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(arr)/sizeof(int);
    cout<<binSearch(arr, n, 11);
    return 0;
}