#include <bits/stdc++.h>
using namespace std;
void removeMidElement(stack<int> &st, int mid)
{
    if (mid == 1)
    {
        st.pop();
        return;
    }
    int temp = st.top();
    st.pop();
    removeMidElement(st, mid--);
    st.push(temp);
}
int main()
{
    int n;
    cin >> n;
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        st.push(x);
    }
    int mid = (n / 2) + 1;
    removeMidElement(st, mid);
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}