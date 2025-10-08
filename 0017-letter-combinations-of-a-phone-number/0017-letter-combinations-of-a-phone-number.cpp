class Solution {
public:
    void f(vector<string>& ans,map<char,string> m,string s,string cur,int idx){
         if(idx==s.length()){
          ans.push_back(cur);
          return;
         }
        for (char d : m[s[idx]]) {
        f(ans, m, s, cur + d, idx + 1);
        }
    }
    vector<string> letterCombinations(string s) {
        if(s==""){
         return {};
        }
        map<char,string> m;
        m['2']="abc";
        m['3']="def";
        m['4']="ghi";
        m['5']="jkl";
        m['6']="mno";
        m['7']="pqrs";
        m['8']="tuv";
        m['9']="wxyz";
        vector<string> ans;
        f(ans,m,s,"",0);
        return ans;
    }
};