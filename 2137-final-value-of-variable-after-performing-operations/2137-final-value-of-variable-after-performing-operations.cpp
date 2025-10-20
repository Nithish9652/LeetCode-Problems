class Solution {
public:
    int finalValueAfterOperations(vector<string>& arr) {
        int ans = 0;
        for(int i=0;i<arr.size();i++){
          if(arr[i]=="--X" || arr[i]=="X--"){
            ans--;
          }
          else{
            ans++;
          }
        }
        return ans;
    }
};