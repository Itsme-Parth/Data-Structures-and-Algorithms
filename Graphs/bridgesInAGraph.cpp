#include <bits/stdc++.h>
using namespace std;
void dfs(int node, int parent, vector<int> &vis, vector<int> &tin, vector<int> &low, int &timer, vector<int> adj[])
{
    vis[node] = 1;
    tin[node] = low[node] = timer++;
    for (auto itr : adj[node])
    {
        if (it == parent)
        {
            continue;
        }
        if (!vis[itr])
        {
            dfs(itr, node, vis, tin, low, timer, adj); //we do the further steps after completing the dfs
            low[node] = min(low[node], tin[itr]);      //low of node comparison b/w itself and minimum time of adjacent node
            if (low[itr] > tin[node])                  //mera min time bhi tere time se greater hai toh agar i leave you, you will disconnect me into a different component
            {
                cout << "It is a bridge!!";
            }
        }
        else //if already visited
        {
            low[node] = min(low[node], tin[it]);
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
        adj[v].push_back(u);
    }

    vector<int> tin(n, -1); //time inserted vector
    vector<int> low(n, -1); //minimum insertion time possible vector
    vector<int> vis(n, 0);  //visited array for dfs
    int timer = 0;          //setting timer as zero initially
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i, -1, vis, tin, low, timer, adj); //setting -1 as the parent first
        }
    }

    return 0;
}