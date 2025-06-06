class Solution {
public:
    vector<vector<int>> adj;
    vector<array<int, 26>> freq;
    vector<bool> vis, cycle;
    int dfs(int u, string& colors) {
        if (cycle[u]) return INT_MAX;
        if (vis[u]) return freq[u][colors[u]-'a'];

        vis[u]=cycle[u]=1;
        for (int v : adj[u]) {
            if (dfs(v, colors)==INT_MAX) 
                return INT_MAX;
            for (int i=0; i<26; i++)
                freq[u][i] = max(freq[u][i], freq[v][i]);
        }
        cycle[u]=0;
        return ++freq[u][colors[u]-'a']; 
    }

    int largestPathValue(string& colors, vector<vector<int>>& edges) {
        const int n=colors.size();
        adj.resize(n);
        freq.resize(n);
        for (auto& e : edges) 
            adj[e[0]].push_back(e[1]);

        int ans=0;
        vis.assign(n, 0);
        cycle.assign(n, 0);
        for (int i=0; i<n; i++) 
            ans= max(ans, dfs(i, colors));

        return ans==INT_MAX?-1:ans;
    }
};