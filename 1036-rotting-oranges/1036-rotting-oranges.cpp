class Solution {
public:
    vector<vector<int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int c = 0;
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
             if(grid[i][j]==1){
               c++;
             }
             else if(grid[i][j]==2){
              q.push({i,j});
             }
           } 
        }
        int ans = 0;
        while(!q.empty()){
           int k = q.size();
           while(k--){
           int x = q.front().first;
           int y = q.front().second;
           q.pop();
           for(auto it:dir){
             int nx = it[0]+x,ny = it[1]+y;
             if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]==1){
               q.push({nx,ny});
               grid[nx][ny] = 2;
               c--;
             }
           }
           }
           if(!q.empty()){
           ans++;
           }
        }
        if(c>0){
         return -1;
        }
        return ans;
    }
};