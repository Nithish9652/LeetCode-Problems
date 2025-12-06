#include <bits/stdc++.h>
using namespace std;

class SummaryRanges {
    map<int,int> mp;

public:
    SummaryRanges() {}

    void addNum(int value) {
        if (mp.empty()) {
            mp[value] = value;
            return;
        }

        auto it = mp.upper_bound(value);
        int start = value, end = value;

        if (it != mp.begin()) {
            auto prev = it;
            prev--;
            if (prev->second >= value) return;
            if (prev->second + 1 == value) start = prev->first;
        }

        if (it != mp.end() && it->first == value + 1) end = it->second;

        mp.erase(value + 1);
        mp[start] = end;

        auto it2 = mp.find(start);
        if (it2 != mp.begin()) {
            auto prev = it2; prev--;
            if (prev->second + 1 == start) {
                int ns = prev->first;
                int ne = max(prev->second, end);
                mp.erase(prev);
                mp.erase(it2);
                mp[ns] = ne;
            }
        }
    }

    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;
        for (auto &p : mp) res.push_back({p.first, p.second});
        return res;
    }
};
