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
    void id(TreeNode* root,int& ans,int c){
         if(root==NULL){
          return;
         }
         ans = max(c,ans);
         id(root->left,ans,c+1);
         id(root->right,ans,c+1);
    }
    int maxDepth(TreeNode* root) {
        int ans = 0;
        id(root,ans,1);
        return ans;
    }
};