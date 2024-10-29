class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
       vector<pair<int, int>> possibleDirections = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,-1},{-1,1}};
        int n = grid.size();
        if(grid[0][0] != 0 || grid[n-1][n-1] != 0) return -1;
        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1; 
        while (!q.empty()) {
            pair<int, int> currentCoords = q.front();
            q.pop();
            int row = currentCoords.first;
            int col = currentCoords.second;
            int distance = grid[row][col];
            if (row == n-1 && col == n-1) {
                return distance;
            }
            for (auto dir : possibleDirections) {
                int dr = dir.first;
                int dc = dir.second;
                int nr = row + dr;
                int nc = col + dc;
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0) {
                    q.push({nr, nc});
                    grid[nr][nc] = distance + 1; 
                }
            }
        }
        return -1;
    }
};