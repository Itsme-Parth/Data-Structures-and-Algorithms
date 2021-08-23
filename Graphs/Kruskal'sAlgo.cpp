#include <bits/stdc++.h>
using namespace std;
struct node
{
    int u;
    int v;
    int wt;
    node(int first, int second, int weight)
    {
        u = first;
        v = second;
        wt = weight;
    }
};

bool comp(node a, node b)
{
    return a.wt < b.wt;
}

int findPar(int node, vector<int> parent)
{
    if (parent[node] == node)
        return node;

    return parent[node] = findPar(parent[node], parent);
}

int unionn(int u, int v, vector<int> parent, vector<int> rank)
{
    int u = findPar(u, parent);
    int v = findPar(v, parent);

    if (rank[u] < rank[v])
    {
        parent[u] = v;
    }
    else if (rank[v] < rank[u])
    {
        parent[v] = u;
    }
    else
    {
        parent[v] = u;
        rank[u]++;
    }
}

int main()
{
    int N, m;
    cin >> N >> m;
    vector<node> edges;
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back(node(u, v, wt));
    }
    sort(edges.begin(), edges.end(), comp); //sorting the edges according to the weights
    vector<int> parent(N);
    for (int i = 0; i < N; i++)
    {
        parent[i] = i;
    }
    vector<int> rank(N, 0);
    int cost = 0;
    vector<pair<int, int>> mst;
    for (auto itr : edges)
    {
        if (findPar(it.v, parent) != findPar(it.u, parent)) //check if they are from the same component
        {
            cost += it.wt;                    //add to the total cost
            mst.push_back({it.u, it.v});      //push to the mst vector
            unionn(it.u, it.v, parent, rank); //union the nodes
        }
    }
    cout << cost << endl;
    for (auto it : mst)
        cout << it.first << " - " << it.second << endl;
    return 0;
}