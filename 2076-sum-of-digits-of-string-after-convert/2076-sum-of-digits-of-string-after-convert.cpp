class Solution {
public:
    int getLucky(string s, int k) {
        string ans;
        for(int i = 0; i < s.length(); i++) {
            int d = s[i] - 'a' + 1;
            ans += to_string(d);
        }
        
        int ans1 = 0;
        for(int i = 0; i < ans.length(); i++) {
            ans1 += ans[i] - '0';
        }
        
        while(k > 1) {
            int f = 0;
            while(ans1 != 0) {
                f += ans1 % 10;
                ans1 /= 10;
            }
            ans1 = f;
            k--;
        }
        
        return ans1;
    }
};
