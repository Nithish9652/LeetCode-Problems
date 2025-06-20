class Solution {
public:
    bool isMatch(string s, string p) {
         int n = s.length();
         int m = p.length();
         vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
         dp[0][0] = true;
         for(int j=2;j<=m;j+=2){
            if(p[j-1]=='*' && dp[0][j-2]){
              dp[0][j] = true;
            }
            else{
             break;
            }
         }
         for(int i=1;i<=n;i++){
           for(int j=1;j<=m;j++){
             if(p[j-1]=='*'){
              if(j>=2 && dp[i][j-2]){
                dp[i][j] = true;
              }
              if (j >= 2 && (p[j - 2] == s[i - 1] || p[j - 2] == '.')) {
                dp[i][j] = dp[i][j] || dp[i - 1][j];
              }
             }
             else{
               if(p[j-1]==s[i-1] || p[j-1]=='.'){
                 dp[i][j]  = dp[i-1][j-1];
               }
             }
           }
         }
         return dp[n][m];
    }
};