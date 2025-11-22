class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int n=s.size(),count=0,b_count=0;

        for(int i=0;i<n;i++){
            if(s[i]=='a'){
                count++;
            }
            else{ 
                b_count++;
            }
        }
        int d = max(count,b_count);
        int d1 = min(count,b_count);
        return d-d1;
    }
};