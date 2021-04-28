#include <bits/stdc++.h>
using namespace std;
int romanToDecimal(string &);
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << romanToDecimal(s) << endl;
    }
}
int val(char a)
{
    if(a == 'I')
        return 1;
    if(a == 'V')
        return 5;
    if(a == 'X')
        return 10;
    if(a == 'L')
        return 50;
    if(a == 'C')
        return 100;
    if(a == 'D')
        return 500;
    if(a == 'M')
        return 1000;
}
int romanToDecimal(string &str) {
    int sum = 0;
    for(int i = 0; i < str.length(); i++)
    {
        if(i + 1 < str.length())
        {
            if(val(str[i]) < val(str[i + 1]))
            {
                sum += val(str[i + 1]) - val(str[i]);
                i++;
            }
            else 
                sum += val(str[i]);
        }
        else 
            sum += val(str[i]);
    }
    return sum;
}