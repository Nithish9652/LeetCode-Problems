class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;

        int n = routes.size();
        unordered_map<int, vector<int>> stopToRoutes;

        // Map stop -> list of route indices
        for (int i = 0; i < n; i++) {
            for (int stop : routes[i]) {
                stopToRoutes[stop].push_back(i);
            }
        }

        queue<int> q;
        vector<int> visitedRoute(n, 0);
        unordered_set<int> visitedStop;

        // Start from all routes containing source
        for (int r : stopToRoutes[source]) {
            q.push(r);
            visitedRoute[r] = 1;
        }

        int buses = 1;

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int route = q.front();
                q.pop();

                // Check if this route reaches target
                for (int stop : routes[route]) {
                    if (stop == target) return buses;

                    // Explore all new routes reachable from this stop
                    if (!visitedStop.count(stop)) {
                        visitedStop.insert(stop);

                        for (int nextRoute : stopToRoutes[stop]) {
                            if (!visitedRoute[nextRoute]) {
                                visitedRoute[nextRoute] = 1;
                                q.push(nextRoute);
                            }
                        }
                    }
                }
            }
            buses++;
        }
        return -1;
    }
};