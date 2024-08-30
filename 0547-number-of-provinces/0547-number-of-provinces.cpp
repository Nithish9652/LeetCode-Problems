class Solution {
public:
    void dfs(int node, vector<int>& vis, vector<int> adj[]) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, vis, adj);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<int> vis(n, 0);
        vector<int> adj[n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && arr[i][j] == 1) {
                    adj[i].push_back(j);
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                ans++;
                dfs(i, vis, adj);
            }
        }

        return ans;
    }
};
