class Solution
{
public:
    bool checkCycle(int node, vector<int> adj[], vector<int> &vis, vector<int> &dfsvis)
    {
        vis[node] = 1;    //setting current node in vis array to 1
        dfsvis[node] = 1; //setting current node in dfsvis array to 1
        for (auto itr : adj[node])
        {
            if (!vis[itr])
            {
                if (checkCycle(itr, adj, vis, dfsvis)) //if somewhere deep it returns a true thus this also returns a true right
                    return true;
            }
            else if (dfsvis[itr] == 1) //if it has already been visited in the current dfs movement, thus cycle exists
            {
                return true;
            }
        }
        dfsvis[node] = 0; //setting the current node back to 0 to imply that it doesn't exist in the current movement
        return false;
    }

public:
    //Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0);
        vector<int> dfsvis(V, 0); //to determine the visited nodes in the current movement of dfs
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (checkCycle(i, adj, vis, dfsvis))
                    return true;
            }
        }
        return false;
    }
};