#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos,
                                          vector<vector<int>>& friends,
                                          int id, int level) {

        int n = friends.size();
        vector<int> dist(n, -1);
        queue<int> q;

        dist[id] = 0;
        q.push(id);

        // BFS to find all friends at exactly 'level'
        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : friends[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }

        // Frequency count of videos
        unordered_map<string, int> freq;
        for (int i = 0; i < n; i++) {
            if (dist[i] == level) {
                for (auto &vid : watchedVideos[i]) {
                    freq[vid]++;
                }
            }
        }

        // Move data to a vector for sorting
        vector<pair<string, int>> arr(freq.begin(), freq.end());

        // Sort: increasing frequency, then alphabetical
        sort(arr.begin(), arr.end(),
            [](auto &a, auto &b) {
                if (a.second == b.second) return a.first < b.first;
                return a.second < b.second;
            }
        );

        // Build answer
        vector<string> result;
        for (auto &p : arr) result.push_back(p.first);

        return result;
    }
};
