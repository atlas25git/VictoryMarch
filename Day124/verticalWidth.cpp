int fill(Node* root,int& mn,int& mx,int cr)
{
    if(!root)return 0;
    fill(root->right,mn,mx,cr+1);
    mx = max(mx,cr);
    fill(root->left,mn,mx,cr-1);
    mn = min(mn,cr);
}

//Function to find the vertical width of a Binary Tree.
int verticalWidth(Node* root)
{
    if(!root)return 0;
    int mn = INT_MAX,mx=INT_MIN;
    fill(root,mn,mx,0);
    return mx + abs(mn) + 1;
}
