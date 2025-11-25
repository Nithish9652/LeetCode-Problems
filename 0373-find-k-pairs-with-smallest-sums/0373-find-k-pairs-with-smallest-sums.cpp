class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        if (nums1.empty() || nums2.empty()) return ans;

        // min-heap: stores {sum, i, j}
        priority_queue<
            vector<long long>,
            vector<vector<long long>>,
            greater<vector<long long>>
        > pq;

        // start by pairing nums1[i] with nums2[0]
        for (int i = 0; i < nums1.size() && i < k; i++) {
            pq.push({(long long)nums1[i] + nums2[0], i, 0});
        }

        while (k-- > 0 && !pq.empty()) {
            auto top = pq.top();
            pq.pop();

            long long sum = top[0];
            int i = top[1];
            int j = top[2];

            ans.push_back({nums1[i], nums2[j]});

            // move to next element in nums2
            if (j + 1 < nums2.size()) {
                pq.push({(long long)nums1[i] + nums2[j+1], i, j+1});
            }
        }

        return ans;
    }
};
