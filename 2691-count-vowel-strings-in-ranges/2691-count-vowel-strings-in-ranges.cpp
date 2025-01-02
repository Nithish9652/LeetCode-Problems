class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> brr(n, 0);

        auto isVowel = [](char ch) {
            return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
        };

        if (isVowel(words[0][0]) && isVowel(words[0].back())) {
            brr[0] = 1;
        }

        for (int i = 1; i < n; i++) {
            if (isVowel(words[i][0]) && isVowel(words[i].back())) {
                brr[i] = brr[i - 1] + 1;
            } else {
                brr[i] = brr[i - 1];
            }
        }

        vector<int> result;

        for (const auto& query : queries) {
            int l = query[0], r = query[1];
            if (l == 0) {
                result.push_back(brr[r]);
            } else {
                result.push_back(brr[r] - brr[l - 1]);
            }
        }

        return result;
    }
};
