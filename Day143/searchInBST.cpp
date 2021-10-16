bool search(Node* root, int x) {
    if(!root)return 0;
    if(root->data == x)return 1;
    bool l,r;
    l=search(root->left,x);
    r=search(root->right,x);
    
    return l||r;
}
