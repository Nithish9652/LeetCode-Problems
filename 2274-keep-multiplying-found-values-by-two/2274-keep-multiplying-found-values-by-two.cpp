class Solution {
public:
    int findFinalValue(vector<int>& nums, int d) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        while(true){
          int low  = lower_bound(nums.begin(),nums.end(),d)-nums.begin();
          if(low==n){
           return d;
          }
          if(nums[low]!=d){
           return d;
          }
          d*=2;
        }
        return -1;
    }
};