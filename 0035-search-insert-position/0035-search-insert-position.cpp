class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
         int low = lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        //  if(nums[low]==target){
        //    low--;
        //  }
         return low;
    }
};