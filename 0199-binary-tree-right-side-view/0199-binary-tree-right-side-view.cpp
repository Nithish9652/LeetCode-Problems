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
    void id(TreeNode* root,map<int,int>& m,int dep){
         if(root==NULL){
          return;
         }
         if(m.find(dep)==m.end()){
           m[dep] = root->val;
         }
         id(root->right,m,dep+1);
         id(root->left,m,dep+1);
    }
    vector<int> rightSideView(TreeNode* root) {
      map<int,int> m;
      vector<int> ans;
      id(root,m,0);
      for(auto it : m){
       ans.push_back(it.second);
      }
      return ans;
    }
};