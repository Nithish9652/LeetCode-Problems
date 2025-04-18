class Solution {
public:
    bool comp(vector<int> piles,int h,int mid){
         int ans = 0;
         int n = piles.size();
         for(int i=0;i<n;i++){
           ans += (piles[i]+mid-1)/mid;
         }
         return ans<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1 , hi = 1e9;
        while(lo<hi-1){
          int mid = lo + (hi-lo)/2;
          if(comp(piles,h,mid)){
            hi = mid;
          }
          else{
            lo = mid+1;
          }
        }
        if(comp(piles,h,lo)){
         return lo;
        }
        return hi;
    }
};