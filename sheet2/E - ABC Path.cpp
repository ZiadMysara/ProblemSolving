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

int N, M;
vector<vector<char>> grid;
vector<vector<int>> memo;
int directions[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

bool isValid(int x, int y)
{
    return x >= 0 && x < N && y >= 0 && y < M;
}

int dfs(int x, int y)
{
    if (memo[x][y] != -1)
    {
        return memo[x][y];
    }

    int maxLength = 1; // At least the current letter itself

    for (auto dir : directions)
    {
        int newX = x + dir[0];
        int newY = y + dir[1];

        if (isValid(newX, newY) && grid[newX][newY] == grid[x][y] + 1)
        {
            maxLength = max(maxLength, 1 + dfs(newX, newY));
        }
    }

    memo[x][y] = maxLength;
    return maxLength;
}
void Print(int T)
{
    int maxLength = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (grid[i][j] == 'A')
            {
                maxLength = max(maxLength, dfs(i, j));
            }
        }
    }

    cout << "Case " << T << ": " << maxLength << endl;
}
void LetsDoIt()
{
    int T = 0;
    cin >> N >> M;
    while (!(N == 0 && M == 0))
    {

        grid = vector<vector<char>>(N, vector<char>(M));
        memo = vector<vector<int>>(N, vector<int>(M, -1));

        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                cin >> grid[i][j];
            }
        }

        T++;
        Print(T);
        cin >> N >> M;
    }
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
