#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int middle(int A, int B, int C){
        if(A < B)
            return B < C ? B : max(A, C);//B if the condition is true else B is the highest hence for the middle 
                                        //element we find the max between the two left
        return A < C ? A : max(B, C);
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int A,B,C;
        cin>>A>>B>>C;
        Solution ob;
        cout<<ob.middle(A,B,C) <<"\n";
    }
    return 0;
} 