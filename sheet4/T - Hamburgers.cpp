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
void LetsDoIt()
{
    string recipe;
    cin >> recipe;

    int nb, ns, nc;
    cin >> nb >> ns >> nc;

    int pb, ps, pc;
    cin >> pb >> ps >> pc;

    long long r;
    cin >> r;

    long long b_count = 0, s_count = 0, c_count = 0;
    for (char ch : recipe)
    {
        if (ch == 'B')
            b_count++;
        else if (ch == 'S')
            s_count++;
        else
            c_count++;
    }

    long long hamburgers = 0;
    long long lo = 0, hi = 1e13;

    while (lo <= hi)
    {
        long long mid = lo + (hi - lo) / 2;

        long long cost = max(0LL, b_count * mid - nb) * pb +
                         max(0LL, s_count * mid - ns) * ps +
                         max(0LL, c_count * mid - nc) * pc;

        if (cost <= r)
        {
            hamburgers = max(hamburgers, mid);
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }

    cout << hamburgers << endl;
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
