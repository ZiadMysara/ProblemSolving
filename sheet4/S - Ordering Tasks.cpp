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

int add(const int &a, const int &b, int MOD)
{
    return (a + b + 2 * MOD) % MOD;
}
void topologicalSort(vector<vector<int>> &graph, vector<int> &indegree, int n)
{
    queue<int> q;
    vector<int> order;

    // Finding tasks with no dependencies
    for (int i = 1; i <= n; ++i)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    // Performing topological sort
    while (!q.empty())
    {
        int task = q.front();
        q.pop();
        order.push_back(task);

        // Updating dependencies of adjacent tasks
        for (int dependentTask : graph[task])
        {
            indegree[dependentTask]--;
            if (indegree[dependentTask] == 0)
                q.push(dependentTask);
        }
    }

    // Outputting the order of execution
    for (int i = 0; i < n; ++i)
    {
        cout << order[i];
        if (i < n - 1)
            cout << " ";
    }
    cout << endl;
}   
void LetsDoIt()
{
    int numTasks, numRelations;
    cin >> numTasks >> numRelations;
    while (!(numTasks == 0 && numRelations == 0))
    {
        vector<vector<int>> graph(numTasks + 1);
        vector<int> indegree(numTasks + 1, 0);

        // Building the task dependency graph
        for (int i = 0; i < numRelations; ++i)
        {
            int precedingTask, dependentTask;
            cin >> precedingTask >> dependentTask;
            graph[precedingTask].push_back(dependentTask);
            indegree[dependentTask]++;
        }

        // Finding the order of execution
        topologicalSort(graph, indegree, numTasks);
        cin >> numTasks >> numRelations;
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
