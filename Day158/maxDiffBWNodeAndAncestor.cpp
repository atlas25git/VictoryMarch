int fill1(Node* root,int& diff)
{
  if(!root)return INT_MAX;
  
  int l = fill1(root->left,diff);
  int r = fill1(root->right,diff);
  
  diff = max(diff,root->data - min(l,r));
  
  return min({root->data,l,r});
}

//Function to return the maximum difference between any node and its ancestor.
int maxDiff(Node* root)
{
  int diff = INT_MIN;
  if(!root)return 0;
  fill1(root,diff);
  return diff;
}
