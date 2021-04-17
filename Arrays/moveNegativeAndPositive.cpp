#include <bits/stdc++.h>
using namespace std;
void shiftall(int arr[], int low, int n)
{
    int right = n, i = low;
    while (i <= right)
    {
        if (arr[i] > 0)
        {
            swap(arr[i], arr[right]);
            right--;
        }
        else
            i++;
    }
}
void display(int arr[], int right)
{
    for (int i = 0; i <= right; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int arr[] = {-12, 11, -13, -5, 6, -7, 5, -3, 11};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    shiftall(arr, 0, arr_size - 1);
    display(arr, arr_size - 1);
    return 0;
}