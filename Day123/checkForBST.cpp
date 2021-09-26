class Solution
{
    public:
    //Function to check whether a Binary Tree is BST or not.
    bool ibu(Node* root,int min,int max)
    {
        if(!root)return true;
        
        if(root->data<min || root->data>max)return false;
        
        return (ibu(root->left,min,root->data-1)
                &&
                ibu(root->right,root->data+1,max));
        
    }

    bool isBST(Node* root) 
    {
        return ibu(root,INT_MIN,INT_MAX);
    }
};
