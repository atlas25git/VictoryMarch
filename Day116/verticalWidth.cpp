int fill(Node* rt,int& mx,int& mn,int curr)
{
    if(!rt)return 0;
    fill(rt->left,mx,mn,curr-1);
    mn = min(mn,curr);
    fill(rt->right,mx,mn,curr+1);
    mx = max(mx,curr);
}

//Function to find the vertical width of a Binary Tree.
int verticalWidth(Node* root)
{
    if(!root)return 0;
    int mx=INT_MIN,mn=INT_MAX;
    fill(root,mx,mn,0);
    return mx + abs(mn) +1;
}