class Solution {
public:
    long long flowerGame(int n, int m) {
        long long a1=(n+1)/2;
        long long a2=(m+1)/2;
        long long b1=n/2;
        long long b2=m/2;
        long long c1 = a1 * b2;
        long long c2 = a2 * b1;
        long long count= c1 + c2;
        return count;
    }
};