/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void  id(TreeNode* root,vector<int>& a1){
       if(root==NULL){
       return;
       }
       id(root->left,a1);
       id(root->right,a1);
        a1.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> a1;
        id(root,a1);
        return a1;
    }
};