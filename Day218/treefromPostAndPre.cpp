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
//since we've been given pre and post order traversals hence, we'll
//know when iterating from the pre order traversal's starting we'll proceed
//rightwards in post order, ans the given the virtue of orders for a current
//root node p the postOrder will contain p at the last index.
//signifying that this subtree has completely been created.
//Here we'll get the range of node values for a particular subTree but it 
//won't help us with discerning about the direction of children nodes.
class Solution {
public:
    
    int pre = 0,post=0;
    
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        
        TreeNode* root = new TreeNode(preorder[pre++]);
        //subtree not complete
        if(root->val != postorder[post])
            root->left = constructFromPrePost(preorder,postorder);
        //subtree still not complete
        if(root->val != postorder[post])
            root->right = constructFromPrePost(preorder,postorder);
        post++;
        return root;
        
    }
};