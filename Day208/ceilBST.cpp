void fill(Node* root,int input,int& ceil)
{
    if(!root)return;
    if(root->data == input){
        ceil = root->data;
        return;
    }
    if(root->data > input)
    {
        ceil = min(ceil,root->data);
        fill(root->left,input,ceil);
    }
    else fill(root->right,input,ceil);
}

// Function to return the ceil of given number in BST.
int findCeil(Node* root, int input) {
    if (root == NULL) return -1;
    int ceil = INT_MAX;
    fill(root,input,ceil);
    return ceil;
    // Your code here
}