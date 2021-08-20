class Solution
{
public:
    //Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector<int> dijkstra(int n, vector<vector<int>> g[], int source)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // min-heap ; In pair => (dist,from)
        vector<int> distTo(n, INT_MAX);                                                     // 1-indexed array for calculating shortest paths;

        distTo[source] = 0;
        pq.push(make_pair(0, source)); // (dist,from)

        while (!pq.empty())
        {
            int dist = pq.top().first;
            int prev = pq.top().second;
            pq.pop();

            vector<pair<int, int>>::iterator it;
            for (it = g[prev].begin(); it != g[prev].end(); it++)
            {
                int next = it->first;
                int nextDist = it->second;
                if (distTo[next] > distTo[prev] + nextDist)
                {
                    distTo[next] = distTo[prev] + nextDist;
                    pq.push(make_pair(distTo[next], next));
                }
            }
        }
        vector<int> res;
        for (int i = 0; i < n; i++)
        {
            res.push_back(distTo[i]);
        }
        return res;
    }
};