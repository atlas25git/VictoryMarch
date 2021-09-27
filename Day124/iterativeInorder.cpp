class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> res;
        TreeNode* curr = root;
        while(!s.empty() || curr)
        {
            while(curr)
                s.push(curr),
                curr = curr->left;
            
            curr = s.top();
            s.pop();
            res.push_back(curr->val);
            curr = curr->right;
        }
        
        return res;
    }
};