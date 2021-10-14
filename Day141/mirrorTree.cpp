class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        //base cases
        if(!node)return;
        if(!node->left && !node->right)return;
        
        //in all other cases just swap the nodes be it null or not null
        swap(node->left,node->right);
        
        mirror(node->left);
        mirror(node->right);
    }
};
