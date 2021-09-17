class Solution {
  public:
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* rt) {
        if(!rt)return 0;
        int mx=INT_MIN;
        fill(rt,mx);
        return mx;
        
    }
    int fill(Node* rt, int& mx)
    {
       if(!rt)return 0;
       int ld = fill(rt->left,mx);
       int rd = fill(rt->right,mx);
       
       mx = max(mx,ld+rd+1);
       
       return max(ld,rd)+1;
        
    }
};