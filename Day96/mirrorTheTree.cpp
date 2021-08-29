class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        
        if(!node)return;
        swap(node->left,node->right);
        mirror(node->left);
        mirror(node->right);
    }
};