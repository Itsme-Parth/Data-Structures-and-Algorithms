/*
Print all permutations of a string keeping the sequence but changing cases.
Examples: 
 

Input : ab
Output : AB Ab ab aB

Input : ABC
Output : abc Abc aBc ABc abC AbC aBC ABC 
*/
#include <bits/stdc++.h>
using namespace std;
void caseChangeUtil(string input, string output, vector<string> &res)
{
    if (input.length() == 0)
    {
        res.push_back(output);
        return;
    }
    string output1 = output;
    string output2 = output;
    output1.push_back(input[0]); //choice 1: Adding the current small case to op1
    input[0] = input[0] - 32;
    output2.push_back(input[0]);    //Choice 2: Adding uppercase value to op2
    input.erase(input.begin() + 0); //removing the first element
    caseChangeUtil(input, output1, res);
    caseChangeUtil(input, output2, res);
}
vector<string> caseChange(string str)
{
    vector<string> res;
    if (str.length() == 0)
    {
        return res;
    }
    string output;
    caseChangeUtil(str, output, res);
    return res;
}
int main()
{
    string str;
    cin >> str;
    vector<string> result;
    result = caseChange(str);
    for (auto itr : result)
    {
        for (auto itr1 : itr)
        {
            cout << itr1;
        }
        cout << " ";
    }
    return 0;
}