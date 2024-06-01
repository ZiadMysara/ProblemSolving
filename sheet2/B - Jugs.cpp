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
bool dfs(int Ca, int Cb, int N, int a, int b, unordered_set<string> &visited, vector<string> &steps)
{
    if (b == N)
    {
        steps.push_back("success");
        return true;
    }

    string state = to_string(a) + "," + to_string(b);
    if (visited.find(state) != visited.end())
    {
        return false; // Already visited this state
    }
    visited.insert(state);

    // Fill A
    if (a < Ca)
    {
        steps.push_back("fill A");
        if (dfs(Ca, Cb, N, Ca, b, visited, steps))
            return true;
        steps.pop_back();
    }

    // Fill B
    if (b < Cb)
    {
        steps.push_back("fill B");
        if (dfs(Ca, Cb, N, a, Cb, visited, steps))
            return true;
        steps.pop_back();
    }

    // Empty A
    if (a > 0 && b > 0)
    {
        steps.push_back("empty A");
        if (dfs(Ca, Cb, N, 0, b, visited, steps))
            return true;
        steps.pop_back();
    }

    // Empty B
    if (b > 0 && a > 0)
    {
        steps.push_back("empty B");
        if (dfs(Ca, Cb, N, a, 0, visited, steps))
            return true;
        steps.pop_back();
    }

    // Pour A to B
    if (a > 0 && b < Cb)
    {
        int pour = min(a, Cb - b);
        steps.push_back("pour A B");
        if (dfs(Ca, Cb, N, a - pour, b + pour, visited, steps))
            return true;
        steps.pop_back();
    }

    // Pour B to A
    if (b > 0 && a < Ca)
    {
        int pour = min(b, Ca - a);
        steps.push_back("pour B A");
        if (dfs(Ca, Cb, N, a + pour, b - pour, visited, steps))
            return true;
        steps.pop_back();
    }

    return false;
}

void LetsDoIt()
{
    int Ca, Cb, N;
    while (cin >> Ca >> Cb >> N)
    {
        vector<string> steps;
        unordered_set<string> visited;
        dfs(Ca, Cb, N, 0, 0, visited, steps);
        for (const string &step : steps)
        {
            cout << step << endl;
        }
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
