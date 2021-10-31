class Solution
{
  public:
    
    vector<Node*> props;
  
    //Function to check if S is a subtree of tree T.
    bool isSubTree(Node* T, Node* S) 
    {
        //1. Calculate the depth of subtree
        //2. Fill in all the nodes of T which can be prospects.
        //3. Now check for these if these match.
        int dpt = getDepth(S,-1);
        
        //filling
        getDepth(T,dpt);
        
        for(auto x: props)
        {
            if(isSame(x,S))
            return true;
        }
        return false;
        
    }
    
    int getDepth(Node* rt,int dpt)
    {
        if(!rt)return 0;
        int ld = getDepth(rt->left,dpt);
        int rd = getDepth(rt->right,dpt);
        
        int dpt1 =  max(ld,rd)+1;
        if(dpt1 == dpt)props.push_back(rt);
        return dpt1;
    }
    
    bool isSame(Node* a,Node* b){
        if(!a && !b)return true;
        if(!a || !b)return false;
        return (a->data == b->data && isSame(a->left,b->left) && isSame(a->right,b->right));
        
    }

    
};