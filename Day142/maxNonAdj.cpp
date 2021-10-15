class Solution{
  public:
    //Function to return the maximum sum of non-adjacent nodes.
    pair<int,int> msh(Node* root)
{
    if(!root)return pair<int,int> (0,0);
    
    pair<int,int> sum1 = msh(root->left);
    pair<int,int> sum2 = msh(root->right);
    pair<int,int> res1;
    
    //including curr node
    //hence our freedom of choice is restricted
    res1.first = root->data + sum1.second + sum2.second;
    //!inc
    ///greater degree of freedom for choice hence any of the max case
    //that is either including the subsequent nodes, or their option of non
    //inclusion
    res1.second = max(sum1.first,sum1.second) + max(sum2.second,sum2.first);
    
    return res1;
}

int getMaxSum(Node *root) 
{
    pair<int,int> res = msh(root);
    return max(res.first,res.second);
}
};