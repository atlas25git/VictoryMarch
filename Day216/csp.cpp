class Solution{
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    int isSumProperty(Node *root)
    {
        if(!root)return 1;
        if(!root->left && !root->right) return 1;
        
        int ls = root->left?root->left->data:0;
        int rs = root->right?root->right->data:0;
        
        return (root->data == ls+rs &&
                isSumProperty(root->left)
                && isSumProperty(root->right));
    }
};