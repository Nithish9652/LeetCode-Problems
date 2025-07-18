class Solution {
public:

    int trapRainWater(vector<vector<int>>& heights) {
        int vol = 0;
        const int M = heights.size(), N = heights[0].size();
        vector<vector<bool>> visited(M, vector<bool>(N, false));
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        auto comp = [&](const array<int, 3>& a, const array<int, 3>& b) { return a[0] >= b[0]; };
        priority_queue<array<int, 3>, vector<array<int, 3>>, decltype(comp)> min_heap(comp);
        for(int i = 0; i < N; i++) {
            min_heap.push({heights[0][i], 0, i}),
            min_heap.push({heights[M-1][i], M-1, i});
            visited[0][i] = true, visited[M-1][i] = true;
        }
        for(int i = 0; i < M; i++) {
            min_heap.push({heights[i][0], i, 0}),
            min_heap.push({heights[i][N-1], i, N-1});
            visited[i][0] = true, visited[i][N-1] = true;
        }
            
        while(!min_heap.empty()) {
            auto [height, row, col] = min_heap.top();
            min_heap.pop();
            for(auto dir: directions) {
                int r = row + dir[0], c = col + dir[1];
                if(r >= 0 && r < M && c >= 0 && c < N && !visited[r][c]) {
                    visited[r][c] = true;
                    if(heights[r][c] < height)
                        vol += height - heights[r][c];
                    
                    min_heap.push({max(height, heights[r][c]), r, c});
                }
            }
        }
        return vol;
    }
};