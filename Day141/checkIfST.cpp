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

class Solution
{
  public:
    vector<Node*>cand;
    //Function to check if S is a subtree of tree T.
    bool isSubTree(Node* T, Node* S) 
    {
        //The idea is here to get depth of the subtree
        //and now fill out all those nodes at depth equal to st
        //in an array, and on these do a lookup for all the nodes
        //against the st
        if(!T && !S)return true;
        if(!T || !S)return false;
        //since depth would never be equal to -1, hence won't be stored
        int dis = getDis(S,-1);
        getDis(T,dis);
        for(auto node: cand)
        {
            if(isSame(S,node))return true;
        }
        return false;
        
    }
    
    int getDis(Node* r,int d)
    {
        if(!r)return 0;
        //since this will be filled top down, hence d == depth
        //would only ever haappen at least d call apart
        int dis = max(getDis(r->left,d),getDis(r->right,d))+1;
        if(dis==d)cand.push_back(r);
        return dis;
    }
    
    bool isSame(Node* r,Node* l)
    {
        if(!r&&!l)return true;
        if(!r || !l || r->data!=l->data)return false;
        return (isSame(r->right,l->right) && isSame(r->left,l->left));
    }
};
