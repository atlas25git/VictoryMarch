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
    vector<int> preorderTraversal(TreeNode* root) {
        // fill(root);
        if(!root)return vector<int>();
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty())
        {
            auto x = st.top();
            st.pop();
            ans.push_back(x->val);
            if(x->right)st.push(x->right);
            if(x->left)st.push(x->left);            
        }
        
        return ans;
    }
    void fill(TreeNode* root)
    {
        if(!root)return;
        ans.push_back(root->val);
        fill(root->left);
        fill(root->right);
    }
};