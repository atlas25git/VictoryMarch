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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)return root;
        if(root->val>key)
            root->left = deleteNode(root->left,key);
        else if(root->val<key)
            root->right = deleteNode(root->right,key);
        else //if(root->val == key)
        {
            if(!root->left)
            {
                TreeNode* temp = root->right;
                return temp;
            }
            else if(!root->right)
            {
                TreeNode* temp = root->left;
                return temp;
            }
            else{
                TreeNode* temp = inOrderSuc(root->right);
                root->val = temp->val;
                root->right = deleteNode(root->right,temp->val);
            }
        }
        return root;
    }
    TreeNode* inOrderSuc(TreeNode* root)
    {
        if(!root->left)return root;
        return inOrderSuc(root->left);
    }
};