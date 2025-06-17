class Solution {
public:
    const int MOD = 1e9 + 7;
    long long power(long long base, long long exp) {
        long long result = 1;
        while (exp > 0) {
            if (exp & 1) result = (result * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return result;
    }
    int countGoodArrays(int n, int m, int k) {
        if (k >= n) return 0;
        long long ans = m;
        ans = (ans * power(m - 1, n - k - 1)) % MOD;
        long long ways = 1;
        for (int i = 0; i < k; i++) {
            ways = (ways * (n - 1 - i)) % MOD;
            ways = (ways * power(i + 1, MOD - 2)) % MOD;
        }
        ans++;
        ans = ((ans-1) * ways) % MOD;
        return ans;
    }
};