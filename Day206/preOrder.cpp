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
    // O(n) S,T solution
    vector<int> preorderTraversal1(TreeNode* root) {
        if(!root)return vector<int>();
        vector<int> ans;
        stack<TreeNode*> st;
        st.push(root);
        
        while(!st.empty())
        {
            TreeNode* curr = st.top();
            ans.push_back(curr->val);
            st.pop();
            if(curr->right)st.push(curr->right);
            if(curr->left)st.push(curr->left);
        }
        return ans;
    }
    
    // TC : O(n)
    // SC : O(h)
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* curr = root;
        
        while(curr || !st.empty())
        {
            while(curr)
            {
                ans.push_back(curr->val);
                st.push(curr->right);
                curr = curr->left;
            }
            if(!st.empty())curr=st.top(),st.pop();
        }
        return ans;
    }

};