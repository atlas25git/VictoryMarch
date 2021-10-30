class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       if(!root)return root;
       Node* l,*r;
       if(root->data == n1 || root->data ==n2)return root;
        //since l and r are called on the same root ,hence will 
        //contain a common node.
       l = lca(root->left,n1,n2);
       r = lca(root->right,n1,n2);
       
       if(l&&r)return root;
       else return l?l:r;
    }
};

class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       if(!root)return 0;
       if(root->data == n1 || root->data == n2)
       return root;
       
       Node* left = lca(root->left,n1,n2);
       Node* right = lca(root->right,n1,n2);
       
       if(left && right) return root;
       else return left?left:right;
    }
};
