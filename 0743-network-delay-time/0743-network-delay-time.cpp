class Solution {
public:
    vector<vector<pair<int, int>>> g;
    vector<int> vis;
    vector<int> dist;

    void dijkstra(int source) {
        set<pair<int, int>> s;
        s.insert({0, source});
        dist[source] = 0;

        while (!s.empty()) {
            auto node = *s.begin();
            int v = node.second;
            int v_dist = node.first;
            s.erase(s.begin());  

            if (vis[v]) continue;
            vis[v] = 1;

            for (auto& i : g[v]) {
                int v_child = i.first;
                int wt = i.second;

                if (wt + dist[v] < dist[v_child]) {
                    dist[v_child] = wt + dist[v];
                    s.insert({dist[v_child], v_child});
                }
            }
        }
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        g.assign(n + 1, vector<pair<int, int>>());
        vis.assign(n + 1, 0);
        dist.assign(n + 1, 1e9);

        for (auto& i : times) {
            g[i[0]].push_back({i[1], i[2]});
        }

        dijkstra(k);

        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (dist[i] == 1e9) return -1;
            ans = max(ans, dist[i]);
        }

        return ans;
    }
};