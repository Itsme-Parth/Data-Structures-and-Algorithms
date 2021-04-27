#include <bits/stdc++.h>
using namespace std;
void func(string ip, int start, int end, string op = "")
{
    if (start == end)
        return;
    cout << op << " ";
    for (int i = start + 1; i < end; i++)
    {
        op += ip[i];
        func(ip, i, end, op);
        op = op.erase(op.size() - 1);
    }
}
int main()
{
    string ip;
    cin >> ip;
    func(ip, -1, ip.size());
    return 0;
}