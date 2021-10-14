int fill(Node* root,int& mn,int& mx,int cr=0)
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
    int mx = INT_MIN,mn = INT_MAX;
    fill(root,mn,mx);
    return abs(mn) + mx + 1;
}