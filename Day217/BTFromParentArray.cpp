class Solution{
        Node* root;
        vector<Node*> nodes;
  public:
    //Function to construct binary tree from parent array.
    Node *createTree(int parent[], int N)
    {   nodes.resize(N,NULL);
        for(int i=0;i<N;i++)
            if(!nodes[i])
                create(parent,N,i);
        return root;
    }
    
    void create(int* parent,int N,int i)
    {   
        // if(nodes[i])return;
        nodes[i] = new Node(i);
        if(parent[i] == -1){root = nodes[i];return;}
        if(!nodes[parent[i]])
            create(parent,N,parent[i]);
        Node * par = nodes[parent[i]];
        
        if(par->left)par->right = nodes[i];
        else par->left = nodes[i];
    }
};