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
    int maxPathSum(TreeNode* root) {
        int max = INT_MIN;
        fill(root,max);
        return max;
    }
    
    int fill(TreeNode* root, int& max)
    {
        if(!root)return 0;
        
        int lm = std::max(fill(root->left,max),0);
        int rm = std::max(fill(root->right,max),0);
        
        max = std::max(max,lm+rm+root->val);
        
        return std::max(lm,rm)+root->val;
    }
};