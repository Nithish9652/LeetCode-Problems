class DSU {
public:
    vector<int> parent, rankv;

    DSU(int n) {
        parent.resize(n);
        rankv.assign(n, 0);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (rankv[a] < rankv[b]) swap(a, b);
            parent[b] = a;
            if (rankv[a] == rankv[b]) rankv[a]++;
        }
    }
};

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        DSU dsu(n);

        for (auto &e : edges)
            dsu.unite(e[0], e[1]);

        return dsu.find(source) == dsu.find(destination);
    }
};
