class Solution {
public:
    unordered_map<int,int> mp;  // value -> index in inorder
    int idx;                    // postorder index

    TreeNode* build(int l, int r, vector<int>& inorder, vector<int>& postorder) {
        if (l > r) return nullptr;

        int val = postorder[idx--];          // root is last in postorder
        TreeNode* root = new TreeNode(val);

        int pos = mp[val];                   // find root in inorder

        // IMPORTANT: build right subtree first (because postorder is left-right-root)
        root->right = build(pos + 1, r, inorder, postorder);
        root->left  = build(l, pos - 1, inorder, postorder);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        idx = n - 1;

        for (int i = 0; i < n; i++) {
            mp[inorder[i]] = i;
        }

        return build(0, n - 1, inorder, postorder);
    }
};
