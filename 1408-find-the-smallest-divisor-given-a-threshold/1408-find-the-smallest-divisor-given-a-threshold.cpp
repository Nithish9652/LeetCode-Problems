class Solution {
public:
    bool sumy(vector<int>& nums, int the, int m) {
        int d = 0;
        for(int i = 0; i < nums.size(); i++) {
            d += (nums[i] + m - 1) / m;  
        }
        return d <= the;
    }

    int smallestDivisor(vector<int>& nums, int the) {
        int l = 1, r = 1e6;
        int ans = 0;
        while (l < r) { 
            int mid = l + (r - l) / 2;
            if (sumy(nums, the, mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
