class Solution {
public:
    vector<int> dx = {0, 1, 0, -1}; 
    vector<int> dy = {1, 0, -1, 0}; 
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if (n == 0) return;
        int m = board[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O' && (i==0 ||  i==n-1 || j==0 || j==m-1)) {
                    q.push({i, j});
                    board[i][j] = '1';
                }
            }
        }
        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int newX = p.first + dx[i];
                int newY = p.second + dy[i];
                if (newX >= 0 && newX < n && newY >= 0 && newY < m && board[newX][newY] == 'O') {
                    board[newX][newY] = '1';
                    q.push({newX,newY});
                }
            }
        }
        for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
             if(board[i][j]=='1'){
               board[i][j]='O';
             }
             else{
              board[i][j]='X';
             }
          }
        }
    }
};
