class Solution {
    TreeNode* fe = NULL,*se=NULL,*pe;
public:
    void recoverTree(TreeNode* root) {
        traverse(root);
        swap(fe->val,se->val);
    }
    
    void traverse(TreeNode* root)
    {
        if(!root)return;
        traverse(root->left);
        if(!fe && (!pe || pe->val >= root->val))
                fe = pe;
        if(fe && pe->val >= root->val)
            se = root;
        pe = root;
        traverse(root->right);
    }
};