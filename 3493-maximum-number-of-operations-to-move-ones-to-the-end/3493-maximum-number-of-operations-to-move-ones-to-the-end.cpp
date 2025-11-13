class Solution {
public:
    int maxOperations(string s) {
        int result = 0;
        int c = 0;
        bool flag = false;
        
        for (char ch : s) {
            if (ch == '0') {
                flag = true;
            } else {
                if (flag) {
                    result += c;
                }
                c++;
                flag = false;
            }
        }
        
        if (flag) {
            result += c;
        }
        
        return result;
    }
};