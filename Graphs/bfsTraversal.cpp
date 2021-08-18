class Solution
{
public:
    //Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        vector<int> bfs;       //bfs vector
        vector<int> vis(V, 0); //visited vector with all nodes initialised to 0
        queue<int> q;          //queue to help bfs implementation
        q.push(0);             //pushing the first node
        vis[0] = 1;            // agar yeh nahi karoge toh queue toh empty ho jayegi na
        while (!q.empty())
        {
            int node = q.front(); //select the top node
            q.pop();
            bfs.push_back(node);       //push the current node to result
            for (auto itr : adj[node]) //check neighbours of the current node
            {
                if (!vis[itr]) //add in the queue if not visited
                {
                    q.push(itr);
                    vis[itr] = 1;
                }
            }
        }
        return bfs;
    }
};