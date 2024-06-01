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
bool isConnected(vector<vector<int>> &adj, int N)
{
    vector<bool> visited(N, false);
    queue<int> q;

    // Find a vertex with a non-zero degree
    int start = 0;
    for (start = 0; start < N; ++start)
        if (!adj[start].empty())
            break;

    // If no edges in the graph
    if (start == N)
        return true;

    // Start BFS
    q.push(start);
    visited[start] = true;
    int count = 1;

    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int u : adj[v])
        {
            if (!visited[u])
            {
                visited[u] = true;
                q.push(u);
                count++;
            }
        }
    }

    // Check if all non-zero degree vertices are connected
    for (int i = 0; i < N; ++i)
        if (!adj[i].empty() && !visited[i])
            return false;

    return true;
}

bool hasEulerianCircuit(vector<vector<int>> &adj, int N)
{
    if (!isConnected(adj, N))
        return false;

    // Check if all vertices have even degree
    for (int i = 0; i < N; ++i)
        if (adj[i].size() % 2 != 0)
            return false;

    return true;
}

void LetsDoIt()
{
    int N, R;
    while (cin >> N >> R)
    {
        vector<vector<int>> adj(N);

        for (int i = 0; i < R; ++i)
        {
            int c1, c2;
            cin >> c1 >> c2;
            adj[c1].push_back(c2);
            adj[c2].push_back(c1);
        }

        if (hasEulerianCircuit(adj, N))
            cout << "Possible" << endl;
        else
            cout << "Not Possible" << endl;
    }
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
