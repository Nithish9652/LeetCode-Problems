class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> g(n+1);
        for (auto &r : roads) {
            int a = r[0], b = r[1], w = r[2];
            g[a].push_back({b, w});
            g[b].push_back({a, w});
        }

        vector<int> vis(n+1, 0);
        queue<int> q;
        q.push(1);
        vis[1] = 1;

        int ans = INT_MAX;

        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (auto &p : g[u]) {
                int v = p.first, w = p.second;
                ans = min(ans, w);      // track smallest edge seen in component of 1
                if (!vis[v]) {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }

        return ans;
    }
};
