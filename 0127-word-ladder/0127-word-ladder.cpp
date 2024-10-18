class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> q;
        unordered_set<string> s(wordList.begin(), wordList.end());

        if (s.find(endWord) == s.end())
            return 0;

        q.push({beginWord, 1});
        s.erase(beginWord);

        while (!q.empty()) {
            auto [currentWord, steps] = q.front();
            q.pop();

            if (currentWord == endWord)
                return steps;

            for (int i = 0; i < currentWord.size(); ++i) {
                char originalChar = currentWord[i];

                for (char ch = 'a'; ch <= 'z'; ++ch) {
                    currentWord[i] = ch;

                    if (s.find(currentWord) != s.end()) {
                        q.push({currentWord, steps + 1});
                        s.erase(currentWord);
                    }
                }

                currentWord[i] = originalChar;
            }
        }

        return 0;
    }
};
