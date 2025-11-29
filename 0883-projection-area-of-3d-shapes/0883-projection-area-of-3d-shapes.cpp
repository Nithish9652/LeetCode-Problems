class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int xy = 0, yz = 0, zx = 0;

        for(int i = 0; i < n; i++) {
            int maxRow = 0;
            int maxCol = 0;
            for(int j = 0; j < n; j++) {
                if(grid[i][j] > 0) xy++;          // top view
                maxRow = max(maxRow, grid[i][j]); // front view
                maxCol = max(maxCol, grid[j][i]); // side view
            }
            yz += maxRow;
            zx += maxCol;
        }

        return xy + yz + zx;
    }
};
