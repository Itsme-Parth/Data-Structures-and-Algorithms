 #include <bits/stdc++.h>
using namespace std;

class Solution{
public:	
	
	
	int isPlaindrome(string S)
	{
	    int ptr1 = 0, ptr2 = S.length() - 1, flag = 0;
	    while(ptr1 <= ptr2)
	    {
	        if(S[ptr1++] == S[ptr2--])
	            flag = 1;
	        else 
	       {
	           flag = 0;
	           break;
	       }
	    }
	    return flag;
	}

};

int main() 
{
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.isPlaindrome(s) << "\n";
   	}

    return 0;
}  