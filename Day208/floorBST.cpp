void fill(Node* root,int key,int& flr)
{
    if(!root)return;
    if(root->data == key)
    {
        flr = root->data;
        return;
    }
    if(root->data>key)
    {
        fill(root->left,key,flr);
    }
    if(root->data<key)
    {
        flr = max(root->data,flr);
        fill(root->right,key,flr);
    }
    
}

int floor(Node* root, int key) {
    int flr = -1;
    fill(root,key,flr);
    return flr;
}