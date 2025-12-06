struct Node {
    Node* nxt[26];
    bool end;
    Node() {
        end = false;
        for (int i = 0; i < 26; i++) nxt[i] = NULL;
    }
};

class StreamChecker {
    Node* root;
    string s;
    int mx;

public:
    StreamChecker(vector<string>& words) {
        root = new Node();
        mx = 0;
        for (auto &w : words) {
            mx = max(mx, (int)w.size());
            Node* cur = root;
            for (int i = w.size() - 1; i >= 0; i--) {
                int x = w[i] - 'a';
                if (!cur->nxt[x]) cur->nxt[x] = new Node();
                cur = cur->nxt[x];
            }
            cur->end = true;
        }
    }

    bool query(char letter) {
        s.push_back(letter);
        Node* cur = root;
        int cnt = 0;
        for (int i = s.size() - 1; i >= 0 && cnt < mx; i--, cnt++) {
            int x = s[i] - 'a';
            if (!cur->nxt[x]) return false;
            cur = cur->nxt[x];
            if (cur->end) return true;
        }
        return false;
    }
};
