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
    vector<int> in,post;
    int idx;
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        swap(in,inorder),swap(post,postorder);
        idx = n-1;
        return create(0,n-1);
    }
    
    TreeNode* create(int i,int j)
    {
        if(i>j)return NULL;
        TreeNode* root = new TreeNode(post[idx--]);
        if(i==j)return root;
        int div = find(in.begin()+i,in.end(),root->val) - in.begin();
        root->right = create(div+1,j);
        root->left = create(i,div-1);
        return root;
    }
};