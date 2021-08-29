int fill(Node* root,int& res)
{
    if(!root)return INT_MAX;
    if(!root->right && !root->left)return root->data;
    int val = min(fill(root->right,res),fill(root->left,res));
    res = max(res,root->data - val);
    return min(root->data,val);//zero in the case that diff might become negative
}

//Function to return the maximum difference between any node and its ancestor.
int maxDiff(Node* root)
{
    if(!root)return 0;
    int res = INT_MIN;
    fill(root,res);
    return res;
}
