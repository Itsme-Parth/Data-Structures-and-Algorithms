#include <bits/stdc++.h>
using namespace std;
struct myStruc
{
    int min;
    int max;
};
struct myStruc func(int arr[], int low, int high)
{
    struct myStruc minMax, a1, a2;
    if (low == high)
    {
        minMax.min = arr[low];
        minMax.max = arr[high];
        return minMax;
    }
    if (low == high + 1)
    {
        if (arr[low] < arr[high])
        {
            minMax.min = arr[low];
            minMax.max = arr[high];
        }
        else
            minMax.min = arr[high];
            minMax.max = arr[low];
        return minMax;
    }
    int mid = (low + high) / 2;
    a1 = func(arr, 0, mid);
    a2 = func(arr, mid + 1, high);
    if (a1.min < a2.min)
    {
        minMax.min = a1.min;
    }
    else
        minMax.min = a2.min;
    if (a1.max < a2.max)
    {
        minMax.max = a2.max;
    }
    else
        minMax.max = a1.max;
    return minMax;
}
int main()
{
    int arr[] = {1000, 11, 445, 1, 330, 3000};
    int arr_size = 6;
    struct myStruc minmax = func(arr, 0, arr_size - 1);
    cout << "Minimum element is "
         << minmax.min << endl;
    cout << "Maximum element is "
         << minmax.max;
    return 0;
}