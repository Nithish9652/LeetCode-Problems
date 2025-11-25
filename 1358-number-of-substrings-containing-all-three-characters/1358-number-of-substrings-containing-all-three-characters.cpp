class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> freq(3, 0);
        int left = 0;
        int ans = 0;

        for (int right = 0; right < n; right++) {
            freq[s[right] - 'a']++;

            // shrink window until it still contains all three chars
            while (freq[0] > 0 && freq[1] > 0 && freq[2] > 0) {
                ans += (n - right);  // all substrings starting at left and ending ≥ right
                freq[s[left] - 'a']--;
                left++;
            }
        }
        return ans;
    }
};
