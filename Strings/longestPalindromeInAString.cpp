#include<bits/stdc++.h>
using namespace std;

string longestPalin (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestPalin (S) << endl;
    }
}
bool isPalin(string str)
{
    int ptr1 = 0, ptr2 = str.length() - 1;
    while(ptr1 <= ptr2)
    {
        if(str[ptr1++] != str[ptr2--])
            return false;
    }
    return true;
}
string longestPalin (string S)
{
    int n = S.length();
    string temp, res = "";
    for(int i = 0; i < n; i++)
    {
        temp = "";
        char val = S[i];
        temp += val;
        for(int j = i + 1; j < n; j++)
        {
            temp += S[j];
            if(isPalin(temp))
            {
                if(res.length() < temp.length())
                    res = temp;
            }
        }
    }
    if(res == "")
    {
        char val = S[0];
        res += val;
    }
    return res;
}