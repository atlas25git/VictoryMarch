int k;

Node* create(int in[],int post[],int s, int e)
{
    if(s>e)return NULL;
    Node* curr = new Node(post[k--]);
    if(s==e)return curr;
    int ind = find(in+s,in+e,curr->data) - in;
    
    curr->right = create(in,post,ind+1,e);
    curr->left = create(in,post,s,ind-1);
    
    return curr;
}

Node *buildTree(int in[], int post[], int n) {
    // Your code here
    k=n-1;
    return create(in,post,0,n-1);
}