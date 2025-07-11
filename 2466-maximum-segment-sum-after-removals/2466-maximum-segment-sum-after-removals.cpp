class Solution {
public:
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) {
        int n = nums.size();
        vector<long long> res(n);
        vector<long long> segSum(n);
        vector<int> parent(n);
        vector<bool> active(n, false);
        iota(parent.begin(), parent.end(), 0);
        long long currMax = 0;

        function<int(int)> find = [&](int x) {
            if (parent[x] != x)
                parent[x] = find(parent[x]);
            return parent[x];
        };

        auto unite = [&](int x, int y) {
            int rootX = find(x);
            int rootY = find(y);
            if (rootX != rootY) {
                parent[rootY] = rootX;
                segSum[rootX] += segSum[rootY];
            }
        };

        for (int i = n - 1; i >= 0; --i) {
            res[i] = currMax;
            int idx = removeQueries[i];
            active[idx] = true;
            segSum[idx] = nums[idx];

            if (idx > 0 && active[idx - 1]) {
                unite(idx, idx - 1);
            }

            if (idx + 1 < n && active[idx + 1]) {
                unite(idx, idx + 1);
            }

            currMax = max(currMax, segSum[find(idx)]);
        }

        return res;
    }
};
