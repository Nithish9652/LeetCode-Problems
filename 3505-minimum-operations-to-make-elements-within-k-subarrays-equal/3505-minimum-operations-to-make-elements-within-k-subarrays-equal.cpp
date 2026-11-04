#define ll long long

class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        multiset<int> left, right;
        ll Lsum = 0;
        ll Rsum = 0;
        int Lsize = 0;
        int Rsize = 0;
        vector<ll> op(n, 0);

        for (int i = 0; i < n; i++) {
            if (Lsize + Rsize == x) {

                auto itleft = left.find(nums[i-x]);
                if (itleft != left.end()) {
                    left.erase(itleft);
                    Lsum -= nums[i-x];
                    Lsize--;
                }
                else {
                    auto itright = right.find(nums[i-x]);

                    right.erase(itright);
                    Rsum -= nums[i-x];
                    Rsize--;
                }
            }
            auto LMX = left.end();
            auto RMN = right.begin();
            if (left.size() == 0 || nums[i] <= *prev(LMX)) {
                left.insert(nums[i]);
                Lsum += nums[i];
                Lsize++;
            }
            else {
                right.insert(nums[i]);
                Rsum += nums[i];
                Rsize++;
            }

            ll mid;

            if (abs(Lsize-Rsize) <= 1) {
                if (Lsize < Rsize) {
                    auto it = right.begin();

                    Lsum += *it;
                    Rsum -= *it;

                    Lsize++;
                    Rsize--;

                    left.insert(*it);
                    right.erase(it);
                }
                mid = *prev(left.end());
            }
            else {

                if (Lsize < Rsize) {
                    auto it = right.begin();

                    Lsum += *it;
                    Rsum -= *it;

                    Lsize++;
                    Rsize--;

                    left.insert(*it);
                    right.erase(it);
                }
                else {
                    auto it = prev(left.end());

                    Lsum -= *it;
                    Rsum += *it;

                    Lsize--;
                    Rsize++;

                    right.insert(*it);
                    left.erase(it);
                }

                mid = *prev(left.end());
            }
            if (i >= x-1) {
                op[i] = abs(
                    Rsum - (Lsum-mid)
                    - abs((Lsize-1)-Rsize)*mid
                );
            }
        }
        vector<vector<ll>> dp(
            n+1,
            vector<ll>(k+1, LLONG_MAX)
        );

        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }

        for (int i = 1; i <= n; i++) {
            for (int kk = 1; kk <= i/x && kk <= k; kk++) {
                dp[i][kk] = dp[i-1][kk];
                if (dp[i-x][kk-1] != LLONG_MAX) {
                    dp[i][kk] = min(
                        dp[i][kk],
                        op[i-1] + dp[i-x][kk-1]
                    );
                }
            }
        }
        return dp[n][k];
    }
};