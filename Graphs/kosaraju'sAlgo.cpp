#include <bits/stdc++.h>
using namespace std;
void dfs(int node, stack<int> &st, vector<int> &vis, vector<int> adj[]) //implementing TopoSort using dfs
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, st, vis, adj);
        }
    }

    st.push(node); //pushing the element in the stack when no more adjacent nodes left
}
void revDfs(int node, vector<int> &vis, vector<int> transpose[]) //dfs
{
    cout << node << " ";
    vis[node] = 1;
    for (auto it : transpose[node])
    {
        if (!vis[it])
        {
            revDfs(it, vis, transpose);
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    stack<int> st;
    vector<int> vis(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i, st, vis, adj); //for topoSort
        }
    }

    vector<int> transpose[n];

    for (int i = 0; i < n; i++) //creating a transpose adjacency list
    {
        vis[i] = 0;
        for (auto it : adj[i]) //before it was from i to it
        {
            transpose[it].push_back(i); //now it is it to i
        }
    }

    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        if (!vis[node])
        {
            cout << "SCC: ";
            revDfs(node, vis, transpose);
            cout << endl;
        }
    }

    return 0;
}