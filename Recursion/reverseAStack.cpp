#include <bits/stdc++.h>
using namespace std;
void insert(stack<int> &st, int temp)
{
    if (st.empty())
    {
        st.push(temp);
        return;
    }
    int top = st.top();
    st.pop();
    insert(st, temp); //Hypothesis step to insert the element at the bottom
    st.push(top);     //Induction step; pushing the removed element
}
void reverse(stack<int> &st)
{
    if (st.size() == 1)
        return;
    int temp = st.top();
    st.pop();
    reverse(st);      //Hypothesis step to reverse the stack
    insert(st, temp); //Induction step; pushing the removed element
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
    reverse(st);
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}