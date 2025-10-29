class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> m(26,0);
        if(s==" "){
        return 1;
        }
        int n = s.length();
        int ans = 0;
        int l = 0;
        for(int i=0;i<n;i++){
           m[s[i]-'a']++;
           while(m[s[i]-'a']>=2 && l<i){
            m[s[l]-'a']--;
            l++;
           }
           ans = max(ans,i-l+1);
        }
        return ans;
    }
};