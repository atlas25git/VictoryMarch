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
