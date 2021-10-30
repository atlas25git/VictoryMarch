class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        int h = 0;
        return isb(root,h);
    }
    
    bool isb(Node* root,int& h)
    {
        if(!root)
        {
            h=0;//lh/rh
            return true;
        }
        int lh=0,rh=0;
        bool l = isb(root->left,lh);
        bool r = isb(root->right,rh);
        
        h = max(lh,rh)+1;//sets lh/rh
        if(abs(lh-rh)>1)return 0;
        
        return l&&r;
    }
};