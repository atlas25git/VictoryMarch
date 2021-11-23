class Solution{
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    int isSumProperty(Node *root)
    {
        if(!root || (!root->left && !root->right))return true;
        
        
        int lc = root->left?root->left->data:0;
        int rc = root->right?root->right->data:0;
        
        return (root->data == lc + rc) 
            && isSumProperty(root->left) 
            && isSumProperty(root->right);
    }
};