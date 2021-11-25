class Solution {
        int max;
public:
    int maxPathSum(TreeNode* root) {
        max = INT_MIN;
        fill(root);
        return max;
    }
    
    int fill(TreeNode* root)
    {
        if(!root)return 0;
        int lm = std::max(fill(root->left),0);
        int rm = std::max(fill(root->right),0);
        max = std::max(max,lm + rm + root->val);
        return std::max(lm,rm) + root->val;
    }
};