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
    int N;
    vector<set<int>> adj;
    vector<bool> visited;

public:
    MyGraph(int n) : N(n), adj(n), visited(n, false) {}

    void addEdge(int u, int v)
    {
        adj[u].insert(v);
        adj[v].insert(u);
    }

    void dfs(int node, int parent)
    {
        visited[node] = true;
        for (int child : adj[node])
        {
            if (child != parent && !visited.at(child))
            {
                dfs(child, node);
            }
        }
    }

    void Run()
    {
        int OurCounter = 1;
        dfs(0, -1);
        for (int i = 1; i < N; i++)
        {
            if (!visited.at(i))
            {
                dfs(i, -1);
                OurCounter++;
            }
        }
        cout << OurCounter;
    }
};

void LetsDoIt()
{
    int n;
    char c;
    string line;
    getline(cin, line);
    c = line[0];
    n = c - 'A' + 1;
    MyGraph graph(n);
    while (getline(cin, line) && !line.empty())
    {
        int u, v;
        u = line[0];
        v = line[1];
        u -= 'A';
        v -= 'A';
        graph.addEdge(u, v);
    }
    graph.Run();
}

int main()
{
    fast;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    string line;
    getline(cin, line);
    t = stoi(line);
    cin.ignore();
    while (t--)
    {
        LetsDoIt();
        if (t >= 0)
        {
            cout << endl;
        }
    }
    return 0;
}
