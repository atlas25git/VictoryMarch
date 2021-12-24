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

#define data val

class Solution {
public:
    
    TreeNode* find(TreeNode* root,int val)
    {   
        if(!root)return NULL;

        if(root->val == val)
            return root;
        else if(root->data<val) 
            return find(root->right,val);
        else 
            return find(root->left,val);
    }
    
    void printST(TreeNode* node)
    {
        if(!node)return;
        cout<<node->data<<" ";
        printST(node->left);
        printST(node->right);

    }
    
    TreeNode* searchBST(TreeNode* root, int val) {
        return find(root,val);
        //printST(ans1);
    }
};