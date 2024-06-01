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
    vector<int> WeightsVector;

public:
    Dijkstra(int nodes) : n(nodes), graph(nodes), WeightsVector(nodes, INF) {}

    void addEdge(int u, int v, int weight)
    {
        graph[u].push_back({v, weight});
    }

    void shortestPath(int src)
    {

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        WeightsVector[src] = 0;
        pq.push({0, src});

        while (!pq.empty())
        {
            int W_pq = pq.top().first;
            int V_pq = pq.top().second;
            pq.pop();

            if (W_pq > WeightsVector[V_pq])
                continue;

            for (pair<int, int> &edgeInGraph : graph[V_pq])
            {
                int vg_nextpq = edgeInGraph.first;
                int wg_nextpq = edgeInGraph.second;

                if (WeightsVector[V_pq] + wg_nextpq < WeightsVector[vg_nextpq])
                {
                    WeightsVector[vg_nextpq] = WeightsVector[V_pq] + wg_nextpq;
                    pq.push({WeightsVector[vg_nextpq], vg_nextpq});
                }
            }
        }
    }

    int Run(int src, int time, int n)
    {
        shortestPath(src);
        int count = 0;
        for (int i = 1; i < n; ++i)
        {
            if (time >= WeightsVector[i])
            {
                count++;
            }
        }
        return count;
    }
};

void LetsDoIt()
{
    int N, E, T, M;
    cin >> N >> E >> T >> M;
    Dijkstra dijkstra(N + 1);
    for (int i = 0; i < M; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        dijkstra.addEdge(v, u, w);
    }

    int minTime = dijkstra.Run(E, T, N + 1);

    cout << minTime << endl;
}

int main()
{
    fast;

    int t = 1;
    // cin >> t;
    while (t--)
    {
        LetsDoIt();
    }
    return 0;
}
