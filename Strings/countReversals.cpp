#include <bits/stdc++.h>
using namespace std;

int countRev(string s)
{
    if (s.length() <= 1)
        return -1;
    stack<char> st;
    int cnt = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '{')
            st.push(s[i]);
        if (st.empty() && s[i] == '}')
            cnt++;
        if (st.top() == '{' && s[i] == '}')
            st.pop();
        else if (st.top() == '}' && s[i] == '}')
            cnt++;
    }
    if (cnt == 0)
        return -1;
    return cnt;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << countRev(s) << '\n';
    }
}
