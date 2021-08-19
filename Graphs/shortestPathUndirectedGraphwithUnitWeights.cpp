class Solution
{
public:
    //Function to return Shortest Path in Undirected Graph with Unit Weights
    vector<int> shortestPath(int V, vector<int> adj[])
    {
        //considering 0 as src
        vector<int> distance(V, INT_MAX); //setting the distance array to infinite initially
        queue<int> q;
        distance[0] = 0; //setting the src distance = 0
        q.push(0);

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (auto itr : adj[node])
            {
                distance[itr] = min(distance[itr], distance[node] + 1); //setting the distance of adjacent node
                q.push(itr);                                            //pushing the adjacent element in queue
            }
        }

        for (auto itr : distance) //printing the shortest distance from src
        {
            cout << itr << " ";
        }
    }
};