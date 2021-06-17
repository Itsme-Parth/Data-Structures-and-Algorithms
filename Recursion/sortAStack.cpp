#include <bits/stdc++.h>
using namespace std;
void insert(stack<int> &st, int temp)
{
    if (st.empty() || st.top() <= temp)
    {
        st.push(temp);
        return;
    }
    int val = st.top();
    st.pop();
    insert(st, temp);
    st.push(val);
}
void sortStack(stack<int> &st)
{
    if (st.size() == 1)
    {
        return;
    }
    int temp = st.top();
    st.pop();
    sortStack(st);
    insert(st, temp);
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
    sortStack(st);
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}