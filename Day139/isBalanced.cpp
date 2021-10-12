class Solution {
public:
    bool isBalanced(TreeNode* root) {
        int h=0;
        return isb(root,h);
    }
    
    bool isb(TreeNode* root,int& h)
    {
        if(!root){
            h=0;
            return true;
        }
        
        int lh=0,rh=0;
        
        int  l = isb(root->left,lh);
        int  r = isb(root->right,rh);
        
        h = max(lh,rh)+1;
        
        if(abs(lh-rh)>1)return false;
        
        return l&&r;
    }
};