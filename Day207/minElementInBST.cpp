int minValue(Node* root) {
    if(!root->left)return root->data;
    return minValue(root->left);
}