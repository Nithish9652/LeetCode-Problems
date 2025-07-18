class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long answer = 0;
        stack<int> stk;
        for (int right = 0; right <= n; ++right) {
            while (!stk.empty() && (right == n || nums[stk.top()] >= nums[right])) {
                int mid = stk.top();
                stk.pop();
                int left = stk.empty() ? -1 : stk.top();
                answer -= (long long)nums[mid] * (right - mid) * (mid - left);
            }
            stk.push(right);
        }
        stk.pop();
        for (int right = 0; right <= n; ++right) {
            while (!stk.empty() && (right == n || nums[stk.top()] <= nums[right])) {
                int mid = stk.top();
                stk.pop();
                int left = stk.empty() ? -1 : stk.top();
                answer += (long long)nums[mid] * (right - mid) * (mid - left);
            }
            stk.push(right);
        }
        return answer;
    }
};