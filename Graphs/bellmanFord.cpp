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

    int src;
    cin >> src;

    int inf = 10000000;
    vector<int> dist(N, inf); //setting distance array as infinity

    dist[src] = 0; //except the source

    for (int i = 1; i <= N - 1; i++) //relaxing n - 1
    {
        for (auto it : edges) //on all edges
        {
            if (dist[it.u] + it.wt < dist[it.v]) //if u + wt < v
            {
                dist[it.v] = dist[it.u] + it.wt; //v = u + wt
            }
        }
    }

    int fl = 0;
    for (auto it : edges)
    {
        if (dist[it.u] + it.wt < dist[it.v]) //if the distance decreases after 1 relaxation then it has a negative cycle
        {
            cout << "Negative Cycle";
            fl = 1;
            break;
        }
    }

    if (!fl) //otherwise no negative cycle and print the shortest difference
    {
        for (int i = 0; i < N; i++)
        {
            cout << i << " " << dist[i] << endl;
        }
    }

    return 0;
}