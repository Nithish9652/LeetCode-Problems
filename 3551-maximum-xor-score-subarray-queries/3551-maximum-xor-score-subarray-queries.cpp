class Solution {
public:
    vector<int> maximumSubarrayXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));  
        vector<vector<int>> mx(n, vector<int>(n, 0));

        for (int i = n - 1; i >= 0; --i) {
            dp[i][i] = mx[i][i] = nums[i];
            for (int j = i + 1; j < n; ++j) {
                dp[i][j] = dp[i][j - 1] ^ dp[i + 1][j];
                mx[i][j] = max({dp[i][j], mx[i + 1][j], mx[i][j - 1]});
            }
        }

        vector<int> res;
        for (auto& q : queries) {
            int l = q[0], r = q[1];
            res.push_back(mx[l][r]);
        }

        return res;
    }
};