#define vi vector<int>
#define pii pair<int, int>
#define vpii vector<pii>
#define fi first
#define se second

template <typename T>
using PQ_mn = priority_queue<T, vector<T>, greater<T>>;

const int mxN = 2e5 + 500;
int n;
vpii e[mxN];

int dijkstra(int sv, int dest, int k)
{
    // minm distance from sv -> dest using at max k operations
    vector<vi> dp(n + 1, vi(k + 1, INT_MAX));
    PQ_mn<pair<int, pii>> q; // {dist , {node , op_used}}

    q.push({0, {sv, 0}});

    while (!q.empty())
    {
        auto tmp = q.top();
        q.pop();
        int d = tmp.fi, cv = tmp.se.fi, op_used = tmp.se.se;

        dp[cv][op_used] = d;

        for (auto &x : e[cv])
        {
            int nv = x.fi, w = x.se;
            q.push({d + w, {nv, op_used}}); // option 1 -> use
            if (op_used < k)
                q.push({d, {nv, op_used + 1}}); // option 2 -> jump
        }
    }
    return *min_element(dp[dest].begin(), dp[dest].end());
}