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
const string target = "ALLIZZWELL";

bool isValid(int r, int c, int R, int C)
{
    return r >= 0 && r < R && c >= 0 && c < C;
}

bool dfs(vector<string> &matrix, int r, int c, int pos)
{
    if (pos == target.length())
    {
        return true;
    }

    if (matrix[r][c] != target[pos])
    {
        return false;
    }

    char temp = matrix[r][c];
    matrix[r][c] = '.';

    int dr[] = {-1, 1, 0, 0, -1, -1, 1, 1};
    int dc[] = {0, 0, -1, 1, -1, 1, -1, 1};

    for (int i = 0; i < 8; ++i)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (isValid(nr, nc, matrix.size(), matrix[0].size()) && dfs(matrix, nr, nc, pos + 1))
        {
            matrix[r][c] = temp; 
            return true;
        }
    }

    matrix[r][c] = temp;
    return false;
}

bool findPath(vector<string> &matrix, int Tr, int Tc)
{
    int R = Tr;
    int C = Tc;

    for (int r = 0; r < R; ++r)
    {
        for (int c = 0; c < C; ++c)
        {
            if (dfs(matrix, r, c, 0))
            {
                return true;
            }
        }
    }

    return false;
}

void LetsDoIt()
{
    int N, M;
    cin >> N >> M;

    vector<string> matrix(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> matrix[i];
    }

    if (findPath(matrix, N, M))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}
int main()
{
    fast;
    int t = 1;
    cin >> t;
    while (t--)
    {
        LetsDoIt();
    }
    return 0;
}
