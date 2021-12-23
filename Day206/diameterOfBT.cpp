class Solution {
  public:
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        int dia = INT_MIN;
        fill(root,dia);
        return dia;
    }
    
    int fill(Node* root, int& dia)
    {
        if(!root)
        {
            return 0;
        }
        
        int ld = fill(root->left,dia);
        int rd = fill(root->right,dia);
        
        dia = max(dia,ld+rd+1);
        
        return max(ld,rd)+1;
    }
};