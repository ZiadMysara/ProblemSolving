#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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

int main()
{
    int caseNumber = 1;

    while (cin >> N >> M)
    {
        if (N == 0 && M == 0)
            break;

        grid = vector<vector<char>>(N, vector<char>(M));
        memo = vector<vector<int>>(N, vector<int>(M, -1));

        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                cin >> grid[i][j];
            }
        }

        int maxPathLength = 0;

        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                if (grid[i][j] == 'A')
                {
                    maxPathLength = max(maxPathLength, dfs(i, j));
                }
            }
        }

        cout << "Case " << caseNumber++ << ": " << maxPathLength << endl;
    }

    return 0;
}
