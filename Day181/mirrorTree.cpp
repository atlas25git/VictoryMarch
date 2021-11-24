class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        mirror(root);
        return root;
    }
    
    void mirror(TreeNode* root)
    {
        if(!root || (!root->left && !root->right))return;
        swap(root->left,root->right);
        mirror(root->left);
        mirror(root->right);
        return;
    }
};