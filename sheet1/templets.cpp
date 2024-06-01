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

//================================
//********************************
//              DFS
//********************************
//================================
// problem Is it a tree or not
//================================
class Graph
{
    int N, M;
    vector<vector<int>> adj;
    vector<bool> visited;

public:
    Graph(int n, int m) : N(n), M(m), adj(n), visited(n, false) {}

    void addEdge(int u, int v)
    {
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }

    bool dfs(int node, int parent)
    {
        visited[node] = true;
        for (int neighbor : adj[node])
        {
            if (!visited[neighbor])
            {
                if (!dfs(neighbor, node))
                {
                    return false;
                }
            }
            else if (neighbor != parent)
            {
                return false; // Cycle detected
            }
        }
        return true;
    }

    bool isTree()
    {
        if (M != N - 1)
            return false; // Condition for tree: exactly N-1 edges
        if (!dfs(0, -1))
            return false; // Check for cycles and connectivity
        for (bool visit : visited)
        {
            if (!visit)
                return false; // Check if all nodes are visited
        }
        return true;
    }

    int main()
    {
        int N, M;
        cin >> N >> M;
        Graph graph(N, M);

        for (int i = 0; i < M; ++i)
        {
            int u, v;
            cin >> u >> v;
            graph.addEdge(u, v);
        }

        cout << (graph.isTree() ? "YES" : "NO") << endl;
        return 0;
    }
};

//================================
//********************************
//          DFS with stack
//********************************
//================================
class DFS_With_Stack
{
    bool dfs(int node, vector<bool> &visited, vector<vector<int>> &graph)
    {
        stack<int> stk;
        stk.push(node);
        visited[node] = true;

        while (!stk.empty())
        {
            int curr = stk.top();
            stk.pop();

            for (int neighbor : graph[curr])
            {
                if (!visited[neighbor])
                {
                    stk.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }

        return true;
    }
};

//================================
//********************************
//      normal DFS algorithm
//********************************
//================================
class normal_DFS_algorithm
{
    vector<vector<int>> adj;
    void dfs(int node, int parent, int depth = 0)
    {
        for (int i = 0; i < adj[node].size(); ++i)
        {
            int child = adj[node].at(i);
            if (child != parent)
            {
                dfs(child, node, depth + 1);
            }
        }
    }
};

//================================
//********************************
//      Strange DFS algorithm
//********************************
//================================
class Strange_DFS_algorithm
{
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
};

//================================
//********************************
//  BFS algorithm shortest path
//********************************
//================================
class BFS_algorithm
{
    int N = 64;
    vector<vector<int>> adj = vector<vector<int>>(N);
    int shortestPath(int src, int dest)
    {
        // this is like bool visited in DFS but here we use distance so we can know the shortest path
        // so by use this we know 2 informations
        // the first one is the node visited or not
        // the second one is the distance from the source node
        vector<int> dist(N, INT_MAX);

        queue<int> q;
        q.push(src);
        dist[src] = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (int child : adj[node])
            {
                if (dist[child] == INT_MAX)
                {
                    dist[child] = dist[node] + 1;
                    q.push(child);
                    if (child == dest)
                        return dist[dest];
                }
            }
        }
        return dist[dest];
    }
};

//================================
//********************************
//  Dijkstra's Algorithm: Shortest Path
//********************************
//================================
class Dijkstra_Algorithm
{
    int N = 64;
    vector<vector<pair<int, int>>> adj = vector<vector<pair<int, int>>>(N);
    int shortestPath(int src, int dest)
    {
        vector<int> dist(N, INT_MAX);
        dist[src] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});
        while (!pq.empty())
        {
            int node = pq.top().second;
            int d = pq.top().first;
            pq.pop();
            if (d > dist[node])
                continue;
            for (pair<int, int> edge : adj[node])
            {
                int child = edge.first;
                int weight = edge.second;
                if (dist[child] > dist[node] + weight)
                {
                    dist[child] = dist[node] + weight;
                    pq.push({dist[child], child});
                }
            }
        }
        return dist[dest];
    }
};

//================================
//********************************
//  Dijkstra_Algorithm_Shorted_Path
//********************************
//================================

class Dijkstra_Algorithm_Shorted_Path
{

    class Dijkstra
    {
        const int INF = 1e9; // قيمة لا نهائية للمسافة // global variable
    private:
        int n;                                // عدد العقد
        vector<vector<pair<int, int>>> graph; // قائمة الجيران (حواف الجراف) // A: {5:B, 3:C} like this
        vector<int> dist;                     // مصفوفة لتخزين المسافات // A:5 , B:3 , C:2 like this

    public:
        // Constructor يستقبل عدد العقد ويهيئ البيانات
        Dijkstra(int nodes) : n(nodes), graph(nodes), dist(nodes, INF) {}

        // إضافة حافة جديدة بين عقدتين مع وزن
        void addEdge(int u, int v, int weight)
        {
            graph[u].push_back({v, weight}); // إضافة الحافة من u إلى v بوزن weight
        }

        // حساب أقصر مسارات من العقدة المعطاة
        void shortestPath(int src)
        {
            // p have type of pair<int,int> and the first element is the distance and the second element is the node
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            dist[src] = 0;
            pq.push({0, src});

            while (!pq.empty())
            {
                // d : weight, (u or v) : node,  dist[u] : the distance from the source node to the node u
                int Wpq_Parent = pq.top().first;
                int Vpq_Parent = pq.top().second;
                pq.pop();

                if (Wpq_Parent > dist[Vpq_Parent])
                    continue;

                for (pair<int, int> &childEdges : graph[Vpq_Parent])
                {
                    int vg_child = childEdges.first;
                    int wg_child = childEdges.second;

                    if (dist[Vpq_Parent] + wg_child < dist[vg_child])
                    {
                        dist[vg_child] = dist[Vpq_Parent] + wg_child;
                        pq.push({dist[vg_child], vg_child});
                    }
                }
            }
        }

        // طباعة المسافات من العقدة المعطاة إلى كل العقد الآخر
        void printDistances(int src)
        {
            for (int i = 0; i < n; i++)
            {
                cout << "Distance from node " << src << " to node " << i << " is " << dist[i] << endl;
            }
        }
    };

    int main()
    {
        int n = 5;         // عدد العقد
        Dijkstra graph(n); // إنشاء كائن من الصنف Dijkstra

        // إضافة الحواف
        graph.addEdge(0, 1, 10);
        graph.addEdge(0, 4, 3);
        graph.addEdge(1, 2, 2);
        graph.addEdge(2, 3, 9);
        graph.addEdge(4, 2, 1);
        graph.addEdge(4, 1, 4);

        int src = 0;               // المصدر
        graph.shortestPath(src);   // حساب أقصر مسارات
        graph.printDistances(src); // طباعة المسافات

        return 0;
    }
};
//================================
//********************************
//  Dijsktra Algorithm print path
//********************************
//================================
class DijsktraAlgorithmPrintPath
{
    typedef pair<int, int> pii;

    vector<int> dijkstra(vector<vector<pii>> &graph, int n)
    {
        // cost to reach node i
        vector<int> dist(n + 1, INT_MAX);
        priority_queue<pii, vector<pii>, greater<pii>> pq;

        dist[1] = 0;
        pq.push({0, 1});

        while (!pq.empty())
        {
            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();

            if (d > dist[u])
                continue; // Skip outdated pairs

            for (auto &edge : graph[u])
            {
                int v = edge.first;
                int w = edge.second;

                if (dist[v] > dist[u] + w)
                {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist;
    }

    int main()
    {
        int n, m;
        cin >> n >> m;

        vector<vector<pii>> graph(n + 1);
        for (int i = 0; i < m; ++i)
        {
            int a, b, w;
            cin >> a >> b >> w;
            graph[a].push_back({b, w});
            graph[b].push_back({a, w}); // Undirected graph
        }

        vector<int> dist = dijkstra(graph, n);

        if (dist[n] == INT_MAX)
        {
            cout << -1 << endl;
        }
        else
        {
            vector<int> path;
            int current = n;

            while (current != 1)
            {
                path.push_back(current);
                for (auto &edge : graph[current])
                {
                    int prev = edge.first;
                    int weight = edge.second;
                    if (dist[current] == dist[prev] + weight)
                    {
                        current = prev;
                        break;
                    }
                }
            }
            path.push_back(1);

            // Print the path in reverse order
            for (int i = path.size() - 1; i >= 0; --i)
            {
                cout << path[i] << " ";
            }
            cout << endl;
        }

        return 0;
    }
};

//================================
//********************************
// Dijsktra Algorithm print path using parent
//********************************
//================================
class Dikstra_parent
{

    struct Edge
    {
        int to, weight;
        Edge(int to, int weight) : to(to), weight(weight) {}
    };

    class Dijkstra
    {
    private:
        int n;
        unordered_map<int, vector<Edge>> graph;
        vector<int> dist;
        vector<int> parent;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    public:
        Dijkstra(int n) : n(n), dist(n + 1, INT_MAX), parent(n + 1, -1) {}

        void addEdge(int u, int v, int w)
        {
            graph[u].emplace_back(v, w);
            graph[v].emplace_back(u, w);
        }

        void shortestPath()
        {
            dist[1] = 0;
            pq.emplace(0, 1);
            while (!pq.empty())
            {
                int Wpq = pq.top().first;
                int Vpq = pq.top().second;
                pq.pop();
                if (Wpq > dist[Vpq])
                {
                    continue;
                }
                for (const auto &edge : graph[Vpq])
                {
                    int Vgrph = edge.to;
                    int Wgrph = edge.weight;
                    if (dist[Vgrph] > dist[Vpq] + Wgrph)
                    {
                        dist[Vgrph] = dist[Vpq] + Wgrph;
                        parent[Vgrph] = Vpq; // Track the parent
                        pq.emplace(dist[Vgrph], Vgrph);
                    }
                }
            }
        }

        void printShortestPath()
        {
            if (dist[n] == INT_MAX)
            {
                cout << -1 << endl;
                return;
            }

            vector<int> path;
            for (int i = n; i != -1; i = parent[i])
            {
                path.push_back(i);
            }
            reverse(path.begin(), path.end());

            for (const int node : path)
            {
                cout << node << " ";
            }
            cout << endl;
        }

        void run()
        {
            shortestPath();
            printShortestPath();
        }
    };

    void solve()
    {
        int n, m;
        cin >> n >> m;
        Dijkstra dijkstra(n);
        for (int i = 0; i < m; ++i)
        {
            int u, v, w;
            cin >> u >> v >> w;
            dijkstra.addEdge(u, v, w);
        }
        dijkstra.run();
    }

    int main()
    {
        fast;
        solve();
        return 0;
    }
};

//================================
//********************************
//  Dijkstra's Algorithm
//********************************
//================================
class Dijkstra_Algorithm2
{

    // Define infinity as a large number
    const int INF = numeric_limits<int>::max();

    // Dijkstra's algorithm to find the shortest path from a source node to all other nodes
    void dijkstra(const vector<vector<pair<int, int>>> &graph, int source)
    {
        int n = graph.size();     // Number of nodes
        vector<int> dist(n, INF); // Distance from source to each node, initialized to infinity
        dist[source] = 0;         // Distance to the source itself is 0

        // Priority queue to process nodes with the shortest known distance first
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, source});

        while (!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();

            // Relaxation step for all adjacent nodes
            for (const auto &neighbor : graph[u])
            {
                int v = neighbor.first;
                int weight = neighbor.second;

                // If a shorter path to v is found
                if (dist[u] + weight < dist[v])
                {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        // Print the shortest distances from the source to all other nodes
        for (int i = 0; i < n; ++i)
        {
            if (dist[i] == INF)
                cout << "INF ";
            else
                cout << dist[i] << " ";
        }
        cout << endl;
    }

    int main()
    {
        int n = 5;
        vector<vector<pair<int, int>>> graph(n);
        graph[0].emplace_back(1, 10);
        graph[0].emplace_back(4, 3);
        graph[1].emplace_back(2, 2);
        graph[1].emplace_back(4, 4);
        graph[2].emplace_back(3, 9);
        graph[3].emplace_back(2, 7);
        graph[4].emplace_back(1, 1);
        graph[4].emplace_back(2, 8);
        graph[4].emplace_back(3, 2);

        // Run Dijkstra's algorithm from node 0
        dijkstra(graph, 0);

        return 0;
    }
};

//================================
//********************************
//  Bellman-Ford Algorithm
//********************************
//================================
class Bellmen_Ford
{

    const int INF = numeric_limits<int>::max();

    struct Edge
    {
        int source, destination, weight;
    };

    // Bellman-Ford algorithm to find the shortest path from a source node to all other nodes
    void bellmanFord(const vector<Edge> &edges, int n, int source)
    {
        vector<int> dist(n, INF); // Distance from source to each node, initialized to infinity
        dist[source] = 0;         // Distance to the source itself is 0

        // Relax edges up to (n-1) times
        for (int i = 1; i <= n - 1; ++i)
        {
            for (const auto &edge : edges)
            {
                if (dist[edge.source] != INF && dist[edge.source] + edge.weight < dist[edge.destination])
                {
                    dist[edge.destination] = dist[edge.source] + edge.weight;
                }
            }
        }

        // Check for negative weight cycles
        for (const auto &edge : edges)
        {
            if (dist[edge.source] != INF && dist[edge.source] + edge.weight < dist[edge.destination])
            {
                cout << "Graph contains a negative weight cycle" << endl;
                return;
            }
        }

        // Print the shortest distances from the source to all other nodes
        for (int i = 0; i < n; ++i)
        {
            if (dist[i] == INF)
                cout << "INF ";
            else
                cout << dist[i] << " ";
        }
        cout << endl;
    }

    int main()
    {
        int n = 5;
        vector<Edge> edges = {
            {0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2}, {1, 4, 2}, {3, 2, 5}, {3, 1, 1}, {4, 3, -3}};

        // Run Bellman-Ford algorithm from node 0
        bellmanFord(edges, n, 0);

        return 0;
    }
};

//================================
//********************************
//  Bellman-Ford Algorithm2
//********************************
//================================
class Bellmen_Ford2
{

    class Graph
    {
        struct Edge
        {
            int source, destination, weight;
        };

        int V, E;           // number of vertices and edges
        vector<Edge> edges; // قائمة بجميع الحواف في الرسم البياني

    public:
        // Constructor to initialize the graph with V vertices and E edges
        Graph(int V, int E) : V(V), E(E) {}

        // Function to add an edge to the graph
        void addEdge(int source, int destination, int weight)
        {
            Edge edge;
            edge.source = source;
            edge.destination = destination;
            edge.weight = weight;
            edges.push_back(edge);
        }

        // Bellman-Ford algorithm implementation
        void bellmanFord(int source)
        {
            // Initialize distances from source to all other vertices as infinite
            vector<int> distance(V, numeric_limits<int>::max());
            // Distance from source to itself is 0
            distance[source] = 0;

            // Relax all edges V-1 times
            // This loop is executed V-1 times because the shortest path in a graph with V vertices contains at most V-1 edges
            for (int i = 0; i < V - 1; ++i)
            {
                // Iterate over all edges
                for (const auto &edge : edges)
                {
                    int u = edge.source;
                    int v = edge.destination;
                    int w = edge.weight;
                    // Relaxation step: update distance if a shorter path is found
                    // If the distance to vertex u plus the weight of the edge (u, v) is less than the current distance to vertex v,
                    // update the distance to vertex v with the new shorter distance
                    if (distance[u] != numeric_limits<int>::max() && distance[u] + w < distance[v])
                    {
                        distance[v] = distance[u] + w;
                    }
                }
            }

            // Check for negative-weight cycles
            // After V-1 iterations, if there's still a shorter path, it means there's a negative-weight cycle
            for (const auto &edge : edges)
            {
                int u = edge.source;
                int v = edge.destination;
                int w = edge.weight;
                // If relaxation is possible, then a negative cycle exists
                if (distance[u] != numeric_limits<int>::max() && distance[u] + w < distance[v])
                {
                    cout << "Graph contains negative weight cycle\n";
                    return;
                }
            }

            // Print shortest distances from source
            cout << "Vertex   Distance from Source\n";
            for (int i = 0; i < V; ++i)
            {
                cout << i << "\t\t" << distance[i] << "\n";
            }
        }
    };

    int main()
    {
        int V, E;
        cout << "Enter the number of vertices and edges: ";
        cin >> V >> E;

        Graph graph(V, E);

        cout << "Enter the source, destination, and weight of each edge:\n";
        for (int i = 0; i < E; ++i)
        {
            int source, destination, weight;
            cin >> source >> destination >> weight;
            graph.addEdge(source, destination, weight);
        }

        int source;
        cout << "Enter the source vertex: ";
        cin >> source;

        // Run Bellman-Ford algorithm from the given source vertex
        graph.bellmanFord(source);

        return 0;
    }
};

//================================
//********************************
//  Floyd-Warshall Algorithm
//********************************
//================================
class Floyd_Warshall_Algorithm
{

    const int INF = numeric_limits<int>::max();

    // Floyd-Warshall algorithm to find the shortest path between all pairs of nodes
    void floydWarshall(vector<vector<int>> &graph)
    {
        int n = graph.size();             // Number of nodes
        vector<vector<int>> dist = graph; // Distance matrix, initialized to the graph's weights

        // Update the distance matrix with the shortest distances
        for (int k = 0; k < n; ++k)
        {
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    // If a shorter path through node k is found
                    if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j])
                    {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        // Print the shortest distances between all pairs of nodes
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (dist[i][j] == INF)
                    cout << "INF ";
                else
                    cout << dist[i][j] << " ";
            }
            cout << endl;
        }
    }

    int main()
    {
        int n = 4;
        vector<vector<int>> graph = {
            {0, 3, INF, 7},
            {8, 0, 2, INF},
            {5, INF, 0, 1},
            {2, INF, INF, 0}};

        // Run Floyd-Warshall algorithm
        floydWarshall(graph);

        return 0;
    }
};

//================================
//********************************
//  Dinamic Programming
//      Max Dollars
//********************************
//================================
class DinamicPrograming
{

    unordered_map<int, long long> dp;

    long long max_dollars(int n)
    {
        if (n == 0)
            return 0;
        if (dp.find(n) != dp.end())
            return dp[n];

        long long dollars = max((long long)n, max_dollars(n / 2) + max_dollars(n / 3) + max_dollars(n / 4));
        dp[n] = dollars;
        return dollars;
    }

    int main()
    {
        int n;
        while (cin >> n)
        {
            cout << max_dollars(n) << endl;
        }
        return 0;
    }
};
//================================
//********************************
//      Dinamic Programming
//      Max Coins
//********************************
//================================
class DinamicPrograming2
{
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
        // cin >> t;
        while (t--)
        {
            LetsDoIt(t);
        }
        return 0;
    }
};

//================================
//********************************
//  Knapsack Algorithm
//********************************
//================================
class KnapsackAlgorithm
{
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

    int main()
    {
        // S: knapsack size, N: number of items
        int S, N;
        cin >> S >> N;

        vector<int> sizes(N + 1), values(N + 1);
        for (int i = 1; i <= N; ++i)
        {
            cin >> sizes[i] >> values[i];
        }

        cout << knapsack(S, N, sizes, values) << endl;
        return 0;
    }
};

//================================
//********************************
//         Eulerian Path
//********************************
//================================
class EulerianPath
{
    // Check if the graph has an Eulerian path
    bool hasEulerianPath(const vector<vector<int>> &adj)
    {
        int n = adj.size();
        int startNodes = 0, endNodes = 0;

        for (int i = 0; i < n; ++i)
        {
            int diff = adj[i].size() - (i == 0 ? 1 : 0);
            if (diff > 1 || diff < -1)
                return false;
            if (diff == 1)
                startNodes++;
            if (diff == -1)
                endNodes++;
        }

        return (startNodes == 0 && endNodes == 0) || (startNodes == 1 && endNodes == 1);
    }

    int main()
    {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> adj(n);
        for (int i = 0; i < m; ++i)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cout << (hasEulerianPath(adj) ? "YES" : "NO") << endl;
        return 0;
    }
};