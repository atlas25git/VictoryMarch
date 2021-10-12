class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* curr = root;
        vector<int> res;
        if(!root)return res;
        st.push(root);
        
        while(!st.empty())
        {
            curr = st.top();
            st.pop();
            res.push_back(curr->val);
            
            if(curr->right)
                st.push(curr->right);
            if(curr->left)
                st.push(curr->left);
        }
        
        return res;
    }
};