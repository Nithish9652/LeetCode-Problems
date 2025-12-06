class KthLargest {
    int k;
    priority_queue<int, vector<int>, greater<int>> pq; // min-heap

public:
    // Constructor
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int num : nums) {
            pq.push(num);
            if (pq.size() > k)
                pq.pop(); // keep only k largest elements
        }
    }

    // Add a new score and return kth largest
    int add(int val) {
        pq.push(val);
        if (pq.size() > k)
            pq.pop();
        return pq.top(); // kth largest element
    }
};
