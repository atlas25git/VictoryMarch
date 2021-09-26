class Solution {
public:
    unordered_set<int> s;
    
    bool findTarget(TreeNode* root, int k) {
        return find(root,k);
    }
    
    bool find(TreeNode* root,int k)
    {
        if(!root)return 0;
        if(s.count(k-root->val))return true;
        else s.insert(root->val);
        bool l = find(root->left,k);
        bool r = find(root->right,k);
        return r||l;
   }
};