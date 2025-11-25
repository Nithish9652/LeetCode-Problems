class Solution {
public:
    bool detectCapitalUse(string word) {
        bool allUpper = true, allLower = true, firstUpperRestLower = true;

        for (int i = 0; i < word.size(); i++) {
            if (!isupper(word[i])) allUpper = false;
            if (!islower(word[i])) allLower = false;

            if (i == 0) {
                if (!isupper(word[i])) firstUpperRestLower = false;
            } else {
                if (!islower(word[i])) firstUpperRestLower = false;
            }
        }

        return allUpper || allLower || firstUpperRestLower;
    }
};
