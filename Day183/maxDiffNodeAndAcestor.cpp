/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        return diff(root,root->val,root->val);
    }
    
    int diff(TreeNode* root,int mx, int mn)
    {
        if(!root)return mx-mn;
        mn = min(mn,root->val);
        mx = max(mx,root->val);
        
        return max(diff(root->left,mx,mn),diff(root->right,mx,mn));
    }
};