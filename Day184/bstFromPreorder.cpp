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
        int i,j,ind;
        vector<int> in,pre;
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        in = preorder;
        sort(in.begin(),in.end());
        preorder.swap(pre);
        ind = 0;
        // for(auto x: pre)cout<<x<<" ";
        i=0,j=pre.size()-1;
        return create(i,j);
    }
    
    TreeNode* create(int i,int j)
    {
        if(i>j)return nullptr;
        TreeNode* root = new TreeNode(pre[ind++]);
        if(i==j)return root;
        int div = find(in.begin()+i,in.end(),root->val) - in.begin();
        root->left = create(i,div-1);
        root->right = create(div+1,j);
        return root;
    }
};