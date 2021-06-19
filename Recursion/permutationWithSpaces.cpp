class Solution
{
public:
    void addSpaces(string input, string output, vector<string> &res)
    {
        if (input.size() == 0)
        {
            res.push_back(output);
            return;
        }
        /* giving values to outputs to previous output */
        string output1 = output;
        string output2 = output;
        output1.push_back(' '); //adding output1 with space & 1st element
        output1.push_back(input[0]);
        output2.push_back(input[0]);    ///Adding output2 with just 1st element
        input.erase(input.begin() + 0); //removing the first element
        addSpaces(input, output1, res);
        addSpaces(input, output2, res);
    }
    vector<string> permutation(string S)
    {
        vector<string> res;
        if (S.length() == 0)
            return res;
        string output = "";
        output += S[0];
        S.erase(S.begin() + 0);
        addSpaces(S, output, res);
        return res;
    }
};