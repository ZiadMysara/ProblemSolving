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

class MyGraph
{
private:
    int N, M;
    vector<vector<int>> adj;
    int maxPathLength = 0;
    int farthestNode = 0;

public:
    MyGraph(int n, int m) : N(n), M(m), adj(n) {}

    void addEdge(int u, int v)
    {
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }

    void dfs(int node, int parent, int depth = 0)
    {
        if (depth > maxPathLength)
        {
            maxPathLength = depth;
            farthestNode = node;
        }
        for (int i = 0; i < adj[node].size(); ++i)
        {
            int child = adj[node].at(i);
            if (child != parent)
            {
                dfs(child, node, depth + 1);
            }
        }
    }

    int getDiameter()
    {
        // Perform first DFS to find the farthest node from node 0
        maxPathLength = 0;
        dfs(0, -1);

        // Perform second DFS from the farthest node found in the first DFS
        int startNode = farthestNode;
        maxPathLength = 0;
        dfs(startNode, -1);

        return maxPathLength;
    }
};

void LetsDoIt()
{

    // n :number of nodes
    // m: number of edges
    int n, m;
    cin >> n;
    m = n - 1;
    MyGraph graph(n, m);
    for (int i = 0; i < m; i++)
    {
        // edge between node(u, v)
        int u, v;
        cin >> u >> v;
        graph.addEdge(u, v);
    }
    cout << graph.getDiameter() << endl;
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
