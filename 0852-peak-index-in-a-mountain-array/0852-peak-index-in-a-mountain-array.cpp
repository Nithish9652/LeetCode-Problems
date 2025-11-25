class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 1, r = arr.size()-2;
        while(l<r-1){
          int mid = (l+r)/2;
          if(arr[l]>arr[l-1] && arr[l]>arr[l+1]){
             return l;
          }
          else if(arr[l]<arr[l-1] && arr[mid+1]<arr[mid+2]){
           l = mid+1;
          }
           else if(arr[r]>arr[r+1] && arr[mid]>arr[mid+1]){
           r = mid;
          }
          else if(arr[l-1]<arr[l]){
          l++;
          }
          else if(arr[r]>arr[r+1]){
          r--;
          }
        } 
        if(arr[l]>arr[l-1] && arr[l]>arr[l+1]){
        return l;
        }
        return r;
    }
};