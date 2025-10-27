class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int row = 0;
        int prev = 0;
        int c = 0;
        int ans = 0;
        for (auto it : bank) {
            int count = 0;
            for (int i = 0; i < bank[0].length(); i++) {
                if (it[i] == '1') count++;
            }
            if(count!=0){
            ans += (prev * count);
            prev = count;
            }
        }
        return ans;
    }
};