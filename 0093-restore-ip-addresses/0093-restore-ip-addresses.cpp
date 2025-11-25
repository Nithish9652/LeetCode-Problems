class Solution {
public:
    vector<string> ans;
    vector<string> parts;

    bool valid(string &s) {
        if (s.size() > 1 && s[0] == '0') return false;   // no leading zeros
        if (s.size() > 3) return false;
        int num = stoi(s);
        return num >= 0 && num <= 255;
    }

    void backtrack(string &s, int idx) {
        if (parts.size() == 4) {
            if (idx == s.size()) {
                ans.push_back(parts[0] + "." + parts[1] + "." + parts[2] + "." + parts[3]);
            }
            return;
        }

        for (int len = 1; len <= 3 && idx + len <= s.size(); len++) {
            string seg = s.substr(idx, len);
            if (valid(seg)) {
                parts.push_back(seg);
                backtrack(s, idx + len);
                parts.pop_back();
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        backtrack(s, 0);
        return ans;
    }
};
