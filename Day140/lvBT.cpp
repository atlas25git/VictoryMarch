void lv(vector<int> &res,Node* root,int lvl,int& ml)
{
    if(!root)return;
    if(ml<lvl)
    {
        res.push_back(root->data);
        ml = lvl;
    }
    lv(res,root->left,lvl+1,ml);
    //since lvl value for this fn call is same, and 
    //in the prior call ml has been made equal to lvl
    lv(res,root->right,lvl+1,ml);
}
//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
   int ml =0;
   vector<int> res;
   lv(res,root,1,ml);
   return res;
}