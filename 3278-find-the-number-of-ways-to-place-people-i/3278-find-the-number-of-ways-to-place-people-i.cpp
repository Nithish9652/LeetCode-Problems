class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
       sort(points.begin(), points.end(), [](auto &a, auto &b) {
        if (a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    });
    int c = 0, n = points.size();
    for (int i = 0; i < n; i++) {
        int uy = points[i][1], ly = INT_MIN;
        for (int j = i + 1; j < n; j++) {
            int cy = points[j][1];
            if (cy <= uy && cy > ly) {
                c++;
                ly = cy;
                if (cy == uy) break;
            }
        }
    }
    return c;
    }
};