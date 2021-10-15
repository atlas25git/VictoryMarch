class Solution {
  public:
    //Function to return maximum path sum from any node in a tree.
    int findMaxSum(Node* root)
    {
        if(!root)return 0;
        int res = INT_MIN;
        fill(root,res);
        return res;
    }
    
    int fill(Node* root,int& res)
    {
        if(!root)return 0;
        
        int l = max(0,fill(root->left,res));
        int r = max(0,fill(root->right,res));
        
        res = max(res,l+r+root->data);
        
        return max(l,r)+root->data;
    }
};