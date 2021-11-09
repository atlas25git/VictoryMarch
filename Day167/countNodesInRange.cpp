void fill(Node* root, int l ,int h, int& count)
    {
        if(!root)return;
        if(root->data >= l && root->data <= h)
            count++;
        fill(root->left,l,h,count);
        fill(root->right,l,h,count);
    }


//Function to count number of nodes in BST that lie in the given range.
int getCount(Node *root, int l, int h)
{
  int count =0;
  fill(root,l,h,count);
  return count;
}