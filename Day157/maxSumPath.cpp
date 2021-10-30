class Solution {
  public:
    //Function to return maximum path sum from any node in a tree.
    int findMaxSum(Node* root)
    {
        // in questions like these we choose postorder traversal
        // and while coming back at each root node of subsequent calls
        // we store the maximum sum appearing there and thus return the 
        //global maxima
        
        if(!root)return 0;
        int res = INT_MIN;
        
        fill(root,res);
        return res;
    }
    
    int fill(Node* rt, int& res)
    {
        if(!rt)return 0;
        
        int l = max(0,fill(rt->left,res));
        int r = max(0,fill(rt->right,res));
        
        res = max(res,l+r+rt->data);
        
        return max(l,r) + rt->data;
    }
};