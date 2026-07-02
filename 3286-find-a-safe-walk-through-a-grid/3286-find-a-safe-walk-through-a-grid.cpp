class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        queue<pair<int,pair<int,int>>> q;
        int n = grid.size(), m = grid[0].size();

        vector<vector<int>> q1(n, vector<int>(m, INT_MAX));

        int s = grid[0][0];
        q.push({s,{0,0}});
        q1[0][0] = s;

        vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};

        while(!q.empty()){
            int c = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;
            q.pop();

            for(auto di : dir){
                int nx = x + di.first;
                int ny = y + di.second;

                if(nx>=0 && nx<n && ny>=0 && ny<m){
                    if(c + grid[nx][ny] < q1[nx][ny]){
                        q1[nx][ny] = c + grid[nx][ny];
                        q.push({c + grid[nx][ny], {nx, ny}});
                    }
                }
            }
        }

        return q1[n-1][m-1] < health;
    }
};