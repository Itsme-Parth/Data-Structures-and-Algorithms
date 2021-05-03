/* 
This implementation is for right side rotated array where we return mid 
whereas in left side rotated array we return (n - mid)%n 
Also this solution does not consider repetitions
*/
#include <bits/stdc++.h>
using namespace std;
int countRotations(int arr[], int n)
{
    int start = 0, end = n - 1;
    if (arr[start] <= arr[end])
        return 0;
    while (start <= end)
    {
        if (arr[start] <= arr[end])
        {
            return start;
        }
        int mid = start + (end - start) / 2;
        //writing circular array type implementation
        int next = (mid + n) % n;     //for the last index
        int prev = (mid + n - 1) % n; //for the first index
        if (arr[mid] <= arr[prev] && arr[mid] <= arr[next])
            return mid;
        else if (arr[start] <= arr[mid])//here it means that this part is sorted check for the other one
            start = mid + 1;
        else if (arr[mid] <= arr[end])//similarly here as well
            end = mid - 1;
    }
}
int main()
{
    int arr[] = {6, 8, 11, 2, 5};
    int n = sizeof(arr) / sizeof(int);
    int count = countRotations(arr, n);
    cout << count;
    return 0;
}