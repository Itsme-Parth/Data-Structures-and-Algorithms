#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str = "mynameisparthchadha";
    map<char, int> freq;
    for(int i = 0; i < str.length(); i++)
    {
        freq[str[i]]++;
    }
    map<char, int>::iterator itr; 
	 for(itr = freq.begin() ; itr != freq.end() ; itr++)
	 {
	     if(itr->second > 1)
            cout<<itr->first<<" -> "<<itr->second<<"\n";
	 }
    return 0;
}