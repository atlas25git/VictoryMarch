// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

void sort_and_print(vector <int> &v)
{
    sort( v.begin() , v.end() );
    for( int i=0 ; i<v.size() ; i++ )
        cout<< v[i] << " ";
    v.clear();
}

void printLevelOrder(struct Node* root)
{
    vector <int> v;
    queue <Node*> q;
    
    q.push(root);
    
    Node* next_row = NULL;
    
    while(!q.empty())
    {
        Node* n = q.front();
        q.pop();
        
        if(n==next_row)
        {
            sort_and_print(v);
            next_row = NULL;
        }
        
        v.push_back(n->data);
        
        if(n->left)
        {
            q.push(n->left);
            if(next_row == NULL) next_row = n->left;
        }
        
        if(n->right)
        {
            q.push(n->right);
            if(next_row == NULL) next_row = n->right;
        }
    }
    sort_and_print(v);
}

Node *createTree(int parent[], int n);

/* Driver program to test above function*/
int main()
{
    int t;
    cin>> t;
    while(t--)
    {
        int n;
        cin>> n;
        int a[n];
        for( int i=0 ; i<n ; i++ )
            cin>> a[i];
        
        struct Node *res = createTree(a,n);
        
        printLevelOrder(res);
        cout<<endl;
    }

    return 0;
}

// } Driver Code Ends


/* node structure  used in the program

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

void createNode(int parent[],int i,Node* created[],Node*& root)
{   //return if the node has already been created
    if(created[i])
        return;
    
    //creatiing the node    
    created[i] = new Node(i);
    
    //checking if the current node is the root
    if(parent[i]==-1)
    {
        root = created[i];
        return;
    }
    
    //if not root then checking for the parent of the current node
    if(!created[parent[i]])
    {
        createNode(parent,parent[i],created,root);
        
    }
    
    Node *p = created[parent[i]];
    //filling the children of parent
    //parent is common thus we see if the left 
    //one or the right one has to be filled
    if(!p->left)
            p->left = created[i];
            else p->right = created[i];
}


//Function to construct binary tree from parent array.
Node *createTree(int parent[], int N)
{
    Node* created[N];
    for(int i=0;i<N;i++)
            created[i]=NULL;
    Node* root = NULL;
    for(int i=0;i<N;i++)
        createNode(parent,i,created,root);
    return root;
}