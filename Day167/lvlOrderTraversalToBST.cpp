Node* fill(Node*& rt,int i)
{
    if(!rt)
        return new Node(i);
    if(rt->data>i)
        rt->left = fill(rt->left,i);
    else
        rt->right = fill(rt->right,i);
    return rt;
}


//Function to construct the BST from its given level order traversal.
Node* constructBst(int arr[], int n)
{
    Node* bst = NULL;
    bst  = fill(bst,arr[0]);
    for(int i=1;i<n;i++)
        fill(bst,arr[i]);
    return bst;
}