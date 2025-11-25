class Solution {
public:
    char invert(char c) {
        return c == '0' ? '1' : '0';
    }

    char findKthBit(int n, long long k) {
        if (n == 1) return '0';

        long long mid = 1LL << (n - 1);  
        if (k == mid) return '1';

        if (k < mid) 
            return findKthBit(n - 1, k);
        long long pos = k - mid;
        long long lenPrev = (1LL << (n - 1)) - 1;
        long long mirrored = lenPrev - pos + 1;

        return invert(findKthBit(n - 1, mirrored));
    }
};
