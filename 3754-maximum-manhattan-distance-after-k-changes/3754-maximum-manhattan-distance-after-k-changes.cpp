class Solution {
public:
    int maxDistance(string s, int k) {
        int n = s.length();
        int ans= 0;
        vector<int> count(150, 0);
        int temp = k;
        for (char c : s) {
        count[c]++;
        int verticalDist = abs(count['N'] - count['S']);
        int verticalShift = min(k, min(count['N'], count['S']));
        k -= verticalShift;
        verticalDist = max(0, verticalDist + 2 * verticalShift);
        int horizontalDist = abs(count['E'] - count['W']);
        int horizontalShift = min(k, min(count['E'], count['W']));
        horizontalDist = max(0, horizontalDist + 2* horizontalShift);
        ans = max(ans,verticalDist + horizontalDist);
        k=temp;
        }
        return ans;
    }
};