class Solution {
public:
    int pivotInteger(int n) {
        long long T = 1LL * n * (n + 1) / 2;
        long long x = (long long)floor(sqrt((long double)T));
        if (x * x == T) return (int)x;
        return -1;
    }
};
