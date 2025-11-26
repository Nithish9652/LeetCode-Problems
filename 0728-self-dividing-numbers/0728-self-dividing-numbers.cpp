class Solution {
public:
    bool isSelfDividing(int n) {
        int x = n;
        while (x > 0) {
            int d = x % 10;
            if (d == 0 || n % d != 0) return false;
            x /= 10;
        }
        return true;
    }

    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for (int i = left; i <= right; i++) {
            if (isSelfDividing(i)) res.push_back(i);
        }
        return res;
    }
};
