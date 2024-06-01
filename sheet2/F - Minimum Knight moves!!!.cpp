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
// Traveling Knight Problem
//================================
class chessBoard
{
private:
    vector<vector<int>> board;
    vector<vector<int>> moves = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};
    int N = 64;
    vector<vector<int>> adj;
    // Length of SHORTEST PATH FROM SOURCE TO DESTINATION
    int shortPath = INT_MAX;

public:
    chessBoard()
    {
        board = vector<vector<int>>(8, vector<int>(8, 0));
        adj = vector<vector<int>>(N);
        createGraph();
    }
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void createGraph()
    {
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                for (int k = 0; k < 8; k++)
                {
                    int x = i + moves[k][0];
                    int y = j + moves[k][1];
                    if (x >= 0 && x < 8 && y >= 0 && y < 8)
                    {
                        addEdge(i * 8 + j, x * 8 + y);
                    }
                }
            }
        }
    }

    // Length of SHORTEST PATH FROM SOURCE TO DESTINATION
    // using BFS
    int shortestPath(int src, int dest)
    {
        vector<int> dist(N, INT_MAX);
        queue<int> q;
        q.push(src);
        dist[src] = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (int child : adj[node])
            {
                if (dist[child] == INT_MAX)
                {
                    dist[child] = dist[node] + 1;
                    q.push(child);
                    if (child == dest)
                        return dist[dest];
                }
            }
        }
        return dist[dest];
    }
    int getShortestPath(int src, int dest)
    {
        shortPath = shortestPath(src, dest);
        return shortPath;
    }
};
void print(int shortPath)
{
    cout << shortPath << endl;
    flush(cout);
}

void LetsDoIt(string src, string dest)

{
    chessBoard board;
    int srcX = src[0] - 'a';
    int srcY = src[1] - '1';
    int destX = dest[0] - 'a';
    int destY = dest[1] - '1';
    int srcNode = srcX * 8 + srcY;
    int destNode = destX * 8 + destY;
    int shortPath = board.getShortestPath(srcNode, destNode);
    print(shortPath);
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
    string src, dest;
    while (t--)
    {
        cin >> src >> dest;
        LetsDoIt(src, dest);
    }
    return 0;
}
