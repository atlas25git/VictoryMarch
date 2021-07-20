class Solution
{
    vector<Node*> nodes;
    
  public:
    
    bool isSubTree(Node* T, Node* S) 
    {
        if(!S && !T)return true;
        if(!S || !T)return false;
        
        
        int dis = getDepth(S,-1);
        //cout<<"dis "<<dis<<" ";
        //stores all the nodes with depth equal to subtree
        getDepth(T,dis);
        //cout<<nodes.size()<<"s";
        for(Node* n: nodes)
            {   //cout<<"n "<<n<<" ";
                if(identical(n,S))
                    return true;
            }
        return false;
        
    }
    
    
    int getDepth(Node* r,int d)
    {
        if(!r)return -1;
        
        int depth = max(getDepth(r->left,d),getDepth(r->right,d))+1;
       
        if(depth == d)
            nodes.push_back(r);
        return depth;
    }
    
    bool identical(Node* a,Node* b)
    {
        if(!a && !b)return true;
        if(!a || !b || a->data != b->data)return false;
        return identical(a->left,b->left) && identical(a->right,b->right);
    }
    
    
    
};