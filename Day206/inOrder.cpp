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
// T.C. : O(n)
// S.C. : O(h)

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root)return ans;
        stack<TreeNode*> st;
 
        TreeNode* curr = root;
        
        while(curr || !st.empty())
        {
            while(curr)
                st.push(curr),
                curr = curr->left;
            curr = st.top();
            st.pop();
            ans.push_back(curr->val);
            curr  = curr->right;
        }
        return ans;
    }
};