class Solution {
public:
    void solve(int n,int colu,vector<bool>&row,vector<bool>&col,vector<bool>&diaglow,vector<bool>&diaghigh,int &ans){
        if(colu==n){
            ans++;
            return;
        }
        for(int j=0;j<n;j++){
            if(row[colu]==false && col[j]==false && diaglow[colu+j]==false && diaghigh[n-1-colu+j]==false){
                row[colu]=true;
                col[j]=true;
                diaglow[colu+j]=true;
                diaghigh[n-1-colu+j]=true;
                solve(n,colu+1,row,col,diaglow,diaghigh,ans);
                row[colu]=false;
                col[j]=false;
                diaglow[colu+j]=false;
                diaghigh[n-1-colu+j]=false;
            }
        }
    }
    int totalNQueens(int n) {
        vector<bool>row(n,false);
        vector<bool>col(n,false);
        vector<bool>diaglow(2*n -1,false);
        vector<bool>diaghigh(2*n -1,false);
        int ans=0;
        solve(n,0,row,col,diaglow,diaghigh,ans);
        return ans;
    }
};