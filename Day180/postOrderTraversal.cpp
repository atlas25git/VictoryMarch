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
    vector<int> postorderTraversal(TreeNode* root) {
        // fillRecursive(root);
        fillIteratively(root);
        return ans;
    }
    
    void fillIteratively(TreeNode* root)
    {
        stack<TreeNode*> st;
        TreeNode* curr = root;
        
        while(!st.empty() || curr)
        {
            while(curr)
                {st.push(curr);
                ans.push_back(curr->val);
                curr = curr->right;}
    
            curr = st.top()->left;
            st.pop();
        }
        reverse(ans.begin(),ans.end());
    }
    
    void fillRecursively(TreeNode* root)
    {
        if(!root)return;
        fillRecursively(root->left);
        fillRecursively(root->right);
        ans.push_back(root->val);
    }
};