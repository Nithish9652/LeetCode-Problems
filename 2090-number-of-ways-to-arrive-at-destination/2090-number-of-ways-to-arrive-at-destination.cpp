class Solution {
public:
    const int M=1e9+7;
    vector<long long> dijkstra(vector<vector<int>> &roads, int n, int source, vector<int>& pathCount) {
        unordered_map<int,list<pair<int,int>>>adj;
        for(int i=0;i<roads.size();i++) {
            int u=roads[i][0];
            int v=roads[i][1];
            int w=roads[i][2]; 
            adj[u].push_back(make_pair(v,w));
            adj[v].push_back(make_pair(u,w));
        }
        vector<long long>dist(n,LLONG_MAX);
        pathCount.resize(n, 0); 
        set<pair<long long,int>>st;
        dist[source]=0;
        pathCount[source]=1;
        st.insert(make_pair(0, source));
        while(!st.empty()){
            auto top= *(st.begin());
            long long nodeDist=top.first;
            int node=top.second;
            st.erase(st.begin());
            for(auto j:adj[node]){
                int  neighbor=j.first;
                int  weight=j.second;
                if(nodeDist+weight<dist[neighbor])                {
                    auto record=st.find(make_pair(dist[neighbor], neighbor));
                    if(record!=st.end()) {
                    st.erase(record);
                    }
                    dist[neighbor]=nodeDist+weight;
                    pathCount[neighbor]=pathCount[node]; 
                    st.insert(make_pair(dist[neighbor],neighbor));
                } 
                else if(nodeDist+weight==dist[neighbor]) {
                    pathCount[neighbor]=(pathCount[neighbor]+pathCount[node])%M;
                }
            }
        }
        return dist;
    }

    int countPaths(int n, vector<vector<int>>& roads) {
        vector<int>pathCount;
        vector<long long>dist =dijkstra(roads, n, 0, pathCount);
        return pathCount[n-1];
    }
};