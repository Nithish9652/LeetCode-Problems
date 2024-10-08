class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int l = 0 , r = arr.size();
        int ans = 0;
        while(l<r){
        int mid = (l+r)/2;
        if(arr[mid]-mid-1 < k){
        ans = mid;
        l = mid+1;
        }
        else{
        r = mid;
        }
        }
        if(arr[0]>k){
          return k;
        }
        return arr[ans] + k - (arr[ans] - ans - 1);
    }
};