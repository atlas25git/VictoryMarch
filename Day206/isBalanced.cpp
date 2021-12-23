class Solution {
public:
    bool isBalanced(TreeNode* root) {
        //our approach here is to create height variables for each node
        //and check if at any node the diff>1 hence it fails the defn of
        //balanced tree.
        //The dichotomy here is of that the return type has to be bool meanwhile
        //the judging criteria has to be on the basis of depth of the tree.
        int h = 0;
        return isb(root,h);
    }
    
    bool isb(TreeNode* root,int& h)
    {
        if(!root)
        {
            h = 0;
            return true;
        }
        int lh=0,rh=0;
        bool l = isb(root->left,lh);
        bool r = isb(root->right,rh);
        
        h = max(lh,rh)+1;
        if(abs(lh-rh)>1)return false;
        return l&&r;
    }
};