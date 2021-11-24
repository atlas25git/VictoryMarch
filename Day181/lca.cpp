class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)return root;
        if(root->val == p->val || root->val == q->val)return root;
        TreeNode* lc = lowestCommonAncestor(root->left,p,q);
        TreeNode* rc = lowestCommonAncestor(root->right,p,q);
        
        if(lc && rc)return root;
        return lc?lc:rc;
    }
};