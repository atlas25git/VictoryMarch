void fill(Node* rt,int k)
{
    if(!rt->left && k<rt->data)
        {
            rt->left = new Node(k);
            return;
        }
    if(!rt->right && k>rt->data)
        {
            rt->right = new Node(k);
            return;
        }
    if(rt->data == k)return;
    if(rt->data>k)fill(rt->left,k);
    else fill(rt->right,k);
}


// Function to insert a node in a BST.
Node* insert(Node* root, int Key) {
    fill(root,Key);
    return root;
}