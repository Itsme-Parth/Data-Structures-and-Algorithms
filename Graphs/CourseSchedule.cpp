class Solution
{
public:
    typedef vector<vector<int>> graph;

    graph buildGraph(int numCourses, vector<pair<int, int>> &prerequisites)
    {
        graph adj(numCourses);
        for (auto p : prerequisites)
        {
            adj[p.second].push_back(p.first);
        }
        return adj;
    }

    bool checkCycle(int node, graph adj, vector<int> &vis, vector<int> &dfsvis)
    {
        vis[node] = 1;
        dfsvis[node] = 1;
        for (auto itr : adj[node])
        {
            if (!vis[itr])
            {
                if (checkCycle(itr, adj, vis, dfsvis))
                    return true;
            }
            else if (dfsvis[itr] == 1)
                return true;
        }
        dfsvis[node] = 0;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        graph adj = buildGraph(numCourses, prerequisites);
        vector<int> vis(numCourses, 0);
        vector<int> dfsvis(numCourses, 0);
        for (int i = 0; i < numCourses; i++)
        {
            if (!vis[i])
            {
                if (checkCycle(i, adj, vis, dfsvis))
                    return false;
            }
        }
        return true;
    }
};