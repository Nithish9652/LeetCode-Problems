class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        multiset<int> availableBaskets(baskets.begin(), baskets.end());
        int unplaced = 0;
        
        for (int fruit : fruits) {
            auto it = availableBaskets.lower_bound(fruit);
            
            if (it == availableBaskets.end()) {
                unplaced++;
            } else {
                availableBaskets.erase(it);
            }
        }
        
        return unplaced;
    }
};