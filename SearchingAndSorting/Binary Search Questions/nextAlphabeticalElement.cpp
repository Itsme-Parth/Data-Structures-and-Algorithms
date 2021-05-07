//Next alphabetical element in the array
#include <bits/stdc++.h>
using namespace std;
char binSearch(char arr[], int n, char ch)
{
    int start = 0, end = n - 1;
    char res = '#';
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (ch == arr[mid])
        {
            start = mid + 1;
            if(mid + 1 > n - 1)
                return res;
        }
        else if (int(arr[mid]) < int(ch))
        {
            start = mid + 1;
        }
        else if (int(arr[mid]) > int(ch))
        {
            res = arr[mid];
            end = mid - 1;
        }
    }
    return res;
}
int main()
{
    char alphabets[] = {'a', 'c', 'f', 'h'};
    int size = sizeof(alphabets)/sizeof(char);
    char ch;
    cin>>ch;
    char nextElement = binSearch(alphabets, size, ch);
    cout<<nextElement;
    return 0;
}