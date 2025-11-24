class Solution {
public:
    int evalRPN(vector<string>& arr) {
        stack<int> st;
        int n = arr.size();
        for(int i=0;i<n;i++){
           string d = arr[i];
           if(d=="+"){
             int a1 = st.top();
             st.pop();
             int a2 = st.top();
             st.pop();
             int c = a1 + a2;
             st.push(c);
           }
           else if(d=="-"){
             int a1 = st.top();
             st.pop();
             int a2 = st.top();
             st.pop();
             int c = a2 - a1;
              st.push(c);
           }
           else if(d=="*"){
             int a1 = st.top();
             st.pop();
             int a2 = st.top();
             st.pop();
             int c = a1 * a2;
              st.push(c);
           }
           else if(d=="/"){
             int a1 = st.top();
             st.pop();
             int a2 = st.top();
             st.pop();
             int c = a2 / a1;
             st.push(c);
           }
           else{
             st.push(stoi(d));
           }
        }
        return st.top();
    }
};