class Solution {
public:
    int maxScore(string s) {
        int maxi = 0;
        if(s=="00" || s=="11"){
        return 1;
        }
        for(int i=1;i<s.length();i++){
        string s1 = s.substr(0,i);
        int c = 0;
        for(int i=0;i<s1.length();i++){
        if(s1[i]=='0'){
        c++;
        }
        }
        int d = 0;
        string s2 = s.substr(i);
         for(int i=0;i<s2.length();i++){
        if(s2[i]=='1'){
        d++;
        }
        }
        maxi = max(maxi,c+d);
        }
        return maxi;
    }
};