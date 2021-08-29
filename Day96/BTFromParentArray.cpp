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
        if(created[parent[i]] == NULL)go(parent,created,parent[i],root);
        Node* p  = created[parent[i]];
        if(!p->left) 
                p->left = created[i];
        else p->right = created[i];
    }
};

class Solution{
  public:
    //Function to create nodes.
    void createNode(int parent[], int i, Node *created[], Node **root)
    {
        
        //base case if this node is already created.
        if (created[i] != NULL)
            return;
            
        //creating a new node and setting created[i]. 
        created[i] = new Node(i);
        
        //if 'i' is root, changing root pointer.
        if (parent[i] == -1)
        {
            *root = created[i];
            return;
        }
        
        //if parent is not created then we create parent first.
        if (created[parent[i]] == NULL)
            createNode(parent, parent[i], created, root);
        
        //finding parent pointer. 
        Node *p = created[parent[i]];
        
        //if this is first child of parent, we store it as left child.
        if (p->left == NULL)
            p->left = created[i];
        //else we store it as right child.
        else
            p->right = created[i];
    }
    
    //Function to construct binary tree from parent array.
    Node *createTree(int parent[], int n)
    {
        //creating an array created[] to keep track of created nodes, 
        //initializing all entries as NULL.
        Node *created[n];
        for (int i=0; i<n; i++)
            created[i] = NULL;
    
        Node *root = NULL;
        for (int i=0; i<n; i++)
            createNode(parent, i, created, &root);
        
        //returning root of created tree.
        return root;
    }
};