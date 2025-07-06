class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        int count = 0;
        multiset<long> prefixSet;
        prefixSet.insert(0);  // For subarrays starting from index 0
        
        long prefixSum = 0;
        for(int i = 0; i < n; i++){
            prefixSum += nums[i];
            
            // Find range of valid previous prefix sums
            auto low = prefixSet.lower_bound(prefixSum - upper);
            auto high = prefixSet.upper_bound(prefixSum - lower);
            
            count += distance(low, high);
            prefixSet.insert(prefixSum);
        }
        return count;
    }
};