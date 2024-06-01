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
long long max_coins(vector<ll> &coins)
{
    int n = coins.size();
    if (n == 0)
        return 0;
    if (n == 1)
        return coins[0];

    vector<long long> dp(n);
    dp[0] = coins[0];
    dp[1] = max(coins[0], coins[1]);

    for (int i = 2; i < n; ++i)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + coins[i]);
    }

    return dp[n - 1];
}

void LetsDoIt(int t)
{
    int t;
    cin >> t;
    for (int c = 1; c <= t; ++c)
    {
        int n;
        cin >> n;
        vector<ll> coins(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> coins[i];
        }
        cout << "Case " << c << ": " << max_coins(coins) << endl;
    }
}
int main()
{
    fast;
    int t = 1;
    //cin >> t;
    while (t--)
    {
        LetsDoIt(t);
    }
    return 0;
}
