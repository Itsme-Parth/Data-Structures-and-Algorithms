class Solution
{
public:
    bool checkBipartite(int node, vector<int> adj[], int color[])
    {
        if (color == -1)
            color[node] = 1;
        for (auto itr : adj[node])
        {
            if (color[itr] == -1)
            {
                color[itr] = 1 - color[node];         //change the color first and then call for adjacent nodes
                if (!checkBipartite(itr, adj, color)) //if somewhere deep it returns a false thus this also returns a false right
                    return false;
            }
            else if (color[itr] == color[node])
                return false;
        }
        return true;
    }

public:
    bool isBipartite(int V, vector<int> adj[])
    {
        int color[V];
        memset(color, -1, sizeof color);
        for (int i = 0; i < V; i++)
        {
            if (color[i] == -1)
            {
                // color[i] = 1;
                if (!checkBipartite(i, adj, color)) //if a component isn't bipartite then the whole graph isn't bipartite
                    return false;
            }
        }
        return true;
    }
};