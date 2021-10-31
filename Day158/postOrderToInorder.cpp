int k = 0;
Node* root= NULL;

Node* create(int in[], int post[],int s, int e)
{
    if(s>e)return NULL;
    Node* curr = new Node(post[k--]);
    if(s==e)return curr;
    
    int ind = find(in,in+e,curr->data)-in;
    //we find out the index seperating left and right subtrees
    //filling the children nodes
    //right first cause while reverse iterating the postOrder
    //right will come first, left would be filled first in case of preOrder
    curr->right = create(in,post,ind+1,e);
    curr->left = create(in,post,s,ind-1);
    
    return curr;
}

//Function to return a tree created from postorder and inoreder traversals.
Node *buildTree(int in[], int post[], int n) {
    k=n-1;
    root = create(in,post,0,n-1);
    return root;
}