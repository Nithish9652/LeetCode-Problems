class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<vector<int>> graph(numCourses);

        for (auto i: prerequisites) graph[i[1]].push_back(i[0]);

        vector<int> ans, seen(numCourses, false), color(numCourses, 0);
        bool isCycle = false;

        function<void(int)> dfs = [&](int node) -> void {
            if (isCycle) return;

            if (!color[node]) {
                color[node] = 1; 

                for (int child : graph[node]) dfs(child);

                color[node] = 2;
                ans.push_back(node);
            } else if (color[node] == 1) isCycle = true;
        };

        for (int i = 0; i < numCourses; ++i) {
            if (!color[i]) {
                dfs(i);
                if (isCycle) return {};
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};