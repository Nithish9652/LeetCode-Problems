class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int b1 = -1, b2 = -1, w1 = -1, w2 = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    b1 = i;
                    break;
                }
            }
            if (b1 != -1) break;
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    b2 = i;
                    break;
                }
            }
            if (b2 != -1) break;
        }
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                if (grid[i][j] == 1) {
                    w1 = j;
                    break;
                }
            }
            if (w1 != -1) break;
        }
        for (int j = m - 1; j >= 0; j--) {
            for (int i = 0; i < n; i++) {
                if (grid[i][j] == 1) {
                    w2 = j;
                    break;
                }
            }
            if (w2 != -1) break;
        }
        int ans = (abs(b2 - b1) + 1) * (abs(w2 - w1) + 1);
        return ans;
    }
};