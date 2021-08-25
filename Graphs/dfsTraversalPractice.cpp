vector<int> elements;
void dfsUtil(int node, vector<int> &visited, vector<int> &dfsTraversal, vector<int> adj, int count)
{
    components++;
    visited[node] = 1;
    dfsTraversal.push_back(node);
    for (auto itr : adj[node])
    {
        if (!vis[itr])
        {
            dfsUtil(itr, visited, dfsTraversal, adj, components);
        }
    }
    elements.push_back(components);
    components = 0;
}
vector<int> bfs(vector<int> adj, int n)
{
    vector<int> dfsTraversal;
    vector<int> visited(n, 0);
    int count = 0;      //to count the number of elements in a component
    int components = 0; //to count the number of components
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfsUtil(i, visited, dfsTraversal, adj, count);
            components++;
        }
    }
}