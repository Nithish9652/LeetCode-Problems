class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        //We have to find breadth so b = nextSmallerElement'sIndex - previousSmallerElement'sIndex - 1;
        int n = heights.size();
        vector<int> nextSmaller(n);
        vector<int> prevSmaller(n);
        stack<int> st;
        prevSmaller[0] = -1;
        st.push(0);
        for(int i = 1;i<n;i++){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if(st.empty()) prevSmaller[i] = -1;
            else prevSmaller[i] = st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        nextSmaller[n-1] = n;
        st.push(n-1);
        for(int i = n-2;i>=0;i--){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if(st.empty()) nextSmaller[i] = n;
            else nextSmaller[i] = st.top();
            st.push(i);
        }
        int area = INT_MIN;
        for(int i = 0;i<n;i++){
            int breadth = nextSmaller[i] - prevSmaller[i] - 1;
            int height = heights[i];
            area = max(area, height*breadth);
        }
        return area;
    }
};