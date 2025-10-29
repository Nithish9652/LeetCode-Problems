class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        stack<pair<int,int>> st;
        int n = arr.size();
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && st.top().first <= arr[i]) {
                st.pop();
            }
            int d = 0;
            if(!st.empty()) {
                d = st.top().second - i;
            }
            st.push({arr[i], i});
            arr[i] = d;
        }
        return arr;
    }
};
