Node* fill(Node* root,int i)
{
    if(!root)return new Node(i);
    if(i>=root->data)
        root->right = fill(root->right,i);
    else root->left = fill(root->left,i);
    
    return root;
}

Node* constructBst(int arr[], int n)
{
    Node* root = NULL;
    for(int i=0;i<n;i++)
        root =fill(root,arr[i]);
    return root;
}