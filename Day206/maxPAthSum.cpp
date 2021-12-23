class Solution {
  public:
    int max;
    //Function to return maximum path sum from any node in a tree.
    int findMaxSum(Node* root)
    {
        max = INT_MIN;
        findMaxSum1(root);
        return max;
    }
    
    int findMaxSum1(Node* root)
    {
        if(!root)return 0;
        
        int l = std::max(0,findMaxSum1(root->left));
        int r = std::max(0,findMaxSum1(root->right));
        
        max = std::max(max,l+r+root->data);
        
        return std::max(l,r) + root->data;
    }
};
