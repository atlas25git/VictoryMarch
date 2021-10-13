class Solution
{
    public: 
    void lv(vector<int> &res,Node* root,int lvl,int& ml)
{
    if(!root)return;
    if(ml<lvl)
    {
        res.push_back(root->data);
        ml = lvl;
    }
    lv(res,root->right,lvl+1,ml);
    lv(res,root->left,lvl+1,ml);
}
//Function to return a list containing elements of left view of the binary tree.
vector<int> rightView(Node *root)
{
   int ml =-1;
   vector<int> res;
   lv(res,root,0,ml);
   return res;
}
};