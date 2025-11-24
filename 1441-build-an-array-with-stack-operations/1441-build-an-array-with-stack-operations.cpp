class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
       int c = 1;
       vector<string> ans;
       for(int i=0;i<target.size();i++){
         while(c!=target[i]){
          ans.push_back("Push");
          ans.push_back("Pop");
          c++;
         }
         ans.push_back("Push");
         c++;
       }
       return ans;
    }
};