#include <bits/stdc++.h>
using namespace std;
bool isRotation(string str1, string str2)
{
    if(str1.length() != str2.length())
        return false;
    string temp = str1 + str1;
    return(temp.find(str2) != string::npos);
}
int main()
{
    string str1 = "ABACD";
    string str2;
    cin>>str2;
    if(isRotation(str1, str2))
        cout<<"YES";
    else 
        cout<<"NO";
    return 0;
}