class Solution
{   
    vector<Node*> nodes;
  public:
    //Function to check if S is a subtree of tree T.
    bool isSubTree(Node* T, Node* S) 
    {
        fill(T,fill(S,-1));
        
        for(auto x: nodes)
        {
            if(isSame(x,S))
                return true;
        }
        return false;
    }
    
    int fill(Node* root, int d)
    {
        if(!root)return 0;
        int l  = fill(root->left,d);
        int r  = fill(root->right,d);
        
        int d1 = max(l,r)+1;
        
        if(d==d1)nodes.push_back(root);
        
        return d1;
    }
    
    bool isSame(Node* T,Node* S)
    {
        if(!S && !T)return true;
        if(!S || !T)return false;
        
        return (S->data == T->data) && isSame(T->left,S->left) && isSame(T->right,S->right);
    }
};