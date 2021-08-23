class Solution
{
    bool isBipartite(int src, vector<vector<int>> adj, vector<int> &color)
    {
        queue<int> q;
        q.push(src);
        color[src] = 1; //as it is a new component
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (auto itr : adj[node])
            {
                if (color[itr] == color[node]) //bipartite not possible
                {
                    return false;
                }
                if (color[itr] == -1)
                {
                    color[itr] = 1 - color[node];
                    q.push(itr);
                }
            }
        }
        return true;
    }

public:
    bool possibleBipartition(int n, vector<vector<int>> &dislikes)
    {
        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < dislikes.size(); i++)
        {
            adj[dislikes[i][0]].push_back(dislikes[i][1]); //creating an undirected graph
            adj[dislikes[i][1]].push_back(dislikes[i][0]); //through our adjacency list adj
        }
        vector<int> color(n + 1, -1); //1 based indexing of graph
        color[1] = 0;
        for (int i = 1; i < n + 1; i++)
        {
            if (color[i] == -1)
            {
                if (!isBipartite(i, adj, color))
                    return false;
            }
        }
        return true;
    }
};