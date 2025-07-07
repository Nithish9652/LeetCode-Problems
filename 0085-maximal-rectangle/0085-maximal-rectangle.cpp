class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int row= matrix.size();
        int col= matrix[0].size();
        vector<vector<int>> rows(row,vector<int>(col));
        for(int j=0;j<col;j++){
            rows[0][j]=matrix[0][j]-'0';
        }
        for(int i=1;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]=='0'){
                    rows[i][j]=0;
                }else{
                    rows[i][j]=rows[i-1][j] + 1;
                }
            }
        }
        int ans=0;
        for(int i=0;i<row;i++){
            stack<int> st;
            int temp=0;
            for(int j=0;j<=col;j++){
                int curr= (j==col)?0:rows[i][j];
                while(!st.empty() && rows[i][st.top()]>curr){
                    int height = rows[i][st.top()];
                    st.pop();
                    int w=0;
                    if(st.empty()){
                        w=j;
                    }else{
                        w= j-st.top()-1;
                    }
                    temp=max(temp,height*w);

                }
                st.push(j);
            }
            ans= max(ans,temp);
        }
        return ans;

    }
};