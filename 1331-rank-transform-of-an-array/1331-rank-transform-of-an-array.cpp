class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
         map<int,int> m;
         for(auto x : arr){
            m[x]++;
         }
         int c = 1;
         for(auto &it : m){
           it.second = c;
           c++;
         }
         for(int i=0;i<arr.size();i++){
            arr[i] = m[arr[i]];
         }
         return arr;
    }
};