class Solution{
  public:
    //Function to construct binary tree from parent array.
    Node *createTree(int parent[], int N)
    {
        vector<Node*> created(N,NULL);
        Node* root;
        for(int i=0;i<N;i++)
            conTree(i,parent,created,root);
        return root;
    }
    
    void conTree(int i,int parent[],vector<Node*>& created,Node*& root)
    {
        if(created[i])return;
        
        created[i] = new Node(i);
        
        if(parent[i] == -1)
        {
            root = created[i];
            return;
        }
        
        if(created[parent[i]] == NULL)
            conTree(parent[i],parent,created,root);
        
        Node* par = created[parent[i]];
        
        if(par->left)
            par->right = created[i];
        else par->left = created[i];
    }
};
