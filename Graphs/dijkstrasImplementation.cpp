class Solution
{
public:
    //Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector<int> dijkstra(int n, vector<vector<int>> g[], int source)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> distance(n, INT_MAX);
        pq.push({make_pair(0, source)});
        distance[source] = 0;

        while (!pq.empty())
        {
            int adjNode = pq.top().second;
            int adjWeight = pq.top().first;
            pq.pop();
            vector<pair<int, int>>::iterator itr;
            for (itr = g[adjNode].begin(); itr != g[adjNode].end(); itr++)
            {
                int newNode = itr.first;
                int newWeight = itr.second;
                if (distance[adjNode] + newWeight < distance[newNode])
                {
                    distance[newNode] = distance[adjNode] + newWeight;
                    pq.push({make_pair(distance[newNode], newNode)});
                }
            }
        }
        for (int itr : distance)
            cout << itr << " ";
    }
};
