//Search in a nearly sorted array
#include <bits/stdc++.h>
using namespace std;
int binSearch(int arr[], int n, int num)
{
    int start = 0, end = n - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (num == arr[mid])
        {
            return mid;
        }
        else if (num == arr[mid - 1] && mid - 1 >= start)//checking the out of bound conditions as well
            return mid - 1;
        else if (num == arr[mid + 1] && mid + 1 <= end)
            return mid + 1;
        else if (num > arr[mid])
            start = mid + 2;
        else if (num < arr[mid])
            end = mid - 2;
    }
    return -1;
}
int main()
{
    int arr[] = {5, 10, 30, 20, 40};
    int size = sizeof(arr) / sizeof(int);
    int num;
    cin >> num;
    int index = binSearch(arr, size, num);
    cout << index;
    return 0;
}