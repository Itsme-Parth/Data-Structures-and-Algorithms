class Solution
{
public:
    //Function to return list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj[])
    {
        vector<int> inDegree(V, 0); //declaring an indegree vector
        queue<int> q;
        for (int i = 0; i < V; i++) //filling in the indegree vector
        {
            for (auto itr : adj[i]) //incrementing the nodes adjacent to the current node by 1
            {
                inDegree[itr]++;
            }
        }

        for (int i = 0; i < V; i++) //pushing the nodes in queue with indegree 0
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
            }
        }

        vector<int> topo;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for (auto itr : adj[node])
            {
                inDegree[itr]--;        //decrementing the indegree value of (removing the relation) the adjacent node by 1
                if (inDegree[itr] == 0) //if 0 pushing it in the queue
                    q.push(itr);
            }
        }

        return topo;
    }
};