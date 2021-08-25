class Solution
{
public:
    //Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector<int> dijkstra(int n, vector<vector<int>> g[], int source)
    {
        // min-heap ; In pair => (dist,from)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> distTo(n + 1, INT_MAX); // 1-indexed array for calculating shortest paths;

        distTo[source] = 0;            //marking source distance as zero
        pq.push(make_pair(0, source)); // (dist,from)

        while (!pq.empty())
        {
            int currDist = pq.top().first;
            int prevNode = pq.top().second;
            pq.pop();

            vector<pair<int, int>>::iterator it;
            for (it = g[prevNode].begin(); it != g[prevNode].end(); it++)
            {
                //here we are iterating in the adjacency list comprised of (node, wt)
                int next = it->first;
                int nextWeight = it->second;
                if (distTo[prevNode] + nextWeight < distTo[next])
                {
                    distTo[next] = distTo[prev] + nextWeight; //updating the distance
                    pq.push(make_pair(distTo[next], next));   //if we find a new shorter distance we push it in the pq
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