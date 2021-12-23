void fill(vector<int>& ans,Node* root,int& mylvl,int lvl)
{
    if(!root)return;
    if(lvl>mylvl)
    {
        ans.push_back(root->data);
        mylvl++;
    }
    fill(ans,root->left,mylvl,lvl+1);
    fill(ans,root->right,mylvl,lvl+1);
}

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
   vector<int> ans;
   int mylvl = -1;
   fill(ans,root,mylvl,0);
   return ans;
}