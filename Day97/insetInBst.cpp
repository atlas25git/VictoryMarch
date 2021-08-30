void fill(Node* root,int key)
{
    if(!root->right && key>root->data)
        {root->right = new Node(key);return;}
    if(!root->left && key<root->data)
        {root->left = new Node(key);return;}
    if(root->data == key)return;
    if(root->data>key)fill(root->left,key);
    if(root->data<key)fill(root->right,key);
}

//Function to insert a node in a BST.
Node* insert(Node* root, int key)
{
    if(!root)return new Node(key);
    fill(root,key);
    return root;
}