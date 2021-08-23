#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, m;
    cin >> N >> m;
    vector<pair<int, int>> adj[N];

    int a, b, wt;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> wt;
        adj[a].push_back(make_pair(b, wt));
        adj[b].push_back(make_pair(a, wt)); //It being an undirected graph
    }

    int key[N];

    bool mst[N];

    int parent[N];

    for (int i = 0; i < N; i++)
    {
        key[i] = INT_MAX;
        mst[i] = false;
        parent[i] = -1;
    }
    key[0] = 0;

    for (int i = 0; i < N - 1; i++)
    {
        int mini = INT_MAX, u;
        for (int v = 1; v < N - 1; v++) //to find the minimum in the key array
        {
            if (key[i] < mini)
            {
                mini = key[i]; //updating mini to find the minimum node
                u = v;         //u is to store the index
            }
        }

        mst[u] = true;

        for (auto itr : adj[u]) //to update the parent and key of the adjacent nodes to the minimum node found above
        {
            int node = itr.first;
            int weight = itr.second;
            if (mst[node] = false && weight < key[itr])
            {
                parent[v] = u;   //updating the parent with the min node found above
                key[v] = weight; //updating the weight in the key array
            }
        }
    }

    for (int i = 1; i < N; i++)
        cout << parent[i] << " - " << i << " \n";
    return 0;
}