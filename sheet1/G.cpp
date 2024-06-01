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

#define pii pair<int, int>

class Dijkstra
{
private:
    int n;
    vector<vector<pii>> graph;
    // the cost to reach the node i
    vector<int> dist;
    priority_queue<pii, vector<pii>, greater<pii>> pq;

public:
    Dijkstra(int n)
    {
        this->n = n;
        graph = vector<vector<pii>>(n + 1);
        dist = vector<int>(n + 1, INT_MAX);
    }

    // undirected graph
    void addEdge(int u, int v, int w)
    {
        graph[u].push_back({w, v});
        graph[v].push_back({w, u});
    }

    void shortedPath()
    {
        dist[1] = 0;
        pq.push({0, 1});
        while (!pq.empty())
        {
            int Wpq = pq.top().first;
            int Vpq = pq.top().second;
            pq.pop();
            if (Wpq > dist[Vpq])
            {
                continue;
            }
            for (pii VertixWeight : graph[Vpq])
            {
                int Wgrph = VertixWeight.first;
                int Vgrph = VertixWeight.second;
                if (dist[Vgrph] > dist[Vpq] + Wgrph)
                {
                    dist[Vgrph] = dist[Vpq] + Wgrph;
                    pq.push({dist[Vgrph], Vgrph});
                }
            }
        }
    }

    void printShortPath()
    {
        if (dist[n] == INT_MAX)
        {
            cout << -1 << endl;
            return;
        }

        int current = n;
        vector<int> path;

        while (current != 1)
        {
            path.push_back(current);
            for (pii VertixWeight : graph[current])
            {
                int Wprev = VertixWeight.first;
                int Vprev = VertixWeight.second;
                if (dist[current] == dist[Vprev] + Wprev)
                {
                    current = Vprev;
                    break;
                }
            }
        }
        path.push_back(1);

        for (int i = path.size() - 1; i >= 0; i--)
        {
            cout << path.at(i) << " ";
        }
    }

    void Run()
    {
        shortedPath();
        printShortPath();
    }
};

void LetsDoIt()
{
    int n, m;
    cin >> n >> m;
    Dijkstra D(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        D.addEdge(u, v, w);
    }
    D.Run();
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
    // cin >> t;
    while (t--)
    {
        LetsDoIt();
    }
    return 0;
}
