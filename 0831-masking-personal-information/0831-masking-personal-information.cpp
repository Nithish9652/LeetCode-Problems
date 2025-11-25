class Solution {
public:
    string maskPII(string s) {
        // Case 1: Email
        if (s.find('@') != string::npos) {
            // convert to lowercase
            for (char &c : s) c = tolower(c);

            int at = s.find('@');
            string name = s.substr(0, at);
            string domain = s.substr(at);

            string res;
            res += name[0];
            res += "*****";
            res += name[name.size() - 1];
            res += domain;

            return res;
        }

        // Case 2: Phone number
        string digits = "";
        for (char c : s) {
            if (isdigit(c)) digits += c;
        }

        int n = digits.size();
        string last4 = digits.substr(n - 4);

        int country = n - 10;

        string base = "***-***-" + last4;
        if (country == 0) return base;

        string code = "+";
        for (int i = 0; i < country; i++) code += "*";
        code += "-";

        return code + base;
    }
};
