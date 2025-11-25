class Solution {
public:
    vector<vector<pair<int,int>>> g;  // node -> [(neighbor, time)]
    vector<int> values;
    int maxTime, best = 0;
    vector<int> visited;

    void dfs(int u, int timeUsed, int score) {
        if (timeUsed > maxTime) return;

        if (u == 0)
            best = max(best, score);

        for (auto &p : g[u]) {
            int v = p.first, t = p.second;

            bool firstVisit = (visited[v] == 0);
            if (firstVisit) score += values[v];
            visited[v]++;

            dfs(v, timeUsed + t, score);

            visited[v]--;
            if (firstVisit) score -= values[v];
        }
    }

    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        this->values = values;
        this->maxTime = maxTime;

        int n = values.size();
        g.assign(n, {});
        visited.assign(n, 0);

        for (auto &e : edges) {
            int u = e[0], v = e[1], t = e[2];
            g[u].push_back({v, t});
            g[v].push_back({u, t});
        }

        visited[0] = 1;
        dfs(0, 0, values[0]);

        return best;
    }
};
