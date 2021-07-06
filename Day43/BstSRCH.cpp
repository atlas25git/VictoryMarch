// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};

bool search(Node* root, int x);

Node *insert(Node *tree, int val)
{
    Node *temp = NULL;
    if (tree == NULL)
        return new Node(val);

    if (val < tree->data)
    {
        tree->left = insert(tree->left, val);
    }
    else if (val > tree->data)
    {
        tree->right = insert(tree->right, val);
    }
    
    return tree;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node *root = NULL;

        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int k;
            cin>>k;
            root = insert(root, k);

        }

        int s;
        cin>>s;
        
     cout<<search(root,s);
     cout<<endl;
    }
}

// } Driver Code Ends




bool src(Node* root , int x)
{   
    //the case where key isn't present is handled by this base case
    //for the case where we do not have the key present in the bst
    //we'll end up with a Null value;
    if(!root)return false;
    if(root->data == x)return true;
    if(x>root->data)search(root->right,x);
    else if(root && x<root->data)search(root->left,x);
    //return false;
}
//Function to search a node in BST.
bool search(Node* root, int x)
{   
    if(!root)return false;
    //cout<<src(root,x)<<endl;
    if(src(root,x))return true;
    
    
    return false;
}
