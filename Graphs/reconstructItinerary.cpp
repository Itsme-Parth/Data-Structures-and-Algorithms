class Solution
{
public:
    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        //creating an adjacency list using map and multiset(as multiset orders in ascending order)
        unordered_map<string, multiset<string>> adj;
        vector<string> ans;
        int n = tickets.size();
        for (int i = 0; i < n; i++)
        {
            adj[tickets[i][0]].insert(tickets[i][1]); //creating the adjacency list of map
        }
        stack<string> st; //using the stack DS
        st.push("JFK");   //as every route needs to start from JFK
        while (!st.empty())
        {
            string src = st.top();
            if (adj[src].size() == 0) //if the source has no adjacent nodes we push it in the answer and pop it from stack
            {
                ans.push_back(src);
                st.pop();
            }
            else //if adjacent node exists
            {
                auto dst = adj[src].begin(); //selecting the first node as we need lexographical order
                st.push(*dst);               //pushing the node in the stack
                adj[src].erase(dst);         //removing it from the list as already computed
            }
        }
        reverse(ans.begin(), ans.end()); //the answer would be reverse of the answer vector
        return ans;
    }
};