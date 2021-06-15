class Solution
{
public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n)
    {
        stack<long long> s;
        vector<long long> res;
        if (n == 0)
            return res;
        s.push(arr[0]); //pushing the first element in the stack
        for (long long i = 1; i < n; i++)
        {
            if (s.empty() == true)
            {
                s.push(arr[i]);
                continue;
            }
            while (arr[i] > s.top() && s.empty() == false)
            {
                res.push_back(arr[i]);
                s.pop();
            }
            s.push(arr[i]);
        }
        while (s.empty() == false)
        {
            res.push_back(-1);
            s.pop();
        }
        return res;
    }
};