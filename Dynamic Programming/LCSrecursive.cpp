class Solution
{
public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        if (x == 0 || y == 0) //base condition
        {
            return 0;
        }
        if (s1[x - 1] == s2[y - 1]) //if the last elements are equal
        {
            return 1 + lcs(x - 1, y - 1, s1, s2); //1 added to the count
        }
        else
            return max(lcs(x - 1, y, s1, s2), lcs(x, y - 1, s1, s2)); //removing one element from the strings alternatively
    }
};