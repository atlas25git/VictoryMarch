class Solution{
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    int isSumProperty(Node *root)
    {   
        if(!root)return 1;
        if(!root->left && !root->right)return 1;
    
        int lt = root->left?root->left->data:0;
        int rt = root->right?root->right->data:0;
        
        if(root->data == lt + rt)
            return (isSumProperty(root->left) && isSumProperty(root->right))?1:0;
        
        return 0;
    
    }
};