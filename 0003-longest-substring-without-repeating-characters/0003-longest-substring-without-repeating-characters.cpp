#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> m(128, 0);
        int n = s.length();
        int ans = 0, l = 0;
        for (int i = 0; i < n; i++) {
            m[s[i]]++;
            while (m[s[i]] > 1) {
                m[s[l]]--;
                l++;
            }
            ans = max(ans, i - l + 1);
        }
        return ans;
    }
};
