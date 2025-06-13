class Solution {
public:
    int numDistinct(string s, string t) {
        const int MOD = 1e9 + 7;
        int n = s.length();
        int m = t.length();
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));

        for (int i = 0; i <= n; i++) {
            dp[i][m] = 1;  
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                long long inc = 0;
                if (s[i] == t[j]) {
                    inc = dp[i + 1][j + 1];  
                }
                long long exc = dp[i + 1][j];  
                dp[i][j] = (inc + exc) % MOD;
            }
        }

        return static_cast<int>(dp[0][0]);
    }
};