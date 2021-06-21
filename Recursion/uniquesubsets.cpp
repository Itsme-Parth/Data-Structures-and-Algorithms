/* Add unique Subsets in a sorted order */
class Solution
{
public:
    void uniqueSubsets(vector<int> input, vector<int> output, vector<vector<int>> &res)
    {
        if (input.size() == 0)
        {
            res.push_back(output);
            return;
        }
        vector<int> output1 = output;
        vector<int> output2 = output;
        output2.push_back(input[input.size() - 1]);
        input.pop_back();
        uniqueSubsets(input, output1, res);
        uniqueSubsets(input, output2, res);
    }
    //Function to find all possible unique subsets.
    vector<vector<int>> AllSubsets(vector<int> arr, int n)
    {
        vector<vector<int>> res;
        vector<int> input(arr.begin(), arr.end());
        if (n == 0)
            return res;
        vector<int> output;
        uniqueSubsets(input, output, res);
        set<vector<int>> sortedRes;
        for (auto itr : res)
        {
            sortedRes.insert(itr);
        }
        for (auto itr : sortedRes)
        {
            for (auto itr1 : itr)
            {
                cout << itr1;
            }
            cout << " ";
        }
        return res;
    }
};