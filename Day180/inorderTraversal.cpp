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
    private:
    vector<int> ans;
    public:
    vector<int> inorderTraversal(TreeNode* root) {
        // fill(root);
        stack<TreeNode*> st;
        // st.push(root);
        TreeNode* curr = root;
        while(!st.empty() || curr)
        {
            while(curr)
                st.push(curr),
                curr = curr->left;
            
            curr = st.top();
            ans.push_back(curr->val);
            st.pop();
            curr = curr->right;
        }
        return ans;
    }
    
    void fill(TreeNode* root)
    {
        if(!root)return;
        fill(root->left);
        ans.push_back(root->val);
        fill(root->right);
    }
};