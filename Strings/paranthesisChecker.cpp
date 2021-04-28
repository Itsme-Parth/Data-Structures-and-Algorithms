#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    bool check(char x, char y)
    {
        if(x == '[' && y == ']') return true;
        if(x == '{' && y == '}') return true;
        if(x == '(' && y == ')') return true;
        return false;
    }
    bool ispar(string x)
    {
        if(x.length() <= 1)
            return false;
        stack<char> st;
        for(int i = 0; i < x.length(); i++)
        {
            if(x[i] == '(' || x[i] == '[' || x[i] == '{')
                st.push(x[i]);
            if(st.empty())
            {
                if(x[i] == ')' || x[i] == ']' || x[i] == '}')
                    return false;
            }
            if(x[i] == ')' || x[i] == ']' || x[i] == '}')
            {
                if(check(st.top(),x[i]))
                    st.pop();
                else 
                    return false;
            }
        }
    }
};

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}