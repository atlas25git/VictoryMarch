class Solution{
  public:
    //Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root) 
    {
        pair<int,int> ans = fill(root);
        return max(ans.first,ans.second);
    }
    
    pair<int,int> fill(Node* root)
    {
        if(!root)return {0,0};
        
        pair<int,int> s1 = fill(root->left);
        pair<int,int> s2 = fill(root->right);
        
        pair<int,int> res1;
        
        res1.first = root->data + s1.second + s2.second;
        res1.second = max(s1.first,s1.second) + max(s2.first,s2.second);
        
        return res1;
        
    }
};