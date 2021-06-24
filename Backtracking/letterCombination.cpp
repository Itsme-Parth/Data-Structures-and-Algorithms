class Solution
{
public:
    void letterCombinationsUtil(string digits, vector<string> &res, string &currStr, int index, vector<string> digitMap)
    {
        if (index == digits.length()) //Base case
        {
            res.push_back(currStr);
            return;
        }
        for (auto itr : digitMap[digits[index] - '0'])
        {
            currStr.push_back(itr);
            letterCombinationsUtil(digits, res, currStr, index + 1, digitMap);
            currStr.pop_back(); //Backtracking step as we are passing the currStr by reference
        }
    }
    vector<string> letterCombinations(string digits)
    {
        vector<string> res;
        if (digits == "")
            return res;
        int index = 0;
        string currStr = "";
        vector<string> digitMap = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        letterCombinationsUtil(digits, res, currStr, index, digitMap);
        return res;
    }
};