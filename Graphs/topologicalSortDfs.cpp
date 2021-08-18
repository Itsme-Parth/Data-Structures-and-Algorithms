class Solution
{
public:
    void findTopoSort(int node, vector<int> adj[], vector<int> &vis, stack<int> &st)
    {
        vis[node] = 1;
        for (auto itr : adj[node])
        {
            if (!vis[itr])
            {
                findTopoSort(itr, adj, vis, st);
            }
        }
        st.push(node); //pushing the current node to stack
    }

public:
    //Function to return list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0);
        stack<int> st;
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                findTopoSort(i, adj, vis, st);
            }
        }
        vector<int> topo;
        while (!S.empty())
        {
            topo.push_back(st.top());
            st.pop();
        }
        return topo;
    }
};