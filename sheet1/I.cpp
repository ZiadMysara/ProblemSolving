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
    const int INF = 1e9;

private:
    int n;
    vector<vector<pair<int, int>>> graph;
    vector<int> dist;

public:
    Dijkstra(int nodes) : n(nodes), graph(nodes), dist(nodes, INF) {}

    // undirected graph
    void addEdge(int u, int v, int weight)
    {
        graph[u].push_back({v, weight});
        graph[v].push_back({u, weight});
    }

    void shortestPath(int src, int des)
    {

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty())
        {

            int Wpq_Parent = pq.top().first;
            int Vpq_Parent = pq.top().second;
            pq.pop();

            if (Wpq_Parent > dist[Vpq_Parent])
                continue;

            for (pair<int, int> &childEdges : graph[Vpq_Parent])
            {
                int vg_child = childEdges.first;
                int wg_child = childEdges.second;

                if (dist[Vpq_Parent] + wg_child < dist[vg_child])
                {
                    dist[vg_child] = dist[Vpq_Parent] + wg_child;
                    pq.push({dist[vg_child], vg_child});
                }
            }
        }
        if (dist[des] == INF)
        {
            cout << "NONE" << endl;
        }
        else
        {
            cout << dist[des] << endl;
        }
    }
};

void LetsDoIt()
{
    int n, m, src, des;
    cin >> n >> m >> src >> des;
    Dijkstra dijkstra(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        dijkstra.addEdge(u, v, w);
    }
    dijkstra.shortestPath(src, des);
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
