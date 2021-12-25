class Solution {
  public:
  Node* fe=0,*se=0,*pe=0;
    void correctBST( struct Node* root )
    {
        fill(root);
        // cout<<"OG\n";
        // printT(root);
        // cout<<"\nCorrected\n";
        swap(fe->data,se->data);
        // printT(root);
    }
    void printT(Node* root)
    {
        if(!root)return;
        printT(root->left);
        cout<<root->data<<" ";
        printT(root->right);
    }
    
    void fill(Node* root)
    {
        if(!root)return;
        fill(root->left);
        
        if(!fe && (!pe ||(pe->data >= root->data)))
            fe = pe;
        if(fe && (pe->data >= root->data))
            se = root;
        pe = root;
        
        fill(root->right);
    }
};
