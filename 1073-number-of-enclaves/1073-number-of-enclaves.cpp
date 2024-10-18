class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               if(i==n-1 || j==m-1 || i==0 || j==0) {
                    if(grid[i][j]==1){
                        q.push({i,j});
                        vis[i][j]=1;
                    }
                }
            }
        }
        vector<int> row={-1,0,1,0};
        vector<int> col={0,1,0,-1};
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            
            for(int k=0;k<4;k++){
                int nrow=row[k]+x;
                int ncol=col[k]+y;
                if(nrow<n && ncol<m && nrow>=0 && ncol>=0 && grid[nrow][ncol]==1 && vis[nrow][ncol]==0){
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=1;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && vis[i][j]!=1) ans++;
            }
        }
        return ans;
    }
};