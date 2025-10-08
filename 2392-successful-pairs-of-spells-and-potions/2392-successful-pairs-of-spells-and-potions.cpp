class Solution {
public:
    vector<int> successfulPairs(vector<int>& brr, vector<int>& arr, long long k) {
        sort(arr.begin(), arr.end());
        vector<int> ans;
        for (int i = 0; i < brr.size(); i++) {
            long long d = (k + (long long)brr[i] - 1) / brr[i];
            int low = lower_bound(arr.begin(), arr.end(), d) - arr.begin();
            ans.push_back(arr.size() - low);
        }
        return ans;
    }
};