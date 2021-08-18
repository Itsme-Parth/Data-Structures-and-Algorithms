class Solution
{
public:
    bool detectCycleDfs(int node, int prev, vector<int> &vis, vector<int> adj[])
    {
        vis[node] = 1; //marking in the visited array
        for (auto itr : adj[node])
        {
            if (!vis[itr])
            {
                if (detectCycleDfs(itr, node, vis, adj)) //if somewhere deep it returns a true thus this also returns a true right
                {
                    return true;
                }
            }
            else if (itr != prev) //if visited and not equal to prev then cycle exists
                return true;
        }
        return false;
    }

public:
    //Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++) //checking for all the components
        {
            if (!vis[i])
            {
                if (detectCycleDfs(i, -1, vis, adj))
                    return true;
            }
        }
        return false;
    }
};