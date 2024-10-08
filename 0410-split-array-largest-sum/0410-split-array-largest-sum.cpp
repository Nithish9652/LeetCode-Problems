class Solution {
public:
    bool canSplit(vector<int>& nums, int maxSum, int k) {
        int currentSum = 0, splits = 1;
        for (int num : nums) {
            if (currentSum + num > maxSum) {
                splits++;
                currentSum = num;
                if (splits > k) return false;
            } else {
                currentSum += num;
            }
        }
        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        int left = *max_element(nums.begin(), nums.end());
        int right = accumulate(nums.begin(), nums.end(), 0); 
        int ans = right;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canSplit(nums, mid, k)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};
