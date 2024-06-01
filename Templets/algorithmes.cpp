#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

// بيانات الجراف
const int MAX = 1005;
vector<pair<int, int>> adj[MAX]; // قائمة الجوار

// خوارزمية البحث في العمق
void DFS(int node, vector<bool> &visited)
{
    visited[node] = true;
    cout << node << " ";

    for (auto neighbor : adj[node])
    {
        int nextNode = neighbor.first;
        if (!visited[nextNode])
        {
            DFS(nextNode, visited);
        }
    }
}

// خوارزمية البحث في العرض
void BFS(int start)
{
    vector<bool> visited(MAX, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (auto neighbor : adj[node])
        {
            int nextNode = neighbor.first;
            if (!visited[nextNode])
            {
                q.push(nextNode);
                visited[nextNode] = true;
            }
        }
    }
}

// خوارزمية Dijkstra
void Dijkstra(int start)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(MAX, INT_MAX);
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        int node = pq.top().second;
        int distance = pq.top().first;
        pq.pop();

        for (auto neighbor : adj[node])
        {
            int nextNode = neighbor.first;
            int weight = neighbor.second;

            if (dist[nextNode] > dist[node] + weight)
            {
                dist[nextNode] = dist[node] + weight;
                pq.push({dist[nextNode], nextNode});
            }
        }
    }
}

// خوارزمية Bellman-Ford
bool BellmanFord(int start, int n)
{
    vector<int> dist(MAX, INT_MAX);
    dist[start] = 0;

    for (int i = 1; i <= n - 1; ++i)
    {
        for (int u = 1; u <= n; ++u)
        {
            for (auto neighbor : adj[u])
            {
                int v = neighbor.first;
                int weight = neighbor.second;
                if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                {
                    dist[v] = dist[u] + weight;
                }
            }
        }
    }

    // التحقق من وجود دورات سالبة
    for (int u = 1; u <= n; ++u)
    {
        for (auto neighbor : adj[u])
        {
            int v = neighbor.first;
            int weight = neighbor.second;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
            {
                return false; // يوجد دورة سالبة
            }
        }
    }
    return true; // لا يوجد دورات سالبة
}

// خوارزمية Floyd-Warshall
void FloydWarshall(int n)
{
    vector<vector<int>> dist(MAX, vector<int>(MAX, INT_MAX));

    // تعيين الأوزان المبدئية
    for (int u = 1; u <= n; ++u)
    {
        dist[u][u] = 0;
        for (auto neighbor : adj[u])
        {
            int v = neighbor.first;
            int weight = neighbor.second;
            dist[u][v] = weight;
        }
    }

    // خوارزمية الأساس
    for (int k = 1; k <= n; ++k)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX &&
                    dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

int main()
{
    // مثال لاضافة الأضلاع في الجراف
    adj[1].push_back({2, 5});
    adj[1].push_back({3, 3});
    adj[2].push_back({3, 2});
    adj[2].push_back({4, 6});
    adj[3].push_back({4, 7});

    // مثال لاستخدام الخوارزميات
    cout << "DFS: ";
    vector<bool> visited(MAX, false);
    DFS(1, visited);
    cout << endl;

    cout << "BFS: ";
    BFS(1);
    cout << endl;

    cout << "Dijkstra: ";
    Dijkstra(1);
    cout << endl;

    cout << "Bellman-Ford (Negative Cycle?): ";
    if (BellmanFord(1, 4))
    {
        cout << "No";
    }
    else
    {
        cout << "Yes";
    }
    cout << endl;

    cout << "Floyd-Warshall: ";
    FloydWarshall(4);
    // اطبع النتيجة هنا
    return 0;
}
