class Solution {
public:
    int maxFreqSum(string s) {
        map<char,int> m;
        for(int i=0;i<s.length();i++){
          m[s[i]]++;
        }
        int maxi = 0 , ma = 0;
        for(auto it : m){
          if(it.first == 'a' || it.first == 'e' || it.first == 'i' || it.first == 'o'|| it.first == 'u'){
             maxi = max(maxi,it.second);
          }
          else{
            ma = max(ma,it.second);
          }
        }
        return ma+maxi;
    }
};