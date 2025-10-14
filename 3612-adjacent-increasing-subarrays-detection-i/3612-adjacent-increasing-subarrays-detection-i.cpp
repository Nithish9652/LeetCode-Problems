class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
         // sort(nums.begin(),nums.end());
     auto arr = nums;
     if(k==1){
        return true;
     }
     int d = 1;
     int ans = 0;
     int e = arr[0];
     for(int i=1;i<nums.size();i++){
        if(e<arr[i]){
         d++;
         e = arr[i];
        }
        else{
          if(d>= 2*k){
            return true;
          }
          if(d >= k){
            ans++;
              if(ans == 2){
                return true;
              }
           d = 1;
          }
          else{
            ans = 0;
            d = 1;
          }
        }
        e = arr[i];
     }
        if(d >= 2*k){
         return true;
        }
        if(d>=k){
          ans++;
          if(ans==2){
            return true;
          }
        }
        return false;
    }
};