int minValue(Node* root) {
    if(!root->left)return root->data;
    minValue(root->left);
}