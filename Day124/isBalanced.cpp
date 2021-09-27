class Solution {
public:
    bool isBalanced(TreeNode* root) {
        bool flag = true;
        find(root,flag);
        return flag;
    }
    
    int find(TreeNode* root,bool& flag)
    {
        if(!root)return 0;
        
        int lh = find(root->left,flag);
        int rh = find(root->right,flag);
        
        if(abs(lh-rh)>1)flag = false;
        
        return max(lh,rh)+1;
    }
};