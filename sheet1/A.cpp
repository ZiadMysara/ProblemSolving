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

bool dfs(int parent, int node, vector<bool> &visited, const vector<vector<int>> &graph)
{
    visited[node] = true;
    for (int child : graph[node])
    {
        if (!visited[child])
        {

            if (!dfs(node, child, visited, graph))
                return false;
        }
        else if (parent != child)
            return false; // Cycle detected
    }
    return true;
}

void LetsDoIt()
{
    /*to know that if the garph is tree or not there was some condetions:
    1- there is no cycle
    2- the graph is connected
    */
    // n :number of nodes
    // m: number of edges
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    vector<bool> visited(n);
    for (int i = 0; i < m; i++)
    {
        // edge between node(u, v)
        int u, v;
        cin >> u >> v;
        u--, v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    if (m != n - 1)
    {
        cout << "NO" << endl;
        return; // Condition for tree: exactly N-1 edges
    }
    if (!dfs(-1, 0, visited, graph))
    {
        cout << "NO" << endl;

        return; // Check for cycles and connectivity
    }
    for (bool visit : visited)
    {
        if (!visit)
        {
            cout << "NO" << endl;
            return; // Check if all nodes are visited
        }
    }
    cout << "YES";
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
