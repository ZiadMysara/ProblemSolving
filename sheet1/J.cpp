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

unordered_map<ll, ll> dp;

ll max_dollars(ll n)
{
    if (n == 0)
        return 0;
    if (dp.find(n) != dp.end())
        return dp[n];

    ll dollars = max(n, max_dollars(n / 2) + max_dollars(n / 3) + max_dollars(n / 4));
    dp[n] = dollars;
    return dollars;
}

void LetsDoIt()
{
    ll n;
    while (cin >> n)
    {
        cout << max_dollars(n) << endl;
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
