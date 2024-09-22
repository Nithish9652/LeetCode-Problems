class Solution {
public:
    int findKthNumber(int n1, int k1) {
        long long n = n1, k = k1;
        long long curr = 1;
        k--;
        
        while (k > 0) {
            long long steps = calculateSteps(n, curr, curr + 1);
            if (steps <= k) {
                k -= steps;
                curr++;
            } else {
                curr *= 10;
                k--;
            }
        }
        
        return curr;
    }

private:
    long long calculateSteps(long long n, long long curr, long long next) {
        long long steps = 0;
        while (curr <= n) {
            steps += min(n + 1, next) - curr;
            curr *= 10;
            next *= 10;
        }
        return steps;
    }
};
