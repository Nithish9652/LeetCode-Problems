class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)  {
     unordered_map<int,int> m;
     for(int i=0;i<nums.size();i++){
       m[nums[i]]=i;
     }
     for(int i=0;i<nums.size();i++){
       int c = target - nums[i];
       if(m.find(c)!=m.end() && i!=m[c]){
         return {i,m[c]};
       }
     }
     return {-1,-1};
    }
};