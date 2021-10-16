
// Function to return the ceil of given number in BST.
int findCeil(Node* root, int input) {
    if (root == NULL) return -1;
    Node* res;
    while(root)
    {
        if(root->data == input)return root->data;
        else if(root->data>input)
        {
            res = root;
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    return !res?-1:res->data;
    // Your code here
}