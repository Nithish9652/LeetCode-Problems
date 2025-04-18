class Solution {
public:
    bool helper(vector<int>& nums, int k, int mid) {
        int sum = 0;
        int days = 1;
        for (int i : nums) {
            sum += i;
            if (sum > mid) {
                days++;
                sum = i;
            }
        }

        return days <= k;
    }
    int shipWithinDays(vector<int>& nums, int days) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0LL);

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (helper(nums, days, mid)) {

                high = mid - 1;

            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};