class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* r ,int n1 ,int n2 )
    {
       if(!r)return r;
       
       if(r->data == n1 || r->data == n2)return r;
       Node* l = lca(r->left,n1,n2);
       Node* rt = lca(r->right,n1,n2);
       if(l && rt)return r;
       return l?l:rt;
    }
};
