class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
         vector<int> dp(amount+1,INT_MAX);
         dp[0] = 0;
         for(auto it : coins){
           if(it<=amount){
             dp[it] = 1;
           }
         }
         for(int i=1;i<=amount;i++){
          for(auto it:coins){
            if((i-it)>0 && dp[i-it]!=INT_MAX){
              dp[i] = min(dp[i-it]+1,dp[i]);
            }
          }
         }
         if(dp[amount]==INT_MAX){
          return -1;
         }
         return dp[amount];
    }
};