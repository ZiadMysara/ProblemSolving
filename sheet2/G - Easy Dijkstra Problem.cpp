#include <bits/stdc++.h>
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr);
#define endl "\n"
#define ll long long
#define all(v) ((v).begin()), ((v).end())
int mul(const int &a, const int &b, int MOD)
{
    return (a % MOD + MOD) * (b % MOD + MOD) % MOD;
}
// in case negative (2*mod)
int add(const int &a, const int &b, int MOD)
{
    return (a + b + 2 * MOD) % MOD;
}
class Dijkstra
{
    int N;
    vector<vector<pair<int, int>>> adj;

public:
    Dijkstra(int n)
    {
        N = n;
        adj = vector<vector<pair<int, int>>>(n);
    }
    void addEdge(int u, int v, int w)
    {
        adj[u].push_back({v, w});
    }

    int shortestPath(int src, int dest)
    {
        vector<int> dist(N, INT_MAX);
        dist[src] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});
        while (!pq.empty())
        {
            int node = pq.top().second;
            int d = pq.top().first;
            pq.pop();
            if (d > dist[node])
                continue;
            for (pair<int, int> edge : adj[node])
            {
                int child = edge.first;
                int weight = edge.second;
                if (dist[child] > dist[node] + weight)
                {
                    dist[child] = dist[node] + weight;
                    pq.push({dist[child], child});
                }
            }
        }
        return dist[dest];
    }
};
void LetsDoIt()
{
    int n, m;
    cin >> n >> m;
    Dijkstra dijkstra(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        dijkstra.addEdge(u - 1, v - 1, w);
    }
    int src, dest;
    cin >> src >> dest;
    int ans = dijkstra.shortestPath(src - 1, dest - 1);
    if (ans == INT_MAX)
        cout << "NO" << endl;
    else
        cout << ans << endl;
}
int main()
{
    fast;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("errors.txt", "w", stderr);
#endif
    int t = 1;
    cin >> t;
    while (t--)
    {
        LetsDoIt();
    }
    return 0;
}
