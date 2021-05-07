//Find floor value of a number which isn't in the given array
#include <bits/stdc++.h>
using namespace std;
int binSearch(int arr[], int n, int num)
{
    int start = 0, end = n - 1, res = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (num == arr[mid])
        {
            res = arr[mid];
            return res;
        }
        else if (arr[mid] < num)
        {
            res = arr[mid];
            start = mid + 1;
        }
        else if (arr[mid] > num)
        {
            end = mid - 1;
        }
    }
    return res;
}
int main()
{
    int arr[] = {1, 2, 3, 5, 6, 9, 11};
    int size = sizeof(arr) / sizeof(int);
    int num;
    cin >> num;
    int floorVal = binSearch(arr, size, num);
    cout << floorVal;
    return 0;
}