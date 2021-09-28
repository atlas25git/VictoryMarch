class Solution{
  public:
    //Function to construct binary tree from parent array.
    Node *createTree(int parent[], int N)
    {
        vector<Node*>created(N,NULL);
        Node* root;
        for(int i=0;i<N;i++)
            go(parent,created,i,root);
        return root;
    }
    void go(int parent[],vector<Node*>& created,int i,Node*& root)
    {
        if(created[i])return;
        
        created[i] = new Node(i);
        
        if(parent[i] == -1){root = created[i];return;}
        
        if(created[parent[i]] == NULL)
            go(parent,created,parent[i],root);
        
        Node* p  = created[parent[i]];
        
        if(!p->left) 
                p->left = created[i];
        else p->right = created[i];
    
    }
};