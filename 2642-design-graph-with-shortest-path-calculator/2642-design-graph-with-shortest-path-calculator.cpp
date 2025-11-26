class Graph {
public:
    int n;
    vector<vector<pair<int,int>>> adj;

    Graph(int n, vector<vector<int>>& edges) {
        this->n = n;
        adj.resize(n);
        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
        }
    }

    void addEdge(vector<int> edge) {
        int u = edge[0], v = edge[1], w = edge[2];
        adj[u].push_back({v, w});
    }

    int shortestPath(int node1, int node2) {
        const int INF = 1e9;
        vector<int> dist(n, INF);
        dist[node1] = 0;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, node1});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u]) continue;
            if (u == node2) return d;

            for (auto &p : adj[u]) {
                int v = p.first, w = p.second;
                if (dist[v] > d + w) {
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }

        return -1;
    }
};