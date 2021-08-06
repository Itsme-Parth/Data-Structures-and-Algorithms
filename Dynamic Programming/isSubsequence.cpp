/* Given two strings s and t, return true if s is a subsequence of t, or false otherwise. */
//O(n + m) approach using two pointer
class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int ptr1 = 0, ptr2 = 0;
        while (ptr1 < s.length() && ptr2 < t.length())
        {
            if (s[ptr1] == t[ptr2])
            {
                ptr1++, ptr2++;
            }
            else
                ptr2++;
        }
        if (ptr1 == s.length())
            return true;
        else
            return false;
    }
};
