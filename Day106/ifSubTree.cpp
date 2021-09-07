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
