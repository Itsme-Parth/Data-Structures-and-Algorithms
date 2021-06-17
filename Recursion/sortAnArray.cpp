#include <bits/stdc++.h>
using namespace std;
void insert(vector<int> &vect, int temp)
{
    if (vect.size() == 0 || vect[vect.size() - 1] <= temp) //Base case
    {
        vect.push_back(temp);
        return;
    }
    int val = vect[vect.size() - 1];
    vect.pop_back();     //removing the last element one at a time
    insert(vect, temp);  //Hypothesis
    vect.push_back(val); //Induction
}
void sortArray(vector<int> &vect)
{
    if (vect.size() == 1) //Base case
    {                     //If you have one element it is already sorted
        return;
    }
    int temp = vect[vect.size() - 1]; //removing the last element
    vect.pop_back();
    sortArray(vect);    //This is the hypothesis which returns me the sorted vector of size (n - 1)
    insert(vect, temp); //This is the induction step for sortArray function which call another recursive function insert
} //Adds the element which we removed in the hypothesis step
int main()
{
    int n;
    cin >> n;
    vector<int> vect;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        vect.push_back(x);
    }
    int size = n;
    sortArray(vect);
    for (auto itr : vect)
        cout << itr << " ";
    return 0;
}