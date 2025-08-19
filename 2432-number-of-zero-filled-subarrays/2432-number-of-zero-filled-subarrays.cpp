class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
    long long d = 0 , n = nums.size();
    long long ans = 0;
    for(int i=0;i<n;i++){
      if(nums[i]==0){
       d++;
      }
      else if(d>0){
       long long sum = (d*(d+1))/2;
       ans += sum;
       d = 0;
      }
    }
    if(d>0){
       long long sum = (d*(d+1))/2;
       ans += sum;
    }
    return ans;
    }
};