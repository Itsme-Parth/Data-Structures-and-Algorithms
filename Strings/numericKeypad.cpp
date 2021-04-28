#include <bits/stdc++.h>
using namespace std;
string solve(string str[], string input)
{
    string res;
    int n = input.length();
    for (int i = 0; i < n; i++)
    {
        if (input[i] == ' ')
            res += "0";
        else
        {
            res += str[input[i] - 'a'];
        }
    }
    return res;
}
int main()
{
    string str[] = {"2", "22", "222",
                    "3", "33", "333",
                    "4", "44", "444",
                    "5", "55", "555",
                    "6", "66", "666",
                    "7", "77", "777", "7777",
                    "8", "88", "888",
                    "9", "99", "999", "9999"};
    string input;
    cin >> input;
    cout << solve(str, input);
    return 0;
}