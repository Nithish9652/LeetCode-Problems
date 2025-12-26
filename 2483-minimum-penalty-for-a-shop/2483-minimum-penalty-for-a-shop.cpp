class Solution {
public:
    int bestClosingTime(string& customers) {
        int n = customers.size();
    
        int p=0;
        int mini=p, minI=0;
    
        for (int i=1; i<=n; i++) {
            int y=(customers[i-1]=='Y')?1:-1;
            p-=y;
            if (mini>p) {
                mini=p;
                minI=i;
            }
        }
        return minI;
    }
};