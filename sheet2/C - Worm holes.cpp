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
const int INF = 1e9;
class Graph
{

    struct Edge
    {
        int source, destination, weight;
    };

    int V, E;
    vector<Edge> edges;
    bool flag = false;

public:
    Graph(int V, int E) : V(V), E(E) {}

    void addEdge(int source, int destination, int weight)
    {
        Edge edge;
        edge.source = source;
        edge.destination = destination;
        edge.weight = weight;
        edges.push_back(edge);
    }

    void bellmanFord(int source)
    {
        vector<int> distance(V, numeric_limits<int>::max());
        distance[source] = 0;
        for (int i = 0; i < V - 1; ++i)
        {

            for (const auto &edge : edges)
            {
                int u = edge.source;
                int v = edge.destination;
                int w = edge.weight;

                if (distance[u] != numeric_limits<int>::max() && distance[u] + w < distance[v])
                {
                    distance[v] = distance[u] + w;
                }
            }
        }

        for (const auto &edge : edges)
        {
            int u = edge.source;
            int v = edge.destination;
            int w = edge.weight;
            if (distance[u] != numeric_limits<int>::max() && distance[u] + w < distance[v])
            {
                cout << "possible\n";
                flag = true;
                return;
            }
        }
        if (!flag)
        {
            cout << "not possible\n";
        }
    }
};
void LetsDoIt()
{
    int n, m;
    cin >> n >> m;
    Graph graph(n, m);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph.addEdge(u, v, w);
    }
    graph.bellmanFord(0);
}
int main()
{
    fast;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    cin >> t;
    while (t--)
    {
        LetsDoIt();
    }
    return 0;
}
