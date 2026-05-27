class Solution {
public:
    int numberOfSpecialChars(string word) {
        int upperCase = 0 , lowerCase = 0;
        int lowerCaseEnded = 0 , special = (1<<26)-1;
        for(char ch : word){
            if(special >> (toupper(ch) - 'A') & 1 ^ 1) continue;
            if(isupper(ch)){
                upperCase |= 1 << (ch-'A');
                lowerCaseEnded |= 1 << (ch-'A');
            }
            else{
                if(lowerCaseEnded >> (ch-'a') & 1) special ^= 1 << (ch - 'a');
                else lowerCase |= 1 << (ch - 'a');
            }
        }
        return  __builtin_popcount(upperCase & lowerCase & special);
    }
};