class Solution
{
    void dfs(int node, vector<int> &vis, vector<int> adj[], vector<int> &storeDfs) //passing by reference so that storeDfs is updated
    {
        storeDfs.push_back(node); //adding node to result
        vis[node] = 1;            //marking the node
        for (auto it : adj[node])
        {
            if (!vis[it]) //looking a the adjacent nodes
            {
                dfs(it, vis, adj, storeDfs);
            }
        }
    }

public:
    //Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        vector<int> storeDfs;
        vector<int> vis(V + 1, 0);
        for (int i = 0; i < V; i++) //in case of 0 based indexing we run from 0 to v - 1
        {
            if (!vis[i])
                dfs(i, vis, adj, storeDfs);
        }
        return storeDfs;
    }
};