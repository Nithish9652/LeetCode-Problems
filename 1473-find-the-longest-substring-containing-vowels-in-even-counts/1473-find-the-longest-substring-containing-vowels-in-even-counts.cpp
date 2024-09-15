class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char, int> mapping;
        mapping.insert({'a', 0});
        mapping.insert({'e', 1});
        mapping.insert({'i', 2});
        mapping.insert({'o', 3});
        mapping.insert({'u', 4});
        for (int letter = 0; letter < 26; letter++){
            char c = letter + 'a';
            if (mapping.count(c) == 0){
                mapping.insert({c, -1});
            }
        }
        vector<vector<int>> prefix(5, vector<int>(n, 0));
        char c = s[0];
        if (mapping[c] != -1){
            prefix[mapping[c]][0] = 1;
        }
        for (int i = 1; i < n; i++){
            int current_letter = mapping[s[i]];
            for (int letter = 0; letter < 5; letter++){
                prefix[letter][i] = prefix[letter][i - 1];
                if (current_letter == letter){
                    prefix[letter][i]++;
                }
            }
        }
        for (int sliding = n; sliding > 0; sliding--){
            if (is_satisfied(prefix, n, mapping, sliding)){
                return sliding;
            }
        }
        return 0;
    }
    bool is_satisfied(vector<vector<int>>& prefix, int n, unordered_map<char, int>& mapping, int sliding){
        int vowels[5];
        for (int start = 0; start <= n - sliding; start++){
            int back = start + sliding - 1;
            bool satisfied = true;
            if (start == 0){
                for (int letter = 0; letter < 5; letter++){
                    vowels[letter] = prefix[letter][back];
                }
            }
            else{
                for (int letter = 0; letter < 5; letter++){
                    vowels[letter] = prefix[letter][back] - prefix[letter][start - 1];
                }
            }
            for (int letter = 0; letter < 5; letter++){
                if (vowels[letter] % 2 != 0){
                    satisfied = false;
                    break;
                }
            }
            if (satisfied){
                return true;
            }
        }
        return false;
    }
};