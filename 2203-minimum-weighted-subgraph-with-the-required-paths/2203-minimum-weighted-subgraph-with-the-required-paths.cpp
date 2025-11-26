class Solution {
public:
    using ll = long long;
    const ll INF = 1e18;

    vector<ll> dijkstra(int start, vector<vector<pair<int,int>>> &g, int n) {
        vector<ll> dist(n, INF);
        priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;

        dist[start] = 1;
        dist[start] = 0;
        pq.push({0, start});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (d > dist[u]) continue;

            for (auto &p : g[u]) {
                int v = p.first;
                ll w = p.second;
                if (dist[v] > d + w) {
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    }

    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {

        vector<vector<pair<int,int>>> g(n), rg(n);

        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            g[u].push_back({v, w});
            rg[v].push_back({u, w}); // reverse graph
        }

        vector<ll> d1 = dijkstra(src1, g, n);
        vector<ll> d2 = dijkstra(src2, g, n);
        vector<ll> dr = dijkstra(dest, rg, n); // reversed

        ll ans = INF;

        for (int i = 0; i < n; i++) {
            if (d1[i] == INF || d2[i] == INF || dr[i] == INF) continue;
            ans = min(ans, d1[i] + d2[i] + dr[i]);
        }

        return ans == INF ? -1 : ans;
    }
};