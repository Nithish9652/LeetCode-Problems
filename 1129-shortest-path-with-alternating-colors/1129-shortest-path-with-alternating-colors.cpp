#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int,int>>> g(n);
        
        // 0 = red, 1 = blue
        for (auto &e : redEdges) g[e[0]].push_back({e[1], 0});
        for (auto &e : blueEdges) g[e[0]].push_back({e[1], 1});

        vector<vector<int>> dist(n, vector<int>(2, -1));
        queue<pair<int,int>> q;

        // Start at node 0 with both "previous colors" possible
        dist[0][0] = dist[0][1] = 0;
        q.push({0, 0});
        q.push({0, 1});

        while (!q.empty()) {
            auto [node, lastColor] = q.front();
            q.pop();

            for (auto &edge : g[node]) {
                int next = edge.first;
                int color = edge.second;

                // must alternate
                if (color == lastColor) continue;

                if (dist[next][color] == -1) {
                    dist[next][color] = dist[node][lastColor] + 1;
                    q.push({next, color});
                }
            }
        }

        vector<int> ans(n, -1);
        for (int i = 0; i < n; i++) {
            int a = dist[i][0], b = dist[i][1];
            if (a == -1) ans[i] = b;
            else if (b == -1) ans[i] = a;
            else ans[i] = min(a, b);
        }
        return ans;
    }
};
