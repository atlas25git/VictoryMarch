Node* fill(Node* root,int i)
{
    if(!root)return new Node(i);
    
    if(root->data <= i)
        root->right = fill(root->right,i);
    else 
        root->left = fill(root->left,i);
    
    return root;
}

//Function to construct the BST from its given level order traversal.
Node* constructBst(int arr[], int n)
{
    if(!n)return NULL;
    Node* root = NULL;
    for(int i=0;i<n;i++)
        root = fill(root,arr[i]);
    return root;
}
