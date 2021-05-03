#include <bits/stdc++.h>
using namespace std;
int binSearch(int arr[], int n, int low, int high, int num)
{
    int start = low, end = high;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == num)
            return mid;
        else if (num < arr[mid])
            end = mid - 1;
        else if (num > arr[mid])
            start = mid + 1;
    }
    return -1;
}
int midIndex(int arr[], int n)
{
    int start = 0, end = n - 1;
    if (arr[start] <= arr[end])
        return start;
    while (start <= end)
    {
        if (arr[start] <= arr[end])
            return start;
        int mid = start + (end - start) / 2;
        int next = (mid + n) % n;
        int prev = (mid + n - 1) % n;
        if (arr[mid] <= arr[prev] && arr[mid] <= arr[next])
            return mid;
        else if (arr[start] <= arr[mid])
            start = mid + 1;
        else if (arr[mid] <= arr[start])
            end = mid - 1;
    }
}
int main()
{
    int num = 5;
    int arr[] = {6, 7, 7, 8, 11, 2, 5};
    int n = sizeof(arr) / sizeof(int);
    int mid = midIndex(arr, n);
    int one = binSearch(arr, n, 0, mid - 1, num);
    int two = binSearch(arr, n, mid, n - 1, num);
    if(one == -1)
        cout<<two;
    else if(two == -1)
        cout<<one;
    else if(one == -1 && two == -1)
        cout<<-1; 
    return 0;
}