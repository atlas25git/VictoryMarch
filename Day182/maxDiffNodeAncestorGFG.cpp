class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        return dfs(root,root->val,root->val);
    }
    
    int dfs(TreeNode* root,int mn, int mx)
    {
        if(!root)return mx-mn;
        mx = max(mx,root->val);
        mn = min(mn,root->val);
        
        return max(dfs(root->left,mn,mx),dfs(root->right,mn,mx));
    }
    
};