#include <bits/stdc++.h>
using namespace std;
int binSearch(int arr[], int n, int num)
{
    int start = 0, end = n - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == num)
            return arr[mid];
        else if (arr[mid] > num)
            end = mid - 1;
        else
            start = mid + 1;
    }
    if (abs(arr[end] - num) < abs(arr[start] - num))
        return arr[end];
    else
        return arr[start];
}
int main()
{
    int arr[] = {1, 2, 3, 8, 9, 10};
    int n = sizeof(arr) / sizeof(int);
    int num;
    cin >> num;
    cout << binSearch(arr, n, num);
    return 0;
}