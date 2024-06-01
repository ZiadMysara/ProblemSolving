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

// F - Bitmap
class MyGraph
{
private:
    int N, M;
    vector<vector<int>> adj;
    vector<pair<int, int>> directions = {{-1, 0},
                                         {1, 0},
                                         {0, -1},
                                         {0, 1}};

public:
    MyGraph(int n, int m)
    {
        N = n;
        M = m;
        adj = vector<vector<int>>(n, vector<int>(m, INT_MAX));
    }

    void solve_bitmap(const vector<vector<int>> &bitmap)
    {
        queue<pair<int, int>> q;
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                if (bitmap[i][j] == 1)
                {
                    adj[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        // BFS
        while (!q.empty())
        {
            pair<int, int> node = q.front();
            int x = node.first;
            int y = node.second;
            q.pop();
            for (pair<int, int> dir : directions)
            {
                int xn, yn;
                xn = x + dir.first;
                yn = y + dir.second;

                if (xn >= 0 && xn < N && yn >= 0 && yn < M)
                {
                    if (adj[xn][yn] > adj[x][y] + 1)
                    {
                        adj[xn][yn] = adj[x][y] + 1;
                        q.push({xn, yn});
                    }
                }
            }
        }
        printBitMap();
    }

    void printBitMap()
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }
};

void LetsDoIt()
{
    int n, m;
    cin >> n >> m;
    string line;
    MyGraph g(n, m);
    vector<vector<int>> BitMap(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        cin >> line;
        for (int j = 0; j < m; j++)
        {
            BitMap[i][j] = line[j] - '0';
        }
        line.clear();
    }
    g.solve_bitmap(BitMap);
}

int main()
{
    fast;

    int t = 1;
    cin >> t;
    while (t--)
    {
        LetsDoIt();
        cin.ignore();
    }
    return 0;
}
