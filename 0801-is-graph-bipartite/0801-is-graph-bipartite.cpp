class Solution {
    bool f(int start, vector<vector<int>>& graph, vector<int>& col){
        queue<int> q;
        q.push(start);
        col[start] = 0;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto it : graph[node]){
                if(col[it] == -1){
                    col[it] = !col[node];
                    q.push(it);
                }
                else if(col[it] == col[node]) return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> col(V, -1);
        for(int i = 0; i < V; i++){
            if(col[i] == -1){
                if(!f(i, graph, col)) return false;
            }
        }
        return true;
    }
};