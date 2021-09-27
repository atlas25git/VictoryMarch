class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       if(!root)return root;
       Node* l,*r;
       if(root->data == n1 || root->data ==n2)return root;
       l = lca(root->left,n1,n2);
       r = lca(root->right,n1,n2);
       if(l&&r)return root;
       else return l?l:r;
    }
};