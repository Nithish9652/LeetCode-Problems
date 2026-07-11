class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> vis(n, 0);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                vector<int> comp;
                dfs(i, adj, vis, comp);

                int nodes = comp.size();
                int edgesInside = 0;

                // count edges inside this component
                for (int u : comp)
                    edgesInside += adj[u].size();

                edgesInside /= 2; // because edges counted twice

                if (edgesInside == (nodes * (nodes - 1)) / 2)
                    ans++;
            }
        }

        return ans;
    }

    void dfs(int u, vector<vector<int>>& adj, vector<int>& vis, vector<int>& comp) {
        vis[u] = 1;
        comp.push_back(u);
        for (int v : adj[u])
            if (!vis[v])
                dfs(v, adj, vis, comp);
    }
};
