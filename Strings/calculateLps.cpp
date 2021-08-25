class Solution
{
    void calculateRes(string s, int length, vector<int> &lps)
    {
        int len = 0;
        lps[len] = 0;
        int i = 1;
        while (i < length)
        {
            if (s[i] == s[len])
            {
                len++;
                lps[i] = len;
                i++;
            }
            else //if s[i] != s[len]
            {
                if (len != 0) //if len != 0 Consider case AAACAAAA
                    len = lps[len - 1];
                else
                {
                    res[i] = 0;
                    i++;
                }
            }
        }
    }

public:
    int lps(string s)
    {
        int n = s.size();
        vector<int> res(n);
        calculateRes(s, n, res);
        return *max_element(res.begin(), res.end());
    }
};