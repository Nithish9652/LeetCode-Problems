class Solution {
public:
    long long mergeSort(vector<int>& nums, int l, int r) {
        if (l >= r) return 0;

        int mid = (l + r) / 2;
        long long cnt = 0;

        cnt += mergeSort(nums, l, mid);
        cnt += mergeSort(nums, mid + 1, r);

        // count reverse pairs
        int j = mid + 1;
        for (int i = l; i <= mid; i++) {
            while (j <= r && (long long)nums[i] > 2LL * nums[j]) {
                j++;
            }
            cnt += (j - (mid + 1));
        }

        // merge
        vector<int> temp;
        int i = l;
        j = mid + 1;

        while (i <= mid && j <= r) {
            if (nums[i] <= nums[j]) temp.push_back(nums[i++]);
            else temp.push_back(nums[j++]);
        }

        while (i <= mid) temp.push_back(nums[i++]);
        while (j <= r) temp.push_back(nums[j++]);

        for (int k = 0; k < temp.size(); k++) {
            nums[l + k] = temp[k];
        }

        return cnt;
    }

    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};
