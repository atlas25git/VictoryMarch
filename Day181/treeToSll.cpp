class Solution {
    TreeNode* next = NULL;
    public:
    void flatten(TreeNode* root) {
        if(!root)return;
        
        flatten(root->right);
        flatten(root->left);
        
        if(next) 
            root->right = next,
            root->left = NULL;
        next = root;
        
    }
};