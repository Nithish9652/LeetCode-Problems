class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string temp = "";
        
        // remove dashes and convert to uppercase
        for (char c : s) {
            if (c != '-') temp += toupper(c);
        }
        
        int n = temp.size();
        if (n == 0) return "";
        
        string ans = "";
        int firstGroup = n % k;
        
        // add the first group
        int idx = 0;
        if (firstGroup > 0) {
            ans += temp.substr(0, firstGroup);
            idx = firstGroup;
        }
        
        // add the remaining groups
        while (idx < n) {
            if (!ans.empty()) ans += "-";
            ans += temp.substr(idx, k);
            idx += k;
        }
        
        return ans;
    }
};
