/* Power Set Using Recursion */
void printSubset(string input, string output, vector<string> &subset)
{
    if (input.length() == 0)
    {
        subset.push_back(output);
        return;
    }
    /* continuing with the previous output */
    string output1 = output;
    string output2 = output;
    output2.push_back(input[0]);    //Pushing the first character in output2 and not in 1
    input.erase(input.begin() + 0); //removing first element from input whose decision has been taken
    printSubset(input, output1, subset);
    printSubset(input, output2, subset);
}
//Function to return the lexicographically sorted power-set of the string.
vector<string> powerSet(string s)
{
    vector<string> subsets;
    if (s.length() == 0)
        return subsets;
    string input = s;
    string output = "";
    printSubset(input, output, subsets);
    return subsets;
}