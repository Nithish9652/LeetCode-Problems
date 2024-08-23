class Solution {
public:
    string fractionAddition(string s) {
        int sign = 1;
        int num = 0;
        int den = 1;
        for (int i = 0; i < s.length(); i++) {
            if (i > 0 && s[i - 1] == '/') {
                int d = s[i]-'0';
                if(s[i+1]=='0' && i+1<s.length()){
                 d = 10;
                 i++;
                }
                den = (den*(d))/__gcd(den,(d));
            }
        }
        for (int i = 0; i < s.length(); i++) {
            if(s[i]=='-'){
             sign = 0;
            } 
            else if(s[i]=='+'){
             sign = 1;
            }
            if(s[i+1]=='/'){
                int d  = s[i]-'0';
               if(s[i]=='0'){
                  if(i>0 && s[i-1]=='1'){
                   d = 10;
                  }
               }
               int d1 = s[i+2]-'0';
               if(s[i+3]=='0' && i+3<s.length()){
                 d1 = 10;
                }
               if(sign == 0){
                num-=((den/(d1))*(d));
               }
               else{
                num+=((den/(d1))*(d));
               }
            }
        }    
        int d = __gcd(abs(num),abs(den));
        num/=d;
        den/=d;
        return to_string(num)+"/"+to_string(den);
    }
};
