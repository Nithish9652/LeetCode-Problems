class Solution {
public:
    int maxLength(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        if(n<=2){
         return n;
        }
        for(int i=0;i<n;i++){
          int d = nums[i];
          int e = 1;
          for(int j=i+1;j<n;j++){
            if(__gcd(d,nums[j])==1){
              d = (d*nums[j]);
              e++;
            }
            else{
             break;
            }
          }
          ans = max(ans,e);
        }
        return max(2,ans);
    }
};