class Solution
{
public:
    bool detectCycle(int node, vector<int> &vis, vector<int> adj[])
    {
        vis[node] = 1;           //setting the node to visited
        queue<pair<int, int>> q; //queue of node, prev pair
        q.push({node, -1});      //as it is a new component the parent of the first element would be -1
        while (!q.empty())
        {
            int node = q.front().first;
            int prev = q.front().second;
            q.pop();
            for (auto itr : adj[node])
            {
                if (!vis[itr]) //if not visited push in queue and mark as visited
                {
                    q.push({itr, node});
                    vis[itr] = 1;
                }
                else if (itr != prev) //if visited and not equal to prev then cycle exists
                    return true;
            }
        }
        return false;
    }

public:
    //Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i]) //for different components
            {
                if (detectCycle(i, vis, adj)) //util function to detect cycle
                {
                    return true;
                }
            }
        }
        return false;
    }
};