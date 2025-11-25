class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        unordered_set<long long> S;
        vector<int> deg(n+1, 0);

        auto key = [&](int u, int v) {
            if (u > v) swap(u, v);
            return (long long)u * 1000000 + v;
        };

        for (auto &e : edges) {
            int u = e[0], v = e[1];
            deg[u]++, deg[v]++;
            S.insert(key(u, v));
        }

        vector<int> odd;
        for (int i = 1; i <= n; i++) {
            if (deg[i] % 2 == 1) odd.push_back(i);
        }

        int m = odd.size();
        if (m == 0) return true;
        if (m == 1 || m == 3 || m > 4) return false;

        // --- case m = 2 ---
        if (m == 2) {
            int a = odd[0], b = odd[1];
            if (!S.count(key(a, b))) return true;

            for (int x = 1; x <= n; x++) {
                if (x != a && x != b &&
                    !S.count(key(a, x)) &&
                    !S.count(key(b, x)))
                    return true;
            }
            return false;
        }

        // --- case m = 4 ---
        if (m == 4) {
            int a = odd[0], b = odd[1], c = odd[2], d = odd[3];

            auto ok = [&](int u, int v, int x, int y) {
                return !S.count(key(u, v)) && !S.count(key(x, y));
            };

            if (ok(a,b, c,d)) return true;
            if (ok(a,c, b,d)) return true;
            if (ok(a,d, b,c)) return true;
            return false;
        }

        return false;
    }
};
