class Solution {
  public:
    void fill(Node* root,int l,int h,vector<int>& res)
{
    if(!root)return;
    fill(root->left,l,h,res);
    if(root->data>=l && root->data<=h)res.push_back(root->data);
    fill(root->right,l,h,res);
    
}

//Function to return a list of BST elements in a given range.
vector<int> printNearNodes(Node *root, int low, int high)
{ 
  vector<int> res;
  if(!root)return res;
  fill(root,low,high,res);
  return res;
}
};