class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)return nullptr;
        if(root->val>key)
            root->left = deleteNode(root->left,key);
        if(root->val<key)        
        root->right = deleteNode(root->right,key);
        
        if(root->val == key)
        {
            if(!root->left)
            {
                TreeNode* temp = root->right;
                return temp;
            }
            else if(!root->right)
                return root->left;
                TreeNode* r1;
                inOrderSuc(root->right,r1);
                TreeNode* temp = r1;
                root->val = temp->val;
                root->right = deleteNode(root->right,temp->val);
            
        }
        return root;
    }
    
    void inOrderSuc(TreeNode* root,TreeNode*& r1)
    {
        if(!root->left){r1 = root;return;};
        inOrderSuc(root->left,r1);
        // return root;
    }
};