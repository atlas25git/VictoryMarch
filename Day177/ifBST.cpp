class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(!root)return true;
        return chk(root,INT_MIN,INT_MAX);
    }
    
    bool chk(TreeNode* root,long long min,long long max)
    {   
        if(!root)return true;
        if(root->val>max || root->val<min)return false;
        
        bool lft = chk(root->left,min,(long long)root->val-1);
        bool rt = chk(root->right,(long long)root->val+1,max);
        
        return lft&&rt;
    }
        
};