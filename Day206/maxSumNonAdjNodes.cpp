class Solution{
  public:
    
    //Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root) 
    {
        auto a = msa(root);
        return max(a.first,a.second);
    }
    
    pair<int,int> msa(Node* root)
    {
        if(!root)return {0,0};
        auto l = msa(root->left);
        auto r = msa(root->right);
        
        pair<int,int> res;
        res.first = root->data + l.second + r.second;
        res.second = max(l.first,l.second) + max(r.first,r.second);
        
        return res;
    }
};