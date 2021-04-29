/*implemented with binary search */
#include <bits/stdc++.h>
using namespace std;
int firstBinSearch(int arr[], int n, int num)
{
    int start = 0, end = n - 1, res = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == num)
        {
            res = mid;
            end = mid - 1;
        }
        else if (arr[mid] < num)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return res;
}
int lastBinSearch(int arr[], int n, int num)
{
    int start = 0, end = n - 1, res = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == num)
        {
            res = mid;
            start = mid + 1;
        }
        else if (arr[mid] < num)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return res;
}
int main()
{
    int arr[] = {1, 2, 5, 10, 10, 10, 10, 10, 11, 12};
    int n = sizeof(arr) / sizeof(int);
    int firstOccurrence = firstBinSearch(arr, n, 11);
    int lastOccurrence = lastBinSearch(arr, n, 11);
    if (firstOccurrence == -1 && lastOccurrence == -1)
        cout << 0;
    else
        cout << lastOccurrence - firstOccurrence + 1;
    return 0;
}