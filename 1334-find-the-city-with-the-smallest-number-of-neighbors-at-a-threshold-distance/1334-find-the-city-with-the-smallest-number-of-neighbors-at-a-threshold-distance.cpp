class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        const int INF = 1e9;
        
        // Create distance matrix
        vector<vector<int>> dist(n, vector<int>(n, INF));
        for(int i = 0; i < n; i++) dist[i][i] = 0;

        // Fill initial edges
        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            dist[u][v] = dist[v][u] = w;
        }

        // Floyd-Warshall
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        // Count reachable cities for each city
        int result = -1, bestCount = 1e9;
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && dist[i][j] <= distanceThreshold)
                    count++;
            }
            // choose city with smaller count, tie → choose larger index
            if (count <= bestCount) {
                bestCount = count;
                result = i;
            }
        }

        return result;
    }
};
