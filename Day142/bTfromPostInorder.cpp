int idx = 0;

Node* mt(int in[],int post[],int i,int j)
{
    //base case:
    if(i>j)return NULL;
    
    Node* tNode = new Node(post[idx--]);
    
    //Node element
    if(i==j)return tNode;
    
    //has got subchilds:
    int d = find(in,in+j,tNode->data) - in;
    
    //filling the children nodes
    //right first cause while reverse iterating the postOrder
    //right will come first, left would be filled first in case of preOrder
    tNode->right = mt(in,post,d+1,j);
    tNode->left = mt(in,post,i,d-1);
    
    return tNode;
}

//Function to return a tree created from postorder and inoreder traversals.
Node *buildTree(int in[], int post[], int n) {
    idx = n-1;
    return mt(in,post,0,n-1);
}

int k = 0;
Node* root= NULL;

Node* create(int in[], int post[],int s, int e)
{
    if(s>e)return NULL;
    Node* curr = new Node(post[k--]);
    if(s==e)return curr;
    
    int ind = find(in,in+e,curr->data)-in;
    //we find out the index seperating left and right subtrees
    
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
