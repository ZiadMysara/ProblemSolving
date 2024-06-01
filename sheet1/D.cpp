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
bool hasWon(const vector<string> &grid, char player)
{
    // Check rows and columns
    for (int i = 0; i < 3; ++i)
    {
        if (grid[i][0] == player && grid[i][1] == player && grid[i][2] == player)
            return true;
        if (grid[0][i] == player && grid[1][i] == player && grid[2][i] == player)
            return true;
    }
    // Check diagonals
    if (grid[0][0] == player && grid[1][1] == player && grid[2][2] == player)
        return true;
    if (grid[0][2] == player && grid[1][1] == player && grid[2][0] == player)
        return true;

    return false;
}
bool isValidGrid(const vector<string> &grid)
{
    int countX = 0, countO = 0;
    for (string row : grid)
    {
        for (char cell : row)
        {
            if (cell == 'X')
                countX++;
            else if (cell == 'O')
                countO++;
        }
    }

    if (countO > countX || countX > countO + 1)
    {
        return false;
    }

    bool xWins = hasWon(grid, 'X');
    bool oWins = hasWon(grid, 'O');

    if (xWins && oWins)
        return false;
    if (xWins && countX != countO + 1)
        return false;
    if (oWins && countX != countO)
        return false;

    return true;
}
void LetsDoIt()
{
    int N;
    cin >> N;
    vector<string> grid(3);
    for (int i = 0; i < N; ++i)
    {
        if (i > 0)
            cin.ignore();
        for (int j = 0; j < 3; ++j)
        {
            cin >> grid[j];
        }
        if (isValidGrid(grid))
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }
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
