struct Node {
    Node *links[26];
    bool flag = false;
    string word = "";
    bool containsKey(char ch) {
        return links[ch-'a'] != NULL;
    }
    void put(char ch, Node *node) {
        links[ch-'a'] = node;
    }
    Node *get(char ch) {
        return links[ch-'a'];
    }
    void setEnd() {
        flag = true;
    }
    bool isEnd() {
        return flag;
    }
    void setWord(string str) {
        word = str;
    }
};
class Trie {
public:
    Node *root;
    Trie() {
        root = new Node();
    }
    void insert(string word) {
        Node *node = root;
        for(int i=0; i<word.size(); i++) {
            if(!node->containsKey(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
        node->setWord(word);
    }
    Node *getRoot() {
        return root;
    }
};
class Solution {
public:
    int m, n;
    vector<string> ans;
    void dfs(int row, int col, vector<vector<char>>& board, Node *node) {
        char ch = board[row][col];
        if(!node->containsKey(ch)) return ;
        node = node->get(ch);
        if(node->isEnd()) {
            ans.push_back(node->word);
            node->flag = false;
        }
        char temp = board[row][col];
        board[row][col] = '#';
        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        for(auto &d : dir) {
            int Nrow = row + d.first;
            int Ncol = col + d.second;
            if(Nrow>=0 && Ncol>=0 && Nrow<m && Ncol<n && board[Nrow][Ncol] != '#') {
                dfs(Nrow, Ncol, board, node);
            }
        }
        board[row][col] = temp;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie;
        for(string word : words) {
            trie.insert(word);
        }
        m = board.size(), n = board[0].size();
        Node *root = trie.getRoot();
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(root->containsKey(board[i][j])) dfs(i, j, board, root);
            }
        }
        return ans;
    }
};