class Solution
{
public:
    bool checkBipartite(int src, vector<int> adj[], int color[])
    {
        color[src] = 1; //setting the color of the source of new component
        queue<int> q;
        q.push(src); //pushing the first element in source
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (auto itr : adj[node])
            {
                if (color[itr] == -1) //if not visited hence color[i] == -1
                {
                    color[itr] = 1 - color[node];
                    q.push(itr);
                }
                else if (color[itr] == color[node]) //if already visited in case of cycle check if color same to the adjacent element
                    return false;
            }
        }
        return true;
    }

public:
    bool isBipartite(int V, vector<int> adj[])
    {
        int color[V];                    //array color
        memset(color, -1, sizeof color); //all elements set to -1
        for (int i = 0; i < V; i++)
        {
            if (color[i] == -1)
            {
                if (!checkBipartite(i, adj, color)) //if a component isn't bipartite then the whole graph isn't bipartite
                    return false;
            }
        }
        return true;
    }
};