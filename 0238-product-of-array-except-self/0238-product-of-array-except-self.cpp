class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
            int c = 0;
            int n = nums.size();
            long long pro = 1;
            vector<int> arr(n,0);
            for(int i=0;i<n;i++){
               if(nums[i]!=0){
                 pro*=nums[i];
               }
               else{
                c++;
               }
            }
            if(c>1){
              return arr;
            }
            if(c==1){
            for(int i=0;i<n;i++){
             if(nums[i]==0){
               arr[i]=pro;
             }
            }
            return arr;
            }
            for(int i=0;i<n;i++){
             arr[i]=pro/nums[i];
            }
            return arr;
    }
};