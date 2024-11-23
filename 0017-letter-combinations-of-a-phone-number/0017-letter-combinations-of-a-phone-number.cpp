class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }

        unordered_map<char, string> digitMapping = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
            {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
            {'8', "tuv"}, {'9', "wxyz"}
        };

        vector<string> combinations;
        backtrack(0, "", digits, digitMapping, combinations);
        return combinations;
    }

private:
    void backtrack(int index, string path, const string& digits,
                   const unordered_map<char, string>& letters,
                   vector<string>& combinations) {
        if (path.size() == digits.size()) {
            combinations.push_back(path);
            return;
        }

        string possibleLetters = letters.at(digits[index]);
        for (char letter : possibleLetters) {
            backtrack(index + 1, path + letter, digits, letters, combinations);
        }
    }
};