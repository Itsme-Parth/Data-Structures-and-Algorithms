class Solution
{
public:
    int findMaximum(int arr[], int n)
    {
        if (n == 1)
            return arr[0];

        if (arr[0] > arr[1])
            return arr[0];
        if (arr[n - 1] > arr[n - 2])
            return arr[n - 1];

        int start = 1, end = n - 2;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1])
                return arr[mid];
            else if (arr[mid - 1] > arr[mid])
                end = mid - 1;
            else
                start = mid + 1;
        }
        return -1;
    }
};