class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int val = 0;
        vector<bool> ans;

        for (auto& n : nums) {
            val = ((val << 1) + n) % 5;
            ans.push_back(val == 0);
        }

        return ans;
    }
};
