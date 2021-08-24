class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int n = haystack.size();
        int k = needle.size();
        for (int i = 0; i <= n - k; i++)
        {
            int j = 0;
            for (; j < k; j++)
            {
                if (haystack[i + j] != needle[j])
                    break;
            }
            if (j == k)
                return i;
        }
        return -1;
    }
};