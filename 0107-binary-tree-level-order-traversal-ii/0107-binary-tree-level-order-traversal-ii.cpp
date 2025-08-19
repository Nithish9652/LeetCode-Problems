class Solution {
public:
    void helper(TreeNode* root, map<int,vector<int>>&m, int level){
        
        if(root==NULL)
            return;
        
        m[level].push_back(root->val);
        
        helper(root->left, m, level+1);
        helper(root->right, m, level+1);        
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        vector<vector<int>>ans;
        map<int,vector<int>>m;
        helper(root, m, 0);
        
       for(auto it= m.rbegin();it!=m.rend();it++){
            ans.push_back(it->second);
        }        
      
        return ans;        
    } 
};