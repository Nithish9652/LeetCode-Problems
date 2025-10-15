class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        auto arr = nums;
        int n = nums.size();
        int e = arr[0];
        int d = 1;
        int ans = 0;
        int g = 0;
        int prev = 0;
        for(int i=1;i<n;i++){
          if(e<arr[i]){
            d++;
            e = arr[i];
            g = max(g,d/2);
          }
          else{
            if(d>=0){
             ans++;
             if(ans == 2){
              g = max(g,min(d,prev));
              ans = 1;
             }
             prev = d;
            }
            else{
             ans = 0;
            }
            d = 1;
            e = arr[i];
          }
        }
        if(d>=0){
         g = max(g,d/2);
         ans++;
         if(ans==2){
          g = max(g,min(d,prev));
         }
        }
        return max(1,g);
    }
};