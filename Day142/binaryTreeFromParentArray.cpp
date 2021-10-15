class Solution{
  public:
    //Function to construct binary tree from parent array.
    Node *createTree(int parent[], int N)
    {   
        vector<Node*> nodes(N,NULL);
        Node* root;
        for(int i=0;i<N;i++)
            create(parent,nodes,i,root);
        
        return root;
    }
    
    void create(int parent[],vector<Node*>& nodes,int i,Node*& root)
    {
        if(nodes[i]!=NULL)
            return;
        
        nodes[i] = new Node(i);
        
        if(parent[i] == -1)
            {root = nodes[i];return;}
        
        if(nodes[parent[i]] == NULL)
            create(parent,nodes,parent[i],root);
        
        Node* par = nodes[parent[i]];
        
        if(!par->left)
            par->left = nodes[i];
        else par->right = nodes[i];
    }
};