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
    vector<TreeNode*> candidates;
    
    public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        int sh = getDepthAndFill(subRoot,-1);
        
        getDepthAndFill(root,sh);
        // for(auto x: candidates)cout<<x->val<<" ";
        for(auto x: candidates)
        {
            if(same(x,subRoot))
                    return true;
        }
        return false;
    }
    
    int getDepthAndFill(TreeNode* root,int dt)
    {
        if(!root)return 0;
        int lh = getDepthAndFill(root->left,dt);
        int rh = getDepthAndFill(root->right,dt);
        
        int h = max(lh,rh)+1;
        if(h==dt)candidates.push_back(root);
        return h;
    }
    
    bool same(TreeNode* t1, TreeNode* t2)
    {
        if(!t1 && !t2)return true;
        if(!t1 || !t2)return false;
        return {(t1->val == t2->val) && same(t1->left,t2->left) && same(t1->right,t2->right)};
    }
};