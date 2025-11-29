class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;

        int result = 1;

        for (int i = 0; i < n; i++) {
            unordered_map<long double, int> slopeCount;
            int samePoint = 0;
            int vertical = 0;
            int localMax = 0;

            for (int j = i + 1; j < n; j++) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                if (dx == 0 && dy == 0) {
                    samePoint++;
                } 
                else if (dx == 0) {
                    vertical++;
                    localMax = max(localMax, vertical);
                } 
                else {
                    long double slope = (long double)dy / (long double)dx;
                    slopeCount[slope]++;
                    localMax = max(localMax, slopeCount[slope]);
                }
            }

            result = max(result, localMax + 1);
        }

        return result;
    }
};
