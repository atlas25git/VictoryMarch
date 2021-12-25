class Solution
{
    public:
    //Function to check whether a Binary Tree is BST or not.
    bool isBST(Node* root) 
    {
        return check(root,INT_MIN,INT_MAX);
    }
    
    bool check(Node* root,int min,int max)
    {
        if(!root)return true;
        if(root->data>min && root->data<max)
        {
            return check(root->left,min,root->data)
                        && check(root->right,root->data,max);
        }
        return false;
    }
};
