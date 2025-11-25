class Solution {
public:
    bool isPossible(vector<int>& target) {
        if (target.size() == 1) return target[0] == 1;

        priority_queue<long long> pq;
        long long sum = 0;
        for (long long x : target) { pq.push(x); sum += x; }

        while (true) {
            long long x = pq.top(); pq.pop();
            long long rest = sum - x;
            if (x == 1 || rest == 1) return true;
            if (rest == 0 || x < rest) return false;
            long long prev = x % rest;
            if (prev == 0) prev = rest;
            if (prev == x) return false;
            sum = rest + prev;
            pq.push(prev);
        }
    }
};
