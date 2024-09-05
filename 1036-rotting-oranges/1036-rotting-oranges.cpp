class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<bool> vis(rows * cols, false);
        vector<vector<int>> adj(rows * cols);
        queue<pair<int, int>> q;
        int fresh = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                    vis[i * cols + j] = true;
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
                if (i > 0 && grid[i-1][j] != 0) adj[i * cols + j].push_back((i-1) * cols + j);  
                if (i < rows - 1 && grid[i+1][j] != 0) adj[i * cols + j].push_back((i+1) * cols + j);  
                if (j > 0 && grid[i][j-1] != 0) adj[i * cols + j].push_back(i * cols + (j-1));  
                if (j < cols - 1 && grid[i][j+1] != 0) adj[i * cols + j].push_back(i * cols + (j+1)); 
            }
        }
        if (fresh == 0) return 0;  
        int minutes = -1;
        while (!q.empty()) {
            int size = q.size();
            minutes++;
            while (size--) {
                auto [x, y] = q.front();
                q.pop();
                int node = x * cols + y;
                for (int neighbor : adj[node]) {
                    int nx = neighbor / cols;
                    int ny = neighbor % cols;
                    if (!vis[neighbor] && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        q.push({nx, ny});
                        vis[neighbor] = true;
                        fresh--;
                    }
                }
            }
        }
        return fresh == 0 ? minutes : -1;
    }
};
