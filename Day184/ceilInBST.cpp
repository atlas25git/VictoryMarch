int findCeil(Node* root, int input) {
    if (root == NULL) return -1;
    Node* res = NULL;
    
    while(root)
    {
        if(root->data == input)return root->data;
        else if(root->data< input)root = root->right;
        else{
            res = root;
            root = root->left;
        }
    }
    if(!res)return -1;
    return res->data;
}