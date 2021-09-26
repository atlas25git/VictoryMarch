class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)return root;
        TreeNode* lt=NULL,*rt=NULL;
        if(root == p || root==q)return root;
        
        
        lt = lowestCommonAncestor(root->left,p,q);
        rt = lowestCommonAncestor(root->right,p,q);
        
        if(lt && rt)return root;
        else return rt?rt:lt;
    }
};