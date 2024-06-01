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
// S: knapsack size, N: number of items
int knapsack(int S, int N, const vector<int> &sizes, const vector<int> &values)
{
    vector<vector<int>> dp(N + 1, vector<int>(S + 1, 0));

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= S; ++j)
        {
            if (sizes[i] <= j)
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - sizes[i]] + values[i]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[N][S];
}
void LetsDoIt()
{
    int K, M, A, B;
    cin >> K >> M;
    vector<int> sizes(M + 1, 0), values(M + 1, 0);
    for (int i = 1; i <= M; ++i)
    {
        cin >> A >> B;
        sizes[i] = A;
        values[i] = B;
    }
    int P = knapsack(K, M, sizes, values);
    cout << "Hey stupid robber, you can get "<< P << "."<< endl;
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
