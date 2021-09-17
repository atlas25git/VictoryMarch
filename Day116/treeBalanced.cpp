class Solution{
    public:
    bool isb(Node* root,int& h)
    {
        int l=0,r=0,lh=0,rh=0;
        if(!root){h=0;return 1;}
        l = isb(root->left,lh);
        r = isb(root->right,rh);
        h = max(lh,rh)+1;
        if(abs(lh-rh)>=2)return 0;
        else return l&&r;
    }
    
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        int h = 0;
        return isb(root,h);
    }
};

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
            return 1;
        }
        int lh=0,rh=0;
        bool l = isb(root->left,lh);
        bool r = isb(root->right,rh);
        
        h = max(lh,rh)+1;//sets lh/rh
        if(abs(lh-rh)>1)return 0;
        
        return l&&r;
    }
};