class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        
        vector<int> prev(n + 1, 0);
        
        for (int i = 1; i <= m; i++) {
            vector<int> temp(n + 1, 0);
            for (int j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    temp[j] = prev[j - 1] + 1;
                } else {
                    temp[j] = max(prev[j], temp[j - 1]);
                }
            }
            prev = temp;
        }
        
        return prev[n];
    }
};
