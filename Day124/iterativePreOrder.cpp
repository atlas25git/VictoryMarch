class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root)return vector<int>();
        stack<TreeNode*> s;
        vector<int> res;
        s.push(root);
        
        while(!s.empty())
        {
            TreeNode* curr = s.top();
            s.pop();
            res.push_back(curr->val);
            
            if(curr->right)s.push(curr->right);
            if(curr->left)s.push(curr->left);
        }
        
        return res;
    }
};