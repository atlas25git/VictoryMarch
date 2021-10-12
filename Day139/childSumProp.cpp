class Solution{
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    int isSumProperty(Node *root)
    {
        if(!root)return 1;
        if(!root->left && !root->right)return 1;
        
        int lchild = root->left?root->left->data:0;
        int rchild = root->right?root->right->data:0;
        
        if(root->data == lchild+rchild)
            if(isSumProperty(root->left) && isSumProperty(root->right))
                return 1;
                
        return 0;
    }
};