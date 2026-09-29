class Solution {
public:
    vector<vector<int>> ans;
    void combinationSum(int start,int end,int k,int target,vector<int>& arr){
        if(arr.size()==k){
            if(target==0) ans.push_back(arr);
            return;
        }
        if(start>end) return;
        if(start<=target){
            arr.push_back(start);
            combinationSum(start+1,end,k,target-start,arr);
            arr.pop_back();
        }
        combinationSum(start+1,end,k,target,arr);

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> arr;
        combinationSum(1,9,k,n,arr);
        return ans;
    }
};