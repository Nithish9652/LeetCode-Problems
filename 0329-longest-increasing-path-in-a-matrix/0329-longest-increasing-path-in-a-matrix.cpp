class Solution {
public:
    int dp[201][201], add[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int n, m;
    vector<vector<int>> grid;
    inline bool check(int i, int j) {
        return i >= 0 && i < n && j >= 0 && j < m;
    }
    int rec(int x, int y) {
        if (!check(x, y))
            return 0;
        if (dp[x][y] != -1)
            return dp[x][y];
        int x1, y1, ans = 1;
        for (auto i : add) {
            x1 = x + i[0];
            y1 = y + i[1];
            if (check(x1, y1) && grid[x1][y1] > grid[x][y]) {
                ans = max(ans, 1 + rec(x1, y1));
            }
        }
        dp[x][y] = ans;
        return ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        grid = matrix;
        memset(dp, -1, sizeof(dp));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                ans=max(ans,rec(i,j));
        }
        return ans;
    }
};