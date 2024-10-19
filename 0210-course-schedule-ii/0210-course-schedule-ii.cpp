class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prer) {
        vector<vector<int>> adj(numCourses);  
        vector<int> inDegree(numCourses, 0);  
        for(int i = 0; i < prer.size(); i++) {
            adj[prer[i][1]].push_back(prer[i][0]);
            inDegree[prer[i][0]]++;
        }
        
        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(inDegree[i] == 0) {
                q.push(i);
            }
        }
        
        vector<int> ans; 
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            for(auto it : adj[node]) {
                inDegree[it]--;
                if(inDegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        if(ans.size() == numCourses) {
            return ans;
        } else {
            return {};
        }
    }
};
