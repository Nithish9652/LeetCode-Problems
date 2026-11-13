class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), a = n, b = n, r = n - 1;
        vector<int> arr(n);  
        long long ans = 0, water = 0;
        for (int l = n - 1; l >= 0; --l) {
            int x = nums[l];
            while (a < b && nums[arr[a]] <= x) {  
                int s = arr[a++];
                int end = a < b ? arr[a] : r + 1;
                water += 1LL * (x - nums[s]) * (end - s);
            }
            arr[--a] = l;
            while (water > k) {  
                water -= nums[arr[b - 1]] - nums[r];
                if (arr[b - 1] == r)
                    --b;
                --r;
            }
            ans += r - l + 1;
        }
        return ans;
    }
};