class Solution {
public:
    int minElement(vector<int>& nums) {
        int d = INT_MAX;
        for(int i=0;i<nums.size();i++){
           int c = 0;
           while(nums[i]!=0){
             c+=(nums[i]%10);
             nums[i]/=10;
           }
           d = min(d,c);
        }
        return d;
    }
};